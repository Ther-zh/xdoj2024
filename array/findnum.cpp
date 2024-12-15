#include<stdio.h>
struct queue{
	int arr[100];
	int tail=0,head=0;
};
int main(){
	int n,k;
	struct queue que;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int tem;
		scanf("%d",&tem);
		if(tem==k){
			que.arr[que.tail]=i;
			que.tail++;
		}
	}
	if(que.head==que.tail){
		printf("-1");
	}
	while(que.head!=que.tail){
		printf("%d ",que.arr[que.head]);
		que.head++;
	}
	return 0;
}
