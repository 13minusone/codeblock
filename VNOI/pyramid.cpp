#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll hieu,tong;
void check(double canh)
{
    double ab = tong -canh;
    double huyen = canh +hieu;
    if(ab <=0 || canh <=0 || huyen <= 0)
    {
       return ;
    }
    cout << fixed << setprecision(9) << min(canh,ab) << " " <<max(canh,ab) << " " << huyen;
        exit(0);
}

void nhap()
{
    cin >> hieu >> tong;
    ll x1=hieu*hieu,y1=tong*tong,sum =(tong+hieu),tamgiac;
    tamgiac=8*hieu*sum;
    double del=sqrt(tamgiac);
    double canh1=(2*sum-del)/2.0;
    double canh2=(2*sum+del)/2.0;
    check(canh1);
    check(canh2);
}
int main()
{

    fastio();
    // inti();
    nhap();
}




