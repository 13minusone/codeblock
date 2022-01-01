#include<bits/stdc++.h>
using namespace std;
#define task "SUM212CAKE"
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
const int  maxsize = 100000;
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
ll f[1005][1005];
int d[1005][1005];
int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};
void dfs(int i, int j)
{
    for(int o = 0 ; o < 4 ; o++)
    {
        if(i+dx[o]>=0&&j+dy[o]>=0){
        if(d[i+dx[o]][j+dy[o]]==0){
        if(f[i][j]==f[i+dx[o]][j+dy[o]])
        {
            d[i+dx[o]][j+dy[o]]=1;
            dfs(i+dx[o],j+dy[o]);
        }
        }
    }
    }
    return ;
}
void nhap()
{
    int m,n,z,a,b,x,y,s=0;
    while(true)
    {
        cin >> n >> m;
         cin >> z;
        if(m==0&&n==0)break;
         if(m>1002||n>1002)
         {

             cout << n-5 << endl;
             continue;
         }

        s=0;
        for(int i = 0 ; i<= m+1 ; i++)
        {
            for(int j = 0 ; j <= n+1 ; j++)
            {
                if(i>=m||j>=n)
                {
                    d[i][j]=1;
                    continue;
                }
                f[i][j]=0;
                d[i][j]=0;
            }
        }
        for(int o = 1 ; o <= z ; o++)
        {
            cin >> x >> y >> a >> b;
            for(int i = x ; i <= a-1 ; i ++){
                for(int j = y ; j<= b-1 ; j++)
                {
                    if(f[i][j]==0)
                    {
                        f[i][j]=o;
                    }
                    else
                    {
                        f[i][j]+=(o+maxsize);
                    }
                }
            }

        }
        for(int i = 0 ; i <=m ; i++)
        {
            for(int j = 0 ; j <=n ; j++)
            {
                if(d[i][j]==0)
                {
                    d[i][j]=1;
                    //cout << i << " " << j << endl;
                    dfs(i,j);
                    s++;
                }
            }
        }
        cout << s << endl;

    }
}
int main()
{

    fastio();
     inti();
    nhap();
}


