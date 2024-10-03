#include "shared.h"
#include "output.h"

// Adjacency matrix
int dis[N+1][N+1];

void BFS(point startp);
// Solve the map that there are missions on it
void withmission_solver();
void inputdis(int num);
void mindis();
void moving(point a,point b);