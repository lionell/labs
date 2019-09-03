#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf ("%d", &n);

    vector <long long> a(n + 1, 0);

    for (int i = 1; i <= n; i ++)
    {
        scanf ("%I64d", &a[i]);
    }

    vector  < pair <long long, long long> > st (n + 5, make_pair (0, 0));
    int k = 0;
    long long ans = 0;

    for (int i = 1; i <= n; )
    {
        if (k < 3)
        {
            if (a[i] == st[k].first)
                st[k].second ++;
            else
            {
                k ++;
                st[k].first = a[i];
                st[k].second = 1;
            }
            i ++;
            if (i == n + 1 && k >= 3)
            {
            	////
            	bool mark = true;

            	while (mark)
            	{
                if (k < 3)
                        break;
            	if (st[k - 1].first < st[k - 2].first && st[k - 1].first < st[k].first)
            	{
                	if (st[k - 2].first > st[k].first)
                	{
                    	ans += ((st[k].first - st[k - 1].first) * st[k - 1].second);
                    	st[k - 1].second += st[k].second;
                    	st[k - 1].first = st[k].first;
                    	k --;
                	}
                	else
                	if (st[k - 2].first < st[k].first)
               	 	{
                    	ans += ((st[k - 2].first - st[k - 1].first) * st[k - 1].second);
                    	st[k - 2].second += st[k - 1].second;
                    	st[k - 1] = st[k];
                    	k --;
                	}
                	else
                	{
                    	ans += ((st[k - 2].first - st[k - 1].first) * st[k - 1].second);
                    	st[k - 2].second += (st[k - 1].second + st[k].second);
                    	k -= 2;
                	}

            	}
            	else
            	{
            		mark = false;
				}

            	}
            	////
			}
        }
        else
        {
            if (st[k - 1].first < st[k - 2].first && st[k - 1].first < st[k].first)
            {
                if (st[k - 2].first > st[k].first)
                {
                    ans += ((st[k].first - st[k - 1].first) * st[k - 1].second);
                    st[k - 1].second += st[k].second;
                    st[k - 1].first = st[k].first;
                    k --;
                }
                else
                if (st[k - 2].first < st[k].first)
                {
                    ans += ((st[k - 2].first - st[k - 1].first) * st[k - 1].second);
                    st[k - 2].second += st[k - 1].second;
                    st[k - 1] = st[k];
                    k --;
                }
                else
                {
                    ans += ((st[k - 2].first - st[k - 1].first) * st[k - 1].second);
                    st[k - 2].second += (st[k - 1].second + st[k].second);
                    k -= 2;
                }

            }
            else
            {
                if (a[i] == st[k].first)
                    st[k].second ++;
                else
                {
                    k ++;
                    st[k].first = a[i];
                    st[k].second = 1;
                }
                i ++;
                if (i == n + 1 && k >= 3)
                {
                	////
                	bool mark = true;
                	while (mark)
                	{
                    if (k < 3)
                        break;

					if (st[k - 1].first < st[k - 2].first && st[k - 1].first < st[k].first)
            		{
                		if (st[k - 2].first > st[k].first)
                		{
                    		ans += ((st[k].first - st[k - 1].first) * st[k - 1].second);
                    		st[k - 1].second += st[k].second;
                    		st[k - 1].first = st[k].first;
                    		k --;
                		}
                		else
                		if (st[k - 2].first < st[k].first)
               	 		{
                    		ans += ((st[k - 2].first - st[k - 1].first) * st[k - 1].second);
                    		st[k - 2].second += st[k - 1].second;
                    		st[k - 1] = st[k];
                    		k --;
                		}
                		else
                		{
                    		ans += ((st[k - 2].first - st[k - 1].first) * st[k - 1].second);
                    		st[k - 2].second += (st[k - 1].second + st[k].second);
                    		k -= 2;
                		}

            		}
					else
					{
						mark = false;
					}

					}
                	////
				}

            }

        }

    }


    printf ("%I64d\n", ans);

/*
    for (int i= 1; i <= k; i ++)
    {
        for (int j = 1; j <= st[i].second; j ++)
        {
            cout << st[i].first << " ";
        }
    }

    int ddd;
    cin >> ddd;
*/

    return 0;
}
