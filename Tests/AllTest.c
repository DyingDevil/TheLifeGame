#include "Testcore.h"
#include "Testerror.h"
#include "Testlogic.h"
#include "TestUI.h"
#include "Testsave.h"
#include "Testsettings.h"
#include <stdio.h>
int main() {
	//if(testCore() == -1)
		//return -1;
	if(TestError() == -1){
		printf("TestError: fail!");
	}
	//if(TestUI() == -1){
	//	printf("TestUI: fail!");
	//}
	if(testLogic()== -1){
		printf("testLogic: fail!");
	}
	if(TestSave()== -1){
		printf("TestSave: fail!");
	}
	if(TestSettings()== -1){
		printf("TestSettings: fail!");
	}
	printf("Sucsess!");
	return 0;
}