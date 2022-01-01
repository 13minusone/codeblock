#include<bits/stdc++.h>
using namespace std;
long long f[10000000],s=0;
long long n,m,r,d,x;
long long c[10000000];

struct pont
{
    long long x,y,z;
};
bool cmp(pont u,pont v)
{
    if(u.x>v.x)return false ;
    if(u.x<v.x)return !false ;
    if(u.y<v.y)return !false ;
    if(u.y>v.y)return false ;

}
long long  tim(long long i)
{
    long long d=i;
    if(d+r<=n)
    {
        for(int k=d+r+1; k>d; k-- )
        {
            if(a[k]!=0)
            {
                d=k;

                f[s]=d;
                s++;
                return tim(d);

            }

            }
 if(d+r<=n)
                {
                    s=-1;
                    return -1;
                }

    }
    return s;

}pont a[1000000];
int main()
{
//freopen("ptnk17station.inp","r",stdin);
//freopen("ptnk17station.out","w",stdout);

    cin>>n>>m>>r;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].x>>a[i].y;

    }
    for(int i=r; i>=0; i--)
    {

        if(a[i]!=0)
        {
            f[s]=i;
            s++;
            tim(i);
            break;
        }
    }
if(s==-1){cout<<0;}
else{
    cout<<s<<endl;
    for(int i=0; i<s; i++)
    {

        cout<<c[f[i]]<<" ";
    }}
}
