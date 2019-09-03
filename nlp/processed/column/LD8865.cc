#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool f = true;
    int k = 1, ans = 0;
    while (f)
    {
        f = false;
        pair<int,int> ch[10];
        for (int i = 0; i < 10; i++)
            ch[i] = {0,i};
        for (int i = 0; i < n; i++)
        {
            ch[a[i]%10].first ++;
            a[i] /= 10;
            if (a[i]) f = true;
        }
        sort(ch,ch+10);
        if (ch[9].first != ch[8].first) ans += k*ch[9].second;
        k *= 10;
    }
    cout << ans << endl;
}
