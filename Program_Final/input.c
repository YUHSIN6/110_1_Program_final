#include "input.h"
#include "stack.h"

void Read(){
    freopen("input.txt", "r", stdin);
    GetMap();
    Init_Car();
    Init_Missionspots();
}

void GetMap(){
    // [TODO 1-1]: Read the map with arbitrary size m*n.
    int b = 0;
    m = 0;
    n = 0;
    char a;
    while (scanf("%c",&a) != EOF){
        if(a == '1' || a == '3'){
            explorablep++;
        }
        if(a == '3'){
            missionp++;
        }
        if(a == '\n'){
            m++;
            b = 0;
        }else{
            map[m][b] = a-'0';
            if(m == 0){
            n++;
            }
            b++;
        }
    }
    m++;
}


void Init_Car(){
    // We can then discuss in two case and decide the direction of the car and the fix point.
    // Case 0 , Case 1  
    //  ***      o*x
    //  o**      **
    //           **
    // Case 0 : Horizontal 
    // Case 1 : Vertical
    // For example, we can assume there are two cases like this and discuss the fix point 
    // and the direction of the car.

    // Initialize the fix point and dir of the car


    int Case = 3, i = 0,j = 0;
    for(;i<m;i++){
        j = 0;
        for(;j<n;j++){
            if(map[i][j] == Starting){
                if(j+2 > n){
                    Case = 1;
                }else if(map[i][j+2] == Starting){
                    Case = 0;
                }else{
                    Case = 1;
                }
                break;
            }
        }
        if(Case != 3){
            break;
        }
    }
    if (Case == 0){
        if (j+4 > n || map[i][j+3] == Obstruction || map[i+1][j+3] == Obstruction)
            Rovingcar[0].dir = LEFT, Rovingcar[0].lup = make_point(i,j), Rovingcar[1].lup = make_point(i,j+1);
        else
            Rovingcar[0].dir = RIGHT, Rovingcar[0].lup = make_point(i,j+1), Rovingcar[1].lup = make_point(i,j);
    }
    else { // Case 1
        if (i+5 > m || map[i+3][j] == Obstruction || map [i+3][j+1] == Obstruction)
            Rovingcar[0].dir = UP, Rovingcar[0].lup = make_point(i,j), Rovingcar[1].lup = make_point(i+1,j);
        else
            Rovingcar[0].dir = DOWN, Rovingcar[0].lup = make_point(i+1,j),Rovingcar[1].lup = make_point(i,j);
    }
    // Initialize the amount of the car oil to the number you want
    Rovingcar[0].fulloil = Rovingcar[0].curoil = 300;
}

//[TODO 1-3]: Finish the mission_list initialization
void Init_Missionspots(){
    mission_num = visited_mission_num = missionp = 0;
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            if(map[i][j] == Mission){
                missionp++;
                if(map[i+1][j] == Mission || map[i][j+1] == Mission){
                    mission_list[mission_num].spot.i = i;
                    mission_list[mission_num].spot.j = j;
                    mission_list[mission_num].status = Mission;
                    mission_num++;
                }    
            } 
            // Initialize the data in mission_list
            // Status, spots, ...
        }
    }
}