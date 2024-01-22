//Program for page replacement string

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
    for (j = 0; j < frames; j++) {
        repla[0][j] = -1;
    }

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < frames; j++) {
            if (page[i] == repla[i][j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            fault++;
            repla[i][position] = page[i];
            position = (position + 1) % frames;

        }
        for (j = 0; j < frames; j++) {
            repla[i + 1][j] = repla[i][j];
        }
    }

    printf("\nPage faults: %d\n\n", fault);

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
