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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
const ll mod=1e9+7;
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
int a[2*maxsize+5];
ll ans=0;
vector<ll>p;
void nhap()
{
    int n;
    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        int k=lower_bound(p.begin(),p.end(),a[i])-p.begin();
        ans+=1;
        if(k==p.size())
        {
            ans=(ans%mod+1%mod)%mod;
            p.push_back(a[i]);
        }
        else
        {
            p[k]=a[i];
            ans=(ans%mod+(k+1)%mod)%mod;
        }
        cout << i <<" "<<ans << endl;
    }
    cout << ans << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}


