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
    $stdout = fopen("out.log", "a");
    if(fildes_dup2(fildes_fileno($stdout), fildes_fileno(STDOUT))<0){
	fwrite(STDERR, "dup2 failed");
	exit;
    }
    echo "Hello world!"; // this goes to out.log

installation
----------------
    phpize;
    ./configure;
    make;
    make install;

