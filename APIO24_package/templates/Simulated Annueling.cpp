#include<bits/stdc++.h>
#define ld long double
#define ll int
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

const ll TL=5500;
const ld ST=1e3, EN=1e-3;
mt19937 rng(170306);

ll random(ll l, ll r)
{
    return l+rng()%(r-l+1);
}

void get_random_state()
{
    // initialize starting state
    // although most of the time this is not necessary
}

ld random_probability()
{
    return (ld)random(0, 1e5)/1e5;
}

ld temperature(ld a)
{
    return pow(EN/ST, a)*ST;
}

ld P(ll New, ll Old, ld temp)
{
    if (New<Old)
        return 1.0;
    return exp((Old-New)/temp);
}

ll SA()
{
    get_random_state();
    ll best=0, crr=0;
    auto st=clock();
    while (clock()-st<=TL)
    {
        best=min(best, crr);
        ld temp=temperature(((ld)clock()-st)/TL);
        ll New, Old; //New: value of new state, Old: value of crr state (or crr)
        if (P(New, Old, temp)>=random_probability())
        {
            // move to next state
        }
    }
    return best;
}
