#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m,n,x,y,a[101][101];
/*
-----------------AUTHOR-----------------------
--------------Parth Mangal--------------------
----------------------------------------------

██████╗░██╗░░░░░███████╗░█████╗░░██████╗███████╗  ██████╗░░█████╗░███╗░░██╗██╗████████╗
██╔══██╗██║░░░░░██╔════╝██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔══██╗████╗░██║╚█║╚══██╔══╝
██████╔╝██║░░░░░█████╗░░███████║╚█████╗░█████╗░░  ██║░░██║██║░░██║██╔██╗██║░╚╝░░░██║░░░
██╔═══╝░██║░░░░░██╔══╝░░██╔══██║░╚═══██╗██╔══╝░░  ██║░░██║██║░░██║██║╚████║░░░░░░██║░░░
██║░░░░░███████╗███████╗██║░░██║██████╔╝███████╗  ██████╔╝╚█████╔╝██║░╚███║░░░░░░██║░░░
╚═╝░░░░░╚══════╝╚══════╝╚═╝░░╚═╝╚═════╝░╚══════╝  ╚═════╝░░╚════╝░╚═╝░░╚══╝░░░░░░╚═╝░░░

░██╗░░░░░░░██╗░█████╗░████████╗░█████╗░██╗░░██╗  ███╗░░░███╗██╗░░░██╗  ░█████╗░░█████╗░██████╗░███████╗
░██║░░██╗░░██║██╔══██╗╚══██╔══╝██╔══██╗██║░░██║  ████╗░████║╚██╗░██╔╝  ██╔══██╗██╔══██╗██╔══██╗██╔════╝
░╚██╗████╗██╔╝███████║░░░██║░░░██║░░╚═╝███████║  ██╔████╔██║░╚████╔╝░  ██║░░╚═╝██║░░██║██║░░██║█████╗░░
░░████╔═████║░██╔══██║░░░██║░░░██║░░██╗██╔══██║  ██║╚██╔╝██║░░╚██╔╝░░  ██║░░██╗██║░░██║██║░░██║██╔══╝░░
░░╚██╔╝░╚██╔╝░██║░░██║░░░██║░░░╚█████╔╝██║░░██║  ██║░╚═╝░██║░░░██║░░░  ╚█████╔╝╚█████╔╝██████╔╝███████╗
░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░░╚═╝░░░  ░╚════╝░░╚════╝░╚═════╝░╚══════╝
*/
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>n;


fu(i,1,n,1)
{
    ll h,j;
    cin>>m>>x>>y;
    h=y%m;
    j=y/m;
if(y%m!=0)
     {
         cout << (h-1)*x+j+1<< endl;
     }
     else
     {
         cout << (m-1)*x+j<< endl;
     }
}
}
int main()
{
IOS
//inti()
nhap();

}
