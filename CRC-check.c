#include <stdio.h>
#include <string.h>

void xor(char *crc, char *key) {
    for (int i = 1; i < strlen(key); i++) {
        crc[i] = (crc[i] == key[i]) ? '0' : '1';
    }
}

void crcCheck(char *data, char *key) {
    int dataLen = strlen(data);
    int keyLen = strlen(key);
    char temp[100];

    strcpy(temp, data);
    for (int i = 0; i < keyLen - 1; i++) {
        temp[dataLen + i] = '0';
    }
    temp[dataLen + keyLen - 1] = '\0';

    char rem[100];
    strncpy(rem, temp, keyLen);
    rem[keyLen] = '\0';

    for (int i = 0; i < dataLen; i++) {
        if (rem[0] == '1') {
            xor(rem, key);
        } else {
            xor(rem, "0000");  // assuming key is 4 bits
        }

        memmove(rem, rem + 1, keyLen - 1);
        rem[keyLen - 1] = temp[i + keyLen];
    }

    printf("Remainder (CRC): %s\n", rem);
    int error = 0;
    for (int i = 0; i < keyLen - 1; i++) {
        if (rem[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error)
        printf("❌ Error detected!\n");
    else
        printf("✅ No error detected.\n");
}

int main() {
    char data[100], key[10];
    printf("Enter binary data: ");
    scanf("%s", data);
    printf("Enter key (divisor): ");
    scanf("%s", key);

    crcCheck(data, key);
    return 0;
}
