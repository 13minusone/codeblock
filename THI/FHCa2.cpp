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
#define task "a2"
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
int t;
string s,c;
int k;
vector<int>vec[50];
ll f[50][50];
void nhap()
{
    cin >> t;
    for(int Case = 1 ; Case <= t ; Case++)
    {
        for(int i = 'A'-'A'; i <='Z'-'A'; i++)
        {
            for(int j = 'A' -'A'; j <= 'Z' -'A'; j++)
            {
                if(i==j)
                {
                    f[i][j]=0;
                }
                else
                {
                    f[i][j]=mod;
                }
            }
        }

        cin >>s;
        cin >> k;
        for(int i = 1 ; i <= k ; i++)
        {
            cin >> c;
            if(c[0]!=c[1])
            {
                f[ c[0]-'A'][ c[1]-'A' ]=1;
            }
        }
        for(int h = 'A'-'A' ; h <= 'Z' -'A'; h++)
        {
            for(int i = 'A'-'A'; i <='Z'-'A'; i++)
            {
                for(int j = 'A' -'A'; j <= 'Z' -'A'; j++)
                {

                    if(i==j||i==h||j==h||j==i)continue;
                    f[i][j]=min(f[i][j],f[i][h]+f[h][j]);

                }
            }
        }
        //cout << f['F'-'A']['I'-'A'] << endl;
        ll maxx=mod;
        //cout << maxx << endl;
        for(int i ='A'-'A'; i <='Z'-'A'; i++)
        {
            bool te=true;
            ll sum=0;
            for(int j = 0 ; j <SZ(s); j++)
            {
                if(f[s[j]-'A'][i]==N)
                {
                    te=false;
                    break;
                }
                else
                {

                    sum+=f[s[j]-'A'][i];
                }
            }
            if(te==true)maxx=min(maxx,sum);
            else sum=0;
        }
        if(maxx==mod)maxx=-1;
        cout << "Case #"<<Case << ": " << maxx << endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}



