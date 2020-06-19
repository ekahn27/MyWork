"Easy escape to normal mode
imap jj <esc>

function! Ap(isOn)
	if(a:isOn == 1)
		imap ( ()<esc>i
		imap [ []<esc>i
		imap { {<CR><BS>}<esc>ko
	elseif(a:isOn == 0)
		imap ( (
		imap [ [
		imap { {
	endif
endfunction
imap <C-k> <esc>:call Ap(1)<CR>i
imap <C-l> <esc>:call Ap(0)<CR>i

"better multiline comment
imap /* <esc>:set backspace=indent,start<CR>i/<space>*<esc>hxa<CR><CR><BS>*/<esc>:set backspace=indent,eol,start<CR>ki

"move over one space (move outside parens)
imap <C-j> <esc>la
syntax on	"enables syntax highlighting
"Shows current line cursor is on
:set cursorline
nnoremap j gj
nnoremap k gk
set wildmenu
set ignorecase
set smartcase

"makes cursor block when not in insert mode
"even solid, odd blink
"0-2 block, 3-4 underscore, 5-6 vertical bar
let &t_ti.="\e[1 q"
let &t_SI.="\e[5 q" "SI= Insert mode
let &t_EI.="\e[2 q" "EI= Normal mode (else)
let &t_te.="\e[1 q"
"SR is replace mode

set number		"line numbers
set showmode        "show mode currently editing in
set title       "show filename in window title bar
"allow backspacing over everything in insert mode
set backspace=indent,eol,start

filetype indent on
"set autoindent      "indent if already indented
"set smartindent     "smart indenting, ex: for loop
set tabstop=4       "num visual spaces per tab
set smarttab
set softtabstop=4   "num spaces in tab when editing
set shiftwidth=4    "make tab 4 spaces
set noexpandtab		"don't use spaces for tabs
"set expandtab       "use spaces when tab hit
"configure tabs for various files
au BufReadPost,BufNewFile *.py setlocal expandtab
au BufReadPost,BufNewFile *.c,*.h setlocal cindent

set ruler       "always show cursor
set scrolloff=5     "start scrolling before hitting top/bottom
set showmatch       "show matching parens
set incsearch       "search chars as entered
set hlsearch        "highlight matches

set noswapfile
set colorcolumn=80  "highlight column 80 for long lines

colorscheme gruvbox
"set background=dark
"set term=xterm-256color
set t_ut=

"stuff I"m trying out
set completeopt=longest,menuone "autocomplete
