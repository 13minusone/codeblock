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
#define task "T1002FLOWERS"
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
ll sum[105],a[105];
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll s=0;
    for(int i = 1 ; i<= n ; i++)
    {
        for(int j = i ; j<= n ; j++)
        {
            int h=sum[j]-sum[i-1];
            if(h%(j-i+1)!=0)continue;
            else h/=(j-i+1);
            for(int k = i ; k <= j ; k++)
            {
                if(a[k]==h){
                    s++;
                    break;
                }
            }
        }
    }
    cout << s;
}
int main()
{

    fastio();
    inti();
    nhap();
}




