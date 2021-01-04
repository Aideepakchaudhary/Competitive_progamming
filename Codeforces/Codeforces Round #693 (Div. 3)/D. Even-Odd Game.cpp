#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
#define ff first
#define ss second
#define pi pair<int,int>
#define pii std::vector<pi>
#define lcm(a,b)  a*b / (__gcd(a,b))
#define mp  unordered_map<int,int>

void solve()
{
    int n; cin >> n;
    int a[n];
    for(int i =0; i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int> ());
    int Alice =0, bob =0;
    for(int i =0; i<n;i++) {
        if(a[i] %2 == 0 and i %2 == 0) {
            Alice += a[i];
        }
        else if(a[i] & 1 and i & 1) {
            bob += a[i];
        }
    }
    if(Alice > bob) {
        cout<<"Alice\n";
    }
    else if(Alice < bob) {
        cout<<"Bob\n";
    }
    else {
        cout<<"Tie\n";
    }
}

int32_t main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}