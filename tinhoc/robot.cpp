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
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll MAX=1e6;
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

bool snt[MAX+5];
void sang()
{
    snt[1]=0;
    for(int i = 2 ; i*i<=MAX; i++)
    {
        if(snt[i]==0)
        {
            for(int j = i*i ; j<=MAX; j+=i)
            {
                snt[j]=1;
            }
        }
    }
}
void nhap()
{
    int t,n,a;
    cin >> t;
    sang();
    while(t--)
    {
        cin >> n;
        ll maxx=0;
        map<int,ll>cnt;
        for(int i = 1 ; i<= n ; i++)
        {
            cin >> a;
            a=abs(a);
            if (!snt[a])
            {
                cnt[a]++;
                maxx=max(maxx, cnt[a]);
                continue;
            }
            if (a%2==0)
            {
                while(a%2==0) a/=2;
                cnt[2]++;
                maxx=max(maxx, cnt[2]);
            }
            for(int i=3; i<=sqrt(a); i+=2)
            {
                if (a%i==0)
                {
                    while(a%i==0) a/=i;
                    cnt[i]++;
                    maxx=max(maxx, cnt[i]);
                }
            }
            if (a>2)
            {
                cnt[a]++;
                maxx=max(maxx, cnt[a]);
            }
        }
        cout << maxx << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



