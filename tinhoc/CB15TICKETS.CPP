#include<bits/stdc++.h>
using namespace std;
 long long a,n,h[1000000],g[1000000]={0},k[100000],s=0;
int main()
{
    freopen("CB15TICKETS.INP","r",stdin);
    freopen("CB15TICKETS.OUT","w",stdout);

    cin>>n>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];

    }
    for(int j=1;j<=a-n;j++)
    {
    long long minn=1000000000000;
    g[h[0]]=1;
    long long t=h[0];
    for(int i=1;i<=n;i++)
    {
        g[h[i]]++;
        long long u=g[h[i]];

        if(u*h[i]<minn)
        {

           g[t]--;
            minn=u*h[i];
      ;
            t=h[i];
        }
        else
        {
            g[h[i]]--;
        }


    } s=s+minn;}

  cout<<s;
}




