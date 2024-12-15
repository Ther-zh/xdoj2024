#include<iostream>
using namespace std;
void swap(int& a,int&b){
    int tem=a;
    a=b;
    b=tem;
}
//快速排序
void sort(int *arr,int size){
    if(size<=1)return;
    int i=0;
    int j=size-1;
    int standard=arr[0];
    while(i<j){
        if(standard==arr[i]){
            if(arr[j]>standard){
                swap(arr[i],arr[j]);
                i++;
            }
            else{
                j--;
            }
        }
        else{
            if(arr[i]<standard){
                swap(arr[i],arr[j]);
                j--;
            }
            else{
                i++;
            }
        }
    }
    sort(arr,i);
    sort(arr+i+1,size-i-1);
}

int main(){
    string a;
    cin>>a;
    int* nums=new int[a.size()];
    int k=0;
    int state=0;
    int record=-1;//设定为-1，防止没办法接收到0并将其参与排序
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'&&a[i]>='0'){
            if(state==0){
                state=1;
                record=a[i]-('1'-1);
            }
            else{
                record=record*10+a[i]-('1'-1);
            }
        }
        else{
            if(record!=-1){
                nums[k]=record;
                k++;
                state=0;
                record=-1;
            }
        }
        //数字在最后
        if(i==a.size()-1&&record!=-1){
            nums[k]=record;
            k++;
            state=0;
            record=-1;
        }
    }
    sort(nums,k);
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    delete[] nums;
    return 0;
}