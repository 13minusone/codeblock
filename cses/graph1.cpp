#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
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
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
ll d[1003][1003];
char f[1003][1003];
void dfs(int i,int j)
{
    if(f[i][j]=='.')
    {
        if(d[i][j]==0)
        {
            d[i][j]=1;
            dfs(i+1,j);
            dfs(i,j+1);
            dfs(i-1,j);
            dfs(i,j-1);
        }
    }
}


void nhap()
{
    ll n,m;
    cin >> n >> m ;
    for(int  i = 1 ; i <= n ; i++)
    {
        for(int  j = 1 ; j <= m ; j++)
        {
            cin >> f[i][j];
        }
    }
    ll s=0;
    for(int i = 1 ; i<=n ; i++)
    {
        for(int  j = 1 ; j <= m ; j++)
        {
            if(f[i][j]=='.')
            {
                if(d[i][j]==0)
                {
                    s++;
                    dfs(i,j);
                }
            }
        }
    }
    cout << s;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



