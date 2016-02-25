#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
//Бібліотека, яка потрібна для роботи зі змінною кількістю параметрів функції
#include <cstdarg>

//Створимо клас для зручності використання масивів
template <class Type>
class Array {
public:
	int length;
	Type* data;
	//Конструктор по замовчуваню
	Array() {
		length = 0;
		data = 0;
	}
	//Конструктор класу, який має змінну кількість аргументів
	//Потрібен для того, щоб можна було зручно ініціалізувати масив
	Array(int _length, ...) {
		va_list arguments;
		va_start(arguments, _length);
		length = _length;
		data = new Type[length];
		for (int i = 0; i < length; ++i) {
			data[i] = va_arg(arguments, Type);
		}
		va_end(arguments);
	}
	//Деструктор класу
	~Array() {
		//По не зрозумілим причинам не працює :(
		//delete[] data;
	}
	//Перевантаження оператора [] для зручності користування
	Type& operator[](int i) {
		return data[i];
	}
	//Перевантаження оператора = для зручності користування
	Array<Type>& operator=(Array<Type>* example) {
		length = example.length;
		for (int i = 0; i < length; ++i) data[i] = example[i];
	}
	//Друк масиву на екран
	void Print() {
		for (int i = 0; i < length - 1; ++i) std::cout << std::fixed << data[i] << ", ";
		if (length > 0) std::cout << std::fixed << data[length - 1] << endl;
	}
	//Зміна розміру масиву
	void Resize(int _length) {
		length = _length;
		data = new Type[length];
	}
	//Заповнення масиву заданими однаковими елементами
	void Set(Type example) {
		for (int i = 0; i < length; ++i) data[i] = example;
	}
};

const double precision = 1e-2;
//Порівняння двох масивів дійсних чисел
bool IsEqual(Array<double>& first, Array<double>& second) {
	bool result = false;
	//Спочатку порівнюємо довжину
	if (first.length == second.length) {
		int i = 0;
		//Порівнюємо кожну пару елементів з певною точністю
		while ((abs(first[i] - second[i]) < precision) && (i < first.length)) ++i;
		if (i == first.length) result = true;
	}
	return result;
}

#endif