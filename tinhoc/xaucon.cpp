#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i+c)
#define xuo(s) cout << s << endl;
string a,s;
ll maxx[3001][3001];
void nhap()
{
    cin >> a >> s;
    a=" "+a;
    s=" "+s;
    for(int i=1; i<=a.size()-1; i++)
    {
        for(int j=1; j<=s.size()-1; j++)
        {

            if(a[i]==s[j])
            {
                maxx[i][j]=maxx[i-1][j-1]+1;
            }
            else
            {
                maxx[i][j]=max(maxx[i-1][j],maxx[i][j-1]);
            }

        }
    }

    string res;
    ll x=a.size()-1,y=s.size()-1;
    //cout<<maxx[x][y];
    while(x>0&&y>0)
    {
        if (a[x] == s[y])
        {
            res = a[x]+res;
            x--;
            y--;

        }
        else
        {
            if (maxx[x - 1][y] > maxx[x][y - 1])
                x--;
            else
                y--;
        }
    }


    cout<<res;
}
int main()
{

    nhap();
}

