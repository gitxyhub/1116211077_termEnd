

#include <stdio.h>
#include<iostream>
#include <curses.h>
#include<cstdlib>
#include"teF.h"


int tetrix[10][24] = {0};
struct blocksize pattern = { 0 };
struct blocksizemid patternmid = { 0 };

int gameoverFlag = 0;

int main()
{
	
	// 初期化
	if (initscr() == NULL) {
		return 1;
	}
	curs_set(0);
	int StartX = 10;
	int StartY = 5;

	int move = 0;
	struct stageHW stage1 = { 0 };
	stage1.leftx = 10;
	stage1.lefty = 7;
	stage1.rightx = stage1.leftx + 22;
	stage1.righty = stage1.lefty + 20;

	struct startpoint PT = { 0 };
	PT.x = stage1.leftx + 12;
	PT.y = stage1.lefty - 4;
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_RED, COLOR_BLUE);
	init_pair(3, COLOR_BLUE, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(5, COLOR_BLACK, COLOR_CYAN);
	init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(7, COLOR_BLACK, COLOR_RED);

	keypad(stdscr, TRUE);
	int key;
	int start_Flag = 0;
	int combo ;
	int score = 0;
	
	while (true) {
		Start_Field();
		key = getch();

		if (key == KEY_ENTER) {
			start_Flag = 1;
		}
			while (start_Flag == 1) {
				refresh();
				pattern.leftx = PT.x;
				pattern.lefty = PT.y;

				combo = 0;

				int kindNO = rand()%7+1 ;
				int Direct = 1;
				for (int i = 0; i < 3; i++) {
					for (int k = 0; k < 10; k++) {
						tetrix[k][i] = 0;
					}
				}
				
				

				while (true) {
					// 画面をクリア
					erase();

					//積まれたブロックを描画
					for (int i = 0; i < 24; i++) {
						for (int k = 0; k < 10; k++) {
							if (tetrix[k][i] == 1) {
								attrset(COLOR_PAIR(1));
								mvaddstr(stage1.lefty + i - 4, stage1.leftx + 2 + 2 * k, "  ");
							}
						}
					}



					// ステージ描画
					stage(stage1.lefty, stage1.leftx);
					scoreField(score);

					attrset(COLOR_PAIR(2));
					//キー入力
					pattern.leftx = KeyCheck(&pattern, &stage1, tetrix);
					Direct = rotation(Direct);


					// ブロック表示
					block(1, Direct, &pattern, &patternmid);


					//バッファーオーバーランを防ぐ
					int blockleftX = changetetrix_X(pattern.leftx);
					int blockleftY = changetetrix_Y(pattern.lefty);
					int blockrightX = changetetrix_X(pattern.rightx);
					int blockrightY = changetetrix_Y(pattern.righty);
					int blockmidX = changetetrix_X(patternmid.midx);
					int blockmidY = changetetrix_Y(patternmid.midy);
					int blockmid2X = changetetrix_X(patternmid.mid2x);
					int blockmid2Y = changetetrix_Y(patternmid.mid2y);

					// ブロック移動
					if (pattern.righty < 24 && pattern.lefty < stage1.righty - 1 && tetrix[blockleftX][blockleftY + 1] == 0 && tetrix[blockrightX][blockrightY + 1] == 0
						&& tetrix[blockmidX][blockmidY + 1] == 0 && tetrix[blockmid2X][blockmid2Y + 1] == 0) {
						pattern.lefty++;
					}
					else {
						tetrix[blockleftX][blockleftY] = 1;
						tetrix[blockrightX][blockrightY] = 1;
						tetrix[blockmidX][blockmidY] = 1;
						tetrix[blockmid2X][blockmid2Y] = 1;
						break;
					}

					combo=Checkdeleat(tetrix);

					score = score + 100 * combo*combo;
					

					gameover(tetrix,gameoverFlag);

					


					// 画面を更新
					refresh();
					// 1秒待機
					napms(100);
				}
				
				if (gameoverFlag == 1) break;
				
				

			}
			erase();

	}

	endwin();
	return 0;
}







