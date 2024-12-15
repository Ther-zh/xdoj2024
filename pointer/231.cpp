#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int m;
string tem;
int main(){
    string a;
    stringstream ss;
    getline(cin,a);
    ss<<a;
    while(ss>>tem){
        if(tem[tem.size()-1]=='.'){
            m=max(m,(int)tem.size()-1);
        }
        else{
            m=max(m,(int)tem.size());
        }
    }
    cout<<m<<endl;
    return 0;
}