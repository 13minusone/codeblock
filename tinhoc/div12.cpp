#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(ll i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(ll i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<ll,ll> ii;
    ll m,n,x,res;
    vector<ll>vec[101];
    vector<ii>maxx;
void inti()
{
   freopen("df1.inp","r",stdin);
   freopen("df1.out","w",stdout);
}
bool cmp1(ii v,ii u)
{
    if(v.first>u.first)
    {
        return false;
    }

    return true;
}
bool cmp2(ii v,ii u)
{

    if(v.second>u.second)
    {
        return false;
    }

    return true;
}
void nhap()
{
inti();
cin>>n;
while(n>0)
{

    cin >> m >> x;
    fu(i,1,m,1)
    {
       fu(j,1,x,1)
       {
           cin >>res;
           vec[i].pb(res);
           maxx.push_back(ii(res,i));

       }
       sort(vec[i].begin(),vec[i].end());
    }
   sort(maxx.begin(),maxx.end(),cmp1);
   sort(maxx.begin(),maxx.begin()+x,cmp2);
   int k=0;
   fu(i,1,m,1)
   {

       if(i==maxx[k].second)
       {
           if(k>0)
           {
               fd(j,x-1,x-1-k+1,1)
           {
               cout << vec[i][j] << " ";
           }
           }
           fu(j,0,x-1-k,1)
           {
               cout <<vec[i][j] << " ";
           }
       }
       else
       {
           fu(j,0,x-1,1)
           {
               cout << vec[i][j] << " ";
           }
       }
       while(maxx[k].second==i&&k<x)
       {
           k++;
       }
        cout <<endl;
      // cout << k <<endl;

   }
maxx.clear();
fu(i,1,m,1)
{
    vec[i].clear();
}

n--;
}
}
int main()
{
IOS
//inti()
nhap();

}

