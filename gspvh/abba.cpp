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
bool check(string s,string t)
{
     queue<string> que;
    que.push(t);
    while (!que.empty())
    {
        string c = que.front();
        que.pop();
        if (c == s){
           return 1;
        }
        string bien = c;
        if (c.back() == 'A')
        {
            bien.pop_back();
            que.push(bien);
        }
        if (c[0] == 'B')
        {
            bien = c;
            reverse(all(bien));
            bien.pop_back();
            que.push(bien);
        }
    }
    return 0;
}
void nhap()
{
    int n;
    n=3;
    while(n--)
    {
    string s, t;
    cin >> s >> t;
    if (s == t){
        cout << "Yes" <<endl;
        continue;
    }
    if (SZ(s)> SZ(t)){
        cout << "No" << endl;
        continue;
    }
    if (SZ(s) == SZ(t))
        if (s != t)
           {
               cout << "No" << endl;
               continue;
           }
           if(check(s,t)==0)
           {
               cout << "No" << endl;
           }
           else
           {
               cout << "Yes" << endl;
           }

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




