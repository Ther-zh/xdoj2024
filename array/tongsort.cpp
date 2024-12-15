#include<stdio.h>
int main(){
	int arr[1001]={0};
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tem;
		scanf("%d",&tem);
		arr[tem]++;
	}
	int max=-1;
	int record=0;
	while(1){
		max=-1;
		for(int i=0;i<=1000;i++){
			if(arr[i]>max){
				max=arr[i];
				record=i;
			}
		}
		if(max==0)break;
		printf("%d %d\n",record,max);
		arr[record]=0;
	}
	return 0;
}
