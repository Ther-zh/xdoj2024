#include<iostream>
using namespace std;
int main(){
    int map[22][22]={0};
    int book[50]={0};
    int m,n,t,k;
    cin>>m>>n>>t>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((map[i+1][j]==k||map[i-1][j]==k||map[i][j+1]==k||map[i][j-1]==k)&&map[i][j]!=k){
                book[map[i][j]]=1;
            }
        }
    }
    
    int sum=0;
    for(int i=1;i<=t;i++){
        if(book[i]>0){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}