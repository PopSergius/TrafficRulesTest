#include <iostream>
#include <Windows.h>
#include <string>
#include "Test.h"

using namespace std;
//функція для виводу меню
int menu() {
	int chek = 0;

	cout << "\n1. Почати тест"
		<<"\n2. Переглянути питання"
		<<"\n3. Статистика"
		<<"\n4. Пробний тест"
		<<"\n0. Вихід"
		<<"\n===> ";
	cin >> chek;

	return chek;
}

void main() {
	// для розуміння української
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Test test;
	int chek;

	test.ReadTest();

	while (chek = menu()) {
		switch (chek) {
		case 1: {
			cout << "\nВведіть Прізвище => ";
			cin >> test.name;
			test.MakeTest(); }
			break;
		case 2: test.SeeTest();
			break;
		case 3: test.ChekStatistic();
			break;
		case 4:test.TempTest();
			break;
		default: cout << "\nОберіть значення зі списку";
			break;
		}
		system("pause");
		system("cls");
	}
}