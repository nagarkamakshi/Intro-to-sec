#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
  FILE *fPointer1=fopen("/home/kamakshi/hw04/salted.txt", "r");
  FILE *fPointer2= fopen("words.txt", "r");
  FILE *fPointer3 = fopen("flag04.txt", "a");

  unsigned char hashedtxt[SHA_DIGEST_LENGTH];
  unsigned char hashedwords[SHA_DIGEST_LENGTH];
  char userName[50];
  char salt[50];

  int n;
  unsigned char salt_backHex[20];
  unsigned char salt_byte[16];
  char *salt_ptr = &salt_byte[0];
  SHA_CTX ctx;
	SHA1_Init(&ctx);

  while(!feof(fPointer1)){
     fscanf(fPointer1, "%s %s %s", userName, salt, hashedtxt);
     printf("username %s \t salt %s \t salted_password %s \n", userName, salt, hashedtxt);

    for(int k = 0; k < 8; k++) {
         sscanf(salt+2*k, "%2hhx", &salt_byte[k]);
    }
    while(!feof(fPointer2)){
      char *words = malloc(sizeof(char)*1028);
                fscanf(fPointer2, "%s", words);

				// Object to hold the current state of the hash
				// Hash each piece of data as it comes in:
				SHA1_Update(&ctx, words, strlen(words));
				SHA1_Update(&ctx, salt_byte, 8);
				// When you're done with the data, finalize it:
				SHA1_Final(hashedwords, &ctx);

        char output[60];
        char *ptr = &output[0];

                //Convert SHA1 byte into hex
                for (int i = 0; i < 20; i++){
                        ptr += sprintf (ptr, "%02X", hashedwords[i]);
                }
                //Convert into lowercase
                for(int i = 0; i< 40; i++){
                        output[i] = tolower(output[i]);
                }

                if(strncmp(hashedtxt, output,19) == 0){
                  //printf("................Password matched.............");
                    fprintf(fPointer3,"%s\t %s\n", userName, words);
                }
              }
      fclose(fPointer2);
  }
  fclose(fPointer1);

  return 0;
}
