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
#define task "permute"
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
bool check[4*N+5];
vector<int>vec;
int a[4*N+5];
void nhap()
{
    int t,n;
    cin >> t;
    cin >> n;
    memset(check,true,sizeof check);
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> a[i];
        if(a[i]!=-1)
        {
            check[a[i]]=false;
        }
    }
    for(int i = 1 ;i <= n ; i++)
    {
        if(check[i]==true)
        {
            vec.push_back(i);
        }
    }
    int k=0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i]==-1)
        {
            cout << vec[k] << " ";
            k++;
        }
        else
        {
            cout << a[i] << " ";
        }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}




