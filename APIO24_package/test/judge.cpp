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
    for (ll i=0; i<=2000; i++)
    {
        cout << "test " << i << ": ";
        system("gentest.exe");
        system("test.exe");
        system("stress.exe");
        ifstream inp("output.txt");
        ifstream inp2("output2.txt");
        string ans, ans2;
        while (inp>>ans)
        {
            inp2>>ans2;
            if (ans!=ans2) {cout << "WA\n", exit(0);}
        }
        cout << "AC\n";
    }
}
