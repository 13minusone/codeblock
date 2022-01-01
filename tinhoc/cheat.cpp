#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,x[100001],h[100001];
    stack<int>st;
void inti()
{
   freopen("cheat.inp","r",stdin);
   freopen("cheat.out","w",stdout);
}
void nhap()
{

cin>>n;
fu(1,n,1)cin>>x[i];

}
void xuly()
{
    fu(1,x[1],1)
    {
        h[i]=1;
        st.push(i);
    }
    st.pop();
    fu(2,n,1)
    {
        for(int j=x[i-1];j<=x[i];j++)
        {
            if(h[j]==0)
            {
                h[j]=1;
                st.push(j);
            }
        }
        if(st.top()==x[i])
        {
            st.pop();
        }
        else
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    if(st.empty()==true)
    {
        cout<<"NO";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    inti();
nhap();
xuly();
}
