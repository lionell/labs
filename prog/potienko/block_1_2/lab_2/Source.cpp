//Автор: Руслан Сакевич
//Умова задачі: 
//Модифікувати лабораторну роботу таким чином, щоб при введенні некоректних даних вона повідомляла користувача про помилку
//Формат вхідних данних: З клавіатури вводиться стрічка, потрібно вивести на екран єдине число f(x)

#include <iostream>
#include <cmath>
#include <string>

#define Zero 1e-15

using namespace std;

//Намагаємся зчитати з клавіатури дійсне число, повертаємо True у випадку успіху, інакше False
bool TryToReadDouble(double& x) 
{
	bool result = 0;
	cin >> x;
	if (cin.good() && (cin.get() == '\n')) result = 1;
	else {
		cin.clear();
		cin.sync();
	}
	return result;
}

//Обчислення результату за формулою
double Eval(double x) {
	return (1.0f / (sin(1.0f / 5.0f) - log(x) / log(3.0f)));
}

int main(int argv, char** argc) {
	cout << "Enter argument for function f(x) >> ";
	double x = 0;
	//Повідомляємо користувача про помилку, якщо не було введено дійсне число
	if (TryToReadDouble(x) == 0) cout << "Error while reading!" << endl << "Waiting for a double and got string" << endl;
	else {
		cout.precision(15);
		//Виводимо результат у випадку потрапляння x в область визначення функції f(x)
		if ((x > 0) && (abs(sin(1.0f / 5.0f) - log(x) / log(3.0f)) > Zero)) cout << Eval(x) << endl;
		//Повідомляємо користувача про помилку, якщо x не потрапляє в область визначення функції f(x)
		else cout << "Error while evaluating!" << endl << "Argument isn't in domain of function f(x)" << endl;
	}
	system("pause");
	return 0;
}