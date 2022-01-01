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
#define task "b"
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
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int row[55],col[55];
char a[55][55];
int cnthang[55],cntcot[55],cnt[55],t,n,check[55][55];
void nhap()
{
    cin >> t;
    for(int p = 1 ; p <= t ; p++)
    {
        cin >> n;
        memset(row,0,sizeof row);
        memset(col,0,sizeof col);
        memset(cnthang,0,sizeof cnthang);
        memset(cntcot,0,sizeof cntcot);
        memset(cnt,0,sizeof cnt);
        memset(check,0,sizeof check);
        int ans=N,s=0;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                cin >> a[i][j];
                if(a[i][j]=='O')
                {
                    row[i]=1;
                    col[j]=1;
                }
                else
                {
                    if(a[i][j]=='X')
                    {
                        cnthang[i]++;
                        cntcot[j]++;
                    }
                    else
                    {
                        s++;
                    }
                }
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(row[i]==0)
            {
                ans=min(ans,n-cnthang[i]);
                if(n-cnthang[i]==1)
                {
                    for(int j = 1 ; j <= n ; j++)
                    {
                        if(a[i][j]=='.')
                        {
                            if(check[i][j]==1)
                            {
                                continue;
                            }
                            else
                            {
                                cnt[n-cnthang[i]]++;
                            }
                        }
                    }
                    for(int j = 1 ; j <= n ; j++)
                    {
                        if(a[i][j]=='.')
                        {
                            check[i][j]=1;
                        }
                    }
                }
                else
                {
                    cnt[n-cnthang[i]]++;
                }
            }
            if(col[i]==0)
            {
                ans=min(ans,n-cntcot[i]);
                if(n-cntcot[i]<=1)
                {
                    for(int j = 1 ; j <= n ; j++)
                    {
                        if(a[j][i]=='.')
                        {
                            if(check[j][i]==1)
                            {
                                continue;
                            }
                            else
                            {
                                cnt[n-cntcot[i]]++;
                            }
                        }
                    }
                    for(int j = 1 ; j <= n ; j++)
                    {
                        if(a[j][i]=='.')
                        {
                            check[j][i]=1;
                        }
                    }
                }
                else cnt[n-cntcot[i]]++;

                //cout << i << endl;
            }
        }
        cout << "Case #"<<p <<": ";
        if(ans==N)cout << "Impossible" << endl;
        else cout << ans << " "<< (s==1?1:cnt[ans]) << endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}




