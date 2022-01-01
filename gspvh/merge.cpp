#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
string g, res = "";
int n,dem;
int tinh(string f)
{
    int ans = 0;
    for (int j = 0; j<f.size(); j++)
    {
        ans*=10 ;
        ans+= (int)(f[j]-'0');
    }
    return ans;
}
void nhap()
{
    cin >> n;
    getline(cin, g);
    for(int p=0; p<n; ++p){
        res="";
        getline(cin, g);
         dem = g.size();
        dem--;
        while(g[dem] >='0'&&g[dem]<='9')
        {
            res=g[dem]+res;
            dem--;
        }
        int adn= tinh(res), ans=1;
        if (adn==1){
            for (int j = 0; g[j] != ' '; j++){
                cout << g[j];
            }
            cout << ' ';
            continue;
        }
        for (int j = 0; j < dem; j++){
            if (g[j + 1]==' '){
                ans++;
                if(ans==adn){
                    for (int r = j + 2; g[r] != ' '; r++){
                        cout << g[r];}
                    cout << ' ';
                    break;}}}
    }
}
int main()
{
    fastio();
    freopen("merge.inp", "r", stdin);
    freopen( "merge.out", "w", stdout);
    nhap();
}
