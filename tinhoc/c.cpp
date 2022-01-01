#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i+c)
#define xuo(s) cout << s << endl;
string a,s;
ll f,l,k,x,y;

void inti()
{
    freopen("maxx.inp","r",stdin);
    freopen("maxx.out","w",stdout);
}

void nhap()
{
    cin>>f;

    fu(h,1,f,1)
    {
        cin >> a >> s;


ll maxx=0;
        fu(i,0,a.size()-1,1)
        {
            for(int j=0; j<s.size(); j++)
            {
                ll d=0;
                if(a[i]==s[j])
                {
ll p=i;
ll o=j;

                    while(a[p]==s[o]&&p<a.size()&&o<s.size())
                    {
                        d++;
                        p++;
                        o++;
                    }
                    maxx=max(maxx,d);
                }




            }
        }

        cout<<a.size()+s.size()-2*maxx<<endl;

    }
}
int main()
{
    // inti();
    nhap();
}
