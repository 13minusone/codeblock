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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
vector<int>vec[30];
int a[1500], n;
void chia(int k,int z,int i)
{

    if(i<=n)
    {
    //cout << i << endl;
    vec[i].push_back(a[k]);
    chia(k-z/2,z/2,i+1);
    chia(k+z/2,z/2,i+1);
    }
}

void nhap()
{
    cin >> n;
    int k= (1<<n)-1;
    //cout << n << endl;;
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> a[i];
    }
    int h=n-1;
    h=(1<<h);
    //cout << h << endl;
    chia(h,h,1);
    for(int i = 1 ;i <= n ; i++)
    {
        //cout << SZ(vec[i]) << endl;
        if(SZ(vec[i])==1)
        {
            cout << vec[i][0] << endl;
            continue;
        }
        for(int j = 0 ;  j <SZ(vec[i])-1;j++)
        {
            cout << vec[i][j]  << " ";
        }
        cout << vec[i][SZ(vec[i])-1] << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



