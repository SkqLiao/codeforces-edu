/*
 * @date:2021-04-28 14:34:28
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/I
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v, F;

int main() {
    scanf("%d%d", &n, &m);
    v.resize(n);
    F.resize(m);
    for (auto &x : v) scanf("%d", &x);
    fill_n(F.begin(), m, -1e9);
    int ans = n + 1;
    for (int i = 0; i < n; ++i) {
        if (v[i] == m) ans = 1;
        ans = min(ans, i - F[m - v[i]] + 1);
        for (int j = m - 1; j > v[i]; --j) {
            F[j] = max(F[j], F[j - v[i]]);
        }
        F[v[i]] = i;
    }
    if (ans > n) ans = -1;
    printf("%d\n", ans);
    return 0;
}