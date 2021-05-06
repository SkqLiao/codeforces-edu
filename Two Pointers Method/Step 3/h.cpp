/*
 * @date:2021-04-27 18:09:00
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/H
*/
#include <bits/stdc++.h>

using namespace std;

int n, m, s, a, b;
vector<int> va, vb;

int main() {
    scanf("%d%d%d%d%d", &n, &m, &s, &a, &b);
    va.resize(n);
    vb.resize(m);
    for (auto &x : va) scanf("%d", &x);
    for (auto &x : vb) scanf("%d", &x);
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());
    int r = min(n, s / a) - 1, sum = (r + 1) * a;
    long long ans = 0;
    for (int i = 0; i <= r; ++i) ans += va[i];
    long long cur = ans;
    for (int l = 0; l < min(m, s / b); ++l) {
        cur += vb[l];
        sum += b;
        while (sum > s) {
            sum -= a;
            cur -= va[r--];
        }
        ans = max(ans, cur);
    }
    printf("%lld\n", ans);
    return 0;
}