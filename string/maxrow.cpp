#include<iostream>
#include<string>
using namespace std;
int main(){
    string record;
    int max=0;
    while(1){
        string s;
        getline(cin,s);
        if(s=="***end***")break;
        if(s.size()>max){
            max=s.size();
            record=s;
        }
        
    }
    cout<<max<<'\n'<<record<<endl;
    return 0;
}