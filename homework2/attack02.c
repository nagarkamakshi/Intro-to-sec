/* 
 * Attack 02 - Fill out this program to implement your attack for Problem 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
// magic number is $0x208afa8c
 int magic = 0x208afa8c;
printf("%d\n",magic);
fflush(stdout);
sleep(10);
printf("cat /home/kamakshi/hw02/flag02.txt");
  return 0;
}
