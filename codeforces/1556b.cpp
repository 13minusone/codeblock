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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
    //freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int t,n;
ll a[N+5],b[N+5];
queue<int>vec1,vec0;
void nhap()
{
    cin>>t;
    while(t--)
    {
        cin >> n;
        if(n==1)
        {
            cout <<0 << endl;

            for(int i = 1 ; i <= n ; i++)
            {
                cin >> a[i];
            }
            continue;
        }
        int s=0;
        bool te=true;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            if(a[i]%2==0)
            {
                a[i]=0;
                s++;
            }
            else
            {
                a[i]=1;
                s--;
            }
        }
        if(abs(s)>=2)
        {
            cout << -1 << endl;
            continue;
        }
        ll su=0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(i>1)
            {
                if(a[i]==a[i-1])
            {
                int j=i;
                while(j<=n)
                {
                    if(a[j]!=a[i])
                    {
                        swap(a[i],a[j]);
                        su+=j-i;
                        break;
                    }
                    j++;
                }
            }
            }
        }
        cout << su << endl;
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




