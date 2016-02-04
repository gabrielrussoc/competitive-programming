set expandtab
set shiftwidth=4
set softtabstop=4
filetype plugin indent on
syntax on
set number
set relativenumber
autocmd BufNewFile *.cpp :0r ~/.vim/cpp
autocmd BufNewFile *.cpp +18 
