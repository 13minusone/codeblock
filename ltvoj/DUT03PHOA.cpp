#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define F first
#define S second
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define task "DUT03PHOA"

const int N = 2e5+10;
const int M = 2e3+10;
const LL INF = 1e9;
const LL LINF = 1e14;
const LL MOD = 1e9+7;
const double PI = 3.141592653589793;

vector<pair<int,LL>>adj[N];
LL dp[N][350];
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void dfs(int i){

    if(adj[i].empty()){
        for(int j=1;j<=300;j++)
            dp[i][j] = LINF;
    }

    for(auto x:adj[i]){

        dfs(x.F);

        for(int j=0;j<=300;j++){

            LL mn = LINF;
            for(int k=0;k<=j;k++)
                mn = min(mn,dp[x.F][k]+abs(x.S-(abs(k-j))));

            dp[i][j] += mn;
        }
    }
}

int main(){

    //freopen("out.txt","w",stdout);
    inti();
    int n,m;
    scanf("%d%d",&n,&m);
        for(int i=2;i<=n+m;i++){
        LL v,w;
        scanf("%lld%lld",&v,&w);
        adj[v].push_back({i,w});
        }

    dfs(1);

    LL ans = LINF;
    for(int i=0;i<=300;i++)
        ans = min(ans,dp[1][i]);

    printf("%lld",ans);
    }

//
