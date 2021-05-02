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
// #define mp  unordered_map<int,int>


/*         Booking Scheduling Problem...

   We have a bus which have maximum 40 seats in it..

   we have four column in our bus...

   There is a condition that if a person sit at any position then he/she will block the way of the seats which is behind this position.

*/



// Initially no person is sitting in the bus.


std::vector<char> ans(40, '-'); // max 40 sets available...

int32_t main() {

	cout << "Enter firstname of Customers.. \n";
	string s; cin >> s;
	unordered_map<int, int> mp;          // take the vaules in map...

	int n = s.size();
	vector<pair<int, char>> a(n);

	cout << "Enter corresponding no of seats.. \n";

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		a[i].first = tmp, a[i].second = s[i];
		mp[a[i].first]++;
	}

	sort(a.rbegin(), a.rend());   // Sorting on the basis of largest number of bookings....

	int k = 0;

	for (int i = 0; i < n; i++)
	{
		int tmp = k;

		if ( mp[((a[i].first + 4 - 1) / 4 - 0) * 4 - a[i].first] >= 1)  // If remaining seats = any member totals steats...
		{
			if (( (a[i].first + 4 - 1) / 4 - 0) * 4 - a[i].first == 1) {         // It means one seat will left..

				for (int j = 0; j  < 40; j++) {  // Search for the element..
					if (a[j].first == 1) {
						ans[k] = a[j].ss;
						mp[a[j].ff]--;
						a[j].ff = 0;
						k++;
						break;
					}
				}
			}

			for (int j = 0; j < a[i].ff; j++)   // Searching for the member which have booked 1 seats
			{
				ans[k] = a[i].ss;
				mp[a[j].ff]--;
				// a[j].ff--;
				k++;
			}

		}

		else       // it means it should be in new line..
		{
			int tmp = k;
			for (int j = 0; j < a[i].ff; j++) {
				ans[k] = a[i].ss;
				mp[a[i].ff]--;
				k++;
				if (((a[i].first + 4 - 1) / 4 - tmp) * 4 - a[i].ff == 1 and j == a[i].ff - 1) {
					k++;
				}
			}
		}

	}

	// Print the final schedule....

	for (int i = 0; i < 40; i++)
	{
		cout << ans[i] << " ";
		if (i % 4 == 3)
			cout << "\n";
	}


	return 0;
}