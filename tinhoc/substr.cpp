#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
void inti()
{
   freopen("substr.inp","r",stdin);
   freopen("substr.out","w",stdout);
}
void nhap()
{

string s;
cin>>s;
int maxx=-1,le;
//cout<<s[0]<<" "<<int(s[0])<<endl;
fu(i,0,s.size()-2,1)
{
    int d[226];

    fu(j,65,int('Z'),1)d[j]=0;
    d[int(s[i])]++;
    fu(j,i+1,s.size()-1,1)
    {
d[int(s[j])]++;
//cout<<i<<" "<<s[j]<<" "<<d[int(s[j])]<<endl;
        if(d[int(s[j])]>1)
        {
            if(j-1-i+1>maxx)
            {

                maxx=j-1-i+1;
                le=i+1;

            } break;
        }

            if(j==s.size()-1)
            {

                if(j-i+1>maxx)
            {

                maxx=j-i+1;
                le=i+1;

            }

            }

    }
//     cout<<s[i]<<" "<<le<<" "<<maxx<<endl;
}
cout<<le<<" "<<maxx<<endl;
}
int main()
{
    inti();
nhap();
}

