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
#define task "20TI0901TRILAND"
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
typedef pair<ll,ll> ii;
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
void operator -= (ii& A,ii B)
{
    A.fi-=B.fi;
    A.se-=B.se;
}
bool clr(ii a,ii b,ii c)
{
    c-=b;
    b-=a;
    return b.fi*c.se>c.fi*b.se;
}
float canh(ii a,ii b)
{
    b-=a;
    float c=sqrt((b.fi*b.fi+b.se*b.se));
    return c;
}
ll tich(ii a,ii b,ii c)
{
  b-=a;
  c-=a;
  ll p=abs((b.fi*c.se)-(c.fi*b.se));
    return p;
}
ii a[50005];
bool cmp(ii a,ii b)
{
    if(a.fi!=b.fi)return a.fi<b.fi;
    else return a.se<b.se;
}
bool check[50005];
void nhap()
{
    ll n,x,y;
    cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i].fi>> a[i].se ;
        }
        sort(a+1,a+1+n);
        //cout << fixed << setprecision(2) << tich(a[1],a[2],a[3]) << endl;
        if(n<3)
        {
            cout << "0.00" << endl;
        }
        ll ans=0;
        ll hull[50005];
        int k=1;
        for(int i = 1 ; i<=n ; i++)
        {
            check[i]=false;
            while(k>2&&clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--;
            hull[k]=i;
            k++;
        }
        int t=k+1;
        for(int i = n ; i>=1; i--)
        {
            while(k>t&&clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--;
            hull[k]=i;
            k++;
        }
        ll maxx=-10000;
        for(int i = 1 ; i <k; i++)
        {
            int m=i+2;
            for(int j = i + 1; j < k ; j++)
            {
                if(j>=m)m=j+1;
                while(m<k)
                {
                    if(tich(a[hull[i]],a[hull[j]],a[hull[m]])<tich(a[hull[i]],a[hull[j]],a[hull[m-1]]))
                    {
                        maxx=max(maxx,tich(a[hull[i]],a[hull[j]],a[hull[m-1]]));
                        break;
                    }
                    else
                    {
                        m++;
                    }
                }
            }
        }
        cout <<maxx/2  << "." << (maxx%2==0?"0":"5") << endl;
    }

int main()
{

    fastio();
     inti();
    nhap();
}
