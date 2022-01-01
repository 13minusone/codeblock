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
int n,m;
ll f[10005];
ll x,y,z;
vector<ii>w[10005];
vector<int>vec;
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> x >> y >> z;
        if(w[x].size()==0)
        {
            vec.push_back(x);
        }
        w[x].push_back(ii(y,z));
    }
    sort(all(vec));
    for(int i : vec)sort(all(w[i],greater<ii>()));
    for(int i : vec)
    {
        int cnt=0,limit=m/i;
        for()
    }
    cout << f[m];
}
int main()
{

    fastio();
    // inti();
    nhap();
}



