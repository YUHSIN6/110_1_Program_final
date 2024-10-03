#include "algo_nomission.h"
#include "carupdate.h"

int dfsvis[50][50];

void nomission_solver(){

for(int i = 0;i<50;i++){
    for(int j = 0;j<50;j++){
        dfsvis[i][j] = 0;
    }
}
    dfsvis[Rovingcar[0].lup.i][Rovingcar[0].lup.j]=1;
    dfs(Rovingcar[0].lup);
}

void dfs(point temp){

    for (int t = 1; t<5; t++){
        point tempp;
        tempp.i = temp.i + dir[t][0], tempp.j = temp.j + dir[t][1];
        if(Legal(tempp) && !(dfsvis[tempp.i][tempp.j])){
            dfsvis[tempp.i][tempp.j] = 1;
            move_next(t);
            dfs(tempp);
            move_next(5-t);
        }

    }
}