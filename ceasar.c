#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void caesarCipherEncrypt(char message[], int shift) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

int main() {
    char message[MAX_LENGTH];
    int shift;

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    // Remove newline character if present
    if (strlen(message) > 0 && message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Ensure shift value is within range (0-25)
    shift %= 26;

    caesarCipherEncrypt(message, shift);

    printf("Encrypted message: %s\n", message);

    return 0;
}
