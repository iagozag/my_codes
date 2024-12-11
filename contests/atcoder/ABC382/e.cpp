#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, x; cin >> n >> x;

	long double prob = 0;
	vector<long double> v(n); for(auto& y: v) cin >> y, y /= 100.0, prob += y;
	prob /= (long double)n;

	long double dp[x+1]; dp[0] = 0;
	for(int i = 1; i <= x; i++){
		dp[i] = 1.0; long double sum = 0;
		for(int j = i-1; j >= max(0LL, i-n); j--) sum += dp[j]*(i-j+1)*prob;
		dp[i] += sum/(i-max(0LL, i-n)+1);
	}

	cout << fixed << setprecision(12) << dp[x] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}