#include <stdio.h>
#include "resource_manager.h"
#include "user_input.h"

void getInputForTotalResources(ResourceManager *rm) {
    printf("Enter the total number of resources (number of types of resources): ");
    scanf("%d", &rm->m);

    printf("Enter the total number of processes: ");
    scanf("%d", &rm->n);

    printf("Enter available resources for each type:\n");
    for (int i = 0; i < rm->m; i++) {
        printf("Resource type %d: ", i + 1);
        scanf("%d", &rm->available[i]);
    }

    initialize(rm, rm->n, rm->m);
}

void getAllocationInput(ResourceManager *rm) {
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < rm->n; i++) {
        for (int j = 0; j < rm->m; j++) {
            scanf("%d", &rm->allocation[i][j]);
        }
    }
}

void getMaxInput(ResourceManager *rm) {
    printf("Enter maximum matrix:\n");
    for (int i = 0; i < rm->n; i++) {
        for (int j = 0; j < rm->m; j++) {
            scanf("%d", &rm->max[i][j]);
        }
    }
}

void updateResources(ResourceManager *rm) {
    int choice;
    printf("Would you like to update resources? (1: Yes, 0: No): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter new available resources:\n");
        for (int i = 0; i < rm->m; i++) {
            printf("Resource type %d: ", i + 1);
            scanf("%d", &rm->available[i]);
        }
    }
}

void displayMenu() {
    printf("\n--- Resource Allocation System ---\n");
    printf("1. Request Resources\n");
    printf("2. Release Resources\n");
    printf("3. Display Safe Sequence\n");
    printf("4. Update Resources\n");
    printf("5. Exit\n");
}