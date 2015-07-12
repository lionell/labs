//Автор: Руслан Сакевич
//Умова задачі:
//Модифікувати лабораторну роботу №1 - 3 - 1 наступним чином.
//Користувач задає початковий аргумент x та крок h, де a < x < b, h > 0. Програма,
//починаючи з x, збільшує аргумент з кроком h, поки не досягне кінця інтервалу b
//(значення f(b) не обчислювати).Для кожного аргументу програма виводить рядок з
//п’ятьма числами, вказаними у версії 1.
//Результати виводяться «сторінками».Перший рядок сторінки є заголовком і містить
//позначення x, f_lib(x), f_sum(x), difference, N_adds.Наступні 10 рядків — по 5
//відповідних чисел, вирівняних за правим краєм.
//Після виведення кожної «сторінки», окрім останньої, програма виводить запит, чи
//продовжувати, та підказку : відповідь користувача 1 має означати, що треба
//продовжувати, відповідь 0 — закінчити обробку заданого значення x.Остання
//«сторінка» може мати менше 10 рядків.

#include <iostream>
#include <string>
#include "iolib.h"
#include "mathlib.h"
#include "table.h"

using namespace std;

//Порівнюємо два дійсних числа (a < b)
bool Less(double a, double b) {
	return (!(fabs(a - b) < precision) && (a - b < precision));
}

int main(int argv, char** argc) {
	string userAnswer = "y";
	while (userAnswer == "y") {
		double x = -2.0;
		while (!F_check(x)) {
			cout << "Enter x in range (-1, 1): ";
			while (!TryToReadDouble(x)) {
				cout << "Error! Expected double" << endl;
				cout << "Enter x in range (-1, 1): ";
			}
			if (!F_check(x)) cout << "Error! x should be in range (-1, 1)" << endl;
		}
		//Успішно зчитали дійсне x
		int m = 0;
		cout << "Enter natural m >> ";
		while (!TryToReadNatural(m)) {
			cout << "Error! Expected natural number" << endl;
			cout << "Enter natural m: ";
		}
		//Успішно считали натуральне m
		double h = 0.0;
		while (h <= 0) {
			cout << "Enter h > 0: ";
			while (!TryToReadDouble(h)) {
				cout << "Error! Expected double" << endl;
				cout << "Enter h > 0: ";
			}
			if (h <= 0) cout << "Error! h should be positive" << endl;
		}
		//Успішно зчитали дійсне додатнє h
		string goOn = "1";
		//Створюємо динамічний масив 
		double** data = new double*[rowsOnPage];
		for (int j = 0; j < rowsOnPage; ++j) data[j] = new double[colsCount];
		while (goOn == "1") {
			for (int i = 0; i < rowsOnPage; ++i) {
				for (int j = 0; j < colsCount; ++j) data[i][j] = 0.0;
			}
			int k = 0;
			while (Less(x, rrange) && (k < rowsOnPage)) {
				data[k][0] = x;
				data[k][1] = double(m);
				data[k][2] = F_lib(x, m);
				int n_adds = 0;
				data[k][3] = F_sum(x, m, n_adds);
				data[k][4] = fabs(data[k][2] - data[k][3]);
				data[k][5] = double(n_adds);
				x += h;	
				++k;
			}
			DrawTable(data, k);
			if (Less(x, rrange)) {
				cout << "Go on? (1\\0): ";
				cin >> goOn;
			}
			else goOn = "0";
		}
		//Звільнюємо память
		delete[] data;
		cout << "Do you want to continue? (y\\n): ";
		cin >> userAnswer;
	}
	system("pause");
	return 0;
}