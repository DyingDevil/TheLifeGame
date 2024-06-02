#include<stdio.h>
#include<stdbool.h>
#include"logic.h"
#include<Windows.h>
#include"Testlogic.h"
int LTestsCount = 1;

int ruleTests[4] = { -1, 2, 3, 9 };

int testsExpectedVals[7] = {-1, -2, -3, -4, -5, -6, -7};
int testsVals[7] = { 0, };

bool life[gridX][gridY] = { 0, };
bool testGrid[gridX][gridY] = { 0, };

int gridTest(bool grid1[gridX][gridY], bool grid2[gridX][gridY]) {
	int res = 1;
	for (int i = 0; i < gridX; ++i) {
		for (int j = 0; j < gridX; ++j) {
			if (grid1[i][j] != grid2[i][j]) res = 0;
		}
	}
	if (res) {
		printf("Logic test #%d", LTestsCount);
		printf(": success\n");
	}
	else {
		printf("Logic test #%d", LTestsCount);
		printf(": error\n");
	}
	++LTestsCount;
	return 0;
}

int clearGrid(bool grid[gridX][gridY]) {
	for (int i = 0; i < gridX; ++i) {
		for (int j = 0; j < gridX; ++j) {
			grid[i][j] = 0;
		}
	}
	return 0;
}

int testLogic() {
	//----------Тесты на входные данные----------//
	testsVals[0] = get_cells(life, ruleTests[3], ruleTests[1], ruleTests[2]); //test#1 lifeCondition > 8
	testsVals[1] = get_cells(life, ruleTests[0], ruleTests[1], ruleTests[2]); //test#2 lifeCondition < 0
	testsVals[2] = get_cells(life, ruleTests[2], ruleTests[2], ruleTests[1]); //test#3 bottomLifeVal > topLifeVal
	testsVals[3] = get_cells(life, ruleTests[2], ruleTests[3], ruleTests[2]); //test#4 bottomLifeVal > 8
	testsVals[4] = get_cells(life, ruleTests[2], ruleTests[0], ruleTests[2]); //test#5 bottomLifeVal < 0 
	testsVals[5] = get_cells(life, ruleTests[2], ruleTests[1], ruleTests[3]); //test#6 topLifeVal > 8
	testsVals[6] = get_cells(life, ruleTests[2], ruleTests[1], ruleTests[0]); //test#7 topLifeVal < 0
	for (int i = 0; i < 7; ++i) {
		if (testsExpectedVals[i] == testsVals[i]) {
			printf("Test #%d", i+1);
			printf(": success\n");
		}
		else {
			printf("Test #%d", i+1);
			printf(": error value <%d", testsVals[i]);
			printf(">, expected value %d", testsExpectedVals[i]);
			printf("\n");
		}
	}
	//----------Тесты на правильность логики----------//
	//test#1 пустое поле
	int lCount = 1;
	get_cells(life, ruleTests[2], ruleTests[1], ruleTests[2]);
	gridTest(life, testGrid);
	//test#2 палка 3х1 должна повторяться на каждой второй эпохе
	testGrid[1][0] = 1;
	testGrid[1][1] = 1;
	testGrid[1][2] = 1;
	life[1][0] = 1;
	life[1][1] = 1;
	life[1][2] = 1;
	get_cells(life, ruleTests[2], ruleTests[1], ruleTests[2]);
	get_cells(life, ruleTests[2], ruleTests[1], ruleTests[2]);
	gridTest(life, testGrid);
	//test3 квадрат должен сохранитьсся 
	clearGrid(life);
	clearGrid(testGrid);
	testGrid[1][0] = 1;
	testGrid[1][1] = 1;
	testGrid[2][0] = 1;
	testGrid[2][1] = 1;
	life[1][0] = 1;
	life[1][1] = 1;
	life[2][0] = 1;
	life[2][1] = 1;
	get_cells(life, ruleTests[2], ruleTests[1], ruleTests[2]);
	gridTest(life, testGrid);
	//test4 рандомные одиночные клетки должны исчезнуть
	clearGrid(life);
	clearGrid(testGrid);
	life[1][3] = 1;
	life[3][1] = 1;
	life[6][9] = 1;
	life[4][20] = 1;
	get_cells(life, ruleTests[2], ruleTests[1], ruleTests[2]);
	gridTest(life, testGrid);
	return 0;
}