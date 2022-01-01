#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(ll i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen("719B.inp","r",stdin);
    freopen("719B.out","w",stdout);
}
vector<ll>vec;
int d[1000];
ll dem1(int x)
{
    ll s=1;
    while(x!=1)
    {
        s=s*10+1;
        x--;
    }
    return s;
}
ll dem(int x)
{
    ll s=1;
    while(x!=1)
    {
        s=s*10;
        x--;
    }
    return s;
}
void tao()
{

    int s=0;
    fu(i,1,9,1)
    {
        fu(j,1,9,1)
        {
            s++;
            vec.push_back(dem1(i)*j);
            d[vec.size()-1]=s;


    }
    }
}
int main()
{
inti();
  tao();
    int t;

    cin >> t;
    fu(i,1,t,1)
    {
        int x;
        cin >> x;
        int k=upper_bound(vec.begin(),vec.end(),x)-vec.begin();
        cout << d[k-1] <<endl;
    }
}
