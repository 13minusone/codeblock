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
void nhap()
{
    int t;
    ll l,r,s,s1;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        if(r<10&&l<=9)
        {
            cout << 1 <<endl;
            continue;
        }
        if(r<9)
        {
            cout << 0 << endl;
            continue;
        }
        r/=9;
        r*=9;
        if(l%9!=0)
        {
            l/=9;
            l++;
            l*=9;
        }
        if(l>r){
                cout << 0 << endl;
        continue;
        }
        s=(r-l)/9+1;
        cout << s << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



