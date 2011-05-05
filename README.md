README
======

provided functions
----------------
* fildes_fdopen
* fildes_close
* fildes_fileno
* fildes_dup
* fildes_dup2

usage
----------------
<?php
$stdout_fd_orig = fildes_fileno(STDOUT);
fclose(STDOUT);
$stdout = fopen("out.log", "a");
$fd_tmp = fildes_fileno($stdout);
$stdout_fd = fildes_dup2($fd_tmp, $stdout_fd_orig);
if($stdout_fd != $fd_tmp){
        fildes_close($fd_tmp);
}
echo "Hello world!"; // this goes to out.log

installation
----------------
phpize
./configure
make
make install

