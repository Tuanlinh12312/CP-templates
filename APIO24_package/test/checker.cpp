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

const ll maxn=3005, Mod=998244353;
ll a[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream inp("input.txt"), out("output.txt");
    ll n, ok=1; inp >> n;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=i; j++)
            out >> a[n-i][j], assert(a[n-i][j]!=-1);
    for (ll i=1; i<n; i++)
        for (ll j=1; j<=n-i; j++)
            if (a[i][j]!=(a[i-1][j]+a[i-1][j+1])%Mod)
                cout << "not satisfied: " << i << ", " << j << "\n", ok=0;
    if (ok) cout << "correct answer\n";

}
