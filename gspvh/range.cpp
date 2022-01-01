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
const ll maxsize = 600000+5;
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
map<ll,int>d;
ll l,r,a[maxsize+5];
ll n,q;
bool te=true;
void nhap()
{
    cin >> n >> q;
    for(int i = 1 ;i<= n ; i++)
    {
        cin >> a[i];
        d[a[i]]=0;
    }
    for(int i = 1 ; i<= q;i++)
    {
        cin >> l >> r;
        te=true;
        if(r-l+1>5000)
        {
            cout << -1<<" ";
            continue;
        }
        for(int j = l ; j<= r; j++)
        {
            d[a[j]]=0;
        }
        int m=(r-l+1)/2;
        for(int j = l ; j<=r;j++)
        {
            d[a[j]]++;
           //cout << a[j] << " "<< d[a[j]]<<endl;
            if(d[a[j]]>m)
            {
                cout << a[j] << " " ;
                te=false;
                break;
            }
        }
        if(te==true)
        {
            cout << -1 << " " ;
        }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}



