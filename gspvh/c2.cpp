#include<bits/stdc++.h>
using namespace std;
#define task "string"
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
ll c[30],s=0,l,m,k;
void nhap()
{
    for(int i = 0 ; i<26;i++)
    {
        c[i]=0;
    }
    while(cin >> l >> m >> k)
    {
        //cout << l << m << k << endl;
        s=0;
        for(int i = 0 ; i <26 ; i++ )
        {
            cin >> c[i];
            if(c[i]>0)
            {
                s+=c[i];
            }
        }
        if(s<l*k|| l>m)
        {
            cout << "NO" << endl;
            continue;
        }
        if(k==1)
        {
            if(s>=l)
            {
                cout << "YES" << endl;
                for(int i = 0 ; i<26; i++)
                {
                    if(c[i]>0)
                    {
                        if(l>=c[i])
                        {
                            for(int j = 1 ; j<=c[i]; j++)
                            {
                                cout << char('a'+i);
                            }
                            l-=c[i];
                            c[i]=0;
                        }
                        else
                        {
                            for(int j = 1 ; j <= l ; j++)
                            {
                                cout << char('a'+i);
                            }
                            l=0;
                        }

                    }
                    if(l==0)
                    {
                        cout << endl;
                        break;
                    }
                }
                continue;
            }
            else
            {
                cout << "NO" << endl;
                continue;
            }
        }

        if(s==l)
        {
            ll su=1;
            for(int i = 1 ; i<= s; i++)
            {
                su*=i;
            }
            if(su<k)
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                cout << "YES" << endl;
                for(int i = 0 ; i<26 ; i++)
                {
                    if(c[i]>0)
                    {
                        for(int j = 1 ; j <=c[i] ; j++)
                    {
                        cout << char('a'+i);
                    }
                    }
                }
                cout << endl;
                continue;
            }
        }
        int g=l*k;
        g=g+(k+1)*(k/2);
        if(k%2==1)
        {
            g+=int(k/2+1);
        }
        if(g<=s)
        {
            cout <<"YES" << endl;
            int i=0;
            for(int o =l ; o<l+k; o++)
            {
                int j=0;
                while(j<o)
                {
                    while(c[i]>0)
                    {
                        cout << char(i+'a') ;
                        c[i]--;
                        j++;
                        if(j==o)
                        {
                            cout << " ";
                            break;
                        }
                    }
                    i++;
                }
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }


    }
}
int main()
{

    fastio();
    inti();
    nhap();
}



