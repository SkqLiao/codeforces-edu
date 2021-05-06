/*
 * @date:2021-04-25 21:02:15
 * @source:https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v1, v2;

int main() {
    scanf("%d%d", &n, &m);
    v1.resize(n);
    for (auto &x : v1) scanf("%d", &x);
    v2.resize(m);
    for (auto &x : v2) scanf("%d", &x);
    int p1 = 0;
    for (auto x : v2) {
        if (x <= v1[0]) {
            printf("0 ");
            continue;
        }
        while (p1 < n && v1[p1] < x) ++p1;
        printf("%d ", p1);
    }
    return 0;
}