#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
int m,n;
string x;

void inti()
{
    freopen("ngoac797.inp","r",stdin);
    freopen("ngoac797.out","w",stdout);
}

void check(string a)
{

    stack<char>st;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=='{'||a[i]=='('||a[i]=='[')
        {
            st.push(a[i]);
        }
        else
        {
            if(st.empty()==false)
            {if(a[i]=='}')
            {
                if(st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    cout<<"0"<<endl;
                   return;
                }
            }
            else
            {
                if(a[i]==']')
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        cout<<"0"<<endl;
                       return;
                    }
                }
                else
                {
                    if(a[i]==')')
                    {if(st.top()=='(')
                    {
                        st.pop();
                    }
                    else
                    {
                        cout<<"0"<<endl;
                        return;
                    }
                }
            }}
        }}
    }

    cout<<"1"<<endl;
}
void nhap()
{

    cin>>n;
    fu(1,n,1)
    {
        cin>>x;
        check(x);
    }
}
int main()
{
    inti();
nhap();
}
