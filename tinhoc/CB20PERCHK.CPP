#include<bits/stdc++.h>
using namespace std;
long long n,a[10000000],b[10000000];
int main()
{
    freopen("CB20PERCHK.INP","r",stdin);
      freopen("CB20PERCHK.OUT","w",stdout);
    unsigned long long s=0,g;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
       if(b[a[i]]>1)
        {
            cout<<"NO";
            return 0;
        }
        s=s+a[i];
    }
    g=((n+1)*n)/2;
    if(s!=g)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
}

