#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,a[105],minn=100000,maxx=0,l,r;
   cin >> n;
   for(int i = 1 ;i <= n ; i++)
   {
       cin >> a[i];
       if(a[i]>maxx)
       {
           maxx=a[i];
           l=i;
       }
       if(a[i]<=minn)
       {
           minn=a[i];
           r=i;
       }
   }
   swap(a[r],a[l]);
   for(int i =1 ; i<= n ;i++)
   {
       cout << a[i] << " ";
   }
}
