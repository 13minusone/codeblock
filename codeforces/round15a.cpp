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
char a[50],b[50];
int t,n;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        int s=0;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i];
            b[i]=a[i];
        }
        sort(a,a+n);
        for(int i = 0 ; i < n ; i++ )
        {
            if(a[i]!=b[i])
            {
                s++;
            }
        }
        cout << s << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



