/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
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
const ll N = 1e5;
const ll mod =1e9+9;
const ll base = 311;
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
    int t,n;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        s=" "+s;
        int s2=0,s1=0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(s[i]=='2')
            {
                s2++;
            }
            else
            {
                s1++;
            }
        }
        if(s2==0)
        {
            cout << "YES" << endl;
            for(int i = 1 ; i <= n ; i++)
            {
                for(int j = 1 ; j <= n ; j++)
                {
                    if(i==j)cout << "X";
                    else cout << "=";
                }
                cout << endl;
            }
        }
        else
        {
            if(s2<=2)cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                ll su=1;
                for(int i = 1 ; i<= n ; i++)
                {
                    ll o=0;
                    if(s[i]=='2')
                    {
                        for(int j = 1 ; j <= n ; j++)
                        {
                            if(i==j)
                            {
                                cout << "X" ;
                                continue;
                            }
                            if(s[j]=='1')cout << "-";
                            else
                            {
                                o++;
                                if(o==su-1)
                                {
                                    cout << "-";
                                }
                                else
                                {
                                    if(o<=su)
                                    {
                                        cout << "+";
                                    }
                                    else
                                    {
                                        cout << "-";
                                    }
                                }
                            }
                        }
                        su++;
                    }
                    else
                    {
                        for(int j = 1 ; j<= n ; j++)
                        {

                            if(i==j)cout << "X";
                            else if(s[j]=='1')
                            {
                                cout << "=";
                            }
                            else
                            {
                                cout << "+";
                            }
                        }
                    }
                    cout << endl;
                }

            }
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




