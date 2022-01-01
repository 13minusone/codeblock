#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool cmp(int v,int u)
{
    if(v <= u)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    int t;
    cin >> t;
    fu(i,1,t,1)
    {
        int n,arr[51],d[51];
        cin >> n;
        fu(j,1,n,1)
        {
            cin >> arr[j];
            d[arr[j]]=j;
        }
        ll s=0;
       fu(j,1,n,1)
       {
           if(arr[j]==j)
           {
               s++;
           }
       }
       if(s==n)
       {
           cout << 0 << endl;
       }
       else
        {
           if(arr[1]==1||arr[n]==n)
           {
               cout << 1 <<endl;
           }
           else
           {

               if(arr[n]==1)
               {
                   if(arr[1]==n)
                   {
                       cout << 3 <<endl;
                   }
                   else
                   {
                       cout << 2 <<endl;
                   }
               }
               else
               {
                   cout << 2 <<endl;
               }
           }
       }
}
}
int main()
{
    fastio();
    nhap();
}

