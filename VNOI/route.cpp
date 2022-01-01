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
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
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
const ll N = 1e5;
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
ii a[1005][1005];
ii dp[1005][1005];
int l[7][1005][1005];
int n,m,x;
string trace(int k)
{
    int x=n,y=m;
    string s;
    while(true)
    {
        if(x==1&&y==1)break;
        if(l[k][x][y]==1)
        {
            s='D'+s;
            x--;
        }
        else
        {
            s='L'+s;
            y--;
        }
    }
    return s;
}
void nhap()
{
    cin >> n >> m;
    int a0=0,j0=0;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> x;
            //cout << x << " ";
            if(x==0)
            {
                a[i][j].fi=mod;
                a[i][j].se=mod;
                if(a0<i)
                {
                    if(j0!=1)
                    {
                        a0=i;
                    j0=j;
                    }
                }
            }
            while(x!=0&&x%2==0)
            {
                a[i][j].fi++;
                x/=2;
            }
            while(x!=0&&x%5==0)
            {
                a[i][j].se++;
                x/=5;
            }
            //cout << a[i][j].fi << " "<< a[i][j].se << endl;
            dp[i][j]=ii(N,N);
        }
    dp[1][1]=a[1][1];
    l[2][1][1]=l[5][1][1]=N;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ;  j <= m ; j++)
        {

            if(dp[i][j].fi>dp[i][j-1].fi+a[i][j].fi&&j>1)
            {
                dp[i][j].fi=dp[i][j-1].fi+a[i][j].fi;
                l[2][i][j]=0;
            }
            if(dp[i][j].fi>dp[i-1][j].fi+a[i][j].fi&&i>1)
            {
                dp[i][j].fi=dp[i-1][j].fi+a[i][j].fi;
                l[2][i][j]=1;
            }

            if(dp[i][j].se>dp[i][j-1].se+a[i][j].se&&j>1)
            {
                dp[i][j].se=dp[i][j-1].se+a[i][j].se;
                l[5][i][j]=0;
            }
            if(dp[i][j].se>dp[i-1][j].se+a[i][j].se&&i>1)
            {
                dp[i][j].se=dp[i-1][j].se+a[i][j].se;
                l[5][i][j]=1;
            }
        }
    ll y,k;
    //cout << a0 << endl;
    if(min(dp[n][m].fi,dp[n][m].se)>=1&&a0!=0)
    {
        cout << 1 << endl;
        string f;
        for(int i = 2 ; i <= a0; i++)f+="D" ;
        for(int i = 2 ; i <= j0 ; i++)f+="L";
        for(int i = a0+1 ; i <= n ; i++)f+="D";
        for(int i = j0+1; i<= m ; i++)f+="L";
        string s;
        if(min(dp[n][m].fi,dp[n][m].se)==1)
        {
            if(dp[n][m].fi<=dp[n][m].se)
            {
                cout << dp[n][m].fi << endl;
                k=2;
            }
            else
            {
                cout << dp[n][m].se << endl;
                k=5;
            }
            s=trace(k);
            cout << min(s,f) ;
        }
        else
        {
            cout << f << endl;
        }


    }
    else
    {
        string s,f;
        if(dp[n][m].fi==dp[n][m].se)
        {
            cout << dp[n][m].fi << endl;
            s=trace(2);
            f=trace(5);
            cout << min(s,f);
            return ;
        }
        if(dp[n][m].fi<dp[n][m].se)
        {
            cout << dp[n][m].fi << endl;
            k=2;
        }
        else
        {
            cout << dp[n][m].se << endl;
            k=5;
        }

        s=trace(k);
        cout << s << endl;
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}




