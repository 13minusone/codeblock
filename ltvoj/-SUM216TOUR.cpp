#include<bits/stdc++.h>
using namespace std;
#define task "SUM216TOUR"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int m , n , k,cha[1005],dd[1005],x,y,z;
ll minn= 1e15+5,s=0;
vector<int>a[1005];
ll c[1005][1005];
void dfs(int u)
{
   // cout << u << endl;
    for(int i = 0 ; i <SZ(a[u]);i++)
    {
        int v=a[u][i];
        if(k==0&&v==1)
        {
            if(k==0&&v==1)
            {
                ll g=s+c[u][v];
                //cout << g << endl;
                minn=min(minn,g);
                continue;

            }
        }
        if(cha[v]!=u)
        {
            int h=cha[v];
            if(dd[v]==1)
            {
                k--;
                cha[v]=u;
                s+=c[u][v];
                dfs(v);
                k++;
                cha[v]=h;
                s-=c[u][v];

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
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> x;
        dd[x]=1;
    }
    for(int i = 1; i<= m ; i++)
    {
        cin >> x >> y >> z;
        a[x].push_back(y);
        c[x][y]=z;
    }
    cha[1]=1;
    dfs(1);
    cout << minn << endl;
}
int main()
{

    fastio();
     inti();
    nhap();
}



