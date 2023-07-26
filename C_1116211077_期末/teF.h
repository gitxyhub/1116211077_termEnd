
#pragma once

//tetris.cpp
void stage(int s, int t);
int KeyCheck(struct blocksize* arg2, struct stageHW* arg, int tetrix[][24]);
void block( int kind,int Direction, struct blocksize* arg,struct blocksizemid *arg2);
void gameover(int tetrix[][24],int Flag);
int Checkdeleat(int tetrix[][24]);
void blockdown(int tetrix[][24], int i);
int rotation(int Direction);


//system.cpp
int changetetrix_Y(int x);
int changetetrix_X(int y);

//Field.cpp
void Start_Field();
void scoreField(int score);

struct stageHW {
	int leftx;
	int lefty;
	int righty;
	int rightx;
	
};

struct startpoint
{
	int x;
	int y;
};

struct blocksize {
	//左側ブロック座標
	int leftx;
	int lefty;
	//右側ブロック座標
	int rightx;
	int righty;
	
};

struct blocksizemid {
	//真ん中ブロック座標
	int midx;
	int midy;
	//真ん中ブロック座標２（その他）
	int mid2x;
	int mid2y;
};

