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
int n,m;
int f[1005][1005];
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
ll cnt[1005],ans=0;
int a[1005][1005];
void nhap()
{
    cin >> n >> m;
    stack<int>st;
    for(int i = 1 ; i <= n ; i++)
    {

        //cnt[0]=0;
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == a[i-1][j])
            {
                f[i][j]=f[i-1][j]+1;
            }
            else
            {
                f[i][j]=1;
            }
        }
        //cout << endl;
        for(int j = 1 ; j <= m ; j++)
        {
            while(!st.empty()&&f[i][st.top()]>=f[i][j]&&a[i][st.top()]==a[i][j])st.pop();
            ll hi=(st.empty()?0 : st.top());
            cnt[j]=(j-hi)*f[i][j];
            if(a[i][hi]==a[i][j])cnt[j]+=cnt[hi];
            ans+=cnt[j];
            st.push(j);
        }
        while(!st.empty())st.pop();
    }
    cout << ans ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




