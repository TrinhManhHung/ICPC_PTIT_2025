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

void solve(){   
    int  n, q; cin >> n >> q;
    string s; cin >> s;
    s = " " + s;

    int cnt = 0;
    FOR(i, 1, n-2){
        if(s[i] == 'A'){
            if(s[i+1] == 'B' && s[i+2] == 'C') cnt++;
        }
    }

    while(q--){
        int idx; char c; cin >> idx >> c;
        for(int sta = max(1, idx - 2); sta <= idx; sta++){
            if(s[sta] == 'A'){
                if(s[sta+1] == 'B' && s[sta+2] == 'C') cnt--;
            }
        }
        s[idx] = c;
        for(int sta = max(1, idx - 2); sta <= idx; sta++){
            if(s[sta] == 'A'){
                if(s[sta+1] == 'B' && s[sta+2] == 'C') cnt++;
            }
        }

        cout << cnt << endl;
    }
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