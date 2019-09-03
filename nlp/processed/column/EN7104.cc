#include <iostream>
#include <vector>

using namespace std;

pair < int, int > m [10000001], n [10000001];
int S [10000001];

int main()
{
    int N, k = 0, r = 0;
    long long ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> S [i];
        if (i == 0)
        {
            m [0].first = S [i];
            m [0].second = i;
        }
        else
        {
            if (S [i] >= m [k].first)
            {
                ++k;
                m [k].first = S [i];
                m [k].second = i;
            }
        }
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = m [i].second + 1; j < m [i + 1].second; ++j)
        {
            ans += S [i] - S [j];
        }
    }
    for (int i = N - 1; i >= k; --i)
    {
        if (i == N - 1)
        {
            n [0].first = S [i];
            n [0].second = i;
        }
        else
        {
            if (S [i] >= n [r].first)
            {
                ++r;
                n [r].first = S [i];
                n [r].second = i;
            }
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = n [i].second - 1; j > n [i + 1].second; --j)
        {
            ans += n [i].first - S [j];
        }
    }
    cout << ans << '\n';
}
