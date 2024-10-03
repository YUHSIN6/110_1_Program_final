#ifndef SHARED_H
#define SHARED_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

// 基礎變數
int frame_cnt;
int movement,rotate;
int explorablep,visitedp,missionp,missionpv;

// 地圖大小
int map[50][50], m, n;

// 走過地圖大小
int visited[50][50];

//移動方向
int dir[5][2];

// 對point設定
typedef struct point {
    int i, j;
} point;

// 地圖點
typedef enum Status {
	Obstruction = 0,
	Exploreable = 1,
	Starting = 2,
	Mission = 3,
	Visited = 4
} Status;

// 車方向
typedef enum Directions {
	NONE = 0,
	UP = 1,
	LEFT = 2,
	RIGHT = 3,
	DOWN = 4
} Directions;

// 車子設定
typedef struct car {
	//左上角點
    point lup;
	//方向
    Directions dir;
	//滿油量
	int fulloil;
	//現在油量
	int curoil;
} car;

car Rovingcar[2];
//兩台車
int caronmap[50][50];

//任務點狀態
typedef struct mission {
	//位置
	point spot;
	//狀態(是否踩過)
	Status status;
} mission;

//任務總數
#define N 10
int mission_num, visited_mission_num;
mission mission_list[N];


point make_point(int i, int j);

// For debugging
void debug(const char* format, ...);

static void vlog(const char* format, va_list arg);

#endif