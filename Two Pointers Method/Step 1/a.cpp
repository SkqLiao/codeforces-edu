/*
 * @date:2021-04-25 20:59:36
 * @source:https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v1, v2, v3;

int main() {
    scanf("%d%d", &n, &m);
    v1.resize(n);
    for (auto &x : v1) scanf("%d", &x);
    v2.resize(m);
    for (auto &x : v2) scanf("%d", &x);
    int p1 = 0, p2 = 0;
    while (p1 < n || p2 < m) {
        if (p1 == n) v3.push_back(v2[p2++]);
        else if (p2 == m) v3.push_back(v1[p1++]);
        else if (v1[p1] < v2[p2]) v3.push_back(v1[p1++]);
        else v3.push_back(v2[p2++]);
    }
    for (auto x : v3) printf("%d ", x);
    return 0;
}