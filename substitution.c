#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Error if number of arguments is not 2
    if (argc != 2)
    {
        printf("Please run program ./substitution <key>\n");
        return 1;
    }
    
    // Error for entering too many arguments
    if (argc > 2)
    {
        printf("Please enter only the key.\n");
        return 1;
    }
    
    // Store cli argument key as char array pointer (string), find its length
    char *key = argv[1];
    int key_length = strlen(key);
    
    // Check key size
    if (key_length != 26)
    {
        printf("Key must contain 26 non-repeating characters.\n");
        return 1;
    }
    
    // Check for alphabetic input that is non-repeating
    for (int i = 0; i < key_length; i++)
    {
        if (!isalnum(key[i]))
        {
            printf("Enter only alphabetic characters.\n");
            return 1;
        }
        for (int j = i + 1; j < key_length; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Cannot repeat a letter.\n");
                return 1;
            }
        }
    }
    
    // Asks user for plaintext, get length
    char plaintext[50];
    char ciphertext[50];
    printf("plaintext:");
    scanf("%[^\n]", plaintext);
    int plaintext_length = strlen(plaintext);
    
    // Encrypts plaintext
    for (int i = 0; i < plaintext_length; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    
    // Prints ciphertext
    printf("ciphertext:%s\n", ciphertext);
    
    return 0;
}