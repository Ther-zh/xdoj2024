#include <iostream>
#include<string>
using namespace std;
string a;
int m;
int main(){
    getline(cin,a);
    cin>>m;
    if(a.size()<m) cout<<"error"<<endl;
    else{
        cout<<a.substr(m-1,a.size())<<endl;
    }
    return 0;
}