#include <stdio.h>
#include "bank_alg.h"

int isSafeState(ResourceManager *rm) {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safe_sequence[MAX_PROCESSES];
    int count = 0;

    for (int i = 0; i < rm->m; i++) {
        work[i] = rm->available[i];
    }

    while (count < rm->n) {
        int found = 0;
        for (int i = 0; i < rm->n; i++) {
            if (!finish[i]) {
                int can_finish = 1;
                for (int j = 0; j < rm->m; j++) {
                    if (rm->need[i][j] > work[j]) {
                        can_finish = 0;
                        break;
                    }
                }
                if (can_finish) {
                    for (int j = 0; j < rm->m; j++) {
                        work[j] += rm->allocation[i][j];
                    }
                    finish[i] = 1;
                    safe_sequence[count++] = i;
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            return 0;
        }
    }

    for (int i = 0; i < rm->n; i++) {
        rm->safe_sequence[i] = safe_sequence[i];
    }
    return 1;
}

void printSafeSequence(ResourceManager *rm) {
    printf("Safe Sequence: ");
    for (int i = 0; i < rm->n; i++) {
        printf("P%d ", rm->safe_sequence[i]);
        if (i < rm->n - 1) printf("-> ");
    }
    printf("\n");
}
