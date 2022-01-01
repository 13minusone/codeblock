#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<vector<int>>a(7000+5,vector<int>(7000+5,0));
int dx[10]= {-1,1,1,-1,0,0,1,-1};
int dy[10]= {-1,1,-1,1,1,-1,0,0};
void solve(int n,int m,int  s)
{
    int g[25][25],me=0,su=0;

    bool te=true,tr=true;
    for(int i = 0 ; i<mu2(n*m); i++)
    {
        for(int i = 1 ; i<= n ; i++)
        {
            for(int j = 1 ; j<=m; j++)
            {
                g[i][j]=0;
            }
        }

        te=true;
        tr=true;
        me=0;
        su=0;
        for(int j = 0 ; j <(n*m); j++)
        {
            if(getbit(i,j)==1)
            {
                int h=(j+1)/m;
                int k=(j+1)-h*m;
                g[h+1][k]=1;
            }
        }
        for(int j = 1 ; j <= n ; j++ )
        {
            for(int o = 1 ; o <= m; o++)
            {
                su=0;
                if(g[j][o]==0)
                {
                    for(int k = 0 ; k < 8 ; k++)
                    {
                        if(j+dx[k]<=n&&o+dy[k]<=m&&(o+dy[k])*(j+dx[k])>=1)
                            {
                                if(g[j+dx[k]][o+dy[k]]==1)
                            {
                                su++;
                            }
                            }
                    }
                }
                if(g[j][o]!=a[j][o])
                {
                    te=false;
                }
                me+=su;
            }
        }
        if(me==s)
        {
            tr=false;
        }
        if(tr==false&&te==false)
        {
            for(int p = 1 ; p <= n ; p++)
            {
                for(int j = 1 ; j <=m; j++)
                {
                    cout << g[p][j] << " ";
                }
                cout << endl;
            }
            return;
        }
    }
    cout << -1 ;
    return ;

}
int n,m,s=0;
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];

        }
    }
    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(a[i][j]==0)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }

        }
        cout << endl;
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}
/*
1 30
0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
*/

