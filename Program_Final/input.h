#include "shared.h"

extern int mission_num;
extern mission mission_list[N];
extern point starting_spot;
extern car Rovingcar[2];
extern int map[50][50], m, n;

// Reading in the map
void Read();
// Get the data of map and do preprocess
void GetMap();
// Determine the car's initial direction and its position
void Init_Car();
// Initialize the data of missionspots
void Init_Missionspots();