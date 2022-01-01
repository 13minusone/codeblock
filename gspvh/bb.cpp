#include<bits/stdc++.h>
using namespace std;
#define task "olympics"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
void nhap()
{
    string s;
    cin >> s;
    int g=1;
    vector<int>a(4,0);
    ll su=0;
    for(int i = 0 ; i<SZ(s); i++)
    {
        if(s[i]!='.')
        {
            a[g]=a[g]*10+int(s[i]-'0');
        }
        else
        {
            g++;
        }
    }
    //cout << a[1] << " " << a[2] << " " << a[3] << endl;
    while(true)
    {
        if(a[1]==2021&&a[2]==7)
        {
            su+=23-a[3];
            //cout << a[3] << " "<< su << endl;
            a[3]=23;
            break;
        }
        if(a[2]<=7)
        {
            if(a[2]==2)
            {
                if(a[1]%4!=0)
                {
                    su+=28-a[3];
                }
                else
                {
                    if(a[1]%100==0)
                    {
                        if(a[1]%400==0)
                        {
                            su+=29-a[3];
                        }
                        else
                        {
                            su+=28-a[3];
                        }
                    }
                    else
                    {
                        su+=29-a[3];
                    }
                }
            }
            else
            {
                if(a[2]%2==1)
                {
                    su+=31-a[3];
                }
                else
                {
                    su+=30-a[3];
                }
            }
        }
        else
        {
            if(a[2]%2==0)
            {
                su+=31-a[3];
            }
            else
            {
                su+=30-a[3];
            }
        }
        a[2]++;
        if(a[2]>12)
        {
            a[1]++;
            a[2]%=12;
        }
        a[3]=0;
    }
    cout << su << endl;
}
int main()
{

    fastio();
    //inti();
    nhap();
}



