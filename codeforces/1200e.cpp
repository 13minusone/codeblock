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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll MAX = 1000010;
const ll mod=1e9+9;
const ll base=311;
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
ll hasht[MAX],modt[MAX];
vector<vector<ll>>h;
ll gethash(int i,int j)
{
    return (hasht[j]-hasht[i-1]*modt[j-i+1]+mod*mod)%mod;
}
ll geth(int k,int i,int j)
{
    return (h[k][j]-h[k][i-1]*modt[j-i+1]+mod*mod)%mod;
}
string s1,d;
string s[MAX];
void nhap()
{
    int n;
    cin >> n;
    cin >> s[1];
    if(n==1)
    {
        cout <<s[1] ;
        return;
    }
    int k=SZ(s[1]);
    d=d+s[1];
    s[1]=" "+s[1];
    modt[0]=1;
    for(int i = 1 ; i<= k ; i++)
    {
        hasht[i]=(hasht[i-1]*base+s[1][i])%mod;
        modt[i]=(modt[i-1]*base)%mod;
    }
    s1=s1+s[1];
    h.resize(n+3);
    for(int  i = 2 ; i<= n ; i++)
    {

        cin >> s[i];
        k=SZ(s[i]);
        s[i]=" "+s[i];
        h[i].resize(k+3);
        h[i][0]=0;
        for(int j = 1 ; j <= k ; j++)
        {
            h[i][j]=(h[i][j-1]*base+s[i][j])%mod;
        }
    }
    for(int i = 2 ; i<= n ; i++)
    {
        int l=1,r ;
        r=SZ(s[i])-1;
        int g=SZ(s1)-1;
        r=min(r,g);
        for(int j = 1; j<=r; j++)
        {
            if(geth(i,1,j)==gethash(g-j+1,g))
            {
                l=j+1;
            }
        }
        int p=0;
        for(int j = l; j <= SZ(s[i])-1 ; j++)
        {
            s1=s1+s[i][j];
            d=d+s[i][j];
            hasht[g+p+1]=(hasht[g+p]*base+s[i][j])%mod;
            modt[g+p+1]=(modt[g+p]*base)%mod;
            p++;
        }
    }
    cout << d << endl;
}
int main()
{

    fastio();
    //inti();
    nhap();
}



