#include<bits/stdc++.h>

using namespace std;
#define task "select"
#define ll long long
#define SZ(c) (ll)c.size()
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
const ll maxsize = 1000005;
const int base = 311;
const ll mod =1e9+9;
int n;
ll hasht[maxsize],powb[maxsize+5],hashn[maxsize],pown[maxsize+5];
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll geth(int i,int j)
{
    return (hasht[j]-hasht[i-1]*powb[j-i+1]+mod*mod)%mod;
}
ll getn(int i,int j)
{
    return (hashn[j]-hashn[i+1]*pown[n-(i-j)]+mod*mod)%mod;
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void nhap()
{
    string s;
    int b;
    ll maxx=0;
    cin >> b;
    cin >>s ;
    n=SZ(s);
    s=" "+s;
    powb[0]=1;
    for(int i = 1 ; i <= n ; i++)
    {
        hasht[i]=(hasht[i-1]*base+s[i])%mod;
        powb[i]=(powb[i-1]*base)%mod;
    }
    hashn[n+1]=0;
    pown[n+1]=1;
    for(int i = n ; i>= 1 ; i--)
    {
        hashn[i]=(hashn[i+1]*base+s[i])%mod;
         pown[i]=(pown[i+1]*base)%mod;
    }
    //cout << hashn[3] -hashn[5]*pown[4]<< endl;
    for(int i = 1; i<=n-1; i++)
    {
        for(int j = n ; j >=i-1;j--)
        {
            int m=(j-i)/2;
            if((j-i)%2==0)
            {
                //cout << i << " "<< j << " "<< m <<" "<< geth(i,m) << " "<<getn(j,m+2) <<   endl;
                if(geth(i,m)==getn(j,m+2))
                {
                    //cout << 1 << endl;
                    maximize(maxx,(ll)j-i+1);
                    break;
                }
            }
            else
            {
                m++;
                //cout << i << " " << j << " " << m+1 << " "<< geth(i,m) << " "<< getn(j,m+1)<< endl;
                if(geth(i,m)==getn(j,m+1))
                {
                   // cout << 1 << endl;
                    maximize(maxx,(ll)j-i+1);
                    break;
                }
            }
           // cout <<i << " " << j <<" "<< maxx << endl;
        }
    }
    cout << maxx << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




