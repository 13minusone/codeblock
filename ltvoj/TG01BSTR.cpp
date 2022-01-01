/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    This is a code written by long and caitien by 13minusone
*/
#include<bits/stdc++.h>
using namespace std;
#define task "TG01BSTR"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define MAX int(5e5)+5
const int mod = int(1e9)+7;
const int base = 311;
typedef pair<int, int> ii;
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int dx[]= {0,0,1,-1,1,1,-1,-1};
int dy[]= {1,-1,0,0,1,-1,1,-1};
int n;
int poszero[MAX], cntzero[MAX], cnt0=0;
ll s=0;
int posone[MAX], cnt1=0;
char a[MAX];
void read()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        cntzero[i]=cntzero[i-1];
        if (a[i]=='0')
        {
            poszero[++cnt0]=i;
            cntzero[i]++;
        }
        else
        {
            posone[++cnt1]=i;
            s=s+cnt1-1;
        }
    }
    if(a[n]=='1')
    {
        int i=n+1;
        a[n+1]='0';
        cntzero[i]=cntzero[i-1];
        if (a[i]=='0')
        {
            poszero[++cnt0]=i;
            cntzero[i]++;
        }
        else
        {
            posone[++cnt1]=i;
            s=s+cnt1-1;
        }
    }
}
bool oke=false;
ii maxx;
void soln()
{
    for(int mid=1; mid<=n; mid++)
    {
        if (cnt0<2*mid) break;
        int i=poszero[mid], dem=0;
        while(i<=n)
        {
            int k=lower_bound(posone+1, posone+cnt1+1, i+1)-posone;
            if (k==cnt1+1 || cntzero[n]-cntzero[posone[k]]<mid) break;
            i=poszero[cntzero[posone[k]]+mid];
            dem++;
            if((dem+1)*mid+dem>maxx.fi)
            {
                maxx.fi=(dem+1)*mid+dem;
                maxx.se=mid;
            }
            oke=true;
        }
    }
}
void sol()
{
    if (cnt0==0)
    {
        cout << n<< "\n";
        for(int i=1; i<=n; i++) cout << 1;
        return;
    }
    if (cnt1==0)
    {
        cout << 0;
        return;
    }
    soln();
    if(!oke)
    {
        cout << cnt1 << "\n";
        for(int i=1; i<=n; i++) if (a[i]=='1') cout << 1;
        return;
    }
    cout << maxx.fi << "\n";
    for(int i=1; i<=maxx.fi; i++)
    {
        if(i%(maxx.se+1)==0) cout << 1;
        else cout << 0;
    }
}
int main()
{
    fastio();
    init();
    read();
    sol();
}
