#include <stdio.h>

int main() {
    int bits[8], i, count = 0;

    printf("Enter 8-bit data (including parity bit at the end):\n");
    for(i = 0; i < 8; i++) {
        scanf("%d", &bits[i]);
    }

    // Count number of 1s in the first 7 bits (excluding parity bit)
    for(i = 0; i < 7; i++) {
        if(bits[i] == 1)
            count++;
    }

    // Even parity: total 1s (including parity bit) must be even
    if((count % 2 == 0 && bits[7] == 0) || (count % 2 == 1 && bits[7] == 1)) {
        printf("No error detected.\n");
    } else {
        printf("Error detected in transmission!\n");
    }

    return 0;
}
