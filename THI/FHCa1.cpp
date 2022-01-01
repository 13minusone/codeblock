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
#define task "a1"
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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
string s;
int cnt[50];
bool check(char c)
{
    if(c=='A'||c=='E'||c=='U'||c=='O'||c=='I')return true;
    return false;
}
void nhap()
{
    cin >> t;
    for(int p = 1 ; p <= t ; p++)
    {
        cin >> s;
        int k=SZ(s);
        int maxcon=0,maxvow=0,cow=0,con=0;
        memset(cnt,0,sizeof cnt);
        for(int i = 0 ; i < k ; i++)
        {
            cnt[s[i]-'A']++;
            if(check(s[i]))
            {
                if(cnt[s[i]-'A']>maxvow)
                {
                    maxvow=cnt[s[i]-'A'];

                }
                cow++;
            }
            else
            {
                if(cnt[s[i]-'A']>maxcon)
                {
                    maxcon=cnt[s[i]-'A'];
                }
                con++;
            }
        }
        int ans;
        ans=min((k-cow-maxcon)*2+cow,(k-con-maxvow)*2+con);
        cout << "Case #"<<p << ": " << ans << endl;
    }
}
int main()
{

    fastio();
     //inti();
    nhap();
}




