#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
int m,n,x[10000],j[1000],h[1000];
void inti()
{
    freopen("xoacs.inp","r",stdin);
    freopen("xoacs.out","w",stdout);
}
ll d=0,k;
void luu()
{
    while(n!=0)
    {

        d++;
        x[d]=n%10;

        n=n/10;
    }
}
void nhap()
{

    cin>>n>>k;

}
stack<ll>st;
void xuat()
{
    ll s=0;
    vector<int>vec;
    while(st.empty()==false)
    {
        vec.push_back(st.top());
        st.pop();
    }
    fu(0,vec.size()-1,1){s=s*10+vec[i];}
    cout<<s;
}
int main()
{
    nhap();
    luu();
    st.push(x[d]);

    for(int i=d-1; i>=1; i--)
    {
        if(k>0)
        {
            while(st.empty()==false)
            {
                if(st.top()<x[i])
                {
                    st.pop();

                    k--;
                }
                else
                {

                    break;
                }
            }




        }
         st.push(x[i]);
    }
//        fu(1,d,1)
//    {
//        cout<<st.top()<<" "<<'\n';
//        st.pop();
//    }
    xuat();
}
