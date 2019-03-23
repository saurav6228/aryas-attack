
#include<bits/stdc++.h>
#define ll           long long
#define vi           vector<ll>
#define pb           push_back
#define all(a)       (a).begin(),(a).end()
#define F            first
#define S            second
#define sz(x)        (int)x.size()
#define hell         1000000007
#define endl         '\n'
#define fl(z,a,b)   for(ll z=a;z<b;z++)
#define ffl(i,a,b)  for(int i=a;i<=b;i++)
#define speed        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x)    cerr << "at line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define debug2(x)    cerr << #x << " = " << (x) << endl
using namespace std;
//=====================
const int MAXN = 1e5+5;
int disc[MAXN],low[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];
int sz[MAXN];
int tme=0,ans=0;
int p,n; int cc=0;

void ddffss(int s)
{
	vis[s]=true;
	cc++;
	for(auto i:adj[s]) if(!vis[i]) ddffss(i);
}

void dfs(int s,int par=-1)
{
	++tme;
	vis[s]=true;
	disc[s]=low[s]=tme;
	sz[s]=1;
	for(auto i:adj[s])
	{
		if(par==i) continue;
		if(!vis[i]) 
		{
			dfs(i,s);
			low[s] = min(low[s],low[i]);
			sz[s] +=  sz[i];
			if(low[i]<disc[s] and abs(sz(i) - (cc-sz(i)))<p ) ans++;
		}
		else low[s] = min(low[s],disc[i]);
	}
}


void solve()
{	
		int m;
		cin>>n>>m>>p;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		ddffss(1);
		memset(vis,false , sizeof(vis));
		dfs(1);
		cout<<ans<<endl;

}
int main()
{

ll TESTS=1;
//cin>>TESTS;
while(TESTS--)
{
      solve();
}
return 0;
}
