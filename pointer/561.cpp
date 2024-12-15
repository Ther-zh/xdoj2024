#include<iostream>
using namespace std;
int main(){
    string a;
    cin>>a;
    char b[200]={0};
    int tail=0;
    for(int i=0;i<a.size();i++){
        b[tail]=a[i];
        tail++;
        b[tail]=' ';
        tail++;
    }
    cout<<b<<endl;
}