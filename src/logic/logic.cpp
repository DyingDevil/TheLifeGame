#include<stdio.h>
#include<stdbool.h>
#include"logic.h"
#include<Windows.h>

using namespace std;



int errorHandler(int lifeCondition, int bottomLifeVal, int topLifeVal)
{
	if (lifeCondition > 8) {
		return -1;
	}
	else if (lifeCondition < 0) {
		return -2;
	}
	else if (bottomLifeVal > topLifeVal) {
		return -3;
	}
	else if (bottomLifeVal > 8) {
		return -4;
	}
	else if (bottomLifeVal < 0) {
		return -5;
	}
	else if (topLifeVal > 8) {
		return -6;
	}
	else if (topLifeVal < 0) {
		return -7;
	}
	else if (topLifeVal < 0) {
		return -7;
	}
	else {
		return 0;
	}
}
int myMod(int x,int y) {
	if (x >= 0) {
		return x % y;
	}
	else {
		return (x + 100) % y;
	}
}
int get_cells(bool cellConfig[gridX][gridY], int lifeCondition, int bottomLifeVal, int topLifeVal)
{
	bool newConfig[gridX][gridY] = { 0, };
	int error = errorHandler(lifeCondition, bottomLifeVal, topLifeVal);
	if (error) {
		return error;
	}
	for (int i = 0; i < gridX; ++i) {
		for (int j = 0; j < gridY; ++j) {
			int count = 0;
			for (int x = -1; x < 2; ++x) {
				for (int y = -1; y < 2; ++y) {
					int realX = myMod(i + x, gridX);
					int realY = myMod(j + y, gridY);
					if (cellConfig[realX][realY] && !(x==0 && y==0)) {
						count++;
					}
				}
			}
			if (cellConfig[i][j]) {
				if (count >= bottomLifeVal && count <= topLifeVal) {
					newConfig[i][j] = 1;
				}
				else {
					newConfig[i][j] = 0;
				}
			}
			else {
				if (count == lifeCondition) {
					newConfig[i][j] = 1;
				}
				else {
					newConfig[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < gridX; ++i) {
		for (int j = 0; j < gridY; ++j) {
			cellConfig[i][j] = newConfig[i][j];
		}
	}
	return error;
}

