#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int trans(string num){
    int result=0;
    for(int i=num.size()-1;i>=0;i--){
        result+=pow(10,num.size()-i-1)*(num[i]-('1'-1));
    }
    return result;
}

int main(){
    string a[3];
    // for(int i=0;i<3;i++){
    //     a[i]=new char[10];
    // }
    //scanf("%s %s %s",&a[0],&a[1],&a[2]);
    cin>>a[0]>>a[1]>>a[2];
    int result=0;
    char opt;
    int num[2];
    int pit=0;
    for(int i=0;i<3;i++){
        if(a[i].size()==1&&a[i][0]=='+'){
            opt='+';
        }
        else if(a[i].size()==1==1&&a[i][0]=='-'){
            opt='-';
        }
        else if(a[i].size()==1&&a[i][0]=='*'){
            opt='*';
        }
        else if(a[i].size()==1&&a[i][0]=='/'){
            opt='/';
        }
        else if(a[i].size()==1&&a[i][0]=='%'){
            opt='%';
        }
        else{
            num[pit]=trans(a[i]);
            pit++;
        }
    }
    switch(opt){
    case '+':
        result=num[0]+num[1];
        break;
    case '-':
        result=num[0]-num[1];
        break;
    case '*':
        result=num[0]*num[1];
        break;
    case '/':
        result=num[0]/num[1];
        break;
    case '%':
        result=num[0]%num[1];
        break;
    }
    cout<<result<<endl;
    return 0;
}