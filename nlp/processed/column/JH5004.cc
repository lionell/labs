#include <iostream>

using namespace std;


const int N = 1000*10000 + 2;
int constr[N];


bool state = 0;
long long ans=0;
long long temporary_ans=0;
int n;
int leftpos;
int rightpos;

int main()
{
    constr[0]=0;
    constr[N-1]=0;

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> constr[i];


    for (int i=1; i<=n; i++)
    {
        if(!state)
        {
            if (constr[i]>=constr[i-1] && constr[i]>constr[i+1])
            {
                state=1;
                temporary_ans=0;
                leftpos=i;
            }
        }

        else
        {
            if (constr[i]<constr[leftpos])
            {
                temporary_ans+=constr[leftpos]-constr[i];
            }
            else
            {
                ans+=temporary_ans;
                i=i-1;
                state=0;
            }


        }

    }

    if(state)
    {
        state=temporary_ans=0;
        for (int i=n; i>=leftpos; i--)
        {
            if(!state)
            {
                if (constr[i]>=constr[i+1] && constr[i]>constr[i-1])
                {
                    state=1;
                    temporary_ans=0;
                    rightpos=i;
                }
            }
            else
            {
                if (constr[i]<constr[rightpos])
                {
                    temporary_ans+=constr[rightpos]-constr[i];
                }
                else
                {
                    ans+=temporary_ans;
                    i=i-1;
                    state=0;
                }
            }

        }
    }

    cout << ans;

    return 0;

}
