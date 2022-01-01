#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 1000000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
void nhap()
{
    int n,m,a,b,f[maxsize+3],f1[maxsize+3],s=0;
    cin >> n >> m >> a >> b;
    fu(i,1,m,1)
    {
        int t,v;
        cin >> t >> v;
        if(t==a)f[v]++;
        if(v==a)f[t]++;
        if(t==b)f1[v]++;
        if(v==b)f1[t]++;

    }
    fu(i,1,n,1)
    {
        if(f[i]*f1[i]!=0)
        {
            s++;
        }
    }
    cout << s*(s-1)/2;
}
int main()
{
    fastio();
    nhap();
}

