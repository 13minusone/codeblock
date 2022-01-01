#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
string COLORS = "RGBYW";
bool have[5][5];
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
bool ok(int askColor, int askDigit)
{
    for (int c1 = 0; c1 < 5; c1++)
    {
        for (int d1 = 0; d1 < 5; d1++)
        {
            if (have[c1][d1])
            {
                for (int c2 = 0; c2 < 5; c2++)
                {
                    for (int d2 = 0; d2 < 5; d2++)
                    {
                        if (have[c2][d2])
                        {
                            if (c1 == c2 && d1 == d2) continue;

                            if (c1 == c2)
                            {
                                if (!BIT(askDigit, d1) && !BIT(askDigit, d2)) return false;
                            }
                            if (d1 == d2)
                            {
                                if (!BIT(askColor, c1) && !BIT(askColor, c2)) return false;
                            }

                            if (c1 != c2 && d1 != d2)   // khác cả màu và số, phải hỏi ít nhất một thứ
                            {
                                if (!BIT(askDigit, d1) && !BIT(askDigit, d2) &&
                                        !BIT(askColor, c1) && !BIT(askColor, c2))
                                    return false;
                            }
                        }


                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    freopen("cards.inp","r",stdin);
    freopen("cards.out","w",stdout);
    int n;
    cin >> n;
    for (int vi = 0; vi < n; vi++)
    {
        string card;
        cin >> card;
        for (int i = 0; i < 5; i++) if (COLORS[i] == card[0]) have[i][card[1] - '1'] = true;
    }
    int best = 11;
    for (int askColor = 0; askColor < MASK(5); askColor++)
        for (int askDigit = 0; askDigit < MASK(5); askDigit++)
            if (ok(askColor, askDigit))
                best=min(best, __builtin_popcount(askColor) + __builtin_popcount(askDigit));
    cout << best << endl;

}


