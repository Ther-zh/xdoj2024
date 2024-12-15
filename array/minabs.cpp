#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int n;
	int* a=new int[n];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int min=10000;
	for (int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(min>abs(a[i]-a[j])){
				min=abs(a[i]-a[j]);
			}
		}
	}
	cout<<min;
	return 0;
}
