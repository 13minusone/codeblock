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
const ll cnt = 10000005;
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
int danhdau[cnt];
vector<int>nto(cnt,0);
ll pre[cnt];
vector<int>vec;
void sang()
{
    nto[1]=1;
    for(ll i = 2 ; i <=cnt; i++)
    {
        if(nto[i]==0)
        {
            vec.push_back(i);
            for(ll j=i*i; j<=cnt; j=j+i)
            {
                if(j<=cnt)
                {
                    nto[j]=1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return;
}
void nhap()
{
    int t,l,r;
    cin >> t;
    sang();
    for(int i = 0 ; i < SZ(vec); i++)
    {
        if((ll)vec[i]*vec[i]*vec[i]<=cnt)
        {
            danhdau[(ll)vec[i]*vec[i]*vec[i]]=1;
        }
        else
        {
            break;
        }
    }
    for(int i = 0 ; i<SZ(vec); i++)
    {
        for(int j = i+1 ; j<(SZ(vec)); j++)
        {
            if((ll)vec[i]*vec[j]<=cnt)
            {
                danhdau[(ll)vec[i]*vec[j]]=1;
            }
            else
            {
                break;
            }
        }
    }
    pre[0]=0;
    for(int i = 1 ; i <= cnt ; i++)
    {
    pre[i]=pre[i-1]+danhdau[i];
    }
    while(t--)
    {
        cin >> l>> r;
        cout << pre[r]-pre[l-1] << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



