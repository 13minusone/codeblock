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
int a[20],f[mu2(20)];
void nhap()
{
    int n;
    cin >> n;
    for(int i =0 ; i<n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i<mu2(n);i++)
    {
        ll s=0;
        for(int j = 0 ; j<n;j++)
        {
            if(getbit(i,j)==1)
            {
                s-=a[j];
            }
            else
            {
                s+=a[j];
            }
        }
        if(s%360==0)
        {
            cout << "YES" ;
            return;
        }
    }
    cout << "NO";
}
int main()
{

    fastio();
    // inti();
    nhap();
}


