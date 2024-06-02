#include <stdio.h>
#include "core.h"
#include "error.h"
#include "logic.h"
#include "UI.h"
#include "save.h"
#include "settings.h"
#include<Windows.h>
#include <conio.h>
int start() {
	bool field[50][50] = { 0, };
	int choise;
	int sett[3] = { 3,2,3 };
	int error;
	while (1) {
		error = show_menu(&choise);
		if (error) {
			char* st_err = process_error(error);
			printf("%s", st_err);
			system("pause");
		}
		switch (choise) {
		case 1:
			play(sett, field);
			break;
		case 2:
			{error = get_settings(sett);
			if (error) {
				char* st_err = process_error(error);
				printf("%s", st_err);
				system("pause");
			}
			break;}
		case 3:
			{error = get_cell(field);
			if (error) {
				char* st_err = process_error(error);
				printf("%s", st_err);
				system("pause");
			}
			break;}
		case 4:
			{char* fname = get_file_name();
			error = load_game(fname,field);
			if (error) {
				char* st_err = process_error(error);
				printf("%s", st_err);
				system("pause");
			}
			break;}
		case 5:
			{char* fname = get_file_name();
			error = load_settings(fname,sett);
			if (error) {
				char* st_err = process_error(error);
				printf("%s", st_err);
				system("pause");
			}
			break;}
		case 6:
			{char* fname = get_file_name();
			error = save_game(fname,field);
			if (error) {
				char* st_err = process_error(error);
				printf("%s", st_err);
				system("pause");
			}
			break;}
		case 7:
			{char* fname = get_file_name();
			error = save_settings(fname,sett);
			if (error) {
				char* st_err = process_error(error);
				printf("%s", st_err);
				system("pause");
			}
			break;}
		case 8:
			return 0;
		default:{
			const char* st_err = process_error(-10);
			printf("%s", st_err);
			system("pause");
			break;
			}
		}

		//if(choise == 4) {
		//	char* file_name = get_file_name();
		//	load_game(file_name, field);
		//}
		//else if (choise == 5) {
		//	char* file_name = get_file_name();
		//	load_settings(file_name, sett);
		//}
		//else if (choise == 6) {
		//	char* file_name = get_file_name();
		//	save_game(file_name, field);
		//}
		//else if (choise == 7) {
		//	char* file_name = get_file_name();
		//	save_settings(file_name, sett);
		//}
	}
}
int play(int set[3], bool fiel[50][50]) {
	int ctr = 0;
	int error = 0;
	draw_field(fiel, ctr);
	while (button_is_not_pressed()) {  //до нажатия кнопки цикл работает
		ctr++;
		error = get_cells(fiel, set[0], set[1], set[2]);
		if (error) {
			const char* st_err = process_error(error);
			printf("%s", st_err);
			system("pause");
		}
		draw_field(fiel, ctr);
		Sleep(100);
	}
	return 0;
}
