#include<stdio.h>

void paint(int num, int (*book)[4], int *res){
    int mp[100][100]={0};
    for(int i=0;i<num;i++){
        for(int x=book[i][0];x<=book[i][2]-1;x++){
            for(int y=book[i][1];y<=book[i][3]-1;y++){
                mp[x][y]++;
            }
        }
    }
    int cal[110]={0};
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cal[mp[i][j]]++;
        }
    }
    int tail=0;
    int flag=0;
    //逆天的点在于找到一个最大的不为零的数后面的所有数都要输出（即使是0）
    for(int i=100;i>=0;i--){
        if(flag==1){
            res[tail]=i;
            tail++;
            res[tail]=cal[i];
            tail++;
        }
        if(cal[i]!=0&&flag==0){
            flag=1;
            res[tail]=i;
            tail++;
            res[tail]=cal[i];
            tail++;
        }
    }
}

int main()
{
	int n,l[100][4]; 
	int result[300];
	int i;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&l[i][0],&l[i][1],&l[i][2],&l[i][3]);
	}

	paint(n,l,result);
	for(i=0;i<=result[0];i++)
	{
		printf("%d %d\n",result[i*2],result[i*2+1]);
	}

	return 0;
}
