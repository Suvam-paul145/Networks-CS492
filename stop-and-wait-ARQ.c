#include <stdio.h>

int main() {
    int frames, i;
    printf("Enter number of frames to send: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        printf("Sending frame %d...\n", i);
        printf("Waiting for ACK...\n");

        int ack;
        printf("Enter 1 if ACK received, 0 if lost: ");
        scanf("%d", &ack);

        if (ack == 1) {
            printf("ACK received for frame %d.\n\n", i);
        } else {
            printf("ACK lost. Resending frame %d...\n", i);
            i--; // resend same frame
        }
    }

    printf("All frames sent successfully using Stop-and-Wait ARQ.\n");
    return 0;
}