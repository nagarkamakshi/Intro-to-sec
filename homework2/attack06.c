#include <stdio.h>
#include <unistd.h>

void spawn_shell() {

  /* Your job is to fill in this function with code that calls 
   * execve() to execute a shell.
   * For more information on execve, run 'man execve' or see the 
   * manual page online here http://linux.die.net/man/2/execve
   */

}


/* Warning: Do not modify the main() function.  
 * All your code should go into spawn_shell() above.
 */
int main(int argc, char* argv[])
{
  spawn_shell();
  // If your function works, we should never run this code.
  // If we're still here, return an error.
  printf("Error: spawn_shell() failed.\n");
  return 1;
}
