#include<stdio.h>
int main(){
    int day,id,index;
    scanf("%d %d %d",&day,&index,&id);
    int lastnum=id%10;
    const char* result;
    if(day>=6)
    {
        result="no";
    }
    else
    {
        if(index<200)
        {
            result="no";
        }
        else
        {
            if(index<400)
            {
                if(lastnum==day||(day+5)%10==lastnum)
                {
                    result="yes";
                }
                else
                {
                    result="no";
                }
            }
            else
            {
                if(day==1||day==3||day==5)
                {
                    if(lastnum==1||lastnum==3||lastnum==5||lastnum==7||lastnum==9)
                    {
                        result="yes";
                    }
                    else
                    {
                        result="no";
                    }
                }
                else
                {
                    if(lastnum==2||lastnum==4||lastnum==6||lastnum==8||lastnum==0)
                    {
                        result="yes";
                    }
                    else
                    {
                        result="no";
                    }
                }
            }
        }
    }
    printf("%d %s",lastnum,result);
    return 0;
}