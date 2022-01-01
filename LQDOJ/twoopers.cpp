/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
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
ll h[2*N+5],Pow[2*N+5],ht[N+5];
ll gethash(ll hasht[],int i,int j)
{
    return (hasht[j]-hasht[i-1]*Pow[j-i+1]+mod*mod)%mod;
}
ll check(int le,int nt)
{
   int k=1,l=1,r=nt;
    while(l<r)
    {
        int m=(l+r)/2;
        if(gethash(h,le,le+m)==gethash(ht,1,m))
        {
            //cout << m << endl;
            k=m;
            l=m;
        }
        else
        {
            r=m;
        }
    }
    return k;
}
void nhap()
{
    string s,t;
    cin >> s >> t;
    int nt=SZ(t);
    t=" "+t+t;
    s= " "+ s +s ;
    int n=SZ(s)-1;
    //cout << n << endl;
    h[0]=ht[0]=0;
    Pow[0]=1;
    for(int i = 1 ; i <= n ;i++)
    {
        Pow[i]=(Pow[i-1]*base)%mod;
        h[i]=(h[i-1]*base+int(s[i]-'A'))%mod;
        ht[i]=(ht[i-1]*base+t[i]-'A')%mod;
        //cout << h[i] << endl;
    }
    //cout << gethash(h,1,2) << endl;
    int su=0;
    for(int i = 1 ; i <= nt ; i++)
    {
         int k=check(i,nt);
        cout << i << " "<< k << endl;
        if(k==i+nt-1)
        {
            su++;
        }
        else
        {
            if(gethash(h,k+2,i+nt-1)==gethash(ht,k+2,i+nt-1))
            {
                su++;
            }
        }
    }
    cout << su ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




