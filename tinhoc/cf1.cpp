#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    string x;
   ll tknp(int l,int r,char a,string s)
    {
        ll o=l;
        ll j=r;
        while(l <= r)
        {
            int mid=(l+r)/2;
            if(s[mid]!=a)
            {
                return mid;
            }
            else
            {
                r=mid-1;
            }

        }
        while(o<=j)
        {
            int mid=(o+j)/2;
            if(s[mid]!=a)
            {
                return mid;
            }
            else
            {
                o=mid+1;
            }
        }
 return -1;
    }
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
   freopen("cf1.inp","r",stdin);
   freopen("cf1.out","w",stdout);
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{
    cin>>x;
    int g=x.size();

        if(tknp(0,g-1,'a',x)!=-1)
        {
            int j=0;
            int f=g-1;
            cout << "YES "<<endl;
            if(x[f]!='a')
            {
                cout << "a" << x <<endl;
            }
            else
            {
                if(g>2)
                {int k=(tknp(0,g-1,'a',x)+2);
                x.resize(max(k,g));

                x.insert(tknp(0,g-1,'a',x),"a");
                cout <<x << endl;;
                }
                else
                {
                    int k=(tknp(0,g-1,'a',x)+2);
                x.resize(max(k,g));

                x.insert(tknp(0,g-1,'a',x)+1,"a");
                cout <<x << endl;;
                }
            }
        }
        else
        {
            cout << "NO"<<endl;
        }
    }
}

int main()
{
IOS
inti();
nhap();

}

