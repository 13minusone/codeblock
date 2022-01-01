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
ll a[100005],s[100005],n,k;
vector<ll>vec;
void nhap()
{
    cin >> n >> k ;
    for(int i = 1 ;i<=n;i++ )
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
        vec.push_back(s[i]);
        for(int j=i-1;j>=1;j--)
        {
            vec.push_back(s[i]-s[j]);
        }
    }
    sort(vec.begin(),vec.end(),greater<ll>());
    cout << vec[k-1];
}
int main()
{

    fastio();
    // inti();
    nhap();
}



