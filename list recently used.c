//Lru
#include <stdio.h>

int main() {
    int i, j, n, frames, fault = 0, position = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int page[n];
    printf("Enter the page replacement string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    int repla[n][frames];
    for (i = 0; i < n; i++) {
        for (j = 0; j < frames; j++) {
            repla[i][j] = -1;
        }
    }

    // Track usage timestamps for each frame
    int timestamp[frames];
    for (i = 0; i < frames; i++) {
        timestamp[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < frames; j++) {
            if (page[i] == repla[i][j]) {
                found = 1;
                timestamp[j] = i + 1; // Update timestamp on hit
                break;
            }
        }

        if (!found) { // Page fault case
            fault++;

            // Find least recently used frame (minimum timestamp)
            int lru = 0;
            for (j = 1; j < frames; j++) {
                if (timestamp[j] < timestamp[lru]) {
                    lru = j;
                }
            }

            repla[i][lru] = page[i]; // Replace page in LRU frame
            timestamp[lru] = i + 1; // Update timestamp
        }

        // Shift remaining pages by one frame for next iteration
        for (j = 0; j < frames; j++) {
            repla[i + 1][j] = repla[i][j];
        }
    }

    printf("Page faults: %d\n\n", fault);

    printf("\n   Page Replacement Table:\n");
    int breaker = 5;
    for(int k=0; k<n; k=k+breaker){
        for (i = 0; i < frames; i++) {
            for (j = k; j < k+breaker; j++) {
                if(repla[j][i] == -1) printf("   |   |  \t");
                else printf("   | %d |  \t", repla[j][i]);
                if(j == n) break;
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
