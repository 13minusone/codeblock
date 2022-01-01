/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "keyboard"
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
const ll mod =1e9+9;
const ll base = 311;
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
char a[55][55];
ii d[10];
int cnt=1;
int cha[55][55];
 int n,m,q,y;
void dfs(int i,int j,int x)
{
    if(i>n||i<1||j>m||j<1)
    {
        return;
    }
    if(a[i+1][j]!='X')
    {
        if(cha[i+1][j]==0)
        {

            cha[i+1][j]=x;
            dfs(i+1,j,x);
        }
    }
    if(a[i-1][j]!='X')
    {
        if(cha[i-1][j]==0)
        {
            cha[i-1][j]=x;
            dfs(i-1,j,x);
        }
    }
    if(a[i][j+1]!='X')
    {
        if(cha[i][j+1]==0)
        {
            cha[i][j+1]=x;
            dfs(i,j+1,x);
        }
    }
    if(a[i][j-1]!='X')
    {
        if(cha[i][j-1]==0)
        {
            cha[i][j-1]=x;
            dfs(i,j-1,x);
        }
    }
}
void nhap()
{
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ;j++)
        {
          cin >> a[i][j];
          if('0'<=a[i][j]&&a[i][j]<='9')
          {
              d[cnt].first=i;
              d[cnt].second=j;
              cnt++;
          }
        }
    }
    int x;
    for(int i = 1 ; i <cnt;i++)
    {
        x=int(a[d[i].first][d[i].second]-'0')+1;
        cha[d[i].first][d[i].second]=x;
        dfs(d[i].first,d[i].second,x);
    }
    string s;
    while(q--)
    {
        cin >> x >> y;
        if(a[x][y]!='X')
        {
            //cout << a[x][y] << endl;
            if(cha[x][y]>=1)
            {
                s=s+char(cha[x][y]-1+'0');
            }
        }
    }
    //cout << s.size() << endl;
    if(s.size()!=0)
    {
        cout << s ;
    }
    else
    {
        cout << "Empty";
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}



