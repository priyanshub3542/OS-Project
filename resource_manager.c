#include <stdio.h>
#include "bank_alg.h"
#include "resource_manager.h"
void initialize(ResourceManager *rm, int processes, int resources) {
    rm->n = processes;
    rm->m = resources;

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < rm->n; i++) {
        for (int j = 0; j < rm->m; j++) {
            scanf("%d", &rm->allocation[i][j]);
        }
    }

    printf("Enter maximum matrix:\n");
    for (int i = 0; i < rm->n; i++) {
        for (int j = 0; j < rm->m; j++) {
            scanf("%d", &rm->max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (int i = 0; i < rm->m; i++) {
        scanf("%d", &rm->available[i]);
    }
    for (int i = 0; i < rm->n; i++) {
        for (int j = 0; j < rm->m; j++) {
            rm->need[i][j] = rm->max[i][j] - rm->allocation[i][j];
        }
    }

    for (int i = 0; i < rm->n; i++) {
        rm->finished[i] = 0;
    }
}
void requestResources(ResourceManager *rm, int process_id, int request[MAX_RESOURCES]) {
    int can_allocate = 1;
    for (int i = 0; i < rm->m; i++) {
        if (request[i] > rm->need[process_id][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            can_allocate = 0;
            break;
        }
    }
    for (int i = 0; i < rm->m; i++) {
        if (request[i] > rm->available[i]) {
            printf("Error: Not enough resources available.\n");
            can_allocate = 0;
            break;
        }
    }

    if (can_allocate) {
        for (int i = 0; i < rm->m; i++) {
            rm->allocation[process_id][i] += request[i];
            rm->need[process_id][i] -= request[i];
            rm->available[i] -= request[i];
        }
        if (isSafeState(rm)) {
            printf("Resources allocated successfully.\n");
        } else {
        
            for (int i = 0; i < rm->m; i++) {
                rm->allocation[process_id][i] -= request[i];
                rm->need[process_id][i] += request[i];
                rm->available[i] += request[i];
            }
            printf("Error: Request would result in an unsafe state.\n");
        }
    }
}
void releaseResources(ResourceManager *rm, int process_id) {
    for (int i = 0; i < rm->m; i++) {
        rm->available[i] += rm->allocation[process_id][i];
        rm->allocation[process_id][i] = 0;
        rm->need[process_id][i] = rm->max[process_id][i];
    }
    printf("Resources released successfully.\n");
}
