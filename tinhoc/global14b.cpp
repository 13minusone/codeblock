#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x;
map<ll,int>f;
void tao()
{
    int g=10000000000;
    f[2]=1;
    for(ll i = 2 ; i <=g; i=i*2)
    {
        f[i]=1;
    }
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
vector<int>vec;
bool check(int x)
{
    if(x==2||f[x]==1)
    {
        return true;
    }
    map<ll,int>d;
    fu(j,2,sqrt(x)+1,1)
    {
        if(x%j==0)
        {
            int res=x/j;
            if(d[j]==0)
            {
                vec.push_back(j);
            }
            d[j]++;

            if(vec.size()>2)
            {
                return false;
            }
            x=x/j;
        }
    }
    cout <<vec.size() << " " << vec[0] << " " << d[vec[1]] <<endl;
    if(vec.size()==2)
    {
        if(vec[0]!=2||f[d[vec[1]]]==0)
        {
            return false;

        }
        if(vec[0]==2&&f[d[vec[1]]]==1)
        {
            return true;
        }
    }

    if(vec.size()==1)
    {
        if(vec[0]!=2)
        {
            return false;
        }
    }
    vec.clear();
    return true;


}
void nhap()
{

    cin>>n;

    tao();
    fu(i,1,n,1)
    {
        cin >> x;
        if(check(x))
        {
            cout << "YES" <<endl;
        }
        else
        {
            cout << "NO" <<endl;
        }
    }
}
int main()
{
    IOS
//inti()
    nhap();

}

