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
    sort(v.begin(),v.end(),cmp);
    int n = v.size();
    vector<process>result;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int i =0,cur=0;
    while(result.size()<n){
       while(i<n && cur>=v[i].arival){
        pq.push({v[i].burst,i});
        i++;
       }
        if(pq.empty()){
            cur=v[i].arival;
        }
        else{
            int j = pq.top().second;
            pq.pop();
            cur+=v[j].burst;
            v[j].exi=cur;
            v[j].turn=cur-v[j].arival;
            v[j].wait=v[j].turn-v[j].burst;
            result.push_back(v[j]);
        }
    }
    v=result;
}
void gant(vector<process>&v){
    int cur=0;
    for(auto u:v){
        if(cur<u.arival){
            cout<<"Idle\t|\t";
        }
        cur=u.exi;
        cout<<u.id<<"\t|\t";
    }
     cout<<"\n";
    cur=0;
    cout<<cur<<"   \t";
    for(auto u:v){
        if(cur<u.arival){
            cout<<u.arival<<"\t\t";
        }
        cur=u.exi;
        cout<<cur<<"   \t\t";
    }
    cout<<"\n\n";
}

void printt(vector<process>&v){
    cout<<"Id\t"<<"AT\t"<<"BT\t ET\t TAT\t WA\t\n\n";
    for(auto &u:v){
        cout<<u.id<<"\t"<<u.arival<<"\t"<<u.burst<<"\t"<<u.exi<<"\t"<<u.turn<<"\t"<<u.wait<<"\n";
    }
}
int main(){
    int n;cin>>n;
    vector<process>v(n);
    for(auto &u:v){
        cout<<"Id: ";
        cin>>u.id;
        cout<<"\n";
        cout<<"Arival: ";
        cin>>u.arival;
        cout<<"\n";
        cout<<"Burst Time: ";
        cin>>u.burst;
        cout<<"\n";

    }
    calculate(v);
    gant(v);
   printt(v);
}
