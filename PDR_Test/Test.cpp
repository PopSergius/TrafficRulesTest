#include "Test.h"
#include <iostream>
#include <fstream>
#include <string>
// метод класу для зчитування з файлу
void Test::ReadTest() {
	// відкриваємо файл
	ifstream read ("questions.txt");
	//змінні
	question *temp = nullptr;
	int index;
	string text;
	char unswer;
	//цикл для зчитування файлу
	while (read >> index >> text >> unswer) {
		//новий вузол у списку
		question* newNode = new question;
		newNode->index = index;
		newNode->text = text;
		newNode->unswer = unswer;
		// запис даних до списку
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
	//закриваємо файл
	read.close();
}
// функція для без повторного вибору питань
question* randomQustions(question* head, int numb) {
	srand(time(nullptr));
	question* selectedHead = nullptr;
	question* selectedTemp = nullptr;

	for (int i = 0; i < numb; i++) {
		question* temp = head;
		int randIndex = rand() % numb;

		//переміщуємось до потрібного питання
		for (int j = 0; j < randIndex; j++) {
			if (temp == nullptr) { break; }
			temp = temp->next;
		}
		if (temp == nullptr) { break; }

		//створюємо новий елемент
		question* newNode = new question();
		newNode->index = temp->index;
		newNode->text = temp->text;
		newNode->unswer = temp->unswer;
		newNode->next = nullptr;

		// переміщуємо новий елемент у новий список
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
//функція для виводу питань
void printList(question* head, int test) {
	question* temp = head;
	char chek;
	//цикл для виводу питань
	while (temp != nullptr) {
		cout << "\nПитання №" << temp->index;
		cout << '\n' << temp->text;
		// перевірка чи це справжній тест
		if (test == 1) { 
			cout << "\nВведіть відповідь => ";
			cin >> chek;
			//перевірка відповіді
			if (chek == temp->unswer) { temp->chek = true; }
			else { temp->chek = false; }
		}
		else if (test == 2) {
			cout << "\nВведіть відповідь => ";
			cin >> chek;
			cout << "\nПравильна відповідь: " << temp->unswer;
		}
		else {
			cout << "\nВідповідь: " << temp->unswer;
		}
		temp = temp->next;
	}
}
//очищення списку
void freeLinkedList(question* head) {
	question* current = head;
	while (current != nullptr) {
		question* temp = current;
		current = current->next;
		delete temp;
	}
}
// метод класу для прохдження тесту
void Test::MakeTest() {
	cout << "\nПідготовка питань ...";
	//рандомні питання
	cout << "\nОсь ваші питання\n";
	question* selectionQuestions = randomQustions(head, 20);
	// вивід питань
	printList(selectionQuestions, 1);
	//вивід результату
	int i = 0;
	while (selectionQuestions != nullptr) {
		if (selectionQuestions->chek) { i++; }
		selectionQuestions = selectionQuestions->next;
	}
	cout << "\nВаш результат: " << i << "/20";
	//запис результату у файл
	ofstream writeResult("statistic.txt", ios::app);
	writeResult << "Користувач: " << name << ", Результат: " << i << "/20\n";
	writeResult.close();
	//очищуємо список
	freeLinkedList(selectionQuestions);

}
//Вивід всіх питань на тест
void Test::SeeTest() {
	printList(head, 3);
}
//Пробний тест
void Test::TempTest() {
	cout << "\nПідготовка питань ...";
	//рандомні питання
	question* selectionQuestions = randomQustions(head, 20);
	// вивід питань
	printList(selectionQuestions, 2);
	//очищуємо список
	freeLinkedList(selectionQuestions);

}
//Вивід результатів
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