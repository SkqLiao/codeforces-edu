/*
 * @date:2021-05-07 00:02:54
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000 + 5;

int A[MAXN << 2];

int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        if (!A[x] && !A[x + n]) {
            printf("%d\n", x);
            A[x] = 1;
            if (A[x - 1]) merge(x, x - 1);
            if (A[x + 1]) merge(x, x + 1);
        }
    }
    return 0;
}