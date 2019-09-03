#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int S[10000000];

int main()
{
    long long N, rl = 0, rp = 0, res = 0;
    cin >> N;
    for (long long i = 0; i < N; i ++) cin >> S [i];
    long long left = S [rl];
    long long right = S [rp];
    while (rp < N)
    {
        while (left == 0 && rl < N)
        {
            rl++;
            rp++;
            left = S[rl];
            right = S[rp];
        }
        while (S[rp + 1] != 0)
        {
            rp++;
            right = S[rp];
        }
        if ((rp - rl) > 1)
        {
            long long rr = rp, rf = rl;
            while (rr - rf > 1)
            {
                while (left <= S [rf + 1])
                {
                    rf++;
                    left = S [rf];
                }
                while (right <= S [rr - 1])
                {
                    rr--;
                    right = S [rr];
                }
                if (rr - rf <= 1) break;
                if (left <= right)
                {
                    while (left > S[rf + 1])
                    {
                        rf++;
                        res += (left - S[rf]);

                    }
                    rf++;
                    left = S [rf];
                }
                else
                {
                    while (right > S[rr - 1])
                    {
                        rr--;
                        res += (right - S[rr]);

                    }
                    rr--;
                    right = S [rr];
                }
            }

        }
        rl = rp + 1;
        left = S[rl];
        rp = rl + 1;
        right = S[rp];

    }
    cout << res << endl;
    return 0;
}
