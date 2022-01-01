#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x;
const int maxsize = 1000000;
void inti()
{
    freopen("e.inp","r",stdin);
    freopen("e.out","w",stdout);
}
void nhap()
{
    //inti();
    char a;
    char s[maxsize];
    cin>>n>>m;
    fu(i,1,m,1)
    {
        cin>> x >>a ;
        s[x]=a;
        stack<char>st;
        if(a=='('||a==')')
        {
            st.push(a);
            if(a=='(')
            {
                int i=x+1;
                while(i<=n)
                {
                    if(s[i]==')')
                    {
                        char se=st.top();
                        if(se!=s[i])
                        {
                            st.pop();
                            if(st.empty()==true)
                            {
                                cout << i << endl;
                                break;
                            }
                        }
                        else
                        {
                            st.push(s[i]);
                        }

                    }
                    else
                    {
                         if(s[i]=='(')
                        {st.push(s[i]);}

                    }
                    i++;

                }
                if(st.empty()==false)
                {
                    cout << "-1" <<endl;
                }
            }
            else
            {
                int i=x-1;
                while(i>=1)
                {
                    if(s[i]=='(')
                    {
                        char se=st.top();
                        if(se!=s[i])
                        {
                            st.pop();
                            if(st.empty()==true)
                            {
                                cout << i << endl;
                                break;
                            }
                        }
                        else
                        {
                            st.push(s[i]);
                        }

                    }
                    else
                    {
                        if(s[i]==')')
                        {st.push(s[i]);}

                    }
                    i--;

                }
                if(st.empty()==false)
                {
                    cout << "-1" <<endl;
                }

            }

        }
    }
}
int main()
{
    IOS
//inti()
    nhap();

}
