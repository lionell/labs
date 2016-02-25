//Автор: Руслан Сакевич
//Умова задачі: 
//Спочатку програма просить ввести ім'я користувача(або це ім'я задається параметром).
//Потім вона виводить привітання, потім іде процес роботи. Перед завершенням програма виводить повідомлення
//Формат вхідних данних: З клавіатури вводиться стрічка, потрібно вивести на екран єдине число f(x)

#include <iostream>
#include <cmath>
#include <string>
#include "library.h"

#define Zero 1e-15

using namespace std;

//Намагаємся зчитати з клавіатури дійсне число, повертаємо True у випадку успіху, інакше False
bool TryToReadDouble(double& x)
{
	bool result = 0;
	cin >> x;
	if (cin.good() && (cin.get() == '\n')) return 1;
	cin.clear();
	cin.sync();
	return 0;
}

//Обчислення результату за формулою
double Eval(double x) {
	return (1.0f / (sin(1.0f / 5.0f) - log(x) / log(3.0f)));
}

int main(int argv, char** argc) {
	ReadName(argv, argc);
	bool goOn = 1;
	string answer = "";
	while (goOn) {
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
		//Запитуємо у користувача чи не хоче він продовжити роботу з програмою
		cout << "Do you want to continue? (y//n)";
		cin >> answer;
		goOn = (answer == "y");
	}
	WriteCopyright();
	system("pause");
	return 0;
}