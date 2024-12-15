#include<iostream>
#define _for(i,m) for (int i=0;i<m;i++)
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int book[16]={0};
    int map[256][256]={0};
    _for(i,m){
        _for(j,n){
            cin>>map[i][j];
            book[map[i][j]]++;
        }
    }
    _for(i,16){
        if(book[i]!=0)cout<<i<<" "<<book[i]<<endl;
    }
    return 0;
}