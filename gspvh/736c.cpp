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
ll a[2*maxsize+5];
void nhap()
{
    int t,n;
    ll g,s=0,maxx=1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        maxx=1;
        for(int i = 1;i <= n ; i++)
        {
            cin >> a[i];
        }
        for(int i = 1 ; i <= n ; i++)
        {
            int s=a[i];
            for(int  j = i+1; j <= n ; j++)
            {
                s+=a[j];
                if(s%(j-i+1)==0)
                {
                    maximize(maxx,(ll)j-i+1);
                }
                else
                {
                    break;
                }
            }

        }
        cout << maxx << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}


