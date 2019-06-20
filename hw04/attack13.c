
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
  unsigned char salted_password[SHA_DIGEST_LENGTH];
  unsigned char calculated_hashed_password[50];
  unsigned char salt[50];
  char userName[50];
  unsigned char salt_byte[16];

  char *salt_ptr = &salt_byte[0];
  int n;
  char *dict_copy[50];
  unsigned char salt_backHex[20];

  //File related variables
  FILE *fPointer1;
  fPointer1 = fopen("salted.txt", "r");

  FILE *fPointer2;
  fPointer2 = fopen("words.txt", "r");

  FILE *fPointer3;

  while(!feof(fPointer1)){
     fscanf(fPointer1, "%s %s %s", userName, salt, salted_password);

     printf("username %s \t salt %s \t salted_password %s \n", userName, salt, salted_password);
     //convert salt hex into salt bytes
     for(int k = 0; k < 8; k++) {
        sscanf(salt+2*k, "%2X", &n);
        salt_byte[k] = (unsigned char)n;
    }
    //convert bytes back to hex just for reference
    /*char *ptr_backHex = &salt_backHex[0];
    for (int k = 0; k < 8; k++){
       ptr_backHex += sprintf (ptr_backHex, "%02X", salt_byte[k]);
    }
    printf("original salt %s  \t converted salt %s\n", salt, salt_backHex); */
    fPointer2 = fopen("words.txt", "r");
      while(!feof(fPointer2)){
          char *dictionary_password = malloc(sizeof(char)*1024);
                 fscanf(fPointer2, "%s", dictionary_password);
                 //strcpy(dict_copy, dictionary_password);
                  memcpy(salt_byte,dictionary_password, sizeof(salt_byte));
                 //concatenate dictionary password with salt bytes
                 //strcat(dictionary_password, salt_byte);
                 //calculate SHA1
                 SHA1(dictionary_password, sizeof(dictionary_password),calculated_hashed_password);

                char calculated_sha_hex[60];
                char *sha_ptr = &calculated_sha_hex[0];

                 //Convert SHA1 bytes into hex format
                 for (int i = 0; i < 20; i++){
                        sha_ptr += sprintf (sha_ptr, "%02X", calculated_hashed_password[i]);
                }
                //Convert into lowercase
                for(int i = 0; i< 40; i++){
                        calculated_sha_hex[i] = tolower(calculated_sha_hex[i]);
                }
                 //print_hex(calculated_sha_hex,10);
                 //printf("\n");

                printf("salted password is: %s \n calculated sha hex is %s \n",salted_password, calculated_sha_hex);
                //compare if any sha hex matches with the salted password hex from salted.txt
                if(strncmp(salted_password, calculated_sha_hex,10) == 0){
                        printf("==============================Password matched=======================\n");
                        printf("Name: %s\n password: %s\n", userName, salted_password );
                        break;
                }
                free(dictionary_password);
              }
      fclose(fPointer2);

  }
 fclose(fPointer1);
  return 0;
}
