#include <Windows.h>
#include "UI.h"
#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
int show_menu(int* choise) {
	system("CLS");
	*choise = 0;
	printf("#################\n");
	printf("# 1.   Start    #\n");
	printf("# 2. Set rules  #\n");
	printf("# 3. Set cells  #\n");
	printf("# 4. Load game  #\n");
	printf("# 5. Load rules #\n");
	printf("# 6. Save game  #\n");
	printf("# 7. Save rules #\n");
	printf("# 8.    Exit    #\n");
	printf("#################\n");
	while (*choise != 1 && *choise != 2 && *choise != 3 && *choise != 4 && *choise != 5 && *choise != 6 && *choise != 7 && *choise != 8) {
		scanf("%d", choise);
	}
	return 0;
}

int get_cell(bool field[50][50]) {
	bool flag = 1;
	char cho;
	while (flag) {
		int x;
		int y;
		draw_field(field, 0);
		printf("\nEnter x-coord of cell");
		if (!scanf("%d", &x)) {
			return -9;
		}
		else if (x < 0 || x>50) {
			return -8;
		}
		printf("\nEnter y-coord of cell");
		if (!scanf("%d", &y)) {
			return -9;
		}
		else if (y < 0 || y>50) {
			return -8;
		}
		if (field[x][y] == 0) {
			field[x][y] = 1;
		}
		else if (field[x][y] == 1) {
			field[x][y] = 0;
		}
		char cho = '2';
		while (cho != 'y' && cho != 'Y' && cho != 'n' && cho != 'N') {
			system("CLS");
			printf("Continue switching cells? (Y/N)");
			scanf("%1c", &cho);
		}
		if (cho == 'n' || cho == 'N') {
			flag = 0;
		}
	}
	return 0;
}

int get_settings(int settings[3]) {
	while (1) {
		int cho = 0;
		system("CLS");
		printf("#########################\n");
		printf("# 1.   Start of live (%d)#\n", settings[0]);
		printf("# 2.Minimum neighbors(%d)#\n", settings[1]);
		printf("# 3.Maximum neighbors(%d)#\n", settings[2]);
		printf("# 4.        Back        #\n");
		printf("#########################\n");
		while (cho != 1 && cho != 2 && cho != 3 && cho != 4) {
			scanf("%d", &cho);
		}
		if (cho == 1) {
			system("CLS");
			printf("Enter amount of minimum neighbors to start a new life. (0-8)\n");
			int a = 40;
			while (!(a >= 0 && a <= 8)) {
				scanf("%d", &a);
			}
			settings[0] = a;
		}
		else if (cho == 2) {
			system("CLS");
			printf("Enter amount of minimum neighbors to continue life. (0-8)\n");
			int a = 40;
			while (!(a >= 0 && a <= 8)) {
				scanf("%d", &a);
			}
			settings[1] = a;
		}
		else if (cho == 3) {
			system("CLS");
			printf("Enter amount of maximum neighbors to continue life. (0-8)\n");
			int a = 40;
			while (!(a >= 0 && a <= 8)) {
				scanf("%d", &a);
			}
			settings[2] = a;
		}
		else if (cho == 4) {
			return 0;
		}
		else {
			return -10;//unexpected option of menu
		}
	}
}

int draw_field(bool field[50][50], int ctr) {
	SetPosition(0, 0);
	char black = 219;
	char white = 176;

	printf("%c", 201);
	for (int i = 0; i < 100; ++i) {
		printf("%c", 205);
	}
	printf("%c\n", 187);
	for (int i = 0; i < 50; ++i) {
		printf("%c", 186);
		for (int j = 0; j < 50; ++j) {
			if (field[i][j] == 0) {
				printf("%c%c", black, black);
			}
			else {
				printf("%c%c", white, white);
			}
		}
		printf("%c\n", 186);

	}
	printf("%c", 200);
	for (int i = 0; i < 100; ++i) {
		printf("%c", 205);
	}
	printf("%c", 188);
	return 0;
}
int button_is_not_pressed(){
	if (_kbhit()) {
		return 0;
	}
	return 1;
}

void SetPosition(int x, int Y)
{
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { x, Y };

	SetConsoleCursorPosition(Screen, Position);
}

char* get_file_name() {
	char name[20];
	system("CLS");
	printf("Enter the name of a file: \n");
	scanf("%20s", &name);
	return name;
}