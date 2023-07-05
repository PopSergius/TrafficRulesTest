#pragma once
#include <string>

using namespace std;

struct question{
	int index;
	string text;
	char unswer;
	bool chek;
	question *next;
};

//клас для основного функціоналу
class Test
{
public:
	question* head = nullptr;
	string name;

	void ReadTest(); // зчитати питання з файлу
	void MakeTest(); // пройти тест
	void SeeTest(); // передивитись питання
	void ChekStatistic(); // подивитись на статистику
	void TempTest(); // пробний тест
};

