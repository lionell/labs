//Автор: Руслан Сакевич
//Умова задачі: 
//Програму запитує у користувача його ім'я, а потім виводить охайне повідомлення "Привіт ...!", де замість ... підставляє ім'я, що ввів користувач.
//Формат віхдних даних: Програма читає з клавіатури стрічку.
#include <iostream>
#include <string>

using namespace std;

int main() {
	string name = "";
	cout << "Enter your name: ";
	cin >> name;
	cout << "Hello " << name << "!" << endl;
	system("pause");
	return 0;
}