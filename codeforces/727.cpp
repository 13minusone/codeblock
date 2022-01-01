/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
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
typedef pair<ll,ll> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 3000010;
const int base = 311;
ll mod[3]={1000000007,1000000009};
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
int n , k,m;
string s;
ll hasht[maxsize][5],powb[maxsize][5];
bool vis[maxsize];
map<ii,int>dd;

ll geth(int l,int r,int t)
{
    ll res= (hasht[r][t]-(hasht[l-1][t]*powb[r-l+1][t])+mod[t]*mod[t])%mod[t];
    return res;
}
void nhap()
{
    cin >> n  >> k ;
    cin >> s;
    s=" "+s+s;

    powb[0][0]=powb[0][1]=1;
    for(int i = 1; i <=n*k*2 ; i++)
    {
        for(int j = 0 ; j<= 1 ; j++)
        {
            hasht[i][j]=(hasht[i-1][j]*base+s[i])%mod[j];
        powb[i][j]=(powb[i-1][j]*base)%mod[j];
        }

    }
    cin >> m;
    string in;
    for(int i =1 ; i <= m ; i++)
    {
        cin >> in;
        ll hashin1=0,hashin0=0;
        for(int j = 0 ; j < k ; j++)
        {
            hashin1=(hashin1*base+in[j])%mod[1];
            hashin0=(hashin0*base+in[j])%mod[0];
        }
        //cout << i << " "<< hashin << endl;
        dd[{hashin0,hashin1}]=i;
    }
    for(int i = 1 ; i <=k ; i++)
    {
        bool ok=true;
        for(int j = i ; j <n*k+i ; j+=k)
        {
            ll val=dd[{geth(j,j+k-1,0),geth(j,j+k-1,1)}];
            vis[val]=0;
        }
        for(int j = i ; j <n*k+i;j+=k)
        {
            ll val=dd[{geth(j,j+k-1,0),geth(j,j+k-1,1)}];
            //cout << val << " ";
            if(val==0||vis[val]==1)
            {
                ok=false;
                break;
            }
            vis[val]=1;
        }
        //cout  << endl;
        if(ok==true)
        {
            cout << "YES" << endl;
            for(int j = i ; j <n*k + i ; j+=k)
            {
                ll val=dd[{geth(j,j+k-1,0),geth(j,j+k-1,1)}];
                cout <<val << " ";
            }
            return;
        }

    }
    cout <<"NO" << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



