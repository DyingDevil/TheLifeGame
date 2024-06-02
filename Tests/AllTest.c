#include "Testcore.h"
#include "Testerror.h"
#include "Testlogic.h"
#include "TestUI.h"
#include "Testsave.h"
#include "Testsettings.h"
#include <stdio.h>
int main() {
	int c = 0;
	if(TestError() == -1){
		printf("TestError: fail!\n");
		c++;
	}else{
		printf("TestError: Sucsess!\n");
	}
	if(TestUI() == -1){
		printf("TestUI: fail!\n");
		c++;
	}else{
		printf("TestUI: Sucsess!\n");
	}
	if(testLogic()== -1){
		printf("testLogic: fail!\n");
		c++;
	}else{
		printf("testLogic: Sucsess!\n");
	}
	if(TestSave()== -1){
		printf("TestSave: fail!\n");
		c++;
	}else{
		printf("TestSave: Sucsess!\n");
	}
	if(TestSettings()== -1){
		printf("TestSettings: fail!\n");
		c++;
	}else{
		printf("TestSettings: Sucsess!\n");
	}
	remove("TrashData.txt");
	if(!c){
		printf("\n\n\nMainTest: Sucsess!\n\n\n");
	}else{
		printf("\n\n\nMainTest: Fail!\n\n\n");
	}
	return 0;
}