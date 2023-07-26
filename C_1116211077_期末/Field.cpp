#include <stdio.h>
#include<iostream>
#include <curses.h>
#include"teF.h"

void Start_Field() {
	refresh();
	attrset(COLOR_PAIR(3));

	mvaddstr(5, 10, "     ");
	mvaddstr(5, 17, "     ");
	mvaddstr(5, 24, "     ");
	mvaddstr(5, 31, "    ");
	mvaddstr(5, 35, " ");
	mvaddstr(5, 45, " ");

	mvaddstr(20, 20, "enterkey to start");
}

void scoreField(int score) {
	attrset(COLOR_PAIR(2));
	int score0 = 0;  //‚P‚ÌˆÊ
	int score1 = 0;
	int score2 = 0;
	int score3 = 0;
	int score4 = 0;  //1–œ‚ÌˆÊ

	score4 = score / 10000;
	score3 = (score % 10000)/1000;
	score2 = (score % 1000) / 100;
	score1 = (score % 100) / 10;
	score0 = score % 10;
	char s4 = '0' + score4;
	char s3 = '0' + score3;
	char s2 = '0' + score2;
	char s1 = '0' + score1;
	char s0 = '0' + score0;

	mvaddstr(14, 40, "score");
	mvaddch(15, 40,  s4);
	mvaddch(15, 41, s3);
	mvaddch(15, 42, s2);
	mvaddch(15, 43, s1);
	mvaddch(15, 44, s0);
}