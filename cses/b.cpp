/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
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
void nhap()
{
    int t;
    unsigned ll a,b,c;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        ll s=max(a,b)-min(a,b);
        ll d=2*s;
        if(a>d||b>d)
        {
            cout << -1 << endl;
            continue;
        }
        if(c+s<=d&&c+s!=max(a,b)&&c+s>s)
        {
            cout << c+s << endl;
        }
        else
        {
            if(c-s>=1&&c-s!=(min(a,b))&&c-s<=s)
            {
                cout << c-s << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



