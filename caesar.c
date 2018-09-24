/**
 * Palash K Nath
 * 
 * Description: The Caesar cipher is also known as Caesar's cipher, the shift cipher, Caesar's code or Caesar shift, named after
 * Julius Caesar, which is one of the simplest and famous encryption techniques. In caesar cipher a plain text is replaced by a 
 * letter to some fixed number of position which is known as the key down the alphabet.
 * Eg: If _key = 3_ (for Right shift)
 *   > and message = 'a'; then the cipher will be 'd';
 *   > and message = 'D'; then the cipher will be 'G';   
 * Eg: If _key = 3_ (for Left shift) 
 *   > and message = 'g'; then the cipher will be 'd';
 *   > and message = 'E'; then the cipher will be 'B';
 * 
 * */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    char message[100], ch;
    // Check for number of arguments
    if (argc != 2)
    {
        printf("Invalid\n");
        return 1;
    }

    int i, key= atoi(argv[1]);
    
    // check if the integer is non-negative
    if (key < 0)
    {
        printf("Invalid\n");
        return 1;
    }else{
        // Take and store message
        printf("Enter a message to encrypt: ");
        scanf("%[^\n]s",message);
    
        for(i = 0; message[i]!='\0' ; i++){
            
            ch = message[i];
            if islower(ch ){
            
              ch = ((ch + key - 97)%26)+97;
              
            }else if isupper(ch ){
                
                ch = ch + key;
                ch = ((ch  - 65)%26)+65;
                
            }else{
                    ch = message[i];
                }
                
            message[i] = ch;
            
        }

    }
    
    printf("Encrypted message: %s\n", message);

}

OUTPUT:

#1
./caesar 12
Enter a message to encrypt: World, say hello!
ciphertext: Iadxp, emk tqxxa!

#2
./caesar 65
Enter a message to encrypt: barfoo
ciphertext: onesbb

#3
./caesar 4
Enter a message to encrypt: BaRFoo
ciphertext: FeVJss
