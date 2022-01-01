#include<bits/stdc++.h>
using namespace std;
#define task "SUM216TOUR"
#define ll long long
#define SZ(c) (int)c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 1e15;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int  m , n , k,cha[1005],dd[10005],x,y;
ll minn= maxsize,s=0,z;
vector<int>a[1005];
vector<vector<ll>>c(1005,vector<ll>(1005,0));
void dfs(int u)
{
   // cout << u << endl;
   if(SZ(a[u])==0)
   {
       return;
   }
    for(int i = 0 ; i <SZ(a[u]);i++)
    {
        int v=a[u][i];
            if(k==0&&v==1)
            {
                ll g=s+c[u][v];
                //cout << g << endl;
                minn=min(minn,g);
                continue;

            }
        if(cha[v]!=u)
        {
            int h=cha[v];
            if(dd[v]==1)
            {
                k--;
                cha[v]=u;
                dd[v]=0;
                s+=c[u][v];
                dfs(v);
                k++;
                cha[v]=h;
                s-=c[u][v];
                dd[v]=1;

            }
            else
            {
                cha[v]=u;
                s+=c[u][v];
                dfs(v);
                cha[v]=h;
                s-=c[u][v];
            }
            //cout << v <<  " " << s << endl;
        }
    }
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void nhap()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i<= n ; i++)
    {
        dd[i]=0;
        cha[i]=0;
        a[i].clear();
    }
    if(k==0)
    {
        cout << 0 << endl;
        return ;
    }
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> x;
        if(x<=n)
        {
            dd[x]=1;
        }
    }
    for(int i = 1; i<= m ; i++)
    {
        cin >> x >> y >> z;
        a[x].push_back(y);
        c[x][y]=z;
    }

    cha[1]=-1;
    dfs(1);
    if(minn==maxsize)
    {
        cout << -1;
    }
    else{
    cout << minn ;
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




