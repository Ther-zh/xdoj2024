#include<stdio.h>
//int book[1000];
int main(){
    int n;
    int book[1000]={0};
    scanf("%d",&n);
    //°£Ê½É¸·¨
    for(int a=2;a<n;a++){
        book[a]=1;
    }
    int i=2;
    for(int i=2;i<n;i++){
        if (book[i]==0) continue;
        for(int j=i+1;j<n;j++){
            if(j%i==0){
                book[j]=0;
            }
        }
    }
    int start=2,end=n;
    while(book[end]==0){
        end--;
    }
    while(start+end!=n){
        if(start+end>n){
            do {end--;} while(book[end]==0);
        }
        else{
            do {start++;} while(book[start]==0);
        }
    }
    printf("%d %d",start,end);
    return 0;
}