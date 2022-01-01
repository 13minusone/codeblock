#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(ll  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(ll  i = a ; i >=b ;i-=c)
#define ll long long
const ll maxsize = 1000000;

void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int f[maxsize+1];

void tao()
{
    f[1]=1;
    fu(i,2,maxsize,1)
    {
        if(!f[i])
        {


        fu(j,i*i,maxsize,i)
        {
            f[j]=1;
        }

        }

    }
}
void nhap()
{
    int n;
    ll x;


    cin >> n;
    tao();
    //cout << f[7];
    fu(i,1,n,1)
    {
        cin >> x;
        int g=sqrt(x);
        //cout << g <<endl;
        ll d= g;
        d*=g;
        if(d==x)
        {
            if(!f[g])
            {
                cout << "YES" <<endl;
            }
            else
            {
                cout << "NO" <<endl;
            }
        }
        else
        {
            cout << "NO" <<endl;
        }
    }
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
int main()
{
    fastio();
    //inti();
    nhap();
}
