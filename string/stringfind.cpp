#include<iostream>
#include<vector>
#include<string>
using namespace std;

char blur(char c){
    if(c>='a'&&c<='z'){
        return c-('a'-'A');
    }
    else{
        return c;
    }
}
int main(){
    string tar;
    cin>>tar;
    int n,mode;
    cin>>mode;
    cin.ignore();
    cin>>n;
    cin.ignore();//cin读取完毕后会留下一个换行符
    string* arr=new string[n];
    vector<int> recordline;
    for(int i=0;i<n;i++){
        getline(cin,arr[i]);
        int p=0;
        int state=0;
        for(int j=0;j<arr[i].size();j++){
            char a,b;
            if(mode==0){
                a=blur(arr[i][j]);
                b=blur(tar[p]);
            }
            else{
                a=arr[i][j];
                b=tar[p];
            }
            if(p==0){
                //找到第一个字符变为激发态，尝试找第二个字符
                if(a==b){
                    state=1;
                    p++;
                }
            }
            else{
                if(a==b){
                    p++;
                }
                else{
                    p=0;
                    state=0;
                    //当这个字母与下一个不匹配时，有可能与字符串第一个匹配，所以state might=1！！！  
                    if(mode==0){
                        b=blur(tar[0]);
                    }
                    else{
                        b=tar[0];
                    }
                    if(a==b){
                        state=1;
                        p=1;
                    }
                }
            }
            if(p==tar.size()){
                recordline.push_back(i);
                break;
            }
        }
    }
    for(auto it:recordline){
        cout<<arr[it]<<endl;
    }
    delete[] arr;
    return 0;
}