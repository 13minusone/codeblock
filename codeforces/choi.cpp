#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen("choi.inp","r",stdin);
    freopen("choi.out","w",stdout);
}
ll n,arr[maxsize+5];
void nhap()
{
    cin >> n;
     ll s=0,maxx=0;
    fu(i,1,n,1)
    {
        cin >> arr[i];
        s=s+arr[i];
        maxx=max(arr[i],maxx);
    }
    if(s%2==0&&s>=2*maxx)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    fastio();
    //inti();
    nhap();
}

