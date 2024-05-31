#include "core.h"
#include "error.h"
#include "logic.h"
#include "UI.h"
#include "save.h"
#include "settings.h"
#include <stdio.h>
int main() {
	if(testCore() == -1)
		return -1;
	if(TestError() == -1)
		return -1;
	if(TestUI() == -1)
		return -1;
	if(TestLogic()== -1)
		return -1;
	if(TestSave()== -1)
		return -1;
	if(TestSettings()== -1)
		return -1;
	return 0;
}