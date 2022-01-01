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
int n,k;
string s;
vector<ii>vt;
int numvt;
vector<int>vec;
bool cmp(ii a ,ii b)
{
    if(a.fi==b.fi)
    {
        if(a.se==0)
        {
            if(b.se==numvt)
            {
                return vt[a.se+1]>vt[b.se-1];
            }
            else
            {
                return vt[a.se+1]>(vt[b.se-1]+vt[b.se+1]);
            }

        }
        else
        {
            if(b.se==numvt)
            {
                return vt[a.se+1]+vt[a.se-1]>vt[b.se-1];
            }
            else
            {
                return vt[a.se+1]+vt[a.se-1]>vt[b.se-1]+vec[b.se+1];
            }
        }
    }
    else return a.fi<b.fi;
}
void nhap()
{
    cin >> n >> k;
    cin >> s;
    s=" "+s;
    int n=SZ(s)-1;
    ll su=1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(s[i]==s[i-1])su++;
        else{
            int h=sz(vec);
            vec.push_back(su);
            vt.push_back(ii(su,h));
            su=1;
        }
    }
    vec.push_back(su);
    vt.push_back(su);
    numvt=SZ(vt);
    sort(all(vt),cmp);

}
int main()
{

    fastio();
    // inti();
    nhap();
}




