 #include <bits/stdc++.h>
    using namespace std;
 
    using ll = long long;
    #define ld long double
    #define int long long
    #define sz(x) (int)(x).size()
    #define all(a) (a).begin(), (a).end()
    #define rall(a) (a).rbegin(), (a).rend()
    #define gen(a, b) uniform_int_distribution<int>(a, b)(rnd)
    template<typename T, typename U> bool imin(T& a, U b){if (a > b) {a = b;return true;} return false;}
    template<typename T, typename U> bool imax(T& a, U b){if (a < b){a = b; return true;} return false;}
    #define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>=(b); i+=(s))
    #define F_OR1(e) F_OR(i, 0, e, 1)
    #define F_OR2(i, e) F_OR(i, 0, e, 1)
    #define F_OR3(i, b, e) F_OR(i, b, e, 1)
    #define F_OR4(i, b, e, s) F_OR(i, b, e, s)
    #define GET5(a, b, c, d, e, ...) e
    #define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
    #define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
 
    const int N = 2e5 + 100;
    const int INF = 1e18;
    int mod = 1e9 + 7;
    const ld EPS = 1e-6;
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    #ifndef ONPC
    #define endl '\n'
    #endif
    int max_log = 21;
    struct P {
        ld x{},y{};
        P(ld X, ld Y) {
            x = X;
            y = Y;
        }
        P() {}
        ld operator *(const P p) const {
            return x * p.x + y * p.y;
        }
        ld operator %(const P p) const {
            return x * p.y - y * p.x;
        }
        P operator -(const P p) const{
            return {x - p.x, y - p.y};
        }
        P operator +(const P p) const{
            return {x + p.x, y + p.y};
        }
        bool operator ==(const P p) const{
            return (p.x == x && p.y == y);
        }
    };
    int n;
    vector<P> h;
 
    int get_max(P p, int i = 0){
        for (int k = max_log; k >= 0; --k) {
            P p1 = h[(i + (1 << k)) % n] - p;
            P p2 = h[i] - p;
            P p3 = h[((i - ((1 << k) % n) ) + n) % n] - p;
            if (p2 % p1 > 0) {
                if (p3 % p2 > 0) {
                    i = ((i - ((1 << k) % n) ) + n) % n;
                } else {
 
                }
            } else {
                if (p3 % p1 > 0) {
                    i = ((i - ((1 << k) % n) ) + n) % n;
                } else {
                    i = (i + (1 << k)) % n;
                }
            }
        }
        return i;
    }
    int get_min(P p, int i = 0){
        for (int k = max_log; k >= 0; --k) {
            P p1 = h[(i + (1 << k)) % n] - p;
            P p2 = h[i] - p;
            P p3 = h[((i - ((1 << k) % n) ) + n) % n] - p;
            if (p2 % p1 <= 0) {
                if (p3 % p2 <= 0) {
                    i = ((i - ((1 << k) % n) ) + n) % n;
                } else {
 
                }
            } else {
                if (p3 % p1 <= 0) {
                    i = ((i - ((1 << k) % n) ) + n) % n;
                } else {
                    i = (i + (1 << k)) % n;
                }
            }
        }
        return i;
    }
    signed main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    #ifndef ONPC
        freopen("tangente.in", "r", stdin);
        freopen("tangente.out", "w", stdout);
    #else
        freopen("test.txt", "r", stdin);
    #endif
        int k;
        cin >> n >> k;
        h.assign(n, {});
        for (int i = 0; i < n; ++i) {
            cin >> h[i].x >> h[i].y;
        }
        for (int i = 0; i < k; ++i) {
            P p;
            cin >> p.x >> p.y;
            int t1 = get_min(p) + 1;
            int t2 = get_max(p) + 1;
            cout << min(t1,t2) << " " << max(t1,t2) << endl;
        }
    }
