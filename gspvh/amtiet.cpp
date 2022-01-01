#include<bits/stdc++.h>
using namespace std;
#define task "syllable"
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
bool check(char x)
{
    if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return true;
    return false;
}
void nhap()
{
    string s;
    cin >> s;
    int sum=0;
    int  j=s.size();
    s=s+" ";
    for(int i = 0 ; i < j ; i++)
    {
        if(check(s[i]))
        {
            sum++;
            if(s[i]=='a')
            {
                if(s[i+1]=='u')
                {
                    sum--;
                }
            }
            if(s[i]=='o')
            {
                if(s[i+1]=='a')
                {
                    sum--;
                }
            }

            if(s[i]=='o')
            {
                if(s[i+1]=='o')
                {
                    sum--;
                }
            }

            if(s[i]=='i')
            {
                if(s[i+1]=='o')
                {
                    if(s[i+2]=='u')
                    {
                        sum--;
                    }
                }
            }
        }
    }
    if(s[j-1]=='e')
    {
        sum--;
        if(j>=3)
        {
            if(s[j-2]=='l')
            {
                if(!check(s[j-3]))
                {
                    sum++;
                }
            }
        }
    }

    //cout << sum;
    cout << max(sum,1) ;
}
int main()
{

    fastio();
    inti();
    nhap();
}

