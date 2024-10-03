#include "shared.h"
extern car Rovingcar[2];
// Check whether the point is legal

// Return whether the status of car is vaild or not 
int Legal(point temp);

// Do the next step of moving
int move_next(Directions next);

// Update the data on map ( caronmap and visited )
void update_map();