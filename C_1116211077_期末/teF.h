
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
	//�����u���b�N���W
	int leftx;
	int lefty;
	//�E���u���b�N���W
	int rightx;
	int righty;
	
};

struct blocksizemid {
	//�^�񒆃u���b�N���W
	int midx;
	int midy;
	//�^�񒆃u���b�N���W�Q�i���̑��j
	int mid2x;
	int mid2y;
};

