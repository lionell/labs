//
//  main.cpp
//  nikita and string
//
//  Created by Admin on 27.10.2017.
//  Copyright © 2017 Admin. All rights reserved.
//
#include <iostream>
#include <algorithm>
#define F first
#define S second
using namespace std;
int arr[10001000];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=0; i<n; ++i){
        cin>>arr[i];
    }
    int st=0;
    int fin=n-1;
    while (arr[st+1]>=arr[st]) ++st;
    while (arr[fin-1]>=arr[fin]) --fin;
    if (st==fin){
        cout<<0<<"\n";
        return 0;
    }
    int k=st+1;
    for (int i=st+1; i<fin; ++i){
        if (arr[i]>arr[k]) k=i;
    }
    if (arr[k]<arr[st] && arr[k]<arr[st]){
        int etalon=min(arr[st],arr[fin]);
        long long ans=0;
        for (int i=st+1; i<fin; ++i){
            ans+=(etalon-arr[i]);
        }
        cout<<ans<<"\n";
        return 0;
    }
    else{
        long long res=0,tres=0;
        int pos =st;
        for (int i=st+1; i<=k; ++i){
            if (arr[i]>=arr[pos]){
                pos=i;
                res+=tres;
                tres=0;
            }else{
                tres+=(arr[pos]-arr[i]);
            }
        }
        pos=fin-1;
        for (int i=fin-1; i>=k; --i){
            if (arr[i]>=arr[pos]){
                pos=i;
                res+=tres;
                tres=0;
            }else{
                tres+=(arr[pos]-arr[i]);
            }
        }
        cout<<res<<"\n";
        return 0;
    }
    
}
