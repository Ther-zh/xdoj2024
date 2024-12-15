#include<iostream>
#define _for(i,m) for(int i=0;i<m;i++)
using namespace std;
typedef struct school{
    int gpnum;
    int gpid[80];
}school;
void swap(school& a,school& b){
    school tem=a;
    a=b;
    b=tem;
}

//把学校按人数从大到小排列
void sort(school* schs,int size){
    int standard=schs[0].gpnum;
    int i=0,j=size-1;
    if(size<=1)return;
    while(i<j){
        if(schs[i].gpnum==standard){
            if(standard<schs[j].gpnum){
                swap(schs[i],schs[j]);
                i++;
            }
            else j--;
        }
        else{
            if(schs[i].gpnum<standard){
                swap(schs[i],schs[j]);
                j--;
            }
            else i++;
        }
    }
    sort(schs,i);
    sort(schs+i+1,size-i-1);
}
int main(){
    int n;
    cin>>n;
    int orin=n;
    school* list=new school[n];
    _for(i,n){
        cin>>list[i].gpnum;
    }
    sort(list,n);
    int k=0;
    int id=1;
    while(n>0){
        //学校的编号是（id-1）%n，每次为该学校的第k个人编号
        if(n!=1){
            list[(id-1)%n].gpid[k]=id;
            if((id-1)%n==n-1) k++;//进行一轮后k++
            if(k==list[(id-1)%n].gpnum*8) n--;//一个学校满了，从末尾去掉这个学校（因为学校是按人数从大到小排列的，所以末尾的一定先满）
        }
        else{
            list[0].gpid[k]=id;
            k++;
            id++;
            if(k==list[0].gpnum*8) break;
        }
        id++;
    }
    _for(i,orin){
        cout<<"#"<<i<<endl;
        _for(j,list[i].gpnum){
            for(int m=j*8;m<(j+1)*8;m++){
                cout<<list[i].gpid[m]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    delete[] list;
    return 0;
}