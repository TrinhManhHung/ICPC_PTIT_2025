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
const int maxn = 200000;

//BIT TREE
struct FenwickTree{
	int n;
	vi bit;
	
	FenwickTree(int _n){
		n = _n + 5;
		bit.assign(n, 0);
	}
	void update(int pos){
		for(; pos <= n; pos += (pos&-pos)){
			bit[pos]++;
		}
	}
	int get(int pos){
		int res = 0;
        for(; pos > 0; pos -= (pos&-pos)){
			res += bit[pos];
		}
		return res;
	}

    int getLeft(int pos){
		int res = 0;
		for(; pos > 0; pos -= (pos&-pos)){
			res += bit[pos];
		}
		return res;
	}
};

bool cmp(pii a, pii b){
    if(a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
}

void solve(){   
    int n, m, k; cin >> n >> m >> k;

    vi row(n+1, m+1); //row[i] cột đầu tiên bị chặn ở hàng i
    vi col(m+1, n+1); //col[j] hàng đầu tiên bị chặn ở cột j
    vvi listBanOfCol(m + 1, vi()); //danh sách các hàng bị chặn ở cột j
    
    FOR(i, 1, k){
        int x, y; cin >> x >> y;
        row[x] = min(row[x], y);
        col[y] = min(col[y], x);

        listBanOfCol[y].pb(x);
    }

    ll res = 0;
    //TH1: xuong truoc roi di ngang
    FOR(i, 1, col[1] - 1){
        res += row[i] - 1;
    }

    //TH2: ngang truoc roi di xuong (phai loai bo nhung o da dem o TH1)
    FenwickTree tree(n);
    set<int> baned_row;

    FOR(i, col[1] + 1, n){
        if(baned_row.find(i) == baned_row.end()){
            baned_row.insert(i);
            tree.update(i);
        }        
    }

    FOR(j, 1, row[1] - 1){
        int cnt = tree.get(col[j] - 1);
        res += cnt;

        for(auto x : listBanOfCol[j]){
            if(baned_row.find(x) == baned_row.end()){
                baned_row.insert(x);
                tree.update(x);
            }
        }

    }

    cout << res << endl;
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