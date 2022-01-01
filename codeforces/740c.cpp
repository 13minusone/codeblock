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
typedef long long ll ;
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
int t,n;
ll k[maxsize+5];
struct node
{
    ll maxx,k,l;
};
vector<node>vec;
bool cmp(node a,node b)
{
    if(a.maxx!=b.maxx)
    {
        return a.maxx<b.maxx;
    }
    else
    {
        return a.k>b.k;
    }
}
void nhap()
{

    cin >> t;
    while(t--)
    {
        cin >> n;
        vec.clear();
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> k[i];
            ll maxx=0,l=0,x;
            for(int j= 1 ; j <= k[i];j++)
            {
                cin >> x;
                if(x-j+2> maxx)
                {
                    maxx=x-j+2;
                }
            }
            vec.push_back({maxx,k[i]});
        }
        sort(all(vec),cmp);
        ll maxi=vec[0].maxx,s=vec[0].k;
        for(int i = 1;i< n ; i++)
        {
            if(maxi+s<vec[i].maxx)
            {
                maxi=vec[i].maxx-s;
            }
            s+=vec[i].k;
        }
        cout << maxi << endl;
    }
}
int main()
{

    fastio();
    //inti();
    nhap();
}




