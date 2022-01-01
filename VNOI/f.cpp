/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE A.K.A PVM
*/
#include<bits/stdc++.h>
using namespace std;
#define task "maxsum"
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
const ll maxsize = 400000;
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
ll n,m,sub;
ll a[maxsize+5],pre[maxsize+5],l,r,b,maxx=0,le,ri;
void nhap()
{
    cin >> sub;
    cin >> n >> m;
    pre[0]=0;
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
    if(sub==1||sub==2)
    {
        for(int i = 1 ; i<= m ; i++)
        {
            cin >> l >> r >> b;
            maxx=-1e18;
            for(int j = l ; j<= r ; j++)
            {
                if(a[j]>=b)
                {
                    for(int k = j; k<= r ; k++)
                    {

                        if(a[k]>=b)
                        {
                            if(maxx<pre[k]-pre[j-1])
                            {
                                maxx=pre[k]-pre[j-1];
                                le=j;
                                ri=k;
                            }
                            //cout << j << " "<< k << " " <<maxx  << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

            }

            if(maxx!=-1e18)
            {
                cout << le <<" " <<ri << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    else
    {
        if(sub==3)
        {

        }
        return;
    }
}
int main()
{

    fastio();
    //inti();
    nhap();
}



