#include <iostream>
#include <Windows.h>
#include <string>
#include "Test.h"

using namespace std;
//������� ��� ������ ����
int menu() {
	int chek = 0;

	cout << "\n1. ������ ����"
		<<"\n2. ����������� �������"
		<<"\n3. ����������"
		<<"\n4. ������� ����"
		<<"\n0. �����"
		<<"\n===> ";
	cin >> chek;

	return chek;
}

void main() {
	// ��� �������� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Test test;
	int chek;

	test.ReadTest();

	while (chek = menu()) {
		switch (chek) {
		case 1: {
			cout << "\n������ ������� => ";
			cin >> test.name;
			test.MakeTest(); }
			break;
		case 2: test.SeeTest();
			break;
		case 3: test.ChekStatistic();
			break;
		case 4:test.TempTest();
			break;
		default: cout << "\n������ �������� � ������";
			break;
		}
		system("pause");
		system("cls");
	}
}