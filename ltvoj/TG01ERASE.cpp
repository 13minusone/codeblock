/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
*/
#include<bits/stdc++.h>
#define name "practice"
#define name1 "tg01erase"
#define maxn 100005
#define oo LLONG_MAX
#define INF INT_MAX
#define fo(i,a,b) for(ll i=a;i<=b;++i)
#define CONST
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define e endl
using namespace std;
typedef long long ll;

string s;
ll l[maxn],r[maxn];
int n;

void cre_l_r();
ll convert(int i, int j);
int find_l(int pos);
int find_r(int pos);

ll cal(int L, int R, int del)
{
    ll res=0;
    if(L==R&&L==del)
    {
        char type='+';
        for(int i=L-1; ; i--){
            if(i<1) break;
            if(s[i]=='+'||s[i]=='-')
            {
                if(s[i]=='-'){
                    if(type=='+') type='-';
                    else type='+';
                }
            }
            else{
                res=l[i];
                break;
            }
        }
         for(int i=R+1; ; i++){
            if(i>n) break;
            if(s[i]=='+'||s[i]=='-')
            {
                if(s[i]=='-'){
                    if(type=='+') type='-';
                    else type='+';
                }
            }
            else{
                if(type=='+') res=res+r[i];
                else res=res-r[i];
                break;
            }
        }
        return res;
    }
    for(int i=L; i<=R; ++i){
        if(i==del) continue;
        res=res*10+(s[i]-'0');
    }
    return res;
}

void solve()
{
    ll res=-1e18;
    cre_l_r();
    res=l[n];
    for(int i=2; i<n; ++i){
        int L=find_l(i);
        int R=find_r(i);
        ll tmp=cal(L,R,i);
        if(L==R){
            res=max(res,tmp);
            continue;
        }
        char type='+';
        for(int j=L-1; j>=1; --j){
            if(s[j]=='+'||s[j]=='-'){
                if(s[j]=='-'){
                    if(type=='+') type='-';
                    else type='+';
                }
            }
            else{
                if(type=='+') tmp=l[j]+tmp;
                else tmp=l[j]-tmp;
                break;
            }
        }
        type='+';
         for(int j=R+1; j<=n; ++j){
            if(s[j]=='+'||s[j]=='-'){
                if(s[j]=='-')
                {
                    if(type=='+') type='-';
                    else type='+';
                }
            }
            else{
                if(type=='+') tmp=tmp+r[j];
                else tmp=tmp-r[j];
                break;
            }
        }
        res=max(res,tmp);
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    freopen(name1".inp","r",stdin);
    freopen(name1".out","w",stdout);
    cin>>s;
    solve();
}

void cre_l_r()
{
    n=s.size();
    s=' '+s;
    char type='+';
    for(int i=1,curr=1; i<=n; ++i){
        l[i]=l[i-1];
       if(s[i]=='+'||s[i]=='-'){
            if(s[i]=='-')
            {
                if(type=='+') type='-';
                else type='+';
            }
            continue;
       }
       if(s[i-1]=='+'||s[i-1]=='-') curr=i;

       if(i==n||s[i+1]=='+'||s[i+1]=='-')
       {
            if(type=='+'){
                l[i]+=convert(curr,i);
            }
            else l[i]-=convert(curr,i);
            type='+';
       }
    }
    type='+';
    for(int i=n,curr=n; i>=1; --i){
        r[i]=r[i+1];
        if(s[i]=='+'||s[i]=='-'){
            if(s[i]=='-')
            {
                if(type=='+') type='-';
                else type='+';
            }
            continue;
       }
        if(s[i+1]=='+'||s[i+1]=='-') curr=i;

        if(i==1||s[i-1]=='+'||s[i-1]=='-')
        {
            if(s[i-1]=='-'){
                if(type=='+') type='-';
                else type='+';
            }
            if(type=='+'){
                r[i]=convert(i,curr)+r[i];
            }
            else r[i]=convert(i,curr)-r[i];
            type='+';
        }
    }
}

ll convert(int i, int j)
{
    ll res=0;
    for(int pos=i; pos<=j; ++pos)
    {
        res=res*10+(s[pos]-'0');
    }
    return res;
}

int find_l(int pos)
{
    for(int i=pos-1; ; --i)
    {
        if(i==1||s[i]=='+'||s[i]=='-')
        {
            if(i==1)
            {
                return 1;
            }
            else{
                return i+1;
            }
            break;
        }
    }
}

int find_r(int pos)
{
    for(int i=pos+1; ; i++){
        if(i==n||s[i]=='+'||s[i]=='-')
        {
            if(i==n)
            {
                return n;
            }
            else{
                return i-1;
            }
            break;
        }
    }
}
