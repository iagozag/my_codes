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
	int n, m; cin >> n >> m;
	vector<int> a(n); priority_queue<pair<int, int>> pq; 
	for(auto& x: a) cin >> x;
	for(int i = 0; i < m; i++){ int b; cin >> b; pq.push({b, i}); }

	vector<int> ans(m, -1);
	for(int i = 0; i < n; i++){
		while(!pq.empty() and pq.top().first >= a[i]) ans[pq.top().second] = i+1, pq.pop();
	}	
	for(auto x: ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
