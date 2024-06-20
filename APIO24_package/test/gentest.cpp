#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define sz(a) ((ll)(a).size())
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll l, ll r){return rng()%(r-l+1)+l;}
string random_pair(ll l, ll r)
{
    ll a=random(l, r), b=random(l, r);
    if (a>b) swap(a, b);
    return to_string(a)+" "+to_string(b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "w", stdout);
    ll n=random(5, 10), m=n-1; cout << n << " " << m << "\n";
    for (ll i=2; i<=n; i++) cout << i-1 << " " << i << " " << random(1, 5) << "\n";
    ll q=random(10, 20); cout << q << "\n";
    for (ll i=1; i<=q; i++)
    {
        ll t=random(1, 2), u=t==2?random(1, n):random(1, m), w=random(1, 5);
        cout << t << " " << u << " " << w << "\n";
    }
}
