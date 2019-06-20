#include <stdio.h>
#include <unistd.h>
#include<string.h>

int main()
{
        char buffer[1000];
				int fd[2];
				int read_bytes = read(STDIN_FILENO, buffer, sizeof(buffer));
				if(strncmp(buffer, "What is your name?", read_bytes-1) == 0){
						printf("Bob\n");
					read(STDIN_FILENO, buffer, sizeof(buffer));
			if (strncmp(buffer, "What is the magic number?",read_bytes-1) == 0){
						printf("2\n");
				} else {
								printf("???\n");
						}
				}
        return 0;
}
