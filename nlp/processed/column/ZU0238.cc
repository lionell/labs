#include <iostream>

using namespace std;

int main(){
	long int n,
	max, max_i;
	
	
	cin>>n;
	long int a[n];
	for(long int i = 0; i<n; i++){
		cin>>a[i];
	}
	
	
	//Abs max
	long int Max, Max_i;
	Max = 0;
	for(long int i = 0; i<n; i++){
		if(a[i] >= Max){
			Max = a[i];
			Max_i = i;
		}	
	}
	
	max = Max;
	max_i = Max_i;
	//left 
	long int v, result;
	result = 0;
	long int left, left_i;
	while(max_i != 0){
		left = a[0];
		for(long int i = 0; i < max_i; i++){
			if(a[i] >= left){
				left = a[i];
				left_i = i;
			}	
		}
		//Water
		v = left * (max_i - left_i - 1);
		for(long int i = left_i + 1; i < max_i; i++){
			 v = v - a[i];
		}
		result = result + v;
		
		max = left;
		max_i = left_i;
	}
	max = Max;
	max_i = Max_i;
	//right 
	v = 0;
	long int right, right_i;
	while(max_i != n-1){
		right = 0;
		for(int i = max_i+1; i < n; i++){
			if(a[i] >= right){
				right = a[i];
				right_i = i;
			}	
		}
		//Water
		v = right * (right_i - max_i - 1);
		for(long int i = max_i+1; i < right_i; i++){
			 v = v - a[i];
		}
		result = result + v;
		
		max = right;
		max_i = right_i;
	}
	cout<<result;
}
