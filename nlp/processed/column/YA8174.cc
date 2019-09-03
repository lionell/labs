#include <iostream>
//#include <cstring.h>



using namespace std;

int main() {
	long long li,k,res,sum,n,l,r,i,j,last;
	cin >> n;
	if (n==1) {
		cin >>i;
		cout <<0<<endl;
	} else if (n==2) {
			cin>>i>>j;
			cout <<0<<endl;
	}  else {
		cin >> l;
		li=1;
		i=1;
		sum=0;
		res=0;
		while (i<=n) {	
			i++;
			if (i==n) {
				cin >>j;
			//	cout <<li<<" "<<l<<" "<<i<<" "<<sum<<" "<<res<<endl;
				if (j>k) res+=(i-li-1)*min(j,l)-sum;
				break;
			} else {
				cin >>k;
				if (l>=k) sum+=k; else {
					res+=(i-li-1)*l-sum;
					l=k;
					li=i;
					sum=0;
				}		
			}
		//	cout <<li<<" "<<l<<" "<<i<<" "<<sum<<" "<<res<<endl;
		}
		cout <<res<<endl;		
	}
}
