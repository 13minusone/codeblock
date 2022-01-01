#include<bits/stdc++.h>
#define task "CB16COUNTMOD"
using namespace std;
bool check(long long a,long long b,long long c,long long d,long long f,long long e,long long g,long long h)
{
    if(a==b||b==c||c==d||d==a||d==b||a==c)
    {
        if(f!=e||e!=g||g!=h||h!=f||h!=e||h!=e||f!=g)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}
long long a;
int main()
{
    freopen(task".INP","r",stdin);
    freopen(task".out","w",stdout);
    cin>>a;
    for(int i=1; i<=a; i++)
    {
        vector<long long >c,b;

        for(int j=0; j<=3; j++)
        {
            long long a,g;
            cin>>a>>g;
            c.push_back(a);
            b.push_back(g);
        }
        if(check(c[0],c[1],c[2],c[3],b[0],b[1],b[2],b[3])==false)
        {
            cout<<-1<<endl;
            break;
        }
        else
        {


        for(unsigned long long i=1; i<=int(1e16); i++)
        {
            unsigned long long d=c[0]*i+b[0];
            if(d%c[1]==b[1]&&d%c[2]==b[2]&&d%c[3]==b[3])
            {
                cout<<d<<endl;
                break;
            }
        }


        }
        cout<<-1<<endl;

    }
}



