#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = a; i >= b; i--)

const int MAXN = 1e6+10;
const int INV2 = 500000004;
const int MOD = 1e9 + 7;
int a[MAXN],lf[MAXN],rg[MAXN];

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n;cin >> n;
	rep(i,1,n) cin >> a[i];

	int ans = 0;
	a[0]=a[n+1] = 1e9+1;
	stack<int> stk;
	stk.push(0);

	rep(i,1,n) {
		while (a[i] > a[stk.top()]) stk.pop();
		lf[i] = stk.top();
		stk.push(i);
	}
	while (!stk.empty()) stk.pop();
	stk.push(n+1);
	per(i,n,1) {
		while (a[i] >= a[stk.top()]) stk.pop();
		rg[i] = stk.top();
		stk.push(i);
	}

	rep(i,1,n) {
		int k = a[i]*(a[i]+1)%MOD;
		k = (k*INV2)%MOD;
		k = (k*(i-lf[i]))%MOD;
		k = (k*(rg[i]-i))%MOD;
		ans = (ans+k)%MOD;
	}
	cout << ans << '\n';
}
