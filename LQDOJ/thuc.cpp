#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 10000005;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int f[maxsize], a[maxsize], l, r, q;
bool p[maxsize], kt[maxsize];
bool check(int x)
{
    if(f[x] == x)return false;
    int k = x / f[x];
    if(p[k])return false;
    if(f[x] == k)return false;
    return true;
}

void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
int main()
{
fastio();
    fu( i,2, 1e7,1)
    {
        if(f[i])
        {
        continue;}

        fu(j , i,1e7, i)
        {
            if(f[j]==0)
            {
                f[j] = i;
            }
        }

    }
    for(int i = 2;i * i <= 1e7;++i)
    {
       if(p[i])continue;


        fu(j ,i * i,1e7, i)
        {
            p[j] = 1;
        }

    }
    for(int  i =2;i * i * i <= 1e7;i++)
    {
        if(!p[i])
        {
            kt[i*i*i] = 1;
        }
    }
    fu(i ,6,1e7,1)
    {
        a[i] = a[i-1];
        if(kt[i])
        {
            a[i]++;
        }
        else if(check(i))
        {
            a[i]++;
        }
    }
    cin >> q;
    fu(i,1,q,1)
    {
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
}
