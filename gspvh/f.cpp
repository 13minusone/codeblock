#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
typedef pair<char,char> ii;
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
ll f[maxsize+5];
void nhap()
{
    ll n,k,m,a,b;
    string s,e,r;
    cin >> n >> k >> m;
    for(int i = 1 ;i<=k;i++)
    {
        cin >> a >> b;
    }
    for(int i = 1 ;i <=m ;i++)
    {
        cin >> s >> e >> r;

    }
    for(int i = 1 ; i <= n ;i++)
    {
        f[i]=i;
    }
    {
    while(next_permutation(f+1,f+n)){
            for(int i = 1 ;i<=n;i++)
    {
        cout << f[i] << " ";
    }
    break;

    }

}
}
int main()
{

    fastio();
    // inti();
    nhap();
}



