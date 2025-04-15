#include <stdio.h>

int main()
{
    int frames, i, data, ack;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
    {
        printf("\nEnter data for frame %d: ", i);
        scanf("%d", &data);

        do 
        {
            printf("Sending frame %d (Data: %d)\n", i, data);
            printf("ACK received? (1:Yes/0:No): ");
            scanf("%d", &ack);

            if (ack)
            {
                printf("Frame %d transmitted successfully\n", i);
                break;
            }
            printf("Timeout! Resending frame %d\n", i);
        } while (!ack);
    }

    printf("\nAll frames sent successfully!\n");
    return 0;
}