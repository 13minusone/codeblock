#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,n,a[int(1e6)+8];
int main()
{
    cin >> k >> n;
    for(int i = 1 ; i <=n ; ++i)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);

    int maxx=0,i=n;
    ll f[20][k+10];
    for(int i=0; i<=n; i++)
    {
        f[i][0]=1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {


            if(j>=a[i])
            {

                for(int k=i;k>=1;k--)
                {

                if(f[k-1][j-a[i]]==1)
                {
                    f[i][j]=1;
                    //cout << j << endl;
                }
                }

                if(f[i][j]>0)
                {
                    maxx=max(maxx,j);
                }
            }
        }
    }
    cout << maxx ;
}
