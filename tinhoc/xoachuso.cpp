
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
ll m,x[10000],j[1000],h[1000];
string n;
void inti()
{
    freopen("xoachuso.inp","r",stdin);
    freopen("xoachuso.out","w",stdout);
}
ll d=0,k;
void luu()
{
    for(int i=0;i<n.size();i++)
    {
        x[i+1]=int(n[i])-48;
    }
}
void nhap()
{

    cin>>n>>k;

}
stack<ll>st;
void xuat()
{
    string s="";
    vector<int>vec;
    while(st.empty()==false)
    {
        vec.push_back(st.top());
        st.pop();
    }
    fd(vec.size()-1,0,1){s=s+char(vec[i]+48);}
    cout<<s;
}
int main()
{
    inti();
    nhap();
    luu();
    st.push(x[1]);
 //cout<<d<<endl;;
 //fu(0,n.size()-1,1)cout<<x[i]<<" ";
    for(int i=2; i<=n.size(); i++)
    {
        if(k>0)
        {
            while(st.empty()==false)
            {
                if(k==0)
                {
                    break;
                }
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
        //cout<<i<<" "<<k<<endl;
         st.push(x[i]);
    }
    if(k>0)
    {
        while(k>0)
        {
            st.pop();
            k--;
        }
    }


    xuat();
}
