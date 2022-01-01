#include<bits/stdc++.h>
using namespace std;
struct pont
{
    long long x,y;
};
bool cmp(long long u,long long  v)
{
    if(u<v)return false;
    if(u>v)return !false;

}
long long  a[10000000];
int main()
{
freopen("paint.inp","r",stdin);
freopen("paint.out","w",stdout);
    long long n,m;
unsigned long long  s;
   s=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        s=s+m;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);

    for(int i=0;i<n;i++)
    {

        s=s+a[i]*i;
    }
    cout<<s;
}
