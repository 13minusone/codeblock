#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

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
    freopen("activity862.inp","r",stdin);
    freopen("activity862.out","w",stdout);
}
void nhap()
{
    ll n,m,k,x,y,t;
    cin>>t;
    fu(i,1,t,1)
    {
        cin>>n>>m>>k>>x>>y;


        // cout<<res<<" "<<res1<<endl;
        unsigned ll f;
        if(n%x==0)
        {
            f=n/x;
        }
        else
        {
            f=n/x;
        }
        unsigned ll p;
        if(m%y==0)
        {
            p=m/y;
        }
        else
        {
            p=m/y;
        }

        unsigned ll s=m+n-k;

        unsigned ll o=x+y;
        unsigned ll r;
        if(s%o==0)
        {
            r=s/o;
        }
        else
        {
            r=s/o;
        }


        if(s<x+y)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<min(min(r,p),f)<<endl;
        }

    }
}
int main()
{
    IOS
    inti();
    nhap();

}


