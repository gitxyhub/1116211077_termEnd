#include <stdio.h>
#include<iostream>
#include <curses.h>
#include"teF.h"
int key;


void stage(int s,int t) {
	attrset(COLOR_PAIR(3));
	for (int k = 0; k < 2;k++) {
		for (int i = 0; i < 20; i++) {
			mvaddstr(s+i, t + k*22, "  ");
		}
	}
	for (int k = 0; k < 23;k++) {
		mvaddstr(s + 20, t + k,"  ");
	}
	
}

//ƒuƒƒbƒNˆÚ“®
int KeyCheck(struct blocksize *arg2,struct stageHW *arg,int tetrix[][24]) {
	refresh();
	
	timeout(100);
	key = getch();			//ƒL[“ü—Í

	if (key == KEY_RIGHT&& arg2->rightx < (arg->rightx) - 2&&tetrix[((arg2->rightx - 12) / 2)+1][arg2->righty-1] == 0) {
		arg2->leftx += 2;
	}
	else if (key == KEY_LEFT&& arg2->leftx > (arg->leftx) + 2 && tetrix[(arg2->leftx - 12) / 2 - 1][arg2->lefty - 1] == 0) {
		arg2->leftx -= 2;
	}
	
	return arg2->leftx;
}

int rotation(int Direction) {
	key = getch();
	timeout(100);
	if (key == KEY_UP) {
		Direction++;
		if (Direction > 4) {
			Direction = 1;
		}
	}
	return Direction;
}



//ŠeƒuƒƒbƒN‚Ì•`‰æ
void block(int kind,int Direction,struct blocksize *arg,struct blocksizemid *arg2) {
	
	switch (kind) {
		case 1: //³•ûŒ`‚Ì‚â‚Â
			attrset(COLOR_PAIR(4));
			
			arg2->midx = arg->leftx;
			arg2->midy = arg->lefty - 1;
			
			arg2->mid2x = arg->leftx + 2;
			arg2->mid2y = arg->lefty - 1;
			
			arg->rightx = arg->leftx + 2;
			arg->righty = arg->lefty;
			
			
			break;
		case 2: //ŠK’iŒ^@¶ã‚ª‚è
			switch (Direction%2) {
				case 1:
					attrset(COLOR_PAIR(2));
					
					arg2->midx = arg->leftx;
					arg2->midy = arg->lefty - 1;
					
					arg2->mid2x = arg->leftx + 2;
					arg2->mid2y = arg->lefty;
					
					arg->rightx = arg->leftx + 2;
					arg->righty = arg->lefty + 1;
					
					
					break;
				case 0:
					arg2->midx = arg->leftx + 2;
					arg2->midy = arg->lefty - 1;

					arg2->mid2x = arg->leftx + 2;
					arg2->mid2y = arg->lefty;

					arg->rightx = arg->leftx + 4;
					arg->righty = arg->lefty - 1;
					break;

			}
			break;
		case 3: //ŠK’iŒ^@‰Eã‚ª‚è
			attrset(COLOR_PAIR(2));
			switch (Direction%2) {
				case 1://‰ñ“]‘O
					arg2->midx = arg->leftx;
					arg2->midy = arg->lefty - 1;

					arg2->mid2x = arg->leftx + 2;
					arg2->mid2y = arg->lefty - 2;

					arg->rightx = arg->leftx + 2;
					arg->righty = arg->lefty - 1;
					break;
				case 0://‰ñ“]Œã
					arg2->midx = arg->leftx + 2;
					arg2->midy = arg->lefty;

					arg2->mid2x = arg->leftx + 2;
					arg2->mid2y = arg->lefty + 1;

					arg->rightx = arg->leftx + 4;
					arg->righty = arg->lefty + 1;
					break;
			}
			break;
		case 4:  //LŽš
			attrset(COLOR_PAIR(7));

			switch (Direction) {
			case 1:
				arg2->midx = arg->leftx;
				arg2->midy = arg->lefty - 1;

				arg2->mid2x = arg->leftx;
				arg2->mid2y = arg->lefty - 2;

				arg->rightx = arg->leftx + 2;
				arg->righty = arg->lefty;
				break;
			case 2:
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty;

				arg2->mid2x = arg->leftx + 4;
				arg2->mid2y = arg->lefty - 1;

				arg->rightx = arg->leftx + 4;
				arg->righty = arg->lefty;
				break;
			case 3:
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty;

				arg2->mid2x = arg->leftx + 2;
				arg2->mid2y = arg->lefty + 1;

				arg->rightx = arg->leftx + 2;
				arg->righty = arg->lefty+2;
				break;
			case 4:
				arg2->midx = arg->leftx ;
				arg2->midy = arg->lefty - 1;

				arg2->mid2x = arg->leftx + 2;
				arg2->mid2y = arg->lefty - 1;

				arg->rightx = arg->leftx + 4;
				arg->righty = arg->lefty - 1;
				break;
			}
			break;
		case 5:  //‹tLŽš
			attrset(COLOR_PAIR(7));
			
			switch (Direction) {
			case 1:
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty - 1;

				arg2->mid2x = arg->leftx + 2;
				arg2->mid2y = arg->lefty - 2;

				arg->rightx = arg->leftx + 2;
				arg->righty = arg->lefty;
				break;
			case 2:
				arg2->midx = arg->leftx ;
				arg2->midy = arg->lefty - 1;

				arg2->mid2x = arg->leftx + 2;
				arg2->mid2y = arg->lefty;

				arg->rightx = arg->leftx + 4;
				arg->righty = arg->lefty;
				break;
			case 3:
				arg2->midx = arg->leftx;
				arg2->midy = arg->lefty - 1;

				arg2->mid2x = arg->leftx;
				arg2->mid2y = arg->lefty - 2;

				arg->rightx = arg->leftx + 2;
				arg->righty = arg->lefty - 2;
				break;
			case 4:
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty;

				arg2->mid2x = arg->leftx + 4;
				arg2->mid2y = arg->lefty;

				arg->rightx = arg->leftx + 4;
				arg->righty = arg->lefty + 1;
				break;
			}
			break;
		case 6:  //“Ê
			attrset(COLOR_PAIR(6));
			
			switch (Direction) {
			case 1:
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty;

				arg2->mid2x = arg->leftx + 2;
				arg2->mid2y = arg->lefty - 1;

				arg->rightx = arg->leftx + 4;
				arg->righty = arg->lefty;
				break;
			case 2:
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty;

				arg2->mid2x = arg->leftx + 2;
				arg2->mid2y = arg->lefty - 1;

				arg->rightx = arg->leftx + 2;
				arg->righty = arg->lefty + 1;
				break;
			case 3:
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty;

				arg2->mid2x = arg->leftx + 2;
				arg2->mid2y = arg->lefty + 1;

				arg->rightx = arg->leftx + 4;
				arg->righty = arg->lefty;
				break;
			case 4:
				arg2->midx = arg->leftx;
				arg2->midy = arg->lefty - 1;

				arg2->mid2x = arg->leftx;
				arg2->mid2y = arg->lefty - 2;

				arg->rightx = arg->leftx + 2;
				arg->righty = arg->lefty -1;
				break;
			}
			break;
		case 7:  //c–_
			attrset(COLOR_PAIR(5));
			
			switch (Direction%2) {
			case 1:
				arg2->midx = arg->leftx;
				arg2->midy = arg->lefty - 1;

				arg2->mid2x = arg->leftx;
				arg2->mid2y = arg->lefty - 2;

				arg->rightx = arg->leftx;
				arg->righty = arg->lefty - 3;
				break;
			case 0:  //‰¡–_
				arg2->midx = arg->leftx + 2;
				arg2->midy = arg->lefty;

				arg2->mid2x = arg->leftx + 4;
				arg2->mid2y = arg->lefty;

				arg->rightx = arg->leftx + 6;
				arg->righty = arg->lefty;
				break;
			}
			break;
	}
	mvaddstr(arg->lefty, arg->leftx, "  ");
	mvaddstr(arg2->midy, arg2->midx, "  ");
	mvaddstr(arg2->mid2y, arg2->mid2x, "  ");
	mvaddstr(arg->righty, arg->rightx, "  ");
}


void gameover(int tetrix[][24],int Flag) {
	
	for (int i = 0; i < 10; i++) {
		if (tetrix[i][3] == 1) {
			Flag = 1;
		}
	}
}

//ƒuƒƒbƒN‚ðˆê—ñÁ‹Ž‚·‚é
int Checkdeleat(int tetrix[][24]) {
	int count = 0;
	
	for (int i = 4; i < 24; i++) {
		int one = 0;

		for (int k = 0; k < 10; k++) {
			if (tetrix[k][i] == 1) {
				one++;
			}
			if (one >= 10) {
				blockdown(tetrix, i);
				count++;
			}
		}
	}
	return count;
}

//ƒuƒƒbƒN‚ðˆê’i‰º‚°‚é
void blockdown(int tetrix[][24],int i) {
	for (i; i > 0; i--){
		for (int k = 0; k < 10; k++) {
			tetrix[k][i] = tetrix[k][i - 1];
		}
	}
}



