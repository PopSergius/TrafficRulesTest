#include "Test.h"
#include <iostream>
#include <fstream>
#include <string>
// ����� ����� ��� ���������� � �����
void Test::ReadTest() {
	// ��������� ����
	ifstream read ("questions.txt");
	//����
	question *temp = nullptr;
	int index;
	string text;
	char unswer;
	//���� ��� ���������� �����
	while (read >> index >> text >> unswer) {
		//����� ����� � ������
		question* newNode = new question;
		newNode->index = index;
		newNode->text = text;
		newNode->unswer = unswer;
		// ����� ����� �� ������
		if (head == nullptr) {
			head = newNode;
			temp = head;
		}
		else {
			temp->next = newNode;
			temp = temp->next;
		}
	}
	temp->next = nullptr;
	//��������� ����
	read.close();
}
// ������� ��� ��� ���������� ������ ������
question* randomQustions(question* head, int numb) {
	srand(time(nullptr));
	question* selectedHead = nullptr;
	question* selectedTemp = nullptr;

	for (int i = 0; i < numb; i++) {
		question* temp = head;
		int randIndex = rand() % numb;

		//����������� �� ��������� �������
		for (int j = 0; j < randIndex; j++) {
			if (temp == nullptr) { break; }
			temp = temp->next;
		}
		if (temp == nullptr) { break; }

		//��������� ����� �������
		question* newNode = new question();
		newNode->index = temp->index;
		newNode->text = temp->text;
		newNode->unswer = temp->unswer;
		newNode->next = nullptr;

		// ��������� ����� ������� � ����� ������
		if (selectedHead == nullptr) {
			selectedHead = newNode;
			selectedTemp = selectedHead;
		}
		else {
			selectedTemp->next = newNode;
			selectedTemp = selectedTemp->next;
		}

		temp = temp->next;
	}

	return selectedHead;
}
//������� ��� ������ ������
void printList(question* head, int test) {
	question* temp = head;
	char chek;
	//���� ��� ������ ������
	while (temp != nullptr) {
		cout << "\n������� �" << temp->index;
		cout << '\n' << temp->text;
		// �������� �� �� �������� ����
		if (test == 1) { 
			cout << "\n������ ������� => ";
			cin >> chek;
			//�������� ������
			if (chek == temp->unswer) { temp->chek = true; }
			else { temp->chek = false; }
		}
		else if (test == 2) {
			cout << "\n������ ������� => ";
			cin >> chek;
			cout << "\n��������� �������: " << temp->unswer;
		}
		else {
			cout << "\n³������: " << temp->unswer;
		}
		temp = temp->next;
	}
}
//�������� ������
void freeLinkedList(question* head) {
	question* current = head;
	while (current != nullptr) {
		question* temp = current;
		current = current->next;
		delete temp;
	}
}
// ����� ����� ��� ���������� �����
void Test::MakeTest() {
	cout << "\nϳ�������� ������ ...";
	//������� �������
	cout << "\n��� ���� �������\n";
	question* selectionQuestions = randomQustions(head, 20);
	// ���� ������
	printList(selectionQuestions, 1);
	//���� ����������
	int i = 0;
	while (selectionQuestions != nullptr) {
		if (selectionQuestions->chek) { i++; }
		selectionQuestions = selectionQuestions->next;
	}
	cout << "\n��� ���������: " << i << "/20";
	//����� ���������� � ����
	ofstream writeResult("statistic.txt", ios::app);
	writeResult << "����������: " << name << ", ���������: " << i << "/20\n";
	writeResult.close();
	//������� ������
	freeLinkedList(selectionQuestions);

}
//���� ��� ������ �� ����
void Test::SeeTest() {
	printList(head, 3);
}
//������� ����
void Test::TempTest() {
	cout << "\nϳ�������� ������ ...";
	//������� �������
	question* selectionQuestions = randomQustions(head, 20);
	// ���� ������
	printList(selectionQuestions, 2);
	//������� ������
	freeLinkedList(selectionQuestions);

}
//���� ����������
void Test::ChekStatistic() {
	ifstream readStatistic("statistic.txt");
	string text;
	int i = 0;
	while (readStatistic >> text) {
		cout << text;
		i++;
		if (i == 4) { cout << '\n'; i = 0; }
	}

}