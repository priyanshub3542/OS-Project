#include <stdio.h>
#include "resource_manager.h"
#include "bank_alg.h"
#include "user_input.h"

int main() {
    ResourceManager rm;

    getInputForTotalResources(&rm);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            int process_id;
            int request[MAX_RESOURCES];
            printf("Enter process ID (0 to n-1): ");
            scanf("%d", &process_id);

            printf("Enter resource request for the process:\n");
            for (int i = 0; i < rm.m; i++) {
                printf("Resource type %d: ", i + 1);
                scanf("%d", &request[i]);
            }

            requestResources(&rm, process_id, request);
        } else if (choice == 2) {
            int process_id;
            printf("Enter process ID (0 to n-1): ");
            scanf("%d", &process_id);
            releaseResources(&rm, process_id);
        } else if (choice == 3) {
            if (isSafeState(&rm)) {
                printSafeSequence(&rm);
            } else {
                printf("The system is not in a safe state.\n");
            }
        } else if (choice == 4) {
            updateResources(&rm);
        }
    } while (choice != 5);

    return 0;
}
