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

class Cars {
public:
	string name;
	int price;
	int mileage;
};


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Cars c[4];
	for (int i = 0; i < 4; i++) {
		cin >> c[i].name >> c[i].price >> c[i].mileage;
	}
	sort(c, c + 4, [](Cars & c1, Cars & c2) {
		if (c1.price == c2.price) {
			return c1.mileage < c2.mileage;
		}
		return c1.price < c2.price;
	});

	for (int i = 0; i < 4; i++) {
		cout << c[i].name << " " << c[i].price << " " << c[i].mileage << "\n";
	}


	return 0;
}