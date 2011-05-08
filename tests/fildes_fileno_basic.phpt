--TEST--
This will check that the we have the correct fds for STDIN, STDOUT, STDERR
--FILE--
<?php
echo fildes_fileno(STDIN)."\n";
echo fildes_fileno(STDOUT)."\n";
echo fildes_fileno(STDERR)."\n";
?>
--EXPECT--
0
1
2
