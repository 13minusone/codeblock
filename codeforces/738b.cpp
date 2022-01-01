/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
char s[105];
int t,n;
vector<int>vec;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin>>n;
        vec.clear();
        vec.push_back(0);
        for(int i = 1 ; i<= n ; i++)
        {
            cin >> s[i];
            if(s[i]!='?')
            {
                vec.push_back(i);
            }
        }
        int k = vec.size();

        int i=1;
        while(i<k)
        {
            for(int j = vec[i]-1 ; j >= 1 ; j--)
            {
                if(s[j]!='?')
                {
                    break;
                }
                else
                {
                    if(s[j+1]=='B')
                    {
                        s[j]='R';
                    }
                    else
                    {
                        s[j]='B';
                    }
                }
            }
            i++;
        }
        if(vec[k-1]!=n)
        {
            for(int i = vec[k-1]+1;i<=n;i++)
            {
                 if(s[i]!='?')
                {
                    break;
                }
                else
                {
                    if(s[i-1]=='B')
                    {
                        s[i]='R';
                    }
                    else
                    {
                        s[i]='B';
                    }
                }
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            cout << s[i];
        }
        cout << endl;

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



