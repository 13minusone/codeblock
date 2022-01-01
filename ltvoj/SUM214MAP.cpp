#include<bits/stdc++.h>
using namespace std;
#define task "SUM214MAP"
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
const ll maxsize = 50000;
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
    ll n,k;
    cin >> n;
    if(n==1)
    {
        cout << 1 << " " << 1 ;
        return ;
    }
    for(int i = 1; i<maxsize; i++ )
    {
        ll s=0;
        if(i%2==0)
        {
            s=(i+1)*(i/2);
        }
        else
        {
            s=(i+1)*(i/2)+(i/2+1);
        }
        if(s==n)
        {
            cout << 1 << " " << i;
            return;
        }
        if(s>n)
        {
            k=i;
            break;
        }

    }
    //cout << k << endl;
    k--;
    ll f=0,j=1;
    if(k%2==0)
    {
        f=(k+1)*(k/2);
    }
    else
    {
        f=(k+1)*(k/2)+(k/2+1);
    }
    k++;
    for(int j = 1 ; j<=k; j++)
    {
        if(f+j==n)
        {
            cout << k-j+1 << " " << j << endl;
            return ;
        }
    }
}
int main()
{

    fastio();
    //inti();
    nhap();
}



