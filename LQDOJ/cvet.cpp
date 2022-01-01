#include <bits/stdc++.h>
using namespace std;
#define vec vector
#define SZ(c) c.size()
typedef long long ll;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
int k;
string s1;
void nhap()
{
    cin >> s1 >> k;
    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        int maxx = 1;
        int a = 0, b = 0, dem = 0;
        while (b < SZ(s1))
        {
            if (int(s1[b]) != i)
               {
                ++dem;
               }
            while (dem>k)
            {
                if (int(s1[a]) != i)
                    {
                        dem--;
                    }
                a++;
            }
           maximize(maxx,b-a+1);
            b++;
        }
        maximize(ans,maxx);
    }
    cout << ans;
}
int main()
{
    fastio();
 nhap();
}
