#include<bits/stdc++.h>
using namespace std;
long long a,b[1000000],maxx=-1,n;
int main()
{
    freopen("nn.inp","r",stdin);
    freopen("nn.out","w",stdout);
cin>>a;
for(int i=0;i<a;i++)
{
    cin>>b[i];
   maxx=max(maxx,n);
    }
sort(b,b+a);
b[a]=0;
for(int i=0;i<a;i++)
{



        if (b[i+1]-b[i]>1)
        {
            printf("%d",b[i]+1);

            return 0;
        }


}
printf("%d",b[a-1]+1);
}

