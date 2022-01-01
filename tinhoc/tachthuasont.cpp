#include<bits/stdc++.h>
using namespace std;
long long b[1000000];
long long a[1000000];
int main()
{
    long long n;

    cin>>n;
            for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
b[i]++;
            n /= i;

        }
    }




    if (n != 1)
    {
        b[n]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]>a[i])
        {
            a[i]=b[i];
        }
    }
    for(int i=2;i<=n;i++)
    {
        cout<<i<<" "<<a[i]<<endl;
    }

}
