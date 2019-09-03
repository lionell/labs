#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long* a = new long long[n+1];
    long long* sumarr = new long long[n+1];
    cin >> a[0];
    sumarr[0] = a[0];

    for (long long i = 1; i < n; i++)
    {
        cin >> a[i];
        sumarr[i] = sumarr[i-1]+a[i];
    }

    vector<long long> st;
    st.push_back(0);
    long long maxx = a[0];

    for (long long i = 1; i < n-1; i++)
    {
        //if (a[i] >= a[i-1] && a[i] >= a[i+1] && a[i] >= maxx)
        if (a[i] >= maxx)
        {
            st.push_back(i);
            maxx = a[i];
        }
    }

    vector<long long> st2;

    maxx = a[n-1];

    for (long long i = n-2; i > st[st.size()-1]+1; i--)
    {
        //if (a[i] >= a[i-1] && a[i] >= a[i+1] && a[i] >= maxx)
        if (a[i] >= maxx)
        {
            st2.push_back(i);
            maxx = a[i];
        }
    }

    reverse(st2.begin(), st2.end());

    vector<long long> s;

    set_union(st.begin(), st.end(), st2.begin(), st2.end(), inserter(s, s.begin()));

    s.push_back(n-1);

    long long sm = 0;

    /*for (int i = 0; i < s.size()-1; i++)
    {
        cout << s[i] << " ";
    }

    cout << endl;
*/
    for (long long i = 0; i <= s.size()-2; i++)
    {
        long long width = s[i+1] - s[i] - 1;
        long long height = min(a[s[i]], a[s[i+1]]);
        sm += width * height + sumarr[s[i]] - sumarr[s[i+1]-1];
    }

    cout << sm << endl;

    delete [] a;
    delete [] sumarr;

    return 0;
}
