#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
int n;
int x,d[100001],s[100001];
void inti()
{
    freopen("road.inp","r",stdin);
    freopen("road.out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void nhap()
{
    cin>>n>>x;
    fu(i,1,n,1)
    {
        cin>>d[i];
        s[i]=s[i-1]+d[i];


    }

    int f,maxx=0,k;
    fu(i,1,n,1)
    {
        int j=n;
        if(j-i+1<maxx)break;
        while(j>=i)
        {
            if(j-i+1<maxx ) break;
            if((s[j]-s[i-1])==((j-i+1)*x))
            {
                if(j<k)break;
                if(j-i+1>maxx)
                {
                    maxx=j-i+1;
                    f=i;
                    k=j;
                    break;
                }

            }
            j--;
        }
    }
    if(maxx>0)
    {
        cout<<f<<" "<<maxx;
    }
    else
    {
        cout<<"-1";
    }
}
int main()
{
    fastio();
    inti();
    nhap();
}
