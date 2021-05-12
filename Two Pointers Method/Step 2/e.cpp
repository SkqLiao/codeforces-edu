/*
 * @date:2021-04-25 22:03:30
 * @source:https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, k;
vector<int> v;
int Tms[MAXN];

int main() {
    scanf("%d%d", &n, &k);
    v.resize(n);
    for (auto &x : v) scanf("%d", &x);
    long long ans = 0;
    int l = 0, num = 0;
    for (int i = 0; i < n; ++i) {
        if (!Tms[v[i]]++) {
            if (++num > k) {
                while (true) if (--Tms[v[l++]] == 0) break;
            }
        }
        ans += i - l + 1;
    }
    printf("%lld\n", ans);
    return 0;
}