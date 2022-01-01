#include<bits/stdc++.h>
using namespace std;
long long b,a[1000000],maxx=-100,s=1,o=1;
int main()
{
    freopen("ptnk17lights.inp","r",stdin);
    freopen("ptnk17lights.out","w",stdout);
    cin>>b;
    for(int i=1; i<=b; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<b; i++)
    {

   if(a[i]==a[i+1])
{
    s++;

}
else
{

        s++;
        long long d=a[i];
        for(int j=i+2;j<=b;j++)
        {
            if(a[j]==d)
            {
                s++;

            }
            else
            {
                maxx=max(maxx,s);
                s=1;
                break;
            }
        }

        maxx=max(maxx,s);
s=1;



    }


maxx=max(maxx,s);

    }

    cout<<maxx;
}



