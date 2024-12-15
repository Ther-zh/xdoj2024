#include<stdio.h>
int main(){
    char a[101]={0};
    char b[101]={0};
    scanf("%s",&a);
    int j=0;
    char record;
    int numrecord=-1;//处理13等情况
    for(int i=0;a[i]!='\0';i++){
        if(a[i]<='9'&&a[i]>='0'){
            //若前面数字就更新数字
            if(numrecord!=-1){
                numrecord=numrecord*10+a[i]-('1'-1);
            }
            //否则就记录数字等待下一个字符终止数字录入
            else{
                numrecord=a[i]-('1'-1);
            }
            //如果数字在末尾就提前打印
            if(a[i+1]=='\0'){
                if(numrecord>=3){
                    for(int m=1;m<numrecord;m++){
                        b[j]=record;
                        j++;
                    }  
                }
            }
        }
        //处理字符
        else{
            //有数字记录就把前面欠下来的字符记录打印，再打印当前字符，更新字符记录，数字记录
            if(numrecord!=-1){
                if(numrecord>=3){
                    for(int m=1;m<numrecord;m++){
                        b[j]=record;
                        j++;
                    }
                    b[j]=a[i];
                    record=a[i];
                    j++;
                    numrecord=-1;
                }
                else{
                    //如果是小于3的数字要把数字打印出来:不用打印record（执行到record处已经打印了一次）打印数字再打印当前字符并重置record和numrecord
                    b[j]=numrecord+('1'-1);
                    j++;
                    b[j]=a[i];
                    record=a[i];
                    numrecord=-1;
                    j++;
                }
            }
            //没有记录数字时直接打印，更新字符记录
            else{
                b[j]=a[i];
                record=a[i];
                j++;
            }
        }
    }
    for(int i=0;b[i]!='\0';i++){
        printf("%c",b[i]);
    }
    printf("\n");
    return 0;
}