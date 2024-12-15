#include<iostream>
#define _for(i,m) for(int i=0;i<m;i++)
using namespace std;
class school{
public:
    int gpnum;
    int gpid[80];
    int tail;//tail指向最后一个元素的下一个元素
    int lastid;
    school():tail(0),lastid(-10){}//设置lastid防止用tail-1判断导致数组越界
    int& operator[](int num){
        return gpid[num];
    }
    void push(int a){
        gpid[tail]=a;
        tail++;
        lastid=a;//更新lastid
    }
};
void updatesid(int& sid,int max){
    if(++sid>max){
        sid=0;
    }
}
int main(){
    int n;
    cin>>n;
    school* list=new school[n];
    _for(i,n){
        cin>>list[i].gpnum;
    }
    int id=1;
    int sid=0;//每次循环时操作的学校id
    while(1){
        //如果该学校人满了且不是最后一个就跳到下一个学校
        if(list[sid].tail==list[sid].gpnum*8)
        {
            //如果是最后一个学校退出
            if(id-1==list[sid].lastid){
               break;
            }
            updatesid(sid,n-1);
            continue;
        }
        //如果人没满先判断是否是唯一的学校
        if(id-1==list[sid].lastid){
            id++;//把目前的id自增后加入列表
            list[sid].push(id);
            id++;//正常id自增,等到下一次判断是否是最后一个学校,
        }
        else{
            //该学校不是唯一学校
            list[sid].push(id);
            id++;
            updatesid(sid,n-1);
        }
    }
    //打印
    _for(i,n){
        cout<<"#"<<i+1<<endl;
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