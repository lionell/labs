#include<bits/stdc++.h>

using namespace std;

int main()
{
    signed long long n,i,j,k,l,r,a;
    scanf("%lld",&n);
    stack<long long>mn,q,h;
    for(i=1;i<=n;i++){
        cin>>k;
        q.push(k);
    }
    r=-1;
    k=0;
    while(!q.empty()){
        l=q.top();
        q.pop();
        if(l>=r){
            j=mn.size()*r;
            while(!mn.empty()){
                a=mn.top();
                mn.pop();
                j-=a;
            }
            k+=j;
            r=l;
        }
        else{
            mn.push(l);
        }
        if(q.empty()&&!mn.empty()){
            q.push(r);
            while(!mn.empty()){
                h.push(mn.top());
                mn.pop();
            }
            while(!h.empty()){
                q.push(h.top());
                h.pop();
            }
        r=-1;
        }
    }
    printf("%lld",k);
}
