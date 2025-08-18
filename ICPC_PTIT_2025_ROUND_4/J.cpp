#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int getSxq(int a, int b) {
    if (a > b)
        return a-b;
    return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    int h[n + 5][m + 5];
    memset(h, 0, sizeof(h));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];

    ll s = 0;
    // mat tren + day
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            if (h[i][j] > 0) s += 2;

    // sxq
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s += getSxq(h[i][j], h[i-1][j]);
            s += getSxq(h[i][j], h[i+1][j]);
            s += getSxq(h[i][j], h[i][j-1]);
            s += getSxq(h[i][j], h[i][j+1]);
        }
    }

    cout << s << endl;
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC = 1; 
    cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}

/*
    
*/