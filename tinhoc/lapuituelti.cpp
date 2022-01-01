#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
    int n,m,x;
    string a;
void inti()
{
   freopen("victory.inp","r",stdin);
   freopen("victory.out","w",stdout);
}
int check(char a)
{
    if(a=='8')
    {
        return 8;
    }
    else
    {
        if(a=='0')
        {
            return 0;
        }
        else
        {
            if(a=='2')
            {
                return 5;
            }
            else
            {
                if(a=='1')
                {
                    return 1;
                }
                else
                {
                    if(a=='5')
                    {
                        return 2;
                    }
                    else
                    {
                        return 10;
                    }
                }
            }
        }
    }
}
int maxx=100000000;
int tim(char a,int x,char b)
{
    int p;
    if(abs(x-(int('b'-48)*10+1))<maxx&&(int('b'-48)*10+1)<=x)
    {
        maxx=abs(x-(int('b'-48)*10+1));
        p=1;

    }
    if(abs(x-(int('b'-48)*10+2))<maxx&&(int('b'-48)*10+2)<=x)
    {
        maxx=abs(x-(int('b'-48)*10+2));
        p=2;

    }
    if(abs(x-(int('b'-48)*10+5))<maxx&&(int('b'-48)*10+5)<=x)
    {
        maxx=abs(x-(int('b'-48)*10+5));
        p=5;

    }
    if(abs(x-(int('b'-48)*10+8))<maxx&&(int('b'-48)*10+8)<=x)
    {
        maxx=abs(x-(int('b'-48)*10+8));
        p=8;

    }
    if(abs(x-(int('b'-48)*10+0))<maxx&&(int('b'-48)*10+0)<=x)
    {
        maxx=abs(x-(int('b'-48)*10+0));
        p=0;

    }
    return p;

}
int tim1(char a,int x,char b)
{
    int p;
    if(abs(x-(1*10+int('b'-48)))<maxx&&(1*10+int('b'-48))<=x)
    {
        maxx=abs(x-(1*10+int('b'-48)));
        p=1;

    }
    if(abs(x-(2*10+int('b'-48)))<maxx&&(2*10+int('b'-48))<=x)
    {
        maxx=abs(x-(2*10+int('b'-48)));
        p=2;

    }
    if(abs(x-(5*10+int('b'-48)))<maxx&&(5*10+int('b'-48))<=x)
    {
        maxx=abs(x-(5*10+int('b'-48)));
        p=5;

    }
    if(abs(x-(8*10+int('b'-48)))<maxx&&(8*10+int('b'-48))<=x)
    {
        maxx=abs(x-(8*10+int('b'-48)));
        p=8;

    }
    if(abs(x-(0*10+int('b'-48)))<maxx&&(0*10+int('b'-48))<=x)
    {
        maxx=abs(x-(0*10+int('b'-48)));
        p=0;

    }
    return p;

}
string solve(int x,int m,string a )
{
    int t=0,l=0;
    string s="";
    if(check(a[0])!=10&&check(a[1])!=10)
    {
        if((check(a[0])+check(a[1])*10)<=m)
        {
            t=1;
            s=s+a[0]+a[1]+":";
        }

    }
    if(t!=1)
    {
        if(check(a[0])==10&&check(a[1])!=10)
        {
           s=s+ char(tim(a[0],m,a[1])+48)+a[1]+":";
        }
        else
        {if(check(a[1])==10&&check(a[0])!=10)
        {
           s=s+a[0] +char(tim1(a[1],m,a[0])+48)+":";
        }else
        {
            if(check(a[0])==10&&check(a[1])!=10)
        {
           s=s+ char(tim(a[0],m,a[1])+48)+char(tim1(a[1],m,a[0])+48)+":";
        }
        }
        }
    }
    if(check(a[3])!=10&&check(a[4])!=10)
    {
        if((check(a[3])+check(a[4])*10)<=x)
        {
            l=1;
            s=s+a[3]+a[4];
        }

    }
    if(l!=1)
    {
        if(check(a[3])==10&&check(a[4])!=10)
        {
           s=s+ char(tim(a[3],x,a[4])+48)+a[4];
        }
        else
        {if(check(a[4])==10&&check(a[3])!=10)
        {

           s=s+ a[3]+char(tim1(a[4],x,a[3])+48);
        }else
        {
            if(check(a[3])!=10&&check(a[4])!=10)
        {
           s=s+ char(tim(a[3],x,a[4])+48)+char(tim1(a[4],x,a[3])+48);
        }
        }
        }
    }
    return s;
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{
    cin>>x>>m;
    cin>>a;
    cout<<solve(x,m,a)<<endl;

}
}
int main()
{
    inti();
nhap();
}

