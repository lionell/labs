//Автор: Руслан Сакевич
//Умова задачі: 
//Написати програму, яка друкує охайне повідомлення(можна транслітом) "Цю програму написав студент ..., групи ..., курсу ...". 
//Замість ... програма відповідно підставляє ваше прізвище та ім'я, групу, курс.
#include <iostream>
#include <string>

using namespace std;

int main() {
	string name = "Ruslan Sakevych";
	string course = "1st";
	string group = "K-15";
	cout << "This program was written by " << name << "(" << course << "-year student, " << group << " group)" << endl;
	system("pause");
	return 0;
}