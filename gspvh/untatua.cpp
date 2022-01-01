#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[220797+6],b[220797+6],res=0,maxx=0;
int bs(int x,int l,int r)
{
    int res=0,m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(b[m]<x)
        {
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}

void giai()
{

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
       long long  k=bs(a[i],1,maxx);
        b[k+1]=a[i];
        //cout << i << " "<< k+1 << endl;
        maxx=max(maxx,k+1);
    }

    cout<<maxx<<endl;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("lis.inp","r",stdin);
    freopen("lis.out","w",stdout);
    giai();
}
