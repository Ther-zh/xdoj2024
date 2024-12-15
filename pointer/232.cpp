#include <iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string a;
    cin>>a;
    stack<char> s;
    for(int i=0;i<a.size();i++){
        s.push(a[i]);
    }
    bool flag=true;
    for(int i=0;i<a.size();i++){
        if(s.top()!=a[i]) flag=false;
        s.pop();
    }
    if(flag) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}