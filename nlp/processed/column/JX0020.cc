#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	long long n,temp, res = 0;
	cin >> n;
	vector <int> a, b, c;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	cin >> a[0];
	b[0] = a[0];
	for(int i = 1; i < n; i++){
		cin >> a[i];
		if(a[i] > b[i-1]) b[i] = a[i];
		else b[i] = b[i-1];
	}
	c[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
		if(a[i] > c[i+1]) c[i] = a[i];
		else c[i] = c[i+1];
		b[i] = min(b[i],c[i]);
		res += (b[i] - a[i]);
	}
	cout << res << endl;
	return 0;
}
