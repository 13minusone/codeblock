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
const ll N = 1e6;
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
vector<ii>vec;
ll a[N+5],b[N+5];
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        vec.push_back(ii(a[i],i));
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> b[i];
        vec[i-1].first+=b[i];
    }
    sort(all(vec));
    ii rua;
    rua.first=a[vec[0].second];
    rua.second=vec[0].second;
    int lau=0,s=0;
    for(int i =1 ;i < SZ(vec) ; i++)
    {

        int x=vec[i].second;
        lau-=rua.first;
        s+=rua.first;
        lau=max(lau,0);
        lau+=b[rua.second];
        rua.first=a[x];
        rua.second=x;
        cout << rua.first << " " << lau << " " << s << endl;

    }
    s+=rua.first;
    lau-=rua.first;
    lau=max(lau,0);
    lau+=b[rua.second];
    cout << rua.first << " " << lau << " " << s << endl;

    cout << s+lau << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




