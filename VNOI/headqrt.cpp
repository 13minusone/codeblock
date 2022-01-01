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
void operator -=(ii& a, ii b)
{
    a.fi-=b.fi;
    a.se-=b.se;
}
bool  cw(ii a,ii b, ii c)
{
    c-=b;
    b-=a;
    return 1LL*b.fi*c.se<1LL*c.fi*b.se;
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
ll t,n,x,y,z;
ii a[30005],b[30005];
int s0[30005],s1[3005];
void convex(ii a[],int n,int s[],int& m)
{
    m=0;
    for(int i = 1 ; i <= n ; i++)
    {
        while(m>=2&&cw(a[s[m-2]],a[s[m-1]],a[i])==true)m--;
        m++;
        s[m]=i;

    }
    for(int i = n-1 ,t=m+1; i  ; i--)
    {
        while(m>=t&&cw(a[s[m-2]],a[s[m-1]],a[i])==true)m--;
        if(i>1){
                m++;
        s[m]=i;
        }

    }
}
ll canh(ii a,ii b)
{
    b-=a;
    ll c=(1LL*b.fi*b.fi+1LL*b.se*b.se);
    return c;
}
inline ll sqrt(ll x)
{
    ll l = 1, r = 1e9;
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (mid*mid <= x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        int n0=0,n1=0;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> x>> y >> z;
            if(z==1)
            {
                n1++;
                a[n1]=ii(x,y);
            }
            else
            {
                n0++;
                b[n0]=ii(x,y);
            }
        }
        int m0,m1;
        sort(a+1,a+1+n1);
        sort(b+1,b+1+n0);
        convex(a,n1,s1,m1);
        convex(b,n0,s0,m0);
        ll maxx=0;
        for(int i = 1 ; i <=m1 ; i++)
        {
            for(int j = 1; j <=m0; j++)
            {
                maxx=max(maxx,sqrt(canh(a[s1[i]],b[s0[j]])));
            }
        }
        cout << maxx << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




