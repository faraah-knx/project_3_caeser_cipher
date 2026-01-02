//project 3 - caesar cipher
#include <stdio.h>

int main() {
    char msg[101];
    int choice, shift, i;

    printf("1. Encode\n");
    printf("2. Decode\n");
    printf("Choose 1 or 2: ");
    scanf("%d", &choice);

    printf("Enter message: ");
    scanf(" %[^\n]", msg);
//the shift must be positive and between 1 and 25
  do {
    printf("Enter shift (1 - 25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Error\n");
    }

} while (shift < 1 || shift > 25);
    
    shift = shift % 26;   

    for(i = 0; msg[i]; i++) {

        //small letter 
        if(msg[i] >= 'a' && msg[i] <= 'z') {

            if(choice == 1)
                msg[i] = ((msg[i] - 'a' + shift) % 26) + 'a';
            else
                msg[i] = ((msg[i] - 'a' - shift + 26) % 26) + 'a';
        }

        // capital letters 
        else if(msg[i] >= 'A' && msg[i] <= 'Z') {

            if(choice == 1)
                msg[i] = ((msg[i] - 'A' + shift) % 26) + 'A';
            else
                msg[i] = ((msg[i] - 'A' - shift + 26) % 26) + 'A';
        }
    }

    if(choice == 1)
        printf("Encoded message: %s\n", msg);
    else if(choice == 2)
        printf("Decoded message: %s\n", msg);
    else
        printf("Error \n");

    return 0;
}
