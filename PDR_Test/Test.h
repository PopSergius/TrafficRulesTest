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

//���� ��� ��������� �����������
class Test
{
public:
	question* head = nullptr;
	string name;

	void ReadTest(); // ������� ������� � �����
	void MakeTest(); // ������ ����
	void SeeTest(); // ������������ �������
	void ChekStatistic(); // ���������� �� ����������
	void TempTest(); // ������� ����
};

