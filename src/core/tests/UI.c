#include <stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include "UI.h"
int button_is_not_pressed(){
	int status;
	FILE*file = fopen("button.txt","r");
	fscanf(file,"%d",&status);
	fclose(file);
	if (status == 1){
		remove("button.txt");
		FILE*file = fopen("button.txt","w");
		fprintf(file,"%d",0);
		fclose(file);
		return 1;
	}
	else{
		return 0;
	}
}
int show_menu(int*param){
	scanf("%d",param);
	return 0;
}
int get_settings(int set[3]){
	printf("get_settings\n");
	return 0;
}
int get_cell(bool mas[50][50]){
	printf("get_cell\n");
	return 0;
}
int draw_field(bool mas[50][50], int perem){
	printf("draw_field\n");
	return 0;
}
char* get_file_name() {
	return 0;
}