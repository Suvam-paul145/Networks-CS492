#include <stdio.h>
#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

int main() {
    int i = 0;
    int sent = 0;

    printf("Sliding Window Protocol Simulation (Go-Back-N)\n");
    printf("Total Frames to Send: %d\n", TOTAL_FRAMES);
    printf("Window Size: %d\n", WINDOW_SIZE);

    while (sent < TOTAL_FRAMES) {
        printf("\nSender is sending frames: ");
        for (i = sent; i < sent + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            printf("%d ", i);
        }

        printf("\nReceiver acknowledges frames: ");
        for (i = sent; i < sent + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            printf("%d ", i);
        }

        sent += WINDOW_SIZE;  // All frames in window acknowledged
    }

    printf("\n\nAll frames sent and acknowledged successfully.\n");
    return 0;
}
