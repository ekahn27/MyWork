"For Cygwin
"Easy escape to normal mode
imap jj <esc>

imap /* /*<ENTER><ENTER>*/<esc>ki
imap ( ()<esc>i
imap [ []<esc>i
imap { {}<esc>i
"move over one space (move outside parens)
imap <C-l> <esc>la
"colorscheme koehler
syntax on	"enables syntax highlighting
"Shows current line cursor is on
:set cursorline
nnoremap j gj
nnoremap k gk
set wildmenu

"makes cursor block when not in insert mode
let &t_ti.="\e[1 q"
let &t_SI.="\e[5 q"
let &t_EI.="\e[1 q"
let &t_te.="\e[0 q"

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
set noexpandtab
"set expandtab       "use spaces when tab hit
"configure tabs for various files
au BufRead,BufNewFile *.py set expandtab
au BufRead,BufNewFile *.c, *.h set cindent

set ruler       "always show cursor
set scrolloff=5     "start scrolling before hitting top/bottom
set showmatch       "show matching parens
set incsearch       "search chars as entered
set hlsearch        "highlight matches

set noswapfile
set colorcolumn=80  "highlight column 80 for long lines

colorscheme gruvbox
set background=dark
set term=screen-256color
set t_ut=
