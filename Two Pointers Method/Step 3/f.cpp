/*
 * @date:2021-04-27 17:46:46
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
char s[MAXN], t[MAXN];
int Num[200], a[200];

int main() {
    scanf("%d%d%s%s", &n, &m, s, t);
    for (int i = 0; i < m; ++i) ++Num[t[i]];
    int l = 0;
    long long ans = 0;
    for (int r = 0; r < n; ++r) {
        if (++a[s[r]] > Num[s[r]]) {
            while (s[l] != s[r]) {
                --a[s[l++]];
            }
            --a[s[l++]];
        }
        ans += r - l + 1;
    }
    printf("%lld\n", ans);
    return 0;
}