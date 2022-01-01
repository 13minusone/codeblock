#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,x[1001][1001];
void inti()
{
   freopen("rect9.inp","r",stdin);
   freopen("rect9.out","w",stdout);
}
void nhap()
{

cin>>n>>m;
fu(i,1,n,1)
{
    fu(j,1,m,1)
    {
        cin>>x[i][j];
    }
}
}
int h[1001];
void xuly()
{
    int maxx=-1;
    fu(i,1,n,1)
    {

        int f=1;
        fu(j,1,m,1)
        {
            if(x[i][j]==9)
            {
                h[j]=h[j]+1;
            }
            else
            {
                h[j]=0;
            }

            }
        fu(j,1,m,1)
        {
            int l[1001],r[1001];
            int k=j-1,o=j+1;
            l[j]=j;
            r[j]=j;
            while(k>=1&&h[k]>=h[j])
            {
                l[j]--;
                k--;
            }
            while(o<=m&&h[o]>=h[j])
            {
                r[j]++;
                o++;
            }
            maxx=max(maxx,h[j]*(r[j]-l[j]+1));
        }
        }

    cout<<maxx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    inti();
nhap();
xuly();
}
