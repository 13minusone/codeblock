#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[1000000];
void bcnn(long long d)
{
long long f=d;

    for(int i=2; i<=d; i++)
    {
        b[i]=0;
    }

    for (int i = 2; i * i <= d; ++i) {
        while (d % i == 0) {
b[i]++;
            d /= i;

        }
    }




    if (d != 1)
    {
        b[d]++;
    }
    for(int j=2; j<=f; j++)
    {
        if(b[j]>a[j])
        {
            a[j]=b[j];
        }
    }
}
 int sqr(int x) {
    return x*x;
}

int powe(int a, int b) {
    if (b == 0) return 1;
    else
        if (b % 2 == 0)
            return sqr(powe(a, b/2));
        else
            return a * (sqr(powe(a, b/2)));
}
    long long k=(int(1e9)+7);
int main()
{
    freopen("ptnk17lcm.inp","r",stdin);
    freopen("ptnk17lcm.out","w",stdout);
    unsigned long long n,s=1;

cin>>n;


    for(int i=2; i<=n; i++)
    {
        bcnn(i);
    }
    for(int i=2; i<=n; i++)
    {
        if(a[i]>0)
        {

       s=((s%k)*(powe(i,a[i])%k))%k;
        }
    }
    cout<<s;
}
