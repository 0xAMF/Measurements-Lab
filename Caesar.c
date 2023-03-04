#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char* s, int key);
void decrypt(char* txt, int key);

int main(void)
{
    FILE *fPointer;
    fPointer = fopen("TextIn.txt", "r");
    char txt[1000];
    
    while(!feof(fPointer)){
        fgets(txt, 1000, fPointer);
    }

    int key, n;
    printf("Enter the key: "); //choosing the key
    scanf("%d", &key);
    printf("1 to Encrypt or 0 decrypt : ");  //Encryption or Decryption mode
    scanf("%d",&n);

    /*Writing to the file*/
    fPointer = fopen("TextOut.txt", "w");
 
    if (n == 1)  //Encryption case.
    {
        encrypt(txt, key);
        fprintf(fPointer, txt);
        printf("\nEncrypted text: \n\n");
        puts(txt);
        printf("\n");
        
    }

    else if(n == 0)  //Decryption case.
    {
        decrypt(txt, key);
        fprintf(fPointer, txt);
        printf("\nDecrypted text: \n");
        puts(txt);
    }
    else{printf("Invalid.");}

    fclose(fPointer);

}

/*Encryption function*/
void encrypt(char *txt, int key){
    int i = 0;
    while (txt[i] != '\0')
    {
         if(isalnum(txt[i])){

            if (isupper(txt[i]))
            {
                txt[i] = (txt[i] - 'A' + key) % 26 + 'A';
            }
            if (islower(txt[i]))
            {
                txt[i] = (txt[i] - 'a' + key) % 26 + 'a';
            }
         }
        else
        {
            txt[i] = txt[i];
        }
        ++i;
    }
}

/*Decryption function*/
void decrypt(char* txt, int key){
    int i = 0;
    while (txt[i] != '\0')
    {
        txt[i] = txt[i] - key;
        ++i;
    }
    
}
