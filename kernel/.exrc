if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <C-Space> 
imap <Nul> <C-Space>
inoremap <expr> <Up> pumvisible() ? "\" : "\<Up>"
inoremap <expr> <S-Tab> pumvisible() ? "\" : "\<S-Tab>"
inoremap <expr> <Down> pumvisible() ? "\" : "\<Down>"
nnoremap <silent>  :nohlsearch=has('diff')?'|diffupdate':''
map  :NERDTreeToggle
nnoremap <silent>  :CtrlP
vmap [% [%m'gv``
nmap [c <Plug>GitGutterPrevHunk
nmap \hp <Plug>GitGutterPreviewHunk
nmap \hr <Plug>GitGutterRevertHunk
nmap \hs <Plug>GitGutterStageHunk
nnoremap \d :YcmShowDetailedDiagnostic
vmap ]% ]%m'gv``
nmap ]c <Plug>GitGutterNextHunk
vmap a% [%v]%
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
nnoremap <silent> <Plug>GitGutterPreviewHunk :GitGutterPreviewHunk
nnoremap <silent> <Plug>GitGutterRevertHunk :GitGutterRevertHunk
nnoremap <silent> <Plug>GitGutterStageHunk :GitGutterStageHunk
nnoremap <silent> <expr> <Plug>GitGutterPrevHunk &diff ? '[c' : ":\execute v:count1 . 'GitGutterPrevHunk'\"
nnoremap <silent> <expr> <Plug>GitGutterNextHunk &diff ? ']c' : ":\execute v:count1 . 'GitGutterNextHunk'\"
nnoremap <SNR>57_: :=v:count ? v:count : ''
inoremap <expr> 	 pumvisible() ? "\" : "\	"
inoremap  u
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autoread
set backspace=indent,eol,start
set complete=.,w,b,u,t
set completefunc=youcompleteme#Complete
set completeopt=preview,menuone
set display=lastline
set fileencodings=ucs-bom,utf-8,default,latin1
set formatoptions=tcqj
set helplang=pt
set history=1000
set incsearch
set laststatus=2
set listchars=tab:>\ ,trail:-,extends:>,precedes:<,nbsp:+
set nrformats=bin,hex
set pyxversion=2
set ruler
set runtimepath=~/.vim,~/.vim/bundle/Vundle.vim,~/.vim/bundle/YouCompleteMe,~/.vim/bundle/ctrlp.vim,~/.vim/bundle/nerdtree,~/.vim/bundle/syntastic,~/.vim/bundle/vim-airline,~/.vim/bundle/vim-autoformat,~/.vim/bundle/vim-fugitive,~/.vim/bundle/vim-gitgutter,~/.vim/bundle/vim-markdown,~/.vim/bundle/vim-markdown-preview,~/.vim/bundle/vim-sensible,/usr/share/vim/vimfiles,/usr/share/vim/vim80,/usr/share/vim/vim80/pack/dist/opt/matchit,/usr/share/vim/vimfiles/after,~/.vim/bundle/vim-markdown/after,~/.vim/after,~/.vim/bundle/Vundle.vim/after,~/.vim/bundle/YouCompleteMe/after
set scrolloff=1
set sessionoptions=blank,buffers,curdir,folds,help,tabpages,winsize
set shortmess=filnxtToOc
set sidescrolloff=5
set smarttab
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc,.png,.jpg
set tabpagemax=50
set tags=./tags;,./TAGS,tags,TAGS
set ttimeout
set ttimeoutlen=100
set updatetime=2000
set viminfo=!,'100,<50,s10,h
set wildmenu
" vim: set ft=vim :
