BUILD=build/

KERNEL_SOURCES=$(wildcard kernel/*.c kernel/drivers/*.c)
OBJ=${KERNEL_SOURCES:.c=.o}

C_FLAGS=-m32 -ffreestanding -g
LD_FLAGS=-melf_i386
NASMFLAGS=-felf32

#C_FLAGS=-ffreestanding -g
#LD_FLAGS=-melf
#NASMFLAGS=-felf

QEMU=qemu-system-i386

all: dir kernel.bin boot.bin os-image os

run: 
	$(QEMU) -hda ${BUILD}os.img

debug:
	$(QEMU) -fda ${BUILD}os.img -gdb tcp::9999 -S

os-image:
	cat ${BUILD}boot.bin ${BUILD}kernel.bin > ${BUILD}os-image

os: $(BUILD)os-image
	dd if=/dev/zero bs=1024 count=1440 > ${BUILD}$@.img
	dd if=$< of=${BUILD}$@.img conv=notrunc

boot.bin: boot/boot_sect.asm
	nasm $(NASM_FLAGS) $< -f bin -I 'boot/' -o ${BUILD}$@

%kernel_entry.o: kernel/kernel_entry.asm
	nasm $< $(NASMFLAGS) -o kernel/kernel_entry.o

kernel.bin: kernel/kernel_entry.o $(OBJ)	
	ld $(LD_FLAGS) -o ${BUILD}$@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c
	gcc $(C_FLAGS) -c $< -o $@

dir:
	mkdir -p $(BUILD)

clean:
	@rm -f kernel/*.o kernel/drivers/*.o
	@rm -r $(BUILD)

