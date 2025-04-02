#include <stdio.h>
#include <stdlib.h>

// Function to perform bit stuffing
void bitStuffing(int data[], int size, int stuffedData[], int *stuffedSize) {
    int count = 0;
    *stuffedSize = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        stuffedData[(*stuffedSize)++] = data[i];
        if (count == 5) {
            stuffedData[(*stuffedSize)++] = 0;
            count = 0;
        }
    }
}

// Function to perform bit destuffing
void bitDestuffing(int data[], int size, int destuffedData[], int *destuffedSize) {
    int count = 0;
    *destuffedSize = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        destuffedData[(*destuffedSize)++] = data[i];
        if (count == 5) {
            if (i + 1 < size && data[i + 1] == 0) {
                i++;
                count = 0;
            }
        }
    }
}

int main() {
    int data[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0};
    int size = sizeof(data) / sizeof(data[0]);
    int stuffedData[100], stuffedSize;
    int destuffedData[100], destuffedSize;

    printf("Original Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    bitStuffing(data, size, stuffedData, &stuffedSize);
    printf("Stuffed Data: ");
    for (int i = 0; i < stuffedSize; i++) {
        printf("%d", stuffedData[i]);
    }
    printf("\n");

    bitDestuffing(stuffedData, stuffedSize, destuffedData, &destuffedSize);
    printf("Destuffed Data: ");
    for (int i = 0; i < destuffedSize; i++) {
        printf("%d", destuffedData[i]);
    }
    printf("\n");

    return 0;
}
