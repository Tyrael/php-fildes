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
    $tmp_fd = fildes_fileno($stdout);
    if($tmp_fd, fildes_fileno(STDOUT))<0){
        fwrite(STDERR, "dup2 failed");
        exit;
    }
    fildes_close($tmp_fd);
    echo "Hello world!"; // this goes to out.log

installation
----------------
    phpize;
    ./configure;
    make;
    make install;

