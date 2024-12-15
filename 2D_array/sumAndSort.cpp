#include<iostream>
#define _for(a,b) for(int a=0;a<b;a++)//试试竞赛小技巧hh
using namespace std;
void swap(int&a,int& b){
    int tem=a;
    a=b;
    b=tem;
}
//插入排序
void sort(int* arr,int size){
    int i=1;
    while(i<size-1){
        int j=i;
        for(int j=i;j>=0;j--){
            if(arr[j+1]>arr[j]){
                swap(arr[j],arr[j+1]);
            }
            else{
                break;
            }
        }
        i++;
    }
}


int main(){
    int m;
    cin>>m;
    int arr[20][20];
    int* res=new int[2*m-1];
    int k=0;
    _for(i,m){
        int sum=0;
        _for(j,m){
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
        res[k]=sum;
        k++;
    }
    _for(i,m){
        int sum=0;
        _for(j,m){
            sum+=arr[j][i];
        }
        res[k]=sum;
        k++;
    }
    int sum1=0,sum2=0;
    _for(i,m){
        sum1+=arr[i][i];
        sum2+=arr[i][m-i-1];
    }
    res[k]=sum1;
    k++;
    res[k]=sum2;
    k++;
    sort(res,k);
    _for(i,k){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    delete[] res;
    return 0;
}