#include<bits/stdc++.h>
using namespace std;
long long a[1000000],maxx=0;

vector <long long > v;
  unsigned long long n,s=1;
 int sqr(long long  x) {
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
 long long k=v[v.size()-1];
void bcnn(long long d)
{
long long f=d;
long long b[1000000];
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
    for(int j=2; j<=sqrt(f); j++)
    {
        if(b[j]>a[j])
        {
a[j]=b[j];
        }
    }
}
int main()
{
   // freopen("ptnk17station.inp","r",stdin);
   // freopen("ptnk17station.out","w",stdout);


while (cin>>n)
{

    v.push_back(n);

}
    for(int i=0; i<v.size()-1; i++)
    {
maxx=max(maxx,v[i]);
        bcnn(v[i]);
    }

 for(int i=2; i<=sqrt(maxx); i++)
    {
        if(a[i]>0)
        {

       s=((s%k)*(powe(i,a[i])%k))%k;
        }
    }
    cout<<s;
}

