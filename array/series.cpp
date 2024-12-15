#include<stdio.h> 
int main(){
	int a1,a2,n;
	scanf("%d %d %d",&a1,&a2,&n);
	int a[1001]={0};
	a[1]=a1;
	a[2]=a2;
	int flag=0;
	int record=0;
	int j=3;
	for(int i=1;i<=n;i++){
		if(i>2){
			if(flag==1){
				flag=0;
				a[i]=record;
			}
			else if(a[j-2]*a[j-1]<10){
				a[i]=a[j-2]*a[j-1];
				j++;
			}
			else{
				flag=1;
				a[i]=(a[j-2]*a[j-1])/10;
				record=(a[j-2]*a[j-1])%10;
				j++;
			}
		}
		printf("%d ",a[i]);
	}
	return 0;
}
