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
const ll N = 3005;
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
    //freopen(task".out","w",stdout);
}
int r,c,h,w,a[N][N],cnt[N][N],k;
bool cango(int i,int j)
{
    if(i-h>=0&&j-w>=0)
    {
        return true;
    }
    else return false;
}
bool check(int mid)
{

    for(int i = 1; i <= r ; i++)
    {
        for(int j = 1 ; j <=c; j++)
        {
            cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+(a[i][j]>=mid);
            if(cango(i,j))
            {
                int x = cnt[i][j]-cnt[i][j-w] - cnt[i-h][j]+cnt[i-h][j-w];
                if(x>=k)return true;
            }
        }
    }
    return false;
}
void nhap()
{
    cin >> r >> c >> h >> w;
    for(int i = 1 ; i <= r ; i++)
    {
        for(int j = 1 ; j <= c; j++)
        {
           cin >> a[i][j];
        }
    }
    k=(h*w)/2+1;
    int le = 1, ri= r*c,res=0,mid;
   while(le<=ri)
    {
        mid=(le+ri)>>1;
        if(check(mid))
        {
            res=mid;
            le=mid+1;
        }else ri=mid-1;
    }
    cout << res;
}
int main()
{

    fastio();
    //inti();
    nhap();
}




