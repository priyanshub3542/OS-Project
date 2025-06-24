#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

typedef struct {
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int finished[MAX_PROCESSES];
    int safe_sequence[MAX_PROCESSES];
    int n, m;
} ResourceManager;

void initialize(ResourceManager *rm, int processes, int resources);
void requestResources(ResourceManager *rm, int process_id, int request[MAX_RESOURCES]);
void releaseResources(ResourceManager *rm, int process_id);

#endif
