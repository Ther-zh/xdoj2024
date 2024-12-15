#include<iostream>
#include<string>
#include<vector>
using namespace std;
//忽略大小写
char blur(char c){
    if(c>='a'&&c<='z'){
        return c-('a'-'A');
    }
    else{
        return c;
    }
}
// typedef struct match{
//     int i;//索引位置
//     char c;//索引处字符
// }match;
//src中可能有多处匹配的，如果只记录最早出现的会有问题如abaccccccccccc   如果要acccccccccc只取最早的就不行，所以要有出参mat,并返回匹配上的个数
int csm(char target,string src,vector<int>& mat){
    int count=0;
    for(int i=0;i<src.size();i++){
        if(blur(src[i])==blur(target)){
            mat.push_back(i);
            count++;
        }
    }
    return count;

}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int p=0;
    double max=0;
    //从s1的每一个字符开始逐个和s2的所有相同的字符往后匹配
    for(int i=0;i<s1.size();i++){
        double temmax=0;
        vector<int> mat;
        if(csm(s1[i],s2,mat)!=0){
            for(int m:mat){
                //以在s2出现的m索引位置为起点,以及s1中的i为起点开始逐个匹配
                int j=m;
                int k=i;
                temmax=0;
                while(j<s2.size()&&k<s1.size()){
                    if(blur(s1[k])==blur(s2[j])){
                        temmax++;
                        j++;
                        k++;
                        //及时捕捉max
                        if(temmax>max){
                            max=temmax;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    
    }
    double result=2*max/(s1.size()+s2.size());
    printf("%.3f",result);
    return 0;
}