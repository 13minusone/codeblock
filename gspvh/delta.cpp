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
#define task "delta"
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
const ll N = 5e5+5;
const ll mod =998244353;
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
int sub,n,k;
ll a[N],frac[N];
ll su=0,res=0;
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
ll powe(int i ,int k)
{
    if(k==0)return 1;
    if(k==1)return i;
    ll t=powe(i,k/2);
    if(k&1)return ((t*t)%mod*(i%mod))%mod;
    else return t*t%mod;
}
void nhap()
{
    deque<int>que,st;
    cin >> sub >> n  >> k;
    frac[0]=1;
    int j=1;
    for(int i = 1 ; i <= n ;i++)frac[i]=(frac[i-1]*2)%mod;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
         while ((!que.empty()) && (a[que.front()] < a[i]))que.pop_front();
        while ((!st.empty()) && (a[st.front()] > a[i]))st.pop_front();
        que.push_front(i);
        st.push_front(i);
        while ((!que.empty()) && (!st.empty()) && (j < i) && (a[que.back()] - a[st.back()] > k))
        {
            if (j == que.back())que.pop_back();
            if (j == st.back())st.pop_back();
            ++j;
        }
        add(su,i-j+1);
    }
    sort(a+1,a+1+n);
    queue<int>qu;
    for(int i = 1 ; i <= n ; i++)
    {
        qu.push(i);
        while(!qu.empty()&&abs(a[qu.front()]-a[i])>k){
                qu.pop();
        }
        add(res,frac[i-qu.front()]);
        //cout << qu.front() << endl;
    }
    cout << su << " "<< res ;

}
int main()
{

    fastio();
    inti();
    nhap();
}




