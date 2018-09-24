/*
* Palash K. Nath
*
* Description: The Vigenère cipher is a method of encrypting alphabetic text by using a 
* series of interwoven Caesar ciphers, based on the letters of a keyword. It is a form of polyalphabetic substitution
* 
*
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    // Checking for # of arguments
    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }else{
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be alphabetic chars only.");

                return 1;
            }
        }
    }
    char msg[100];
    string key = argv[1];//Storing the key

    //Getting the string
    printf("Enter Message to Encrypt : ");
    scanf("%[^\n]s",msg);

    int msgLen = strlen(msg), keyLen = strlen(key), i, j;

    char newKey[msgLen], cipheredMsg[msgLen], dcipheredMsg[msgLen], ch;

    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    //encryption
    for(i = 0; i < msgLen; ++i){
        //printf("capital");
        int letterKey = tolower(key[j % keyLen]) - 'a';

        if (isupper(msg[i]))
        {
            ch = ((msg[i]-'A' + letterKey) % 26) + 'A';
            j++;
        }else if (islower(msg[i]))
        {
            ch = ((msg[i]- 'a' + letterKey) % 26) + 'a';
            j++;
        }else{
            ch = msg[i];
        }


        cipheredMsg[i] = ch;
    }
    cipheredMsg[i] = '\0';
    /* 
   //decryption
    for(i = 0; i < msgLen; ++i){
        //int letterKey = tolower(key[j % keyLen]) - 'a';
        if (isupper(cipheredMsg[i]))
        {
            ch = (((cipheredMsg[i] - newKey[i])) % 26) + 'A';
            j++;
        }else if (islower( cipheredMsg[i]))
        {
            ch = (((cipheredMsg[i]- newKey[i])) % 26) + 'a';
            j++;
        }
        dcipheredMsg[i] = ch;
    }
    dcipheredMsg[i] = '\0';
    */
    
    /* Uncomment to see the outputs seperately */
    //printf("Original Message: %s", msg);
    //printf("\nKey: %s", key);
    //printf("\nNew Generated Key: %s", newKey);
    printf("\nciphertext: %s\n", cipheredMsg);
    //printf("\ndciphered Message: %s\n", dcipheredMsg);

    return 0;
}

OUTPUT:
#1
./vigenere baz //executing the file with the key (baz) * key is not limited to "baz"
Enter Message to Encrypt : barfoo

Original Message: barfoo
Key: baz
New Generated Key: bazbaz
ciphertext: caqgon

#2
./vigenere BaZ
Enter Message to Encrypt : BaRFoo

Original Message: BaRFoo
Key: BaZ
New Generated Key: BaZBaZ
ciphertext: CaQGon
