#include<bits/stdc++.h>
using namespace std;
struct pont
{
    long long x,y;
};
long long tknp(long long a[], int l, int r, long long x)
{
    while(l<=r)
    {
        long long mid=(r+l)/2;
        if(x<=a[mid]&&x>a[mid-1])
        {
            cout<<mid<<endl;
            break;
        }
        else
        {
         if(x>a[mid])
         {
             l=mid+1;
         }
         else
         {
             r=mid-1;
         }
        }
    }

    return -1;
}
long long n,m,a,b,h;
long long  s[1000000];
int main()
{
    freopen("song.inp","r",stdin);
    freopen("song.out","w",stdout);
    s[0]=0;
    cin>>n>>m;
    for(int j=1;j<=n;j++)
    {
       scanf("%d%d",&a,&b);
    s[j]=s[j-1]+a*b;


    }
    for(int f=1;f<=m;f++)
    {
        scanf("%d",&h);
       tknp(s,1,n,h);
    }
}
