#include<bits/stdc++.h>
using namespace std;
#define task "SUM215BONUS"
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
ll a[505][505],s=0;
map<ll,int>d;
void nhap()
{
    int n ;
    cin >> n ;
    vector<ll>vec;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
            s+=a[i][j];
            if(d[a[i][j]]==0)
            {
                vec.push_back(a[i][j]);
            }
            d[a[i][j]]++;
        }
    }
    ll maxx=0;
    for(int i = 0 ; i < (int)vec.size();i++)
    {
        maximize(maxx,s-vec[i]*d[vec[i]]);
    }
    cout << maxx;

}
int main()
{

    fastio();
    inti();
    nhap();
}



