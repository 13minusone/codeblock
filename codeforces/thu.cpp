//  ---Author: Đặng Võ Hồng Phúc---  //
#include<bits/stdc++.h>
#define name "practice"
#define maxn
#define oo LLONG_MAX
#define fo(i,a,b) for(ll i=a;i<=b;++i)
#define CONST
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
template<class T> void MIN(T &A, T 😎 {A=min(A,B);}
template<class T> void MAX(T &A, T 😎 {A=max(A,B);}
template<class T> void SUM(T &A, T 😎 {A=A+B;}
template<class T> void HIEU(T &A, T 😎 {A=A-B;}
ll t;
string s;

void solve()
{
    ll res = 0;
    s=' '+s;
    bool type;
    bool next = true;
    ll pt = 1,first=0,d=0;
    while(pt!=s.size())
    {
        if(next)
        {
            if(s[pt]=='?')
            {
                 ll i = pt;
                 while(s[i]=='?') ++i;
                 bool c;
                 if(s[i]=='0') c = false;
                 else c = true;
                 if(i%2==0){
                    if(pt%2==0) type = c;
                    else type = !c;
                 }
                 if(i%2!=0)
                 {
                     if(pt%2!=0) type=c;
                     else type = !c;
                 }
            }
            else
            {
                if(s[pt]=='0') type = false;
                else type = true;
            }
            first = pt;
            next = !next;
        }
        else{
            if(type==0)
            {
                if(s[pt]=='1') next = true;
            }
            if(type==1)
            {
                if(s[pt]=='0') next = true;
            }
        }
        if(next)
        {
            --pt;
            ll tmp = pt-first+1;
            res = res + (tmp*(tmp+1))/2;
            while(s[pt]=='?') pt--,++d;
             res = res - d*(d+1)/2;
             d=0;
        }
        else if(pt==s.size()-1)
        {
            ll tmp = pt-first+1;
            res = res + (tmp*(tmp+1))/2;
        }
        ++pt;
        type=!type;
    }
    cout<<res-d<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
//    freopen(name".inp","r",stdin);
//    freopen(name".out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>s;
        solve();
    }
}
