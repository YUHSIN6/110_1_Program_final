#include "output.h"

//印東西總函式
void Print(int mode){
    update_map();
    Print_Title(10,0);
    Print_Map(40,5,mode);
    Print_Info(5,5,2);
}
//印標題
void Print_Title(int x, int y){
    gotoxy(x, y);
    clrprintf(Green,"car");
}

//印地圖
void Print_Map(int x, int y, int mode){
    for (int i=-1; i<m+1; i++){
        gotoxy(x, y++);
        if(i == -1 || i == m)//邊框
        for(int j = 0,b = 0; j<n+2; j++){
            if(j > 0 && j < n+1){
                b = j;
                if(!(b%10)){
                    clrprintf(Purple_Cube,"%2d",b/10);
                }else{
                    while(b>10){
                        b -=10;
                    }
                    clrprintf(Red_Cube,"%2d",b);
                }
            }else{
            clrprintf(Red_Cube,"  ");
            }
        }else{
            clrprintf(Red_Cube,"%2d",i+1);
            for (int j = 0; j<n; j++){//車
                if (mode && caronmap[i][j]){
                        clrprintf(Purple_Cube,"  ");
                    }
                else  //地圖
                    switch (map[i][j]){
                        case Exploreable :
                            if(visited[i][j] == 1){
                                clrprintf(Yellow_Cube,"XX");
                            }else{
                                clrprintf(Yellow_Cube,"  ");
                            }
                            break;
                        case Obstruction :
                            clrprintf(Blue_Cube,"  ");
                            break;
                        case Mission :
                            if(visited[i][j] == 1){
                                clrprintf(Cyan_Cube,"XX");
                            }else{
                                clrprintf(Cyan_Cube,"  ");
                            }
                            break;
                        case Starting :
                            clrprintf(Green_Cube,"00");
                            break;
                    }
            }
            clrprintf(Red_Cube,"%2d",i);
        }
    }
}

// 印資訊
void Print_Info(int x, int y, int h){
    gotoxy(x, y);
    clrprintf(Yellow,"Car Info");

    gotoxy(x, y += h);
    if(Rovingcar[0].dir == 1){
        clrprintf(Yellow,"direction:up   ");
    }else if(Rovingcar[0].dir == 2){
        clrprintf(Yellow,"direction:left ");
    }else if(Rovingcar[0].dir == 3){
        clrprintf(Yellow,"direction:right");
    }else if(Rovingcar[0].dir == 4){
        clrprintf(Yellow,"direction:down ");
    }
    

    gotoxy(x, y += h);
    clrprintf(Yellow,"n of movement:%2d",movement);

    gotoxy(x, y += h);
    clrprintf(Yellow,"n of rotate:%2d",rotate);

    gotoxy(x, y += h);
    clrprintf(Yellow,"oil quantity:%3d",Rovingcar[0].curoil);

    gotoxy(x, y += h);
    clrprintf(Red,"Map Info");

    gotoxy(x, y += h);
    clrprintf(Red,"Map size:%d*%d",n,m);

    gotoxy(x, y += h);
    clrprintf(Red,"n of explorable points:%2d",explorablep);

    gotoxy(x, y += h);
    clrprintf(Red,"n of visited points:%2d",visitedp-6);

    gotoxy(x, y += h);
    clrprintf(Red,"n of mission point:%2d",missionp);

    gotoxy(x, y += h);
    clrprintf(Red,"n of mission point visited:%2d",missionpv);
}

void gotoxy(int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x, y};
	SetConsoleCursorPosition(h, position);
}	

void clrprintf(const char* color, const char* format, ...){
    //顏色
    printf(color);
    //內容
    va_list arg;
    va_start(arg, format);
    vprintf(format, arg);
	va_end(arg);
    //Resets the text to default color 
    printf("\033[0m"); 
}
