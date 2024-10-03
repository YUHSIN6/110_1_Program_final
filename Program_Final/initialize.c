#include "initialize.h"

void Init(){
    system("CLS");
    printf("\e[?25l"); // Eilliminate the cursor
    frame_cnt = 0;
    movement = 0;
    rotate = 0;
    explorablep = 0;
    missionp = 0;

    dir[UP][0] = -1, dir[UP][1] = 0;
    dir[LEFT][0] = 0, dir[LEFT][1] = -1;
    dir[RIGHT][0] = 0, dir[RIGHT][1] = 1;
    dir[DOWN][0] = 1, dir[DOWN][1] = 0;

    // [TODO 3-1]: set "caronmap" and "visited" to all 0
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n;  j++){
            caronmap[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}