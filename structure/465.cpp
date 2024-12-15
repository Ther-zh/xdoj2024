#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef struct{
	int num;
	int score;
	string name;
}team;

class comp{
public:
	bool operator()(team a,team b){
		if(a.num!=b.num) return a.num<b.num;
		if(a.score!=b.score) return a.score<b.score;
		return a.name.compare(b.name)>0;
	}
};
int tn;
team tem;
int n;
vector<team> q; 
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tem.name;
		q.push_back(tem);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>tn;
			if(tn==5){
				q[i].num++;
				q[i].score+=2;
			}
			else if(tn==4){
				q[i].num++;
				q[i].score+=3;
			}
			else if(tn==3){
				q[i].num++;
				q[i].score+=3;
			}
			else if(tn==-5){
				q[i].score+=1;
			}
			else {
				continue;//0:3和1：3和自己（-4 -3 0 ）积0分 
			}
		}
	}
	priority_queue<team,vector<team>,comp> a(q.begin(),q.end());
	while(!a.empty()){
		team t=a.top();
		cout<<t.name<<" "<<t.num<<" "<<t.score<<endl;
		a.pop(); 
	}
	return 0;
} 
