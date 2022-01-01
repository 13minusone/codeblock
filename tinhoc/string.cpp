#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
int n;
string m,x;
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
void check(string a)
{
    string b;
    char o;
    b="";
    b=b+'(';
    o=a[0];
    //cout<<o<<endl;
    fu(i,1,a.size()-1,1)
    {
        if(a[i]==o)
        {
            b=b+'(';
        }
        else
        {
            b=b+a[i];
        }

    }
    //cout<<b<<endl;
    fu(i,0,b.size()-1,1)
    {
        if(b[i]!='('&&b[i]!=')')
        {
            int s=0,j=i-1,g=0,t=0;
            char d=b[i-1];
            char f;

            while(b[j] == d)
            {
                 s++;
                j--;

                if(j<0)break;
            }

             j=i;

if(d=='(')
{
    f=')';
}
else
{
    f='(';
}
            d=b[j];
            while(b[i]!='('&&b[i]!=')'&&g<=s)
            {
                g++;
                i++;
                if(b[i]!=d)
                {
                    t=1;
                }
                if(i>b.size()-1)break;
            }
i--;
           // cout<<b<<" "<<s<<" "<<g<<" "<<i<<endl;
            if(g!=s)
            {
                cout<<"NO"<<endl;
                return ;
            }
            else
            {

                fu(l,j,b.size()-1,1)
                {
                    if(t==0)
                    {

                        if(b[l]==d)
                        {
                            b[l]=f;
                        }
                    }
                    else
                    {
                        if(a[l]!=o)
                       {

                       b[l]=f;}
                    }
                }
            }

            j=0;
            s=0;
            g=0;
            t=0;

        }

    }

    int s=0,g=0,t=0;
    //cout<<b<<endl;
    fu(i,0,b.size()-1,1)
    {

        if(b[i]=='(')
        {
            while(b[i]=='(')
            {
                s++;
                i++;
            }
            //cout<<b[i]<< " "<<i<<" "<<s<<endl;
            i=i-1;
        }
        else
        {
            while(b[i]==')')
            {
                g++;
                i++;
            }
            i=i-1;
            // cout<<i<<" "<<g<<endl;

            if(s!=g)
            {
                //cout<<i<<endl;
                cout<<"NO"<<endl;
                t=1;
                break;
            }
            else
            {
                s=0;
                g=0;
            }
        }
    }
    if(t==0){
        if(g==s)
            {cout<<"YES"<<endl;}
            else
            {
                cout<<"NO"<<endl;
            }}


}
void nhap()
{

    cin>>n;
    fu(i,1,n,1)
    {
        cin>>x;
        check(x);
    }
}
int main()
{
    nhap();
}

