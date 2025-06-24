#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "resource_manager.h"

void getInputForTotalResources(ResourceManager *rm);
void getAllocationInput(ResourceManager *rm);
void getMaxInput(ResourceManager *rm);
void updateResources(ResourceManager *rm);
void displayMenu();

#endif
