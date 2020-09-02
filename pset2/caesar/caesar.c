#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // loop to check if command line argument is an integer
        for (int i = 0; i < strlen(argv[1]); i++) {
            if (!isdigit(argv[1][i])) {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int key = atoi(argv[1]); // convert key to integer
        string plaintext = get_string("plaintext: "); // prompt user for plaintext

        // apply caesar's cipher
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++) {
            if (isupper(plaintext[i])) {
                int position = (int) plaintext[i] - 64; // get alphabet position of letter
                int newAscii = ((position + key) % 26) + 64; // add cipher and standardize ascii
                printf("%c", newAscii);
            }
            else if (islower(plaintext[i])) {
                int position = (int) plaintext[i] - 96; // get alphabet position of letter
                int newAscii = ((position + key) % 26) + 96; // add cipher and standardize ascii
                printf("%c", newAscii);
            }
            else {
                printf("%c", plaintext[i]);
            }
        }

        printf("\n");
        return 0;
    }
    else {
        printf("argument count wrong\n");
        return 1;
    }
}