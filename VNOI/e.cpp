/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE A.K.A PVM
*/
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
ll a[maxsize*4+5];
ll b[(ll)1e7+5];
void nhap()
{
    ll sub,n,p,q,l,r;
    cin >> sub;
    cin >> n >> q >> p;
    b[0]=1;
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> a[i];
        b[i]=b[i-1]*a[i];
    }
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> l >> r;
        ll maxx=0;
        for(int  j = l ; j<= r; j++)
        {
            ll o=a[j];
            ll s=o;
            for(int k  =1 ; k<= a[j]; k++)
            {
                b[k]=0;
            }
            for(ll k=2; k<=(sqrt(o)); k++)
            {
                if(b[k]==0)
                {
                    if(o%k==0)
                    {
                        b[k]=1;
                        s--;
                        for(int m = k*k; m<=o/k; m+=k)
                        {
                            s--;
                            b[m]=1;
                        }
                    }
                }
                //cout << i << " "<< s << endl;
            }
            cout <<s << endl;
            maxx+=s;

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



