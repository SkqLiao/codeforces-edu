/*
 * @date:2021-04-27 12:48:36
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/E
*/
#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> w, c;

int main() {
    scanf("%d%d", &n, &s);
    w.resize(n);
    c.resize(n);
    for (auto &x : w) scanf("%d", &x);
    for (auto &x : c) scanf("%d", &x);
    int l = 0, sumw = 0;
    long long sumc = 0, ans = 0;
    for (int r = 0; r < n; ++r) {
        sumw += w[r];
        sumc += c[r];
        while (sumw > s) {
            sumw -= w[l];
            sumc -= c[l++];
        }
        ans = max(ans, sumc);
    }
    printf("%lld\n", ans);
    return 0;
}