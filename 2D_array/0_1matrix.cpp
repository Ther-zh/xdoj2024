#include<iostream>
#include<vector>
#define _for(m,n) for(int m=0;m<n;m++)
using namespace std;
typedef struct point{
    int start;
    int end;
}point;
int main(){
    int a[100][100]={0};
    int rows,cols;
    cin>>rows>>cols;
    vector<point> vec;
    _for(i,rows){
        int count=0;
        int records=-1;
        int recorde=-1;
        int maxcount=0;
        int maxrecords=-1;
        int maxrecorde=-1;
        int state=0;
        _for(j,cols){
            cin>>a[i][j];
            if(a[i][j]==1){
                if(state==0){
                    records=j;
                    recorde=j;
                    count=1;
                    state=1;
                    if(count>maxcount){
                        maxrecords=records;
                        maxrecorde=recorde;
                        maxcount=count;
                    }
                }
                else{
                    recorde=j;
                    count++;
                    //及时更新这行的最大起始和count
                    if(count>maxcount){
                        maxrecords=records;
                        maxrecorde=recorde;
                        maxcount=count;
                    }
                }
            }
            else{
                count=0;
                state=0;
            }
        }
        point ele={maxrecords,maxrecorde};
        vec.push_back(ele);
    }
    for(point i:vec){
        cout<<i.start<<" "<<i.end<<endl;
    }
    return 0;
}