#include<bits/stdc++.h>
using namespace std;
struct pont
{
    long long x,y;
};
bool cmp(pont u,pont v)
{
    if(u.x>v.x)return false;
    if(u.x<v.x)return !false;
    if(u.y>v.y)return false;
    if(u.y<v.y)return !false;
}
int main()
{
    freopen("thuocdoan.inp","r",stdin);
    freopen("thuocdoan.out","w",stdout);
    long long n,d=0,maxx=-100;
    pont a[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[2*i].x>>a[2*i+1].x;
       a[2*i].y=0;
       a[2*i+1].y=1;
    }
    sort(a,a+2*n,cmp);
    for(int i=0;i<2*n;i++)
    {
        if(a[i].y==0)
        {
            d++;
        }
        else
        {
            d--;
        }
        maxx=max(maxx,d);

    }
    cout<<maxx;
}
