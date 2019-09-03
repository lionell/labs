#include <iostream>
#include <cmath>
//#include <math.h>

using namespace std;

int main()
{

    int n,k;
    cin >> n;


    if (n%2==1) k=(n/2)*(n/2 +1);
        else k=pow(n/2, 2);


    cout << k << endl;
    return 0;

}
