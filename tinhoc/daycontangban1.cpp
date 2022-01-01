#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'

    int m,n,x;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{
vector<int> vec;
cin>>n;
fu(i,1,n,1)
{
    cin >> x;
    vec.pb(x);
}
ll dp[int(1e5)+1];
ll maxx;
fu(i,0,n-1,1)
{
    int k=upper_bound(vec.begin(),vec.begin()+i,vec[i])-vec.begin();
    dp[i]=dp[k]+vec[i];
    maxx=max(maxx,dp[i]);
        cout << maxx << " " << i << endl;

}
cout << maxx ;
}
int main()
{
IOS
//inti()
nhap();

}
