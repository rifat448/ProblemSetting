/**
 * Author: d0uch3b4g
 * Created: 2020/04/20 00:58:36
**/
#include "bits/stdc++.h" 
#define SIZE          1000005
#define REM           1000000007
#define PI            2*acos(0.0)
#define L             long
#define LL            long long
#define UL            unsigned long
#define ULL           unsigned long long
#define TERMINATE     return 0
#define FAST          ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pick          emplace_back
#define uthao         push_back
#define Pick          insert
using namespace std;
template <class T> inline T bigmod1(T p,T e,T M){
    LL ret=1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
 
template <class T> inline T gcode(T a,T b){if(b==0)return a;return gcode(b,a%b);}
template <class T> inline T modularinv(T a,T M){return bigmod1(a,M-2,M);}
 
bool SA(const pair<string,string> &a, const pair<string,string> &b){
   return a.second<b.second;
}
bool FA(const pair<string,string> &a, const pair<string,string> &b){
   return a.first<b.first;
}
bool SD(const pair<LL,LL> &a, const pair<LL,LL> &b){
   return a.second>b.second;
}
bool FD(const pair<int,int> &a, const pair<int,int> &b){
   return a.first>b.first;
}
//int dirA[8]={0,0,1,-1,1,-1,1,-1};
//int dirB[8]={1,-1,0,0,1,-1,-1,1};
//int dirA[4]={0,0,1,-1};
//int dirB[4]={1,-1,0,0};
//int kingsA[8]={0,0,1,-1,-1,1,-1,1};  //Kings Move
//int kingsB[8]={-1,1,0,0,1,1,-1,-1};  //Kings Move
//int knightsA[8]={-2,-2,-1,-1,1,1,2,2};  //Knights Move
//int knightsB[8]={-1,1,-2,2,-2,2,-1,1};  //Knights Move

vector<pair<LL,LL> > adj[SIZE];
LL res[SIZE],Sub[SIZE],n;
bool vis[SIZE],vis0[SIZE];

void dfs(int s){
	vis[s]=true;
	Sub[s]=1;
	for(int i=0;i<adj[s].size();i++){
		int ch=adj[s][i].first,Chw=adj[s][i].second;
		if(!vis[ch]){
			vis[ch]=true;
			dfs(ch);
			Sub[s]+=Sub[ch];
			res[s]+=res[ch]+(Sub[ch]*Chw);
		}
	}
}

void dfs0(int s){
	vis0[s]=true;
	for(int i=0;i<adj[s].size();i++){
		int ch=adj[s][i].first,chw=adj[s][i].second;
		if(!vis0[ch]){
			vis0[ch]=true;
			res[ch]=res[s]-(Sub[ch]*chw)+((n-Sub[ch])*chw);
			dfs0(ch);
		}
	}
}

int main(){
	FAST;
	//freopen("ff3.txt","r",stdin);
	//freopen("fff4.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pick(make_pair(v,w)); adj[v].pick(make_pair(u,w));
	}
	dfs(1);
	dfs0(1);
	LL mx=INT_MIN;
	for(int i=1;i<=n;i++){
		mx=max(res[i],mx);
		cout<<res[i];
		if(i<n) cout<<" ";
		else cout<<endl;
	}
	//cout<<endl;
	cout<<mx<<endl;
	cerr<<"time elapsed:"<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<"\n";
	return 0;
}

