#include "shared.h"
#include "carupdate.h"

//色塊
#define Black "\033[0;30m"
#define Black_Cube "\033[;40m"
#define Red "\033[0;31m"
#define Red_Cube "\033[;41m"
#define Light_Red "\033[1;31m"
#define Green "\033[0;32m"
#define Green_Cube "\033[;42m"
#define Light_Green "\033[1;32m"
#define Yellow "\033[0;33m"
#define Yellow_Cube "\033[0;43m"
#define Light_Yellow "\033[1;33m"
#define Light_Yellow_Cube "\033[0;103m"
#define Blue "\033[0;34m"
#define Blue_Cube "\033[;44m"
#define Light_Blue "\033[1;34m"
#define Purple "\033[0;35m"
#define Purple_Cube "\033[;45m"
#define Light_Purple "\033[1;35m"
#define Cyan "\033[0;36m"
#define Cyan_Cube "\033[;46m"
#define Light_Cyan "\033[1;36m"
#define White "\033[0;37m"
#define White_Cube "\033[;47m"

//地圖
extern int map[50][50];
extern int m, n;
extern int frame_cnt;


//mode (0/1) (有/無)印車 
void Print(int mode);

//印標題
void Print_Title(int x, int y);

//印地圖
void Print_Map(int x, int y, int mode);

//印資訊
void Print_Info(int x, int y, int h);

//去格上特定點
void gotoxy(int x, int y);

//印顏色(類似printf)
void clrprintf(const char* color, const char* format, ...);
