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
#define task "20TI0901CONVEXHULL"
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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
ii a[N+5],b[N+5];;
bool check[N+5];
void operator -= (ii& A,ii B)
{
    A.fi-=B.fi;
    A.se-=B.se;
}
bool clr(ii a,ii b,ii c)
{
    c-=b;
    b-=a;
    return 1LL*b.fi*c.se>=1LL*c.fi*b.se;
}
bool cmp(ii a,ii b)
{
    if(a.fi!=b.fi)return a.fi<b.fi;
    else return a.se<b.se;
}
ii maxx=ii(mod,mod);
ll pos;
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].fi >> a[i].se;
        if(a[i].se<maxx.se)
        {
            maxx.fi=a[i].fi;
            maxx.se=a[i].se;
            pos=i;
        }
        else
        {
            if(a[i].se==maxx.se)
            {
                if(a[i].fi<maxx.fi)
                {
                     maxx.fi=a[i].fi;
                     pos=i;
                }
            }
        }
    }
    sort(a+1,a+1+n,cmp);
    ll ans=0;
    ll hull[N+5];
        int k=1;
        memset(check,true,sizeof check);
        for(int i = 1 ; i<=n ; i++)
        {

            while(k>2&&clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--; //upper
            hull[k]=i;
            k++;
        }
        //cout << k << endl;
        int t=k+1,vt,p=k;
        for(int i = n ; i>=1; i--)
        {
            while(k>t&&clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--;//lower
            hull[k]=i;
            if(a[i].fi==maxx.fi&&a[i].se==maxx.se)vt=k;
            k++;
        }
        int m=1;
        for(int j= vt; j >=t-1 ; j--)
            if(check[hull[j]]==true)
            {
                b[m]=a[hull[j]];
                m++;
                check[hull[j]]=false;
            }
        for(int j = p ; j>=1 ; j--)
            if(check[hull[j]]==true)
            {
                b[m]=a[hull[j]];
                m++;
                check[hull[j]]=false;
            }

        for(int j = k-1 ; j > vt ; j--)
            if(check[hull[j]]==true)
            {
                b[m]=a[hull[j]];
                m++;
                check[hull[j]]=false;
            }

        cout << m-1<< endl;
        ll sx=0,sy=0;
        for(int i = 1 ; i <m-1 ; i++) sx += b[i].fi*b[i+1].se;
        sx += b[m-1].fi*b[1].se;
       for(int i = 1 ; i <m-1 ; i++) sy += b[i].se*b[i+1].fi;
        sy+=b[m-1].se*b[1].fi;
        cout << abs(sx-sy)/2 << "." << (abs(sx-sy)%2==0?"0":"5") << endl;
        for(int i = 1 ; i < m ; i++)
            cout << b[i].fi << " "<< b[i].se << endl;
}
int main()
{

    fastio();
     inti();
    nhap();
}





