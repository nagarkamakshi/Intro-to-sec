/* 
 * Attack 03 - Fill out this program to implement your attack for Problem 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
// magic number is $ 0x41407034 
 int magic=  0x41407034 ;
printf("%d\n",magic);
fflush(stdout);
sleep(10);
printf("cat /home/kamakshi/hw02/flag03.txt");

  
  return 0;
}
