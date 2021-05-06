/*
 * @date:2021-04-27 17:59:00
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/G
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int n;
long long c;
char s[MAXN];

int main() {
    scanf("%d%lld%s", &n, &c, s);
    int l = 0, ans = 0, numa = 0, numb = 0;
    long long sum = 0;
    for (int r = 0; r < n; ++r) {
        if (s[r] == 'a') ++numa;
        else if (s[r] == 'b') {
            ++numb;
            sum += numa;
        }
        while (sum > c) {
            if (s[l] == 'a') {
                sum -= numb;
                --numa;
            } else if (s[l] == 'b') --numb;
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}