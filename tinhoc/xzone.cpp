#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int i = a ;i<=b;i+=c)
#define fd(i,a,b,c) for(int i = a ;i>=b;i-=c)
#define ll long long
ll arr[int(1e6)+5],maxx[int(1e6)+5],minn[int(1e6)+5],maxx1[int(1e6)+5],minn1[int(1e6)+5];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("xzone.inp","r",stdin);
//    freopen("xzone.out","w",stdout);
    cin >> n;

    fu(i,1,n,1)
    {
        cin >> arr[i];
        if(i==1)
        {
            maxx[i]=arr[i];
        }
        else{maxx[i]=max(maxx[i-1],arr[i]);}

    }

    minn[n]=arr[n];
    ll s=-10000000000001;
    fd(i,n-1,2,1)
    {
        minn[i]=min(minn[i+1],arr[i]);
        ll f=(maxx[i-1]-arr[i])*(arr[i]-minn[i+1]);
        s=max(s,f);
        //cout << s <<endl;
    }
   maxx1[n]=arr[n];
    fd(i,n-1,1,1)
    {
       maxx1[i]=max(maxx1[i+1],arr[i]);
    }
minn1[1]=arr[1];
    fu(i,2,n-1,1)
    {
        minn1[i]=min(minn1[i-1],arr[i]);
        ll f=(minn1[i-1]-arr[i])*(arr[i]-maxx1[i+1]);
        s=max(s,f);
        //cout << s <<endl;
    }
    cout << s <<endl;

}
