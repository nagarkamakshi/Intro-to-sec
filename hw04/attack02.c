#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

void print_hex(unsigned char *buf, int len)
{
  
  for(int i=0;i<len;i++){
    printf("%02x",buf[i]);
  }
}



int main(int argc, char* argv[])
{

  /* Your code goes here */
  //File related variables
  FILE *fPointer1;
  fPointer1 = fopen("/home/kamakshi/hw04/hashed.txt", "r");

  FILE *fPointer2;
  fPointer2 = fopen("words.txt", "r");

  FILE *fPointer3;
  //fPointer3 = fopen("cracked.txt","w");
  unsigned char hashedtxt[SHA_DIGEST_LENGTH];
  unsigned char hashedwords[SHA_DIGEST_LENGTH];
  char userName[50];
  
  int flag = 1;
  //char *fp1 = malloc(sizeof(char)*2024);


  int i;

  while(!feof(fPointer1)){
     fscanf(fPointer1, "%s %s", userName, hashedtxt);
     char *words = malloc(sizeof(char)*1024);
     fPointer2 = fopen("words.txt", "r");
     //fPointer3 = fopen("cracked.txt", "w");
     //if(ret1 == 2){
         while(!feof(fPointer2)){
                 fscanf(fPointer2, "%s", words);
		 SHA1(words, sizeof(words), hashedwords);
                 //print_hex(hashedwords04, sizeof(hashedwords04));
                 //printf("\n");
                 //printf("word read is %s\n", words04);
                 //if(words04[0] == 'p')
                        //printf("%s\n", words04);
                 //if(strcmp("password", words04) == 0)
                         //printf("Password matched\n");


                char output[60];
                char *ptr = &output[0];
                 //Convert SHA1 byte into hex
                 for (i = 0; i < 20; i++){
                        ptr += sprintf (ptr, "%02X", hashedwords[i]);
                }
                //Convert into lowercase 
                for(i = 0; i< 40; i++){
                        output[i] = tolower(output[i]);
                }

                if(strncmp(hashedtxt, output,19) == 0){
                        fPointer3 = fopen("cracked.txt", "a");
                        fprintf(fPointer3,"%s\t %s\n", userName, words);
                       printf("%s\t %s\n", userName, words);
                        fclose(fPointer3);
                        
                }

              }
      fclose(fPointer2);
//      fclose(fPointer3);

  }
  return 0;
}
