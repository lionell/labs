//Автор: Сакевич Руслан
//Модифікувати лабораторну роботу №1 таким чином, щоб програма могла
//працювати	в 3-х режимах(режим	задається параметрами командного рядка):
//1. Кількість елементів та	самі елементи вводить користувач;
//2. Користувач	вводить кількість елементів, масив заповнюється
//випадковими числами;
//3. Програма працює в режимі лабораторної роботи №1.
#include <iostream>
#include <string>
#include <ctime>
#include "array.h"

using namespace std;

const int uniqueElementsCount = 11;

Array<double>* mainFunction(Array<int> input) {
	//Створюємо масив довжиною результат, та заповнюємо його нулями
	Array<double>* result = new Array<double>(11, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	//Рахуємо кулькість відповідних елементів
	for (int i = 0; i < input.length; ++i) result->data[input[i]]++;
	//Рахуємо відсоткове відношення
	for (int i = 0; i < uniqueElementsCount; ++i) result->data[i] = result->data[i] / input.length * 100.0;
	return result;
}

struct Test {
	//Вхідний масив
	Array<int> input;
	//Вихідний масив
	Array<double> output;
	Test(Array<int>& _input, Array<double>& _output) {
		input = _input;
		output = _output;
	}
};

//Набір тестів згенерований та перевірений
//Перша частина тесту - вхідний масив, а інша - вихідний
//В конструкторі масиву перше число вказує кількість елементів у масиві
Test tests[] = {
	Test(Array<int>(1, 0),
	Array<double>(11, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)),
	Test(Array<int>(7, 1, 2, 3, 4, 5, 6, 7),
	Array<double>(11, 0.0, 14.29, 14.29, 14.29, 14.29, 14.29, 14.29, 14.29, 0.0, 0.0, 0.0)),
	Test(Array<int>(10, 0, 0, 0, 1, 3, 2, 2, 0, 1, 7),
	Array<double>(11, 40.0, 20.0, 20.0, 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0)),
	Test(Array<int>(9, 7, 7, 3, 2, 2, 9, 8, 8, 9),
	Array<double>(11, 0.0, 0.0, 22.22, 11.11, 0.0, 0.0, 0.0, 22.22, 22.22, 22.22, 0.0)),
	Test(Array<int>(11, 7, 7, 3, 2, 2, 9, 8, 8, 9, 0, 0),
	Array<double>(11, 18.18, 0.0, 18.18, 9.09, 0.0, 0.0, 0.0, 18.18, 18.18, 18.18, 0.0)),
	Test(Array<int>(12, 7, 7, 3, 2, 2, 9, 8, 8, 9, 8, 9, 1),
	Array<double>(11, 0.0, 8.33, 16.67, 8.33, 0.0, 0.0, 0.0, 16.67, 25.0, 25.0, 0.0)),
	Test(Array<int>(5, 2, 9, 8, 8, 9),
	Array<double>(11, 0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40.0, 40.0, 0.0)),
	Test(Array<int>(2, 7, 7),
	Array<double>(11, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0)),
	Test(Array<int>(3, 1, 2, 3),
	Array<double>(11, 0.0, 33.33, 33.33, 33.33, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)),
	Test(Array<int>(8, 8, 8, 2, 2, 9, 8, 8, 9),
	Array<double>(11, 0.0, 0.0, 25.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 25.0, 0.0))
};

const int testsCount = 10;

void Help() {
	cout << "To launch program type in command line [filename] --mode [numberofmode]." << endl;
	cout << "There are three possible modes: " << endl;
	cout << "1. Program will be launched in User Test Mode." << endl;
	cout << "2. Program will be launched in SemiUser Test Mode" << endl;
	cout << "3. Program will be launched in Automatic Test Mode" << endl;
}

void UserTest() {
	cout << "Welcome to User Test Mode" << endl;
	cout << "Enter numer of elements: ";
	int n = 0;
	cin >> n;
	Array<int> input;
	input.Resize(n);
	cout << "Enter elements of input array: ";
	for (int i = 0; i < n; ++i) cin >> input[i];
	Array<double>& output = *mainFunction(input);
	cout << "Output: ";
	output.Print();
}

void SemiUserTest() {
	cout << "Welcome to SemiUser Test Mode" << endl;
	cout << "Enter number of elements: ";
	int n = 0;
	cin >> n;
	Array<int> input;
	input.Resize(n);
	//Задаємо зерно необхідне для генерації псевдовипадкових чисел
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < n; ++i) input[i] = rand() % 11;
	cout << "Generated input: ";
	input.Print();
	Array<double>& output = *mainFunction(input);
	cout << "Output: ";
	output.Print();
}

void AutomaticTest() {
	cout << "Welcome to Automatic Test Mode!" << endl;
	//Рахуємо загальну кількість пройдених тестів
	int totalPassed = 0;
	for (int i = 0; i < testsCount; ++i) {
		cout << "Test: " << i << endl;
		cout << "Input: ";
		tests[i].input.Print();
		//Отримуємо результат основної функції
		Array<double>& output = *mainFunction(tests[i].input);
		cout << "Output: ";
		output.Print();
		cout << "Result: ";
		//Порівнюємо масиви результатів
		bool result = IsEqual(tests[i].output, output);
		cout << ((result) ? "Passed" : "Failed");
		totalPassed += (result) ? 1 : 0;
		cout << endl << endl;
	}
	cout << "Total result: " << totalPassed << " of " << testsCount << endl;
}

int main(int argv, char** argc) {
	//Задаємо точність виведення данних дійсного типу
	cout.precision(2);
	if ((argv > 2) && (strcmp(argc[1], "--mode") == 0)) {
		if (strcmp(argc[2], "1") == 0) {
			//Користувачьке тестування(Кількість елементів та самі елементи вводить користувач)
			UserTest();
		}
		else if (strcmp(argc[2], "2") == 0) {
			//Напівкористувацьке тестування(Користувач	вводить кількість елементів, масив заповнюється випадковими числами)
			SemiUserTest();
		}
		else if (strcmp(argc[2], "3") == 0) {
			//Автоматичне тестування(Лабораторна робота №1)
			AutomaticTest();
		}
		else cout << "Error! Unknown mode." << endl;
	}
	else {
		cout << "Error! Unknown parameters." << endl;
		//Викликаємо функції, що відображає допомогу в користуванні програмою
		Help();

	}
	system("pause");
	return 0;
}