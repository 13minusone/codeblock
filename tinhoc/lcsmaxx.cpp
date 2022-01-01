#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i+c)
#define xuo(s) cout << s << endl;
string a,s,f;
string maxx[1001][1001];
unsigned ll k,l;
void inti()
{
    freopen("lcsmaxx.inp","r",stdin);
    freopen("lcsmaxx.out","w",stdout);
}
int doi(char a )
{
    long long c=a-48;
    return c;
}
bool  dois(string s,string a)
{
    int i=0,j=0;
    int n= s.size()-1;
    int h=a.size()-1;
    while(doi(s[i])==0&&i<=n)
    {
        i++;
    }
    while(doi(a[j])==0&&j<=h)
    {
        j++;
    }



    if(n-i<h-j)
    {
        return false;
    }
    else
    {
        if(n-i > h-j)
        {
            return true;
        }
        else
        {
            while(i<=n)
            {
                if( doi(s[i]) > doi(a[j]))
                {
                    return true;
                }
                else
                {
                    if( doi( s[i] ) < doi  ( a[j] ) )
                    {
                        return false;
                    }

                }
                i++;
                j++;
            }
        }
    }
    return true;
}
void nhap()
{
    cin >> a >> s;
    s=" "+s;
    a=" "+a;
    f=f+"0";
//    if(dois("01145","345")==true)
//    {
//        cout<<1<<endl;
//        return;
//    }
//    else
//    {
//        cout<<2<<endl;
//        return;
//    }
    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=s.size(); j++)
        {

            if(doi(a[i])==doi(s[j]))
            {
                maxx[i][j]=maxx[i-1][j-1]+a[i];
            }
            else
            {
                if(dois(maxx[i-1][j],maxx[i][j-1])==true)
                {
                    maxx[i][j] = maxx[i-1][j];
                }
                else
                {
                    maxx[i][j] = maxx[i][j-1];
                }
            }

            if(dois(maxx[i][j],f)==true)
            {
                f=maxx[i][j];
                k=i;
                l=j;
            }
        }
    }
    cout << maxx[k][l].size()-1 << endl;
    cout <<"LCS MAX NUMBER is" << " ";
    if( maxx[k][l].size() <= 0 )
    {
        cout<<"NULL";
    }
    else
    {
        cout<< maxx[k][l];
    }
}
int main()
{
    //inti();
    nhap();
}
