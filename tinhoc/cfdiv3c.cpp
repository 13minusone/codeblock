#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x;
int a[200001];
unsigned ll s=0;
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
    int t=0;
    s=0;
    cin>>x;
    fu(j,1,x+2,1)
    {
        cin >> a[j];
        s=s+a[j];
    }
    sort(a+1,a+x+2+1);

    fu(j,1,x+1,1)
    {
        unsigned ll d=s-a[j];
        unsigned ll f=(2*a[x+2]);
        if(d==f)
        {
            t=1;
            fu(k,1,x+1,1)
            {
                if(k!=j)
                {
                    cout << a[k] << " ";
                }

            }
            break;
        }
    }
        if(t==0)
        {
              unsigned ll d=s-a[x+2];
        unsigned ll f=(2*a[x+1]);
            if(d==f)
            {
                fu(k,1,x,1)
                {
                    cout << a[k] << " ";
                }
            }
            else
            {
                cout << "-1" ;
            }
        }
        cout <<endl;



}
}
int main()
{
IOS
//inti()
nhap();

}

