#include<bits/stdc++.h>
using namespace std;

struct process
{
	string id;
	int arival;
	int burst;
	int exi;
	int turn;
	int wait;
	
};
bool cmp(const process &p1,const process &p2){
	if(p1.arival==p2.arival)return p1.id<p2.id;
	return p1.arival<p2.arival;
}
void calculate(vector<process>&v){
	int cur =0;
	sort(v.begin(),v.end(),cmp);
	for(auto &u:v){
		if(cur<u.arival)cur=u.arival;
		u.exi=cur+u.burst;
		cur=u.exi;
		u.turn=u.exi-u.arival;
		u.wait=u.turn-u.burst;
	}
}
void gantt(vector<process>&v){
	int cur =0;
	for(auto u:v){
		if(cur<u.arival){
			cout<<"------- ";
		}
		cur=u.exi;
		cout<<"------- ";
	}
	cout<<"\n |";
	cur=0;
	for(auto u:v){
		if(cur<u.arival){
			cout<<" Idle |";
		}
		cur=u.exi;
		cout<<"  "<<u.id<<"  |";
	}
	cout<<"\n";
	cur =0;
	for(auto u:v){
		if(cur<u.arival){
			cout<<"------- ";
		}
		cur=u.exi;
		cout<<"------- ";
	}
	cout<<"\n";
	cur=0;
	cout<<cur;
	for(auto u:v){
		if(cur<u.arival){
			cout<<"      "<<u.arival;

		}
		cur=u.exi;
		cout<<"      "<<cur;
	}
    cout<<endl;
}
void printt(vector<process>&v){
    cout<<setw(10)<<"Id"<<setw(15)<<"Arival Time"<<setw(15)<<"Burst Time"<<setw(15)<<"Exit Time"<<setw(20)<<"Turn Around Time"<<setw(20)<<"Waiting Time";
    cout<<endl;

    for(auto u:v){
        cout<<setw(9)<<u.id<<setw(15)<<u.arival<<setw(15)<<u.burst<<setw(15)<<u.exi<<setw(15)<<u.turn<<setw(15)<<u.wait<<endl;
    }
}
int main(){
	int n;cin>>n;
	vector<process>v(n);
	for(auto &u:v){
		cout<<"ID : ";
		cin>>u.id;
		cout<<"Arival Time : ";
		cin>>u.arival;
		cout<<"Burst Time : ";
		cin>>u.burst;

		u.exi=0,u.turn=0,u.wait=0;
	}
	calculate(v);
	gantt(v);
	printt(v);

}
