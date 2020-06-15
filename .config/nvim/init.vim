set runtimepath^=~/.vim runtimepath+=~/.vim/after
let &packpath = &runtimepath
source ~/.vimrc
tnoremap <esc> <C-\><C-n>
tnoremap <C-w> <C-\><C-n><C-w>
