//include其他地方東西
#include "algo_nomission.h"
#include "algo_withmission.h"
#include "carupdate.h"
#include "initialize.h"
#include "input.h"
#include "output.h"
#include "queue.h"
#include "share.h"
#include "stack.h"
//
const int fps = 60;

int main(){

    Init();

    Read();

    // First print the map for 10 frames
    Print(0);
    Print(1);

    update_map();
    nomission_solver();
    

    

    printf("\n\n\n");
    system("pause");
    return 0;
}