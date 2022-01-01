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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll maxsize = 100000;
const ll maximum=1500000;
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
int a[maxsize+5];
void nhap()
{
    int t, n,k,l,r;
    cin >> t;
    ll maxx;
    ll minn=maximum,minn1=maximum;
    while(t--)
    {
        cin >> n >> k;
        maxx=-(2*maximum);
        minn=maximum,minn1=maximum,l=0,r=0;
        cin >> a[1];
        minn=a[1];
        r=1;
        for(int i = 2 ; i <= n ; i++)
        {
            cin >> a[i];
            maximize(maxx,(ll)(i*(i-1)-k*(a[i-1]|a[i])));
            if(a[i]<=minn)
            {
                if(minn!=maximum)
                {
                    minn1=minn;
                    l=r;
                }
                minn=a[i];
                r=i;
                if(l*r!=0)
                {
                    if(l>r)
                    {
                        maximize(maxx,(ll)(l*r-k*(minn|minn1)));
                    }
                    else
                    {
                        maximize(maxx,(ll)(l*r-k*(minn1|minn)));
                    }
                }
            }
            else
            {
                if(a[i]<=minn1)
                {
                    minn1=a[i];
                    l=i;
                }
                if(l*r!=0)
                {
                    if(l>r)
                    {
                        maximize(maxx,(ll)(l*r-k*(minn|minn1)));
                    }
                    else
                    {
                        maximize(maxx,(ll)(l*r-k*(minn1|minn)));
                    }
                }
            }

        }
        if(l*r!=0)
        {
            if(l>r)
            {
                maximize(maxx,(ll)(l*r-k*(minn|minn1)));
            }
            else
            {
                maximize(maxx,(ll)(l*r-k*(minn1|minn)));
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



