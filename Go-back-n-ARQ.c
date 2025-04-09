#include <stdio.h>

int main() {
    int totalFrames, windowSize, i, ack;

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    int sent = 0;
    while (sent < totalFrames) {
        printf("\nSending window of frames: ");
        for (i = 0; i < windowSize && (sent + i) < totalFrames; i++) {
            printf("%d ", sent + i);
        }

        printf("\nEnter index of lost frame in this window (-1 if none): ");
        scanf("%d", &ack);

        if (ack == -1) {
            printf("All ACKs received.\n");
            sent += windowSize;
        } else {
            printf("ACK not received for frame %d. Go-Back-N triggered.\n", ack);
            sent = ack; // go back to the lost frame
        }
    }

    printf("\nAll frames sent successfully using Go-Back-N ARQ.\n");
    return 0;
}