#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
ll m,n,x;
ll vec[1000000];
void inti()
{
    freopen("chuyenduong.inp","r",stdin);
    freopen("chuyenduong.out","w",stdout);
}
void nhap()
{

    cin>>n;
    fu(1,n,1)
    {
        cin>>vec[i];
    }
}
stack<ll>st;
void xuly()
{
    ll i = 1,f = 0;
    for(int j=1; j<=n; j++)
    {

            while(i<vec[j])
            {
                st.push(i);
                i++;
                f++;
            }

        if(i==vec[j])
        {
            f++;
            i++;
        }
        else{
        if(i>vec[j])
        {
            if(st.top()==vec[j])
            {
                f++;

                st.pop();
            }
            else
            {
                cout<<"0";
                return;
            }
        }}
    }

    cout<<f<<endl;;
}
int main()
{
    inti();
    nhap();
    xuly();

}
