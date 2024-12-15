#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<string>
class student{
public:
    string name;
    string id;
    vector<double> score;
    vector<double> credit;
    double addscore;
    double sum;
    bool ispass;
/*
*功能：计算总分，并求出是否及格
*参数：无
*返回值：无
*说明：无
*作者：郑智航
*时间：2024/12/13   17:00
*备注：无
*修改：无
*版本：1.0
*/
    void calsum(){
        double cresum=0;
        ispass=true;
        for(int i=0;i<score.size();i++){
            if(score[i]<60){
                ispass=false;
            }
            cresum+=credit[i];
            sum+=score[i]*credit[i];
        }
        sum/=cresum;
        sum+=addscore;
    }
};
class compare{
public:
    bool operator()(student a,student b){
        return a.sum<b.sum;
    }
};
int m,n;
double ratio;
int main(){
    cin>>n>>m>>ratio;
    priority_queue<student,vector<student>,compare> stu;
    for(int i=0;i<n;i++){
        student tem;
        cin>>tem.id>>tem.name;
        tem.sum=0;
        for(int j=0;j<m;j++){
            double tems,temc;
            cin>>tems>>temc;
            tem.score.push_back(tems);
            tem.credit.push_back(temc);
        }
        cin>>tem.addscore;
        tem.calsum();
        if(tem.ispass){
            stu.push(tem);
        }
    }
    int stunum=(int)(ratio*(double)n);
    if(stunum<=0) stunum=1;
    for(int i=0;i<stunum;i++){
        student tem=stu.top();
        stu.pop();
        printf("%s %s %.3lf\n",tem.id.c_str(),tem.name.c_str(),tem.sum);
    }
    return 0;
}