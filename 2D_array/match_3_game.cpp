#include<iostream>
using namespace std;
int main(){
    int chess[30][30]={0};
    int book[30][30]={0};//不可及时消去，要先记录再秋后问斩
    int cols,rows;
    cin>>rows>>cols;
    for(int i=0;i<rows;i++){
        int count=1;
        int record=-1;
        //输入，顺便记录行的
        for(int j=0;j<cols;j++){
            cin>>chess[i][j];
            if(chess[i][j]==record){
                count++;
            }
            else{
                if(count>=3){
                    int k=j-1;
                    for(k;k>=j-count;k--){
                        book[i][k]=1;
                    }
                }
                record=chess[i][j];
                count=1;
            }
            //处理消去项在末尾情况
            if(count>=3&&j==cols-1){
                int k=j;
                for(k;k>j-count;k--){
                    book[i][k]=1;
                }
            }
        }
    }
    //记录列的
    for(int j=0;j<cols;j++){
        int count=1;
        int record=-1;
        for(int i=0;i<rows;i++){
            if(chess[i][j]==record){
                count++;
            }
            else{
                if(count>=3){
                    int k=i-1;
                    for(k;k>=i-count;k--){
                        book[k][j]=1;
                    }
                }
                record=chess[i][j];
                count=1;
            }
            //处理消去项在末尾情况
            if(count>=3&&i==rows-1){
                int k=i;
                for(k;k>i-count;k--){
                    book[k][j]=1;
                }
            }
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(book[i][j]==1){
                chess[i][j]=0;
            }
            cout<<chess[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}