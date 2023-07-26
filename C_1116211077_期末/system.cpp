#include <stdio.h>
#include<iostream>
#include <curses.h>
#include"teF.h"


int changetetrix_X(int x) {
	int X = 0;
	X = (x - 12) / 2;
	return X;
}

int changetetrix_Y(int y) {
	int Y = 0;
	Y = y - 1;
	return Y;
}


