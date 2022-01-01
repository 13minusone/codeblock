#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
unsigned long long k=0,d=10000000000,s=0;
map<unsigned long long,unsigned long long>a,b;
vector <unsigned long long >c;
void gt(unsigned long long m)
{

    for (unsigned long long i = 0; i < c.size(); i++)
    {
        long long s=0;
        while (m%c[i]== 0)
        {
            s++;
            m/=c[i];

        }

        a[c[i]]=a[c[i]]+s;
    }
    if (m!= 1)
    {
        a[c[m]]=a[c[m]]+1;
    }
}
int main()
{
    //freopen("CB20FDP.INP","r",stdin);

//freopen("CB20FDP.OUT","w",stdout);
    cin>>n>>m;

    /* for(int i=2;i<=20;i++)
     {
         cout<<i<<" "<<a[i]<<endl;
     }*/

    for(long long i=2; i*i<=m; ++i)
    {
        unsigned long long s=0;
        while(m%i==0)
        {
            s++;
            m/=i;
        }
        if(s>0)
        {
            c.push_back(i);
            b[i]=s;
        }

    }
    if (m!= 1)
    {
        c.push_back(m);
        b[m]=1;
    }
    for(long long  i=n; i>=2; i--)
    {
        gt(i);
    }
    for(int i=0; i<c.size(); i++)
    {
        if(b[c[i]]>0)
        {
            if(d>a[c[i]]/b[c[i]])
            {
                d=a[c[i]]/b[c[i]];
            }
        }
    }
    cout<<d;
}

