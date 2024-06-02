#ifndef UI_H
#define UI_H
#include <stdbool.h>
int show_menu(int* choise);
int get_cell(bool field[50][50]);
int get_settings(int settings[3]);
int draw_field(bool field[50][50], int ctr);
char* get_file_name();
void SetPosition(int x, int Y);
int button_is_not_pressed();
#endif
