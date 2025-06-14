#include <stdio.h>

int calculateChecksum(int data[], int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    // Wrap around if there's a carry
    while (sum >> 8) {
        sum = (sum & 0xFF) + (sum >> 8);
    }

    // Return 1's complement
    return ~sum & 0xFF;
}

int main() {
    int data[10], size, i;

    printf("Enter number of data bytes: ");
    scanf("%d", &size);

    printf("Enter the data bytes (in decimal, max 255 each):\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    int checksum = calculateChecksum(data, size);
    printf("Calculated Checksum: %d\n", checksum);

    // Now simulate received data check
    printf("\nEnter received data bytes (including checksum):\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }
    scanf("%d", &data[size]);  // input checksum as last byte

    int total = calculateChecksum(data, size + 1);

    if (total == 0)
        printf("No error detected in received data.\n");
    else
        printf("Error detected in received data!\n");

    return 0;
}
