#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
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
void nhap()
{
    int n;
    cin >> n;
    int a[200];
    char c;
    int h;
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> c >> h;
        a[c]++;
        a[h]++;

    }

}
int main()
{

    fast();
    // inti();
    nhap();
}


