#include "../include/drivers/screen.h"
#include "../include/low_level.h"

unsigned char* vidmem;

int get_screen_offset(int row, int col){
  return (row * MAX_COLS + col) * 2;
}

int get_cursor(){
  port_byte_out(REG_SCREEN_CTRL, 14);
  int offset = port_byte_in(REG_SCREEN_DATA) << 8;
  port_byte_out(REG_SCREEN_CTRL, 15);
  offset += port_byte_in(REG_SCREEN_DATA);
  return offset * 2;
}

void set_cursor(int offset){
  offset /= 2;
  port_byte_out(REG_SCREEN_CTRL, 14);
  port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
  port_byte_out(REG_SCREEN_CTRL, 15);
  port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset));
}

void clear_screen()
{
	int i,j;
	for(i=0; i<MAX_ROWS; i++){
		for(j=0;j<MAX_COLS;j++){
			print_char(' ', i, j, WHITE_ON_BLACK);
		}
	}
	set_cursor(get_screen_offset(0, 0));
}

void print_at(char* message, int row, int col){

	if (row >= 0 && col >= 0){
		set_cursor(get_screen_offset(row, col));
	}

	char c;
	int i = 0;
	while((c = message[i++]) != 0){
		print_char(c, -1, -1, 0);
	}
}

int scroll(int offset){
	
	if(offset < MAX_ROWS * MAX_COLS * 2){
		return offset;	
	}

	int i, j;
	char *c, *cc;
	for(i = 1; i < MAX_ROWS; i++){
		for(j = 0; j < MAX_COLS * 2; j++){
			vidmem[get_screen_offset(i-1,j)] = vidmem[get_screen_offset(i,j)];
		}
	}

	for(j = 0; j < MAX_COLS * 2; j++){
		vidmem[get_screen_offset(MAX_ROWS - 1, j)] = 0;	
	}

	offset = get_screen_offset(MAX_ROWS - 1, 0);
	return offset;
}

void print_char(char c, int row, int col, char att){
	
	if(!att){
		att = WHITE_ON_BLACK;	
	}

	int offset;
	if (row >= 0 && col >= 0){
		offset = get_screen_offset(row, col);
	} else {
		offset = get_cursor();
	}

	int rows;
	switch (c){
		case '\n':
			rows = offset / (2*MAX_COLS);
			offset = get_screen_offset(rows, 79);
			break;
		default:
			vidmem[offset] = c;
			vidmem[offset + 1] = att;
	}

	offset = scroll(offset+2);	
	set_cursor(offset);
}

void print(char *str)
{
	int i;
	for(i=0; str[i]!='\0'; i++)
		print_char(str[i], -1, -1, 0);
}

void screen_init(){
	vidmem = (unsigned char*)VIDEO_ADDRESS;
}

