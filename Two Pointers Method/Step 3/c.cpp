/*
 * @date:2021-04-27 11:43:49
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C
*/
#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> v;

int main() {
    scanf("%d%d", &n, &s);
    v.resize(n + 1);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    int l = 1;
    long long ans = 1ll * n * (n + 1) / 2;
    for (int r = 1; r <= n; ++r) {
        while (v[r] - v[l] > s) ++l;
        ans -= r - l + 1;
    }
    printf("%lld\n", ans);
    return 0;
}