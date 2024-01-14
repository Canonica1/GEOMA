#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#ifndef LOCAL
#define endl '\n'
#endif
const int N = 1e5 + 100;
typedef long double ld;
struct P {
    int x, y;
    P(int X = 0, int Y = 0) {
        x = X;
        y = Y;
    }
    int operator%(P a) {
        return x * a.y - y * a.x;
    }
    int operator*(P a) {
        return x * a.x + y * a.y;
    }
    P operator-(P a) {
        return {x - a.x, y - a.y};
    }
    int d() {
        return x * x + y * y;
    }
};
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
#endif
 cout.precision(12);
    fixed(cout);    int n;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    P p0 = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i].x < p0.x || (a[i].x == p0.x && a[i].y < p0.y)) {
            p0 = a[i];
        }
    }
    sort(all(a), [&](P a, P b) { return (a - p0) % (b - p0) > 0 || ((a - p0) % (b - p0) == 0 && (a - p0).d() < (b - p0).d()); });
    vector<P> h;
    for (int i = 0; i < n; i++) {
        while (h.size() >= 2 && (h[h.size() - 1] - h[h.size() - 2]) % (a[i] - h[h.size() - 2]) <= 0) {
            h.pop_back();
        }
        h.push_back(a[i]);
    }
    int j = 0;
    int ans = 0;
    vector<P> g(h.size());
    g.back() = h.front() - h.back();
    for (int i = 0; i < h.size() - 1; ++i)
        g[i] = h[i + 1] - h[i];
    auto nx = [&](int j) { return (j + 1) % h.size(); };
    for (int i = 0; i < h.size(); i++) {
        while (g[i] % g[nx(j)] > 0)
            j = nx(j);
        ans = max({ans, (h[i] - h[j]).d(), (h[i] - h[nx(j)]).d()});
    }
    cout << sqrtl((ld)ans) << endl;
}
