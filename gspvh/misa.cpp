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
#define task "misa"
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
template<class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
const ll N = 1e5;
const ll mod =1e9+9;
const ll base = 311;
int dx8[10]= {-1,-1,-1, 0,0,1,1, 1};
int dy8[10]= { 1,-1, 0,-1,1,0,1,-1};
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
int r,c,d[55][55];
int tinh(int i,int j)
{
    int s=0;
    for(int k = 0 ; k <= 7 ; k++)
    {
        if(a[i+dx8[k]][j+dy8[k]]=='o')s++;
    }
    return s;
}
int solve()
{
    int s=0;
    for(int i = 1 ; i <= r ; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(a[i][j]=='o')
            {
                for(int k = 4 ; k <= 7 ; k++)
                {
                    if(a[i+dx8[k]][j+dy8[k]]=='o')s++;
                }
            }
        }
    }
    return s;
}
void nhap()
{
    cin >> r >> c;
    for(int i = 0 ; i <= c; i++)a[0][i]='.',a[r+1][i]='.';
    for(int j = 0 ; j <= r; j++)a[j][0]='.',a[j][c+1]='.';
    for(int i = 1 ; i <= r ; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> a[i][j];
        }
    }
    int maxx=0,l=r+2,f=c+2;
    //cout << r <<  " "<< c << endl;
    for(int i = 1 ; i <= r ; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(a[i][j]=='.')
            {
                if(tinh(i,j)>maxx)
                {
                    maxx=tinh(i,j);
                    l=i,f=j;
                }
                //cout << i << " "<< j << endl;
            }
        }
    }
    //cout << l << " " << f << endl;
    a[l][f]='o';
    cout << solve();

}
int main()
{

    fastio();
    // inti();
    nhap();
}




