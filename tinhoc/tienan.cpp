#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(i,a,b,c) for( int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for( i=a;i>=b;i=i-c)
int m,n,x[100000];
void inti()
{
    freopen("tienan.inp","r",stdin);
    freopen("tienan.out","w",stdout);
}
int l[100000],r[1000000],p[1000000];
void xuly()
{
    fu( i,1,m,1)
    {
        int j=i-1,h=i+1;
        l[i]=i,r[i]=i;
        while(x[i]<=x[j]&&j>=1)
        {
            l[i]--;
            j--;
        }
        while(x[i]<=x[h]&&h<=m)
        {
            r[i]++;
            h++;
        }
        p[i]=x[i]*(r[i]-l[i]+1);
        //cout<<i<<" "<<p[i]<<" "<<x[i]<<" " <<'\n';
    }
}
void nhap()
{

    cin>>n;
    fu(i,1,n,1)
    {
        int maxx=0;
        cin>>m;
        fu(j,1,m,1)
        {

            cin>>x[j];


        }
        xuly();
        int le,ri;
        fu(j,1,m,1)
        {
            if(maxx<p[j])
            {
                maxx=p[j];
                le=l[j];
                ri=r[j];
            }

        }
        cout<<maxx<<" "<<le<<" "<<ri<<endl;
    }
}
int main()
{
    inti();
    nhap();
}
