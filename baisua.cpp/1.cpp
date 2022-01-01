#include<bits/stdc++.h>
using namespace std;
int a[1005];

void nhap(int n)
{
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];

    }
}
void ktr(int n)
{
    int f[1005];
    int b;
    int k;
    int dem=0;
    int h;
    for(int i=1; i<=n; i++)
    {
        k=a[i];
        while(a[i]!=0)
        {
            b=a[i]%10;
            if(b%2==0)
            {
                break;
            }
            a[i]=a[i]/10;

            if(a[i]==0)
            {
                //cout << 1;
                dem++;
                f[dem]=i;
            }
        }


    }
    for(int i = 1 ; i<= dem ; i++)
    {

        if(f[i+1]-f[i]==1)
        {

            if(f[i+2]-f[i+1]==1)
            {
                cout << f[i] << " " << f[i+1] << " " << f[i+2] << endl;
            }
        }
    }
}
int main()
{
//    freopen("nhietdo.inp","r",stdin);
//    freopen("nhietdo.out","w",stdout);
    int n;
    cin>>n;
    nhap(n);
    ktr(n);


}
