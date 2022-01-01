#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fu0(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fd0(i,a,b,c) for(int i =a ; i>=b ;i-=c)
#define fu1(i,a,b,c) for(int i = a i < b ;i+=c)
#define fd1(i,a,b,c) for(int i =a ; i> b ; i-=c)
#define pb(i) push_back(i)
#define mx 100000
#define endl '\n'
ll f[mx];

bool isprime(unsigned ll x)
{
    if (x<2)
    {
        return false;
    }
    for(ll i =2 ; i <= int(sqrt(x)); i ++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
void solve(int x)
{

    ll   s=x-1;
    ll h=x*x;
    ll g=s*s;
    ll j=s*x;
    ll o=h+j+g;
    if(isprime(o)==false)
    {
       printf("%d\n",0);

    }
    else
    {
       printf("%d\n",1);
    }

}
int t;

void nhap()
{
scanf("%d",&t);
  int x;
 fu0(i,1,t,1)
 {

 cin >> x;
     solve(x);

 }
}
int main()
{

nhap();
}

