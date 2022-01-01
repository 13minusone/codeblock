#include<bits/stdc++.h>
using namespace std;
long long a[10000000],n, d=-1000000000000000,s=0,maxx=-1;
int main()
{
    freopen("CB20INCSEG.INP","r",stdin);
    freopen("CB20INCSEG.OUT","w",stdout);
 cin>>n;
for(int i=1;i<=n;i++)
{
  cin>>a[i];
  if(a[i]<a[i-1]){
        maxx=max(maxx,s);

 s=1;
  }
  else
  {
      s++;

  }
maxx=max(maxx,s);
}
cout<<maxx;
}
