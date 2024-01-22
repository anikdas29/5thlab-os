//file replacement optimal

#include <stdio.h>

int main() {
    int i, j, n, frames, fault = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int page[n];
    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    int repla[n][frames];

    for (j = 0; j < frames; j++) {
        repla[0][j] = -1;
    }


    int future[n];  // Array to store future references

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < frames; j++) {
            if (page[i] == repla[i][j]) {
                found = 1;
                break;
            }
        }

        if (!found) { // Page fault case
            fault++;

            // Find the victim frame using future references
            int victim = 0;
            int farthest_index = -1;
            for (j = 0; j < frames; j++) {
                int next_ref = n;  // Initialize to the last position by default
                for (int k = i + 1; k < n; k++) {
                    if (repla[i][j] == page[k]) {
                        next_ref = k;
                        break;
                    }
                }
                if (next_ref > farthest_index) {
                    farthest_index = next_ref;
                    victim = j;
                }
            }

            repla[i][victim] = page[i]; // Replace page in victim frame

            // Update future references for remaining pages
            for (int k = i + 1; k < n; k++) {
                for (j = 0; j < frames; j++) {
                    if (repla[i][j] == page[k]) {
                        future[k] = farthest_index;  // Update with the farthest future reference index
                        break;
                    }
                }
            }
        }

        // Shift remaining pages by one frame for the next iteration
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
