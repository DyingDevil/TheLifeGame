#include <stdio.h>
#include "UI.h"
#include "TestUI.h"
#include <stdlib.h>
#include <stdbool.h>
#include<conio.h>
int TestUI(){
	int res1 = TestDrawField();
	int res2 = TestGetCell();
	int res3 = TestGetSettings();
	int res4 = TestShowMenu();
	int count = 0;
	if(!res1){
		printf("TestDrawField: Sucsess!\n");
	}
	else{
		printf("TestDrawField: Fail!\n");
		count++;
	}
	if(!res2){
		printf("TestGetCell: Sucsess!\n");
	}
	else{
		printf("TestGetCell: Fail! %d\n",res2);
		count++;
	}
	if(!res3){
		printf("TestGetSettings: Sucsess!\n");
	}
	else{
		printf("TestGetSettings: Fail!\n");
		count++;
	}
	if(!res4){
		printf("TestShowMenu: Sucsess!\n");
	}
	else{
		printf("TestShowMenu: Fail! %d\n",res4);
		count++;
	}

	return -count;
}
int TestShowMenu(){
	unsigned char* expected = "#################\n# 1.   Start    #\n# 2. Set rules  #\n# 3. Set cells  #\n# 4. Load game  #\n# 5. Load rules #\n# 6. Save game  #\n# 7. Save rules #\n# 8.    Exit    #\n#################\n";
	int a;
	FILE* in = fopen("testShowMenuIn.txt","w");
	fprintf(in,"1 2 3 4 5 6 7 8");
	fclose(in);
	freopen("testShowMenuIn.txt","r", stdin);
	freopen("testShowMenuOut.txt","w", stdout);
	show_menu(&a);
	freopen("CON","w", stdout);
	if(a != 1){
		fclose(stdin);
		return -1;
	}
	freopen("TrashData.txt","w", stdout);
	show_menu(&a);
	if(a != 2){
		fclose(stdin);
		return -2;
	}
	show_menu(&a);
	if(a != 3){
		fclose(stdin);
		return -3;
	}
	show_menu(&a);
	if(a != 4){
		fclose(stdin);
		return -4;
	}
	show_menu(&a);
	if(a != 5){
		fclose(stdin);
		return -5;
	}
	show_menu(&a);
	if(a != 6){
		fclose(stdin);
		return -6;
	}
	show_menu(&a);
	if(a != 7){
		fclose(stdin);
		return -7;
	}
	show_menu(&a);
	if(a != 8){
		fclose(stdin);
		return -8;
	}
	remove("TrashData.txt");
	freopen("CON","w", stdout);
	fclose(stdin);
	FILE* comparison = fopen("testShowMenuOut.txt", "r");
	fgetc(comparison);
	for(int i = 0; i < 180; i++){
		unsigned char get = fgetc(comparison);
		if(expected[i]!=get){
			fclose(comparison);
			return -9;
		}
	}
	fclose(comparison);
	
	
	
	remove("testShowMenuIn.txt");
	remove("testShowMenuOut.txt");
	return 0;
}

int TestDrawField(){
	unsigned char* expected[52][102];
	expected[0][0] = 201;
	for (int i = 1; i < 101; ++i) {
		expected[0][i] = 205;
	}
	expected[0][101] = 187;
	for (int i = 1; i < 51; ++i) {
		expected[i][0] = 186;
		for (int j = 1; j < 101; ++j) {
			expected[i][j] = 219;
		}
		expected[i][101] = 186;
	}
	expected[51][0] = 200;
	for (int i = 1; i < 101; ++i) {
		expected[51][i] = 205;
	}
	expected[51][101] = 188;
	
	for (int i = 9; i < 19; ++i) {
		expected[3][i] = 176;
	}
	// for (int i = 0; i < 52; ++i) {
		// for (int j = 0; j < 102; ++j) {
			// printf("%c", expected[i][j]);
		// }
		// printf("\t%d\n",i);
	// }
	
	
	
	bool field[50][50] = {0, };
	for (int i = 4; i < 9; ++i) {
		field[2][i] = 1;
	}
	freopen("testIODraw.txt","w", stdout);
	draw_field(field,0);
	freopen("CON","w", stdout);
	FILE* comparison = fopen("testIODraw.txt", "r");
	freopen("CON","w", stdout);
	for(int i = 0; i<52;++i){
		for(int j = 0; j<102;++j){
			unsigned char curSymb = fgetc(comparison);
			if(curSymb!=expected[i][j]){
				fclose(comparison);

				remove("testIODraw.txt");
				return -1;
			}
		}
		getc(comparison);
	}
	fclose(comparison);
	remove("testIODraw.txt");
	
	return 0;
}
int TestGetCell(){
	bool field[50][50] = {0, };
	bool expected[50][50] = {0, };
	expected[5][5] = 1;
	expected[6][7] = 1;
	FILE* testInput = fopen("GetUserArtificialData1.txt","w");
	fprintf(testInput,"5 5 y 6 7 n 78 a");
	fclose(testInput);
	freopen("TrashData.txt","w", stdout);
	freopen("GetUserArtificialData1.txt","r",stdin);
	if(!get_cell(field)){
		for(int i = 0; i < 50; i++){
			for(int j = 0; j < 50; j++){
				if(field[i][j]!=expected[i][j]){
					fclose(stdin);
					return -1;
				}
			}
		}
	}
	if(get_cell(field) != -8){
		fclose(stdin);
		return -2;
	}
	if(get_cell(field) != -9){
		fclose(stdin);
		return -3;
	}
	remove("TrashData.txt");
	fclose(stdin);
	remove("GetUserArtificialData1.txt");
	return 0;
}
int TestGetSettings(){
	int settings[3] = {0, };
	int expected[3] = {5, 4, 7};
	
	FILE* testInput = fopen("GetUserArtificialData2.txt","w");
	fprintf(testInput,"1 5 2 4 3 7 4");
	fclose(testInput);
	freopen("GetUserArtificialData2.txt","r",stdin);
	if(!get_settings(settings)){
		if(settings[0]!=expected[0] || settings[1]!=expected[1] || settings[2]!=expected[2]){
			fclose(stdin);
			return -1;
		}
	}
	fclose(stdin);
	remove("GetUserArtificialData2.txt");
	return 0;
}