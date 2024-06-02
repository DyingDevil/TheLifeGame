#include "core.h"
#include <stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include<conio.h>
#include "Testcore.h"
int main(){
	int a = test_start();
	if(a){
		printf("TestCore: Fail %d\n", a);
		return -1;
	}
	else{
		printf("TestCore: Sucsess\n");
	}
	return 0;
}
int test_start(){
	FILE* seq = fopen("seq.txt","w");
	fprintf(seq,"2 3 4 5 6 7 1 8");
	fclose(seq);
	FILE*button = fopen("button.txt","w");
	fprintf(button,"1");
	fclose(button);
	freopen("seq.txt","r",stdin);
	freopen("output.txt","w",stdout);
	start();
	freopen("CON", "w", stdout);
	freopen("seq.txt","r",stdin);
	remove("seq.txt");
	FILE*check = fopen("output.txt","r");
	const char*s1 = "get_settings";
	const char*s2 = "get_cell";
	const char*s3 = "load_game";
	const char*s4 = "load_settings";
	const char*s5 = "save_game";
	const char*s6 = "save_settings";
	const char*s7 = "draw_field";
	const char*s8 = "get_cells";
	const char*s9 = "draw_field";
	char mas[20];
	fscanf(check,"%s",mas);
	for (int i = 0; i < 12; ++i){
		if (mas[i] != s1[i]){
			return -1;
		}
	}
	fscanf(check,"%s",mas);
	for (int i = 0; i < 8; ++i){
		if (mas[i] != s2[i]){
			return -2;
		}
	}
	fscanf(check,"%s",mas);
	for (int i = 0; i < 9; ++i){
		if (mas[i] != s3[i]){
			return -3;
		}
	}
	fscanf(check,"%s",mas);
	for (int i = 0; i < 13; ++i){
		if (mas[i] != s4[i]){
			return -4;
		}
	}
	fscanf(check,"%s",mas);
	for (int i = 0; i < 9; ++i){
		if (mas[i] != s5[i]){
			return -5;
		}
	}
	fscanf(check,"%s",mas);
	for (int i = 0; i < 13; ++i){
		if (mas[i] != s6[i]){
			return -6;
		}
	}
	
	fscanf(check,"%s",mas);
	for (int i = 0; i < 10; ++i){
		if (mas[i] != s7[i]){
			return -7;
		}
	}
	fscanf(check,"%s",mas);
	for (int i = 0; i < 9; ++i){
		if (mas[i] != s8[i]){
			return -8;
		}
	}
	fscanf(check,"%s",mas);
	for (int i = 0; i < 10; ++i){
		if (mas[i] != s9[i]){
			return -9;
		}
	}
	fclose(check);
	remove("button.txt");
	remove("seq.txt");
	remove("output.txt");
	return 0;
}
