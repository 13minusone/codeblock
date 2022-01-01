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
int n,t,k,s=0;
ll a[maxsize+5],pos=0;
vector<ll>vec;
void nhap()
{
    int t;
    cin >> t;
    while(t--)
    {
        vec.clear();
        cin>>n >> k;
        s=0;
        pos=-LONG_MAX;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            vec.push_back(a[i]);
        }
        sort(vec.begin(),vec.end());
        for(int i = 1; i<=n;i++)
        {
            int g=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
            if(i-g!=pos)
            {
                s++;
                pos=i-g;
            }
        }
        if(s<=k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



