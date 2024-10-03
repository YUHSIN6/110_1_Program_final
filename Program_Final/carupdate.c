#include "carupdate.h"
#include "output.h"

// [TODO 3-2 ~ 3-5]:implement functions related to car update
// The functionality of the functions are noted in carupdate.h

// [TODO 3-2]:implement legal_pt function
int Legal(point temp){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(temp.i + i < 0 || temp.i + i > m-1 ||temp.j + j < 0 || temp.j + j > n-1 || !(map[temp.i + i][temp.j + j])){
                return 0;
            }
        }
    }
    return 1;
}

// [TODO 3-3]:implement mavable function


// [TODO 3-4]: implement move_next function and its relating functions
int move_next(Directions next){
    car tempcar[2] = {Rovingcar[0],Rovingcar[1]};
    if( tempcar[0].dir + next ==5 || tempcar[0].dir - next == 0){
        tempcar[1] = tempcar[0];
        if(tempcar[0].dir + next == 5){
            tempcar[0].dir = next;        
        }
        tempcar[0].curoil--;
    }else{
        tempcar[1].lup.i += dir[next][0];
        tempcar[1].lup.j += dir[next][1];
        tempcar[0].curoil -= 2;
        if(!Legal(tempcar[1].lup)){
            tempcar[1].lup = tempcar[0].lup;
            tempcar[0].dir = next;
            tempcar[0].curoil -= 3;
        }
    }
    tempcar[0].lup.i += dir[next][0];
    tempcar[0].lup.j += dir[next][1];

    // Check the validity of the tempcar
    if (!Legal(tempcar[0].lup)){
        return 0;
    }
    // If the tempcar is not valid then return (do nothing)
    // Else update the roving car to the tempcar
    movement++;
    if(Rovingcar[0].dir != tempcar[0].dir){
        movement--;
        rotate++;
    }
    Rovingcar[0] = tempcar[0];
    Rovingcar[1] = tempcar[1];
    // Uodate the map and step count
    
    update_map();
    Print(1);
    return 1;
}



// [TODO 3-5]: implement the update map function
void update_map(){
    visitedp = 0;
    missionpv = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            caronmap[i][j] = 0;
        }
    }
    
    // Clear caronmap 
    for(int w = 0; w<2; w++){
        for(int h = 0; h<2; h++){
            for(int k = 0; k<2; k++){
                caronmap[Rovingcar[k].lup.i + w][Rovingcar[k].lup.j + h] = 1;
                visited[Rovingcar[k].lup.i + w][Rovingcar[k].lup.j + h] = 1;
            }
        }
    }
    // Check whether the car touched the mission spot
    // Update "caronmap" and "visited"
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n ; j++){
            if(visited[i][j] == 1){
                if(map[i][j] == 3){
                    missionpv++;
                }
                visitedp++;
            }
        }
    }
    // Update the car's position
    //... = ...
}