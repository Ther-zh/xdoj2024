#include<iostream>
using namespace std;
int main(){
    int book[100][100]={0};
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<n;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<x2;i++){
            for(int j=y1;j<y2;j++){
                if(book[i][j]==0){
                    book[i][j]=1;
                    count++;
                }
            }
        }
    }
    cout<<count;
    return 0;
}