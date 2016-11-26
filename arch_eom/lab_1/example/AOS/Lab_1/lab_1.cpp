#include <iostream>
#include <cfloat>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int counter = 100000000;

//функция перевода clock_t => количество операций в секунду
double getAmountOfOperations(clock_t time) {
    double res = time;
    res /= CLOCKS_PER_SEC;
    res /= counter;
    res /= 19;
    res = 1 / res;
    return res;
}

//массив базовых операций
char operations[4] = {'+', '-', '*', '/'};

//template <typename T>

//функция для подсчета скорости работы integer, которая на вход принимает string type для дальнейшего вывода 
//названия типа на экран
void getInt(string type) {
       vector <double> res;
       int var1 = 546374374, var2 = 344656456, var3 = 945347123, var4 = 845123432, var5 = 345123934, var6 = 456123746,
            var7 = 123746934, var8 = 123423424, var9 = 765384294, var10 = 912756174, var11 = 473912734,
            var12 = 367198234, var13 = 483734205, var14 = 397436834, var15 = 194536241, var16 = 341230645,
            var17 = 945321745, var18 = 701438209, var19 = 190345123, var20 = 734218934;

    clock_t start_time = 0, end_time = 0, common_time, time_of_loop;


    start_time = clock();
    for (int i = 0; i < counter; ++i) {

    }
    end_time = clock();
    time_of_loop = end_time - start_time;

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 += var2;
        var2 += var3;
        var3 += var4;
        var4 += var5;
        var5 += var6;
        var6 += var7;
        var7 += var8;
        var8 += var9;
        var9 += var10;
        var10 += var11;
        var11 += var12;
        var12 += var13;
        var13 += var14;
        var14 += var15;
        var15 += var16;
        var16 += var17;
        var17 += var18;
        var18 += var19;
        var19 += var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    for (int i = 0; i < counter; ++i) {

    }

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 -= var2;
        var2 -= var3;
        var3 -= var4;
        var4 -= var5;
        var5 -= var6;
        var6 -= var7;
        var7 -= var8;
        var8 -= var9;
        var9 -= var10;
        var10 -= var11;
        var11 -= var12;
        var12 -= var13;
        var13 -= var14;
        var14 -= var15;
        var15 -= var16;
        var16 -= var17;
        var17 -= var18;
        var18 -= var19;
        var19 -= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 *= var2;
        var2 *= var3;
        var3 *= var4;
        var4 *= var5;
        var5 *= var6;
        var6 *= var7;
        var7 *= var8;
        var8 *= var9;
        var9 *= var10;
        var10 *= var11;
        var11 *= var12;
        var12 *= var13;
        var13 *= var14;
        var14 *= var15;
        var15 *= var16;
        var16 *= var17;
        var17 *= var18;
        var18 *= var19;
        var19 *= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 1; i <= counter; i++) {
        var1 /= 2;
        var2 /= 2;
        var3 /= 2;
        var4 /= 2;
        var5 /= 2;
        var6 /= 2;
        var7 /= 2;
        var8 /= 2;
        var9 /= 2;
        var10 /= 2;
        var11 /= 2;
        var12 /= 2;
        var13 /= 2;
        var14 /= 2;
        var15 /= 2;
        var16 /= 2;
        var17 /= 2;
        var18 /= 2;
        var19 /= 2;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    //пробегаемся по вектору и ищем максимальный эл-т
    double maxE = *max_element(res.begin(), res.end());
    double percent;
    double amount;
    //выводим скорость работы каждой операции в графичеком и в процентном соотношении 
    for (int i = 0; i < res.size(); i++) {
        percent = floor(res[i] / maxE * 100);
        amount = percent / 2;
        cout << operations[i];
        cout.width(10);
        cout << type;
        cout.width(15);
        cout << res[i];
        cout.width(18);
        for (int j = 0; j < amount; j++) {
            cout << "#";
        }
        cout << setw(10);
        cout <<  percent << "%" << endl;
    }
    cout << endl;
    res.clear();
}

void getLong(string type) {
    vector <double> res;
    long var1 = 546374374, var2 = 344656456, var3 = 945347123, var4 = 845123432, var5 = 345123934, var6 = 456123746,
            var7 = 123746934, var8 = 123423424, var9 = 765384294, var10 = 912756174, var11 = 473912734,
            var12 = 367198234, var13 = 483734205, var14 = 397436834, var15 = 194536241, var16 = 341230645,
            var17 = 945321745, var18 = 701438209, var19 = 190345123, var20 = 734218934;

    clock_t start_time = 0, end_time = 0, common_time, time_of_loop;


    start_time = clock();
    for (int i = 0; i < counter; ++i) {

    }
    end_time = clock();
    time_of_loop = end_time - start_time;

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 += var2;
        var2 += var3;
        var3 += var4;
        var4 += var5;
        var5 += var6;
        var6 += var7;
        var7 += var8;
        var8 += var9;
        var9 += var10;
        var10 += var11;
        var11 += var12;
        var12 += var13;
        var13 += var14;
        var14 += var15;
        var15 += var16;
        var16 += var17;
        var17 += var18;
        var18 += var19;
        var19 += var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    for (int i = 0; i < counter; ++i) {

    }

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 -= var2;
        var2 -= var3;
        var3 -= var4;
        var4 -= var5;
        var5 -= var6;
        var6 -= var7;
        var7 -= var8;
        var8 -= var9;
        var9 -= var10;
        var10 -= var11;
        var11 -= var12;
        var12 -= var13;
        var13 -= var14;
        var14 -= var15;
        var15 -= var16;
        var16 -= var17;
        var17 -= var18;
        var18 -= var19;
        var19 -= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 *= var2;
        var2 *= var3;
        var3 *= var4;
        var4 *= var5;
        var5 *= var6;
        var6 *= var7;
        var7 *= var8;
        var8 *= var9;
        var9 *= var10;
        var10 *= var11;
        var11 *= var12;
        var12 *= var13;
        var13 *= var14;
        var14 *= var15;
        var15 *= var16;
        var16 *= var17;
        var17 *= var18;
        var18 *= var19;
        var19 *= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 1; i <= counter; i++) {
        var1 /= 2;
        var2 /= 2;
        var3 /= 2;
        var4 /= 2;
        var5 /= 2;
        var6 /= 2;
        var7 /= 2;
        var8 /= 2;
        var9 /= 2;
        var10 /= 2;
        var11 /= 2;
        var12 /= 2;
        var13 /= 2;
        var14 /= 2;
        var15 /= 2;
        var16 /= 2;
        var17 /= 2;
        var18 /= 2;
        var19 /= 2;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    double maxE = *max_element(res.begin(), res.end());
    double percent;
    double amount;
    for (int i = 0; i < res.size(); i++) {
        percent = floor(res[i] / maxE * 100);
        amount = percent / 2;
        cout << operations[i];
        cout.width(10);
        cout << type;
        cout.width(15);
        cout << res[i];
        cout.width(18);
        for (int j = 0; j < amount; j++) {
            cout << "#";
        }
        cout << setw(10);
        cout <<  percent << "%" << endl;
    }
    cout << endl;
    res.clear();
}

void getChar(string type) {
    vector <double> res;
    char var1 = 1, var2 = 4, var3 = 3, var4 = 8, var5 = 3, var6 = 9,
            var7 = 8, var8 = 3, var9 = 2, var10 = 4, var11 = 3,
            var12 = 8, var13 = 5, var14 = 4, var15 = 3, var16 = 4,
            var17 = 7, var18 = 4, var19 = 4, var20 = 7;

    clock_t start_time = 0, end_time = 0, common_time, time_of_loop;


    start_time = clock();
    for (int i = 0; i < counter; ++i) {

    }
    end_time = clock();
    time_of_loop = end_time - start_time;

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 += var2;
        var2 += var3;
        var3 += var4;
        var4 += var5;
        var5 += var6;
        var6 += var7;
        var7 += var8;
        var8 += var9;
        var9 += var10;
        var10 += var11;
        var11 += var12;
        var12 += var13;
        var13 += var14;
        var14 += var15;
        var15 += var16;
        var16 += var17;
        var17 += var18;
        var18 += var19;
        var19 += var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    for (int i = 0; i < counter; ++i) {

    }

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 -= var2;
        var2 -= var3;
        var3 -= var4;
        var4 -= var5;
        var5 -= var6;
        var6 -= var7;
        var7 -= var8;
        var8 -= var9;
        var9 -= var10;
        var10 -= var11;
        var11 -= var12;
        var12 -= var13;
        var13 -= var14;
        var14 -= var15;
        var15 -= var16;
        var16 -= var17;
        var17 -= var18;
        var18 -= var19;
        var19 -= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 *= var2;
        var2 *= var3;
        var3 *= var4;
        var4 *= var5;
        var5 *= var6;
        var6 *= var7;
        var7 *= var8;
        var8 *= var9;
        var9 *= var10;
        var10 *= var11;
        var11 *= var12;
        var12 *= var13;
        var13 *= var14;
        var14 *= var15;
        var15 *= var16;
        var16 *= var17;
        var17 *= var18;
        var18 *= var19;
        var19 *= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 1; i <= counter; i++) {
        var1 /= 2;
        var2 /= 2;
        var3 /= 2;
        var4 /= 2;
        var5 /= 2;
        var6 /= 2;
        var7 /= 2;
        var8 /= 2;
        var9 /= 2;
        var10 /= 2;
        var11 /= 2;
        var12 /= 2;
        var13 /= 2;
        var14 /= 2;
        var15 /= 2;
        var16 /= 2;
        var17 /= 2;
        var18 /= 2;
        var19 /= 2;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    double maxE = *max_element(res.begin(), res.end());
    double percent;
    double amount;
    for (int i = 0; i < res.size(); i++) {
        percent = floor(res[i] / maxE * 100);
        amount = percent / 2;
        cout << operations[i];
        cout.width(10);
        cout << type;
        cout.width(15);
        cout << res[i];
        cout.width(18);
        for (int j = 0; j < amount; j++) {
            cout << "#";
        }
        cout << setw(10);
        cout <<  percent << "%" << endl;
    }
    cout << endl;
    res.clear();
}

void getFloat(string type) {
    vector <double> res;
    float var1 = 546374374, var2 = 344656456, var3 = 945347123, var4 = 845123432, var5 = 345123934, var6 = 456123746,
            var7 = 123746934, var8 = 123423424, var9 = 765384294, var10 = 912756174, var11 = 473912734,
            var12 = 367198234, var13 = 483734205, var14 = 397436834, var15 = 194536241, var16 = 341230645,
            var17 = 945321745, var18 = 701438209, var19 = 190345123, var20 = 734218934;

    clock_t start_time = 0, end_time = 0, common_time, time_of_loop;


    start_time = clock();
    for (int i = 0; i < counter; ++i) {

    }
    end_time = clock();
    time_of_loop = end_time - start_time;

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 += var2;
        var2 += var3;
        var3 += var4;
        var4 += var5;
        var5 += var6;
        var6 += var7;
        var7 += var8;
        var8 += var9;
        var9 += var10;
        var10 += var11;
        var11 += var12;
        var12 += var13;
        var13 += var14;
        var14 += var15;
        var15 += var16;
        var16 += var17;
        var17 += var18;
        var18 += var19;
        var19 += var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    for (int i = 0; i < counter; ++i) {

    }

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 -= var2;
        var2 -= var3;
        var3 -= var4;
        var4 -= var5;
        var5 -= var6;
        var6 -= var7;
        var7 -= var8;
        var8 -= var9;
        var9 -= var10;
        var10 -= var11;
        var11 -= var12;
        var12 -= var13;
        var13 -= var14;
        var14 -= var15;
        var15 -= var16;
        var16 -= var17;
        var17 -= var18;
        var18 -= var19;
        var19 -= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 *= var2;
        var2 *= var3;
        var3 *= var4;
        var4 *= var5;
        var5 *= var6;
        var6 *= var7;
        var7 *= var8;
        var8 *= var9;
        var9 *= var10;
        var10 *= var11;
        var11 *= var12;
        var12 *= var13;
        var13 *= var14;
        var14 *= var15;
        var15 *= var16;
        var16 *= var17;
        var17 *= var18;
        var18 *= var19;
        var19 *= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 1; i <= counter; i++) {
        var1 /= 2;
        var2 /= 2;
        var3 /= 2;
        var4 /= 2;
        var5 /= 2;
        var6 /= 2;
        var7 /= 2;
        var8 /= 2;
        var9 /= 2;
        var10 /= 2;
        var11 /= 2;
        var12 /= 2;
        var13 /= 2;
        var14 /= 2;
        var15 /= 2;
        var16 /= 2;
        var17 /= 2;
        var18 /= 2;
        var19 /= 2;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    double maxE = *max_element(res.begin(), res.end());
    double percent;
    double amount;
    for (int i = 0; i < res.size(); i++) {
        percent = floor(res[i] / maxE * 100);
        amount = percent / 2;
        cout << operations[i];
        cout.width(10);
        cout << type;
        cout.width(15);
        cout << res[i];
        cout.width(18);
        for (int j = 0; j < amount; j++) {
            cout << "#";
        }
        cout << setw(10);
        cout <<  percent << "%" << endl;
    }
    cout << endl;
    res.clear();
}

void getDouble(string type) {
    vector <double> res;
    double var1 = 546374374, var2 = 344656456, var3 = 945347123, var4 = 845123432, var5 = 345123934, var6 = 456123746,
            var7 = 123746934, var8 = 123423424, var9 = 765384294, var10 = 912756174, var11 = 473912734,
            var12 = 367198234, var13 = 483734205, var14 = 397436834, var15 = 194536241, var16 = 341230645,
            var17 = 945321745, var18 = 701438209, var19 = 190345123, var20 = 734218934;

    clock_t start_time = 0, end_time = 0, common_time, time_of_loop;


    start_time = clock();
    for (int i = 0; i < counter; ++i) {

    }
    end_time = clock();
    time_of_loop = end_time - start_time;

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 += var2;
        var2 += var3;
        var3 += var4;
        var4 += var5;
        var5 += var6;
        var6 += var7;
        var7 += var8;
        var8 += var9;
        var9 += var10;
        var10 += var11;
        var11 += var12;
        var12 += var13;
        var13 += var14;
        var14 += var15;
        var15 += var16;
        var16 += var17;
        var17 += var18;
        var18 += var19;
        var19 += var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    for (int i = 0; i < counter; ++i) {

    }

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 -= var2;
        var2 -= var3;
        var3 -= var4;
        var4 -= var5;
        var5 -= var6;
        var6 -= var7;
        var7 -= var8;
        var8 -= var9;
        var9 -= var10;
        var10 -= var11;
        var11 -= var12;
        var12 -= var13;
        var13 -= var14;
        var14 -= var15;
        var15 -= var16;
        var16 -= var17;
        var17 -= var18;
        var18 -= var19;
        var19 -= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 0; i < counter; i++) {
        var1 *= var2;
        var2 *= var3;
        var3 *= var4;
        var4 *= var5;
        var5 *= var6;
        var6 *= var7;
        var7 *= var8;
        var8 *= var9;
        var9 *= var10;
        var10 *= var11;
        var11 *= var12;
        var12 *= var13;
        var13 *= var14;
        var14 *= var15;
        var15 *= var16;
        var16 *= var17;
        var17 *= var18;
        var18 *= var19;
        var19 *= var20;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    start_time = clock();
    for (int i = 1; i <= counter; i++) {
        var1 /= 2;
        var2 /= 2;
        var3 /= 2;
        var4 /= 2;
        var5 /= 2;
        var6 /= 2;
        var7 /= 2;
        var8 /= 2;
        var9 /= 2;
        var10 /= 2;
        var11 /= 2;
        var12 /= 2;
        var13 /= 2;
        var14 /= 2;
        var15 /= 2;
        var16 /= 2;
        var17 /= 2;
        var18 /= 2;
        var19 /= 2;
    }
    end_time = clock();
    common_time = end_time - start_time - time_of_loop;
    res.push_back(getAmountOfOperations(common_time));

    double maxE = *max_element(res.begin(), res.end());
    double percent;
    double amount;
    for (int i = 0; i < res.size(); i++) {
        percent = floor(res[i] / maxE * 100);
        amount = percent / 2;
        cout << operations[i];
        cout.width(10);
        cout << type;
        cout.width(15);
        cout << res[i];
        cout.width(18);
        for (int j = 0; j < amount; j++) {
            cout << "#";
        }
        cout << setw(10);
        cout <<  percent << "%" << endl;
    }
    cout << endl;
    res.clear();
}


//аналогичный вариант лабораторной работы, но с использованфием template, что является нежелательным 
//void getResult(T value, string type) {
//    vector <double> res;
//    T var1 = 546374374, var2 = 344656456, var3 = 945347123, var4 = 845123432, var5 = 345123934, var6 = 456123746,
//             var7 = 123746934, var8 = 123423424, var9 = 765384294, var10 = 912756174, var11 = 473912734,
//             var12 = 367198234, var13 = 483734205, var14 = 397436834, var15 = 194536241, var16 = 341230645,
//             var17 = 945321745, var18 = 701438209, var19 = 190345123, var20 = 734218934;
//
//    clock_t start_time = 0, end_time = 0, common_time, time_of_loop;
//
//
//    start_time = clock();
//    for (int i = 0; i < counter; ++i) {
//
//    }
//    end_time = clock();
//    time_of_loop = end_time - start_time;
//
//    start_time = clock();
//    for (int i = 0; i < counter; i++) {
//        var1 += var2;
//        var2 += var3;
//        var3 += var4;
//        var4 += var5;
//        var5 += var6;
//        var6 += var7;
//        var7 += var8;
//        var8 += var9;
//        var9 += var10;
//        var10 += var11;
//        var11 += var12;
//        var12 += var13;
//        var13 += var14;
//        var14 += var15;
//        var15 += var16;
//        var16 += var17;
//        var17 += var18;
//        var18 += var19;
//        var19 += var20;
//    }
//    end_time = clock();
//    common_time = end_time - start_time - time_of_loop;
//    res.push_back(getAmountOfOperations(common_time));
//
//    for (int i = 0; i < counter; ++i) {
//
//    }
//
//    start_time = clock();
//    for (int i = 0; i < counter; i++) {
//        var1 -= var2;
//        var2 -= var3;
//        var3 -= var4;
//        var4 -= var5;
//        var5 -= var6;
//        var6 -= var7;
//        var7 -= var8;
//        var8 -= var9;
//        var9 -= var10;
//        var10 -= var11;
//        var11 -= var12;
//        var12 -= var13;
//        var13 -= var14;
//        var14 -= var15;
//        var15 -= var16;
//        var16 -= var17;
//        var17 -= var18;
//        var18 -= var19;
//        var19 -= var20;
//    }
//    end_time = clock();
//    common_time = end_time - start_time - time_of_loop;
//    res.push_back(getAmountOfOperations(common_time));
//
//    start_time = clock();
//    for (int i = 0; i < counter; i++) {
//        var1 *= var2;
//        var2 *= var3;
//        var3 *= var4;
//        var4 *= var5;
//        var5 *= var6;
//        var6 *= var7;
//        var7 *= var8;
//        var8 *= var9;
//        var9 *= var10;
//        var10 *= var11;
//        var11 *= var12;
//        var12 *= var13;
//        var13 *= var14;
//        var14 *= var15;
//        var15 *= var16;
//        var16 *= var17;
//        var17 *= var18;
//        var18 *= var19;
//        var19 *= var20;
//    }
//    end_time = clock();
//    common_time = end_time - start_time - time_of_loop;
//    res.push_back(getAmountOfOperations(common_time));
//
//    start_time = clock();
//    for (int i = 1; i <= counter; i++) {
//        var1 /= 2;
//        var2 /= 2;
//        var3 /= 2;
//        var4 /= 2;
//        var5 /= 2;
//        var6 /= 2;
//        var7 /= 2;
//        var8 /= 2;
//        var9 /= 2;
//        var10 /= 2;
//        var11 /= 2;
//        var12 /= 2;
//        var13 /= 2;
//        var14 /= 2;
//        var15 /= 2;
//        var16 /= 2;
//        var17 /= 2;
//        var18 /= 2;
//        var19 /= 2;
//    }
//    end_time = clock();
//    common_time = end_time - start_time - time_of_loop;
//    res.push_back(getAmountOfOperations(common_time));
//
//    double maxE = *max_element(res.begin(), res.end());
//    double percent;
//    double amount;
//    for (int i = 0; i < res.size(); i++) {
//        percent = floor(res[i] / maxE * 100);
//        amount = percent / 2;
//        cout << operations[i];
//        cout.width(10);
//        cout << type;
//        cout.width(15);
//        cout << res[i];
//        cout.width(18);
//        for (int j = 0; j < amount; j++) {
//            cout << "#";
//        }
//        cout << setw(10);
//        cout <<  percent << "%" << endl;
//    }
//    cout << endl;
//    res.clear();
//}

int main() {

//        getResult(INT_MAX, "int");
//        getResult(LONG_MAX, "long");
//        getResult(CHAR_MAX, "char");
//        getResult(FLT_MAX, "float");
//        getResult(DBL_MAX, "double");
    
    getInt("int");
    getLong("long");
    getChar("char");
    getFloat("float");
    getDouble("double");
    return 0;
}