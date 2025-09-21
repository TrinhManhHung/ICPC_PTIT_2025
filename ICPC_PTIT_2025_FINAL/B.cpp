#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define COUNT_ONE(x) __builtin_popcountll((x))
#define COUNT_LEAD_ZERO(x) __builtin_clzll((x))
#define COUNT_TRAIL_ZERO(x) __builtin_ctzll((x))
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const ll MOD = 998244353;
const int maxn = 100000;


//Fenwick Tree
struct FenwickTree{
	int n;
	vll tree;
	
	FenwickTree(int _n){
		n = _n;
		tree.assign(n + 5, 0);
	}
	
	void update(int pos){
		for(; pos <= n; pos += (pos & -pos)){
			tree[pos] += 1;
		}
	}
	
	ll get(int pos){
		ll res = 0;
		for(; pos > 0; pos -= (pos & -pos)){
			res += tree[pos];
		}
		return res;
	}
};

int n;
int a[maxn + 5], b[maxn + 5];
ll need;

bool check(int val){
    // SHOW1(val);
    FenwickTree bit(2*maxn);

    ll pre = 100000;
    bit.update(pre);
    ll cnt = 0;

    FOR(i, 1, n){   
        if(a[i] > val){
            pre--;
        } else{
            pre++;
        }
        ll add = bit.get(pre - 1);
        bit.update(pre);
        cnt += add;
    }

    // SHOW2(cnt, need);
    return cnt >= need;
}

void solve(){   
    cin >> n;
    
    FOR(i, 1, n){ 
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b+1, b+n+1);
    int left = 1, right = n;

    need = (1ll * n * (n+1)) / 2;
    need = need/ 2 + 1;

    int ans = 0;
    while(left <= right){
        int mid = (left + right) >> 1;
        // SHOW1(b[mid]);
        if(check(b[mid])){
            ans = b[mid];
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }

    cout << ans << endl;
}   

int main(){
    faster();
    int t = 1;
    // cin >> t;
    while(t--){  
        solve();
    }
    return 0;
}