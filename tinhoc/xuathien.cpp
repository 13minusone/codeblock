#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0;
    long long a[1000000],b[1000000];
    long long tknp(long long arr[], int l, int r, long long x)
{
    if (r >= l) {
        int mid = (l +r) / 2;


        if (arr[mid] == x)
            return mid;
else{

        if (arr[mid] > x)
            {return tknp(arr, l, mid - 1, x);}
            else{

       return tknp(arr, mid + 1, r, x);
    }}}


    return -1;
}
int  main()
{
    freopen("xuathien.inp","r",stdin);
    freopen("xuathien.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);

    }
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0;i<n;i++)
    {
        if(tknp(b,0,m-1,a[i])!=-1)
        {
            s++;

                while(i<n)
                {
            if(a[i]==a[i+1])
            {
                    i++;
                    s++;
                }
                else
                {
                    break;
                }
                }
            }

        }

    cout<<s;
}
