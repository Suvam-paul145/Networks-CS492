#include <stdio.h>
#include <string.h>

#define FLAG 'F'  // Flag character
#define ESC 'E'   // Escape character

void sender(char *data) {
    printf("Stuffed Data: ");
    printf("%c", FLAG);  // Start Flag

    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == FLAG || data[i] == ESC) {
            printf("%c", ESC);  // Stuff ESC before FLAG or ESC
        }
        printf("%c", data[i]);
    }

    printf("%c\n", FLAG);  // End Flag
}

void receiver(char *stuffedData) {
    printf("Original Data: ");
    
    for (int i = 1; i < strlen(stuffedData) - 1; i++) {  // Ignore start & end FLAG
        if (stuffedData[i] == ESC) {
            i++;  // Skip ESC and take next character
        }
        printf("%c", stuffedData[i]);
    }
    
    printf("\n");
}

int main() {
    char data[100], stuffedData[100];

    printf("Enter the data string: ");
    scanf("%s", data);

    printf("\nSending Data...\n");
    sender(data);

    // Simulating stuffed data for receiver
    printf("\nReceiving Data...\n");
    printf("Enter stuffed data: ");
    scanf("%s", stuffedData);

    receiver(stuffedData);

    return 0;
}
