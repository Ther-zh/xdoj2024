#include<iostream>
using namespace std;
int main(){
    int arr[100][100]={0};
    int state=1;//状态1向↗，状态2向↙
    int i=0,j=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    while(i!=n-1||j!=n-1){
        cout<<arr[i][j]<<" ";
        if(state==1){
            if(i-1<0&&j+1>n-1){
                i++;
                state=2;
            }
            else if(i-1<0){
                j++;
                state=2;
            }
            else if(j+1>n-1){
                i++;
                state=2;
            }
            else{
                i--;
                j++;
            }
        }
        else{
            if(i+1>n-1){
                j++;
                state=1;
            }
            else if(j-1<0){
                i++;
                state=1;
            }
            else{
                i++;
                j--;
            }
        }
    }
    cout<<arr[i][j];
    return 0;
}