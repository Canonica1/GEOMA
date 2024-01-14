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
struct P {
    int x, y, id;
};
P a[N];
P T[N];
const int INF = LLONG_MAX;
int ansl, ansr;
int ans = INF;
int dist(int i, int j) {
    return (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
}
void upd(int i, int j) {
    if (dist(i,j) < ans) {
        ans = dist(i,j);
        ansl = a[i].id;
        ansr = a[j].id;
    }
}
void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                upd(i, j);
            }
        }
        sort(a +l, a + r + 1, [&](P a, P b) {
            return a.y < b.y;
        });
        return;
    }
    int m = l + r >> 1;
    int midx = a[m].x;
    rec(l,m);
    rec(m + 1, r);
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, T, [&](P a, P b) {return a.y < b.y;});
    copy(T, T + r - l + 1, a + l);
    for(int i = l; i <= r; i++) {
        if (abs (a[i].x - midx) < sqrt(ans)) {
			for(int j = i - 1; j >= l; j--) {
                if((a[i].y - a[j].y) > sqrt(ans)) break;
                upd(i,j);
            }
		}
    }

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<P> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
        b[i] = a[i];
    }
    sort(a, a + n, [&](P a, P b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
    rec(0, n - 1);
    cout << b[ansl].x << " " << b[ansl].y << endl;
    cout << b[ansr].x << " " << b[ansr].y << endl;
}
