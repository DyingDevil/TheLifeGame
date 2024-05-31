#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "test_error.h"
int TestError(){
	int test = test_process_error();
	freopen("file_errors.txt", "w", stdout);
	if(!test){
		printf("Sucsess");
	}
	else{
		printf("Fail %d", test);
		return -1;
	}
	fclose(stdout);
	return 0;
}
int test_process_error(){
	const char* err1 = "Error: lifeCondition > 8. An impossible condition for the origin of life";
	const char* err2 = "Error: lifeCondition < 0. An impossible condition for the origin of life";
	const char* err3 = "Error: bottomLifeVal > topLifeVal. The boundaries for the continuation of life are set incorrectly";
	const char* err4 = "Error: bottomLifeVal > 8. Incorrect lower bound for the continuation of life";
	const char* err5 = "Error: bottomLifeVal < 0. Incorrect lower bound for the continuation of life";
	const char* err6 = "Error: topLifeVal > 8. Incorrect upper bound for the continuation of life ";
	const char* err7 = "Error: topLifeVal < 0. Incorrect upper bound for the continuation of life";
	const char* err8 = "Error: out of range field. Chosen coordinate is out of range";
	const char* err9 = "Error: missing digit. Set the coordinates in numbers";
	const char* err10 = "Error: unknown menu item. Choose an item in range ";
	const char* err11 = "Error: invalid file name. Choose correct file name";
	const char* err12 = "Error: file is not found. Choose an existing file";
	const char* err13 = "Error: file is empty. Fill the file";
	const char* err14 = "Error: file is not saved. Try again ";
	const char* err15 = "Unknown error";
	const char* result1 = process_error(-1);
	const char* result2 = process_error(-2);
	const char* result3 = process_error(-3);
	const char* result4 = process_error(-4);
	const char* result5 = process_error(-5);
	const char* result6 = process_error(-6);
	const char* result7 = process_error(-7);
	const char* result8 = process_error(-8);
	const char* result9 = process_error(-9);
	const char* result10 = process_error(-10);
	const char* result11 = process_error(-11);
	const char* result12 = process_error(-12);
	const char* result13 = process_error(-13);
	const char* result14 = process_error(-14);
	const char* result15 = process_error(-21);
	for(int i = 0; i < 72; ++i){
		if (err1[i] != result1[i]){
			return -1;
		}
	}
	for(int i = 0; i < 72; ++i){
		if (err2[i] != result2[i]){
			return -2;
		}
	}
	for(int i = 0; i < 98; ++i){
		if (err3[i] != result3[i]){
			return -3;
		}
	}
	for(int i = 0; i < 76; ++i){
		if (err4[i] != result4[i]){
			return -4;
		}
	}
	for(int i = 0; i < 76; ++i){
		if (err5[i] != result5[i]){
			return -5;
		}
	}
	for(int i = 0; i < 73; ++i){
		if (err6[i] != result6[i]){
			return -6;
		}
	}
	for(int i = 0; i < 73; ++i){
		if (err7[i] != result7[i]){
			return -7;
		}
	}
	for(int i = 0; i < 61; ++i){
		if (err8[i] != result8[i]){
			return -8;
		}
	}
	for(int i = 0; i < 52; ++i){
		if (err9[i] != result9[i]){
			return -9;
		}
	}
	for(int i = 0; i < 50; ++i){
		if (err10[i] != result10[i]){
			return -10;
		}
	}
	for(int i = 0; i < 50; ++i){
		if (err11[i] != result11[i]){
			return -11;
		}
	}
	for(int i = 0; i < 49; ++i){
		if (err12[i] != result12[i]){
			return -12;
		}
	}
	for(int i = 0; i < 35; ++i){
		if (err13[i] != result13[i]){
			return -13;
		}
	}
	for(int i = 0; i < 35; ++i){
		if (err14[i] != result14[i]){
			return -14;
		}
	}
	for(int i = 0; i < 13; ++i){
		if (err15[i] != result15[i]){
			return -15;
		}
	}
	return 0;
	
}
