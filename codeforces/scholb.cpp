#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef long double ldb;
typedef double db;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
void nhap()
{
    int p;
    cin >> p;
    for(int dem=1;dem<=p;dem++)
        {
            string s, t;
        cin >> s >> t;
        bool tr = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[0]){
                int h = i,o = 0;
                string s1 = "";
                while(s[h] == t[o]&& (o < t.size() && h < s.size())){
                    s1=s1+s[h];
                    h++;
                    o++;
                }
                if(s1==t){
                    cout << "YES" << endl;
                    tr= 1;
                    break;
                }
                h -= 2;
                while(s[h] == t[o]&&( o<t.size() && h >= 0)){
                    s1=s1+s[h];
                    h--;
                    o++;
                }
                if(s1==t){
                    tr = 1;
                    cout << "YES" << endl;
                    break;
                }
            }
        }
        if(!tr)cout << "NO" << endl;
    }
    return;
}
int main()
{
    fastio();
   nhap();
}
