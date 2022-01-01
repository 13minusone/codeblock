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
string doichu(ll n)
{
    string g;
    while(n>0)
    {
        int h=n%10;
        g=char(h+'0')+g;
        n/=10;
    }
    g=" "+g;
    return g;
}
string sub1(string s)
{
    for(int i = 2 ; i <SZ(s); i++)
    {
        if(s[1]<s[i])
        {
            string s1;
            char d=char(int(s[1])+1);
            for(int i = 1 ; i<SZ(s); i++)
            {
                s1=s1+d;
            }
            return s1;
        }
    }
    string s1;
    char d=s[1];
    for(int i = 1 ; i<SZ(s); i++)
    {
        s1=s1+d;
    }
    return s1;
}
string sub2(string s)
{
    ll d=1;
    ll k=0;
    string r;
    for(int i = 2 ; i <SZ(s); i++)
    {
        if(s[i-1]<s[i])
        {
           if(k==0)
           {
               d=i;
               k++;
           }
           else
           {
               if(s[i]==s[1])
               {
                   r=r+s[i];
                   continue;
               }
               if(k==1)
               {

                   char f=char(int(s[d]+1));
                   string s1;
                   for(int j = 1 ; j <d;j++)
                   {
                       s1=s1+s[1];
                   }
                   s1=s1+f;
                   f=min(f,s[1]);
                   for(int j = d+1; j<SZ(s);j++)
                   {
                       s1=s1+f;
                   }
                   return s1;
               }
           }
        }
        else
        {
            if(k==1)
            {
                r=r+s[i];
            }
        }
    }
    string s1;
    for(int i = 1 ; i< d ; i++)
    {
        s1=s1+s[i];
    }
    s1=s1+r;
    return s1;
}
void nhap()
{
    int t,k;
    ll dd[200];
    ll n;
    cin >> t;
    while(t--)
    {
        cin>>n >> k;
        string s=doichu(n);
        ll su=0;

            if(k==1)
            {
                cout << sub1(s) << endl;
            }
            else
            {
                cout << sub2(s) << endl;
            }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}



