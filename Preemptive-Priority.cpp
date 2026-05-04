#include<bits/stdc++.h>
using namespace std;
struct process{
    string id;
    int arival;
    int burst;
    int priority;
    int exit;
    int turn;
    int wait;
};
vector<string>gid;
vector<int>g;
bool cmp(const process &p1,const process &p2){
    if(p1.arival==p2.arival)return p1.id<p2.id;
    return p1.arival<p2.arival;
}
void calculate(vector<process>&v){
    sort(v.begin(),v.end(),cmp);
    int n = v.size();
    vector<int>rem(n);
    for(int i =0;i<n;i++){
        rem[i]=v[i].burst;
    }
    int i =0,cur=0,complete=0;
    string last;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    while(complete<n){
        while(i<n && cur>=v[i].arival){
            pq.push({v[i].priority,i});
            i++;
        }
        if(pq.empty()){
            if(last!="Idle"){
                gid.push_back("Idle");
                last="Idle";
                g.push_back(cur);
            }
            cur=v[i].arival;
        }
        else{
            int j = pq.top().second;
            pq.pop();

            if(last!=v[j].id){
                last=v[j].id;
                gid.push_back(last);
                g.push_back(cur);
            }
            rem[j]--;
            cur++;
            if(rem[j]==0){
                complete++;
                v[j].exit=cur;
                v[j].turn=cur-v[j].arival;
                v[j].wait=v[j].turn-v[j].burst;
            }
            else{
                pq.push({v[j].priority,j});
            }

        }
    }
    g.push_back(cur);
    
}
void gant(){
    cout<<"\t";
    for(auto u:gid)cout<<u<<"\t|\t";
    cout<<endl;
    for(auto u:g){
        cout<<u<<"   \t\t";
    }
    cout<<"\n\n";

}

void printt(vector<process>&v){
    
    cout<<"Id\t"<<"AT\t"<<"BT\t PR\t ET\t TAT\t WA\t\n\n";
    for(auto &u:v){
        cout<<u.id<<"\t"<<u.arival<<"\t"<<u.burst<<"\t"<<u.priority<<"\t"<<u.exit<<"\t"<<u.turn<<"\t"<<u.wait<<"\n";
    }
}



int main(){
    int n ;cin>>n;
    vector<process>v(n);
    
    for(auto &u:v){
        cin>>u.id>>u.arival>>u.burst>>u.priority;
    }
    calculate(v);
    gant();
   printt(v);

}
