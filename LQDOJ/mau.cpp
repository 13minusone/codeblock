
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
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e6+6;
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
    //freopen(task".out","w",stdout);
}
int cnt[N],n,q,x;
string s;
 stack<char>st;
ll submo()
{
    for(int i = 1; i <= n ; i++)
    {
        if(s[i]=='(')
        {
            s[i]=')';
            st.push(s[1]);
            int k=0;
            for(int j = 2 ;  j <= n ; j++)
            {
                k=j;
                if(s[j]==')')
                {
                    if(st.empty()||st.top()==')')break;
                    else st.pop();
                }
                else st.push(s[j]);
            }
            if(st.empty()&& k==n)return i;
            else
            {
                while(!st.empty())st.pop();
                s[i]='(';
            }
        }
    }
}
ll subdong()
{
    for(int i = 1; i <= n ; i++)
    {
        if(s[i]==')')
        {
            s[i]='(';
            st.push(s[1]);
            int k=0;
            for(int j = 2 ;  j <= n ; j++)
            {
                k=j;
                if(s[j]==')')
                {
                    if(st.empty()||st.top()==')')break;
                    else st.pop();
                }
                else st.push(s[j]);
            }
            if(st.empty() && k==n)return i;
            else
            {
                while(!st.empty())st.pop();
                s[i]=')';
            }
        }
    }
}
void nhap()
{
    cin >> n >> q;
    cin >> s;
    int sum=0;
    s=' '+s;
    for(int i = 1; i <=n ; i++)
    {

        if(s[i]=='(')sum++;
        else sum--;
        cnt[i]=sum;
    }
    while(q--)
    {
        cin >> x;
        if(n<=7000)
        {
            if(s[x]=='(')s[x]=')';
        else s[x]='(';
        for(int i = x; i <= n ; i++)
        {
            if(s[i]=='(')cnt[i]=cnt[i-1]+1;
            else cnt[i]=cnt[i-1]-1;
        }
        if(s[x]=='('){
           int y=submo();
            s[y]=')';
            cout << y << " ";
        }
        else
        {
            int y=subdong();
            s[y]='(';
            cout << y << " ";
        }
        }else cout << x << " " ;
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}
