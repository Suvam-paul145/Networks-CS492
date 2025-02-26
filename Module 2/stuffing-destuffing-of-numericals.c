#include <stdio.h>
#include <stdlib.h>

// Function to perform bit stuffing
int* bitStuffing(int* data, int size, int* stuffedSize) {
    int* stuffedData = (int*)malloc(size * 2 * sizeof(int));
    int count = 0, j = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        stuffedData[j++] = data[i];
        if (count == 5) {
            stuffedData[j++] = 0;
            count = 0;
        }
    }
    *stuffedSize = j;
    return stuffedData;
}

// Function to perform bit destuffing
int* bitDestuffing(int* data, int size, int* destuffedSize) {
    int* destuffedData = (int*)malloc(size * sizeof(int));
    int count = 0, j = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        destuffedData[j++] = data[i];
        if (count == 5) {
            if (i + 1 < size && data[i + 1] == 0) {
                i++;
                count = 0;
            }
        }
    }
    *destuffedSize = j;
    return destuffedData;
}

int main() {
    int data[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0};
    int size = sizeof(data) / sizeof(data[0]);
    int stuffedSize, destuffedSize;

    printf("Original Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    int* stuffedData = bitStuffing(data, size, &stuffedSize);
    printf("Stuffed Data: ");
    for (int i = 0; i < stuffedSize; i++) {
        printf("%d", stuffedData[i]);
    }
    printf("\n");

    int* destuffedData = bitDestuffing(stuffedData, stuffedSize, &destuffedSize);
    printf("Destuffed Data: ");
    for (int i = 0; i < destuffedSize; i++) {
        printf("%d", destuffedData[i]);
    }
    printf("\n");

    free(stuffedData);
    free(destuffedData);

    return 0;
}
