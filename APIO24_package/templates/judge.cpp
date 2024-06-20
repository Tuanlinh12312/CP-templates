#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
using namespace std;

int main()
{
    for (ll i=0; i<=100; i++)
    {
        cout << "test " << i << ": ";
        system("gentest.exe");
        system("code.exe");
        system("stress.exe");
        ifstream inp1("output.txt");
        ifstream inp2("output2.txt");
        ll ans1, ans2;
        while(inp1 >> ans1)
        {
            inp2 >> ans2;
            if (ans1!=ans2)
            {
                cout << "WA\n";
                exit(0);
            }
        }
        cout << "AC\n";
    }
}
