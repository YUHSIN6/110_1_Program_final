#include "algo_withmission.h"
#include "queue.h"
#include "carupdate.h"


int bfsvis[50][50];
int bfsdis[50][50];
int distance[10][10];
int route[10];
int movedir[50][50];
int moveroute[2500];
int totaldis,tempdis;
// [TODO]: Implement the algorithm for with mission.
void withmission_solver(){

    //找出最短路徑
    BFS(Rovingcar[0].lup);
    inputdis(-1);
    for(int i = 0;i<mission_num;i++){
        BFS(mission_list[i].spot);
        inputdis(i);
    }
    mindis(); 
    moving(Rovingcar[0].lup,mission_list[route[1]].spot);
    for(int i = 1;i<4;i++){
    moving(mission_list[route[i]].spot,mission_list[route[i+1]].spot);
    }
}






void BFS(point startp) {
    //歸零
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            bfsvis[i][j] = 0;
            bfsdis[i][j] = 0;
            movedir[i][j] = 0;
        }
    }

    queue q = init_queue();
    q_push(&q,startp);
    bfsvis[startp.i][startp.j] = 1;
    while(!q_empty(q)){
        point temp = q_front(q);
        q_pop(&q);
        for(int t = 1; t<5; t++){
            point tempp;
            tempp.i = temp.i + dir[t][0],tempp.j = temp.j + dir[t][1];
            if(Legal(tempp) && !(bfsvis[tempp.i][tempp.j])){
                bfsvis[tempp.i][tempp.j] = 1;
                bfsdis[tempp.i][tempp.j] = bfsdis[temp.i][temp.j] + 1;
                movedir[tempp.i][tempp.j] = t;
                q_push(&q,tempp);
            }
        }
    }

}

void inputdis(int num){
    distance[num+1][0] = bfsdis[Rovingcar[0].lup.i][Rovingcar[0].lup.j];
    for(int i=0;i<mission_num;i++){
        distance[num+1][i+1] = bfsdis[mission_list[i].spot.i][mission_list[i].spot.j];
    }
}


void mindis(){
    for(int i = 0;i<10;i++){
        route[i] = 0;
    }
    totaldis = distance[0][1]+distance[1][2]+distance[2][3]+distance[3][4];
    for(int i = 0; i<4;i++){
        route[i] = i;
    }
    totaldis = 99;
    for(int i = 0;i<mission_num; i++){
        for(int ii = 0;ii<mission_num;ii++){
            if(ii != i){
                for(int iii = 0;iii<mission_num;iii++){
                    if(iii != i && iii != ii){
                        for(int iv = 0;iv<mission_num;iv++){
                            if(iv != i && iv != ii && iv != iii){
                                tempdis =distance[0][i+1] + distance[i+1][ii+1] +distance[ii+1][iii+1] +distance[iii+1][iv+1];
                                if(tempdis<totaldis){
                                    totaldis =tempdis;
                                    route[1] = i;
                                    route[2] = ii;
                                    route[3] = iii;
                                    route[4] = iv;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void moving(point a,point b){
    BFS(a);
    int j = 0;
    for(int i = 0; i<2500; i++){
        moveroute[i] = 0;
    }
    while(a.i != b.i || a.j != b.j){
        moveroute[j] = movedir[b.i][b.j];
        b.i += dir[5-moveroute[j]][0];
        b.j += dir[5-moveroute[j]][1];
        j++;
    }

    for(int i = j-1;i>=0;i--){
        move_next(moveroute[i]);
    }
}

    