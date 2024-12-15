#include <stdio.h>

void printFactorial(int n)
{
	if(n==0||n==1) {
		printf("1");
		return;
	}
	int num[3000]={0};
	int tail=0;
	if(n>1000) printf("Invalid input");
	else{
		int on=n;
		num[0]=1;
		tail++;
		int t=0;
		for(int i=2;i<=on;i++){
			for(int j=0;(j<tail||t!=0);j++){
				if(j==tail) tail++;
				t+=num[j]*i;
				num[j]=t%10;
				t/=10;
			}
		}
		for(int i=tail-1;i>=0;i--) printf("%d",num[i]);
	}
}

int main()
{
    int n;
    scanf("%d", &n);
	printFactorial(n);
    return 0;
}


