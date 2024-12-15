#include<iostream>
#include<string>
using namespace std;
int main(){
    string code;
    cin>>code;
    int nums[9];//存储除了最后一位外的all数字（最后一位可能为x）
    int k=0;
    for(int i=0;i<13;i++){
        if(i!=1&&i!=5&&i!=11&&i!=12){
            nums[k]=code[i]-('1'-1);
            k++;
        }
    }
    
    int core=0;
    for(int i=1;i<=9;i++){
        core+=i*nums[i-1];
    }
    char result=(core%11==10)?'X':(core%11+('1'-1));
    
    if(result==code[12]){
        cout<<"Right"<<endl;
    }
    else{
        code[12]=result;
        cout<<code<<endl;
    }
    return 0;
}