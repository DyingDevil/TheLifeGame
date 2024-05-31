#include "error.h"

const char* process_error(int exception) {
	switch (exception) {
	case -1:
		//около 1 клетки не может быть задано больше 8 живых клеток для условия зарождения жизни
		return "Error: lifeCondition > 8. An impossible condition for the origin of life";
	case -2:
		//около 1 клетки не может быть задано меньше 0 живых клеток для условия зарождения жизни
		return "Error: lifeCondition < 0. An impossible condition for the origin of life";
	case -3:
		//нижняя граница должна быть меньше верхней для продолжения жизни клетки
		return "Error: bottomLifeVal > topLifeVal. The boundaries for the continuation of life are set incorrectly";
	case -4:
		//Некорректная нижняя граница для продолжения жизни (слишком большая)
		return "Error: bottomLifeVal > 8. Incorrect lower bound for the continuation of life";
	case -5:
		//Некорректная нижняя граница для продолжения жизни (не может быть меньше 0)
		return "Error: bottomLifeVal < 0. Incorrect lower bound for the continuation of life";
	case -6:
		//Некорректная верхняя граница для продолжения жизни (слишком большая)
		return "Error: topLifeVal > 8. Incorrect upper bound for the continuation of life ";
	case -7:
		//Некорректная верхняя граница для продолжения жизни (не может быть меньше 0)
		return "Error: topLifeVal < 0. Incorrect upper bound for the continuation of life";
	case -8:
		//Выход за пределы поля (неверные координаты)
		return "Error: out of range field. Chosen coordinate is out of range";
	case -9:
		//В кооординаты введены не цифры
		return "Error: missing digit. Set the coordinates in numbers";
	case -10:
		//Выбран несуществующий пункт меню
		return "Error: unknown menu item. Choose an item in range ";
	case -11:
		//Неправильное название файла
		return "Error: invalid file name. Choose correct file name";
	case -12:
		//Файл отсутствует
		return "Error: file is not found. Choose an existing file";
	case -13:
		//Файл пустой
		return "Error: file is empty. Fill the file";
	case -14:
		//Файл не сохранен
		return "Error: file is not saved. Try again ";
	default:
		//Подан неизвестный код ошибки
		return "Unknown error";

	}
}