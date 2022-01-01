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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
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
char b[51];
int n;
bool check(char a)
{
    return a!= '2' && a!= '3' && a != '5' && a!= '7';
}
void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> b[i];
    for (int i = 1; i <= n; i++){
        if (check(b[i])==true){
            cout << 1 << endl;
            cout << b[i] << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++){
        if (b[i]=='2'||b[i]=='5'){
            if (i > 1){
                cout << 2 << endl;
                cout << b[i - 1] << b[i] << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (b[i] == b[j]){
                cout << 2 << endl;
                cout << b[i] << b[j] << endl;
                return;
            }
        }
    }
    if (b[1] == '5'){
        cout << 2 << endl;
        cout << "57" << endl;
    }
    else if (b[1] == '2'){
        cout << 2 << endl;
        cout << "27"<<endl;
    }
}
int t;
int main()
{
    fastio();
    cin >> t;
    while (t--)nhap();
    return 0;
}
