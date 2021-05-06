/*
 * @date:2021-04-28 16:14:21
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/I
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1005;

int n, m;
vector<int> v;

struct Stack{
    vector<int> v;
    vector<bitset<MAXM>> val;
    void init(int x) {
        bitset<MAXM> b = 0;
        b[x] = 1;
        val.push_back(b);
    }
    void push(int x, int t) {
        if (t) val.push_back(val.back() | val.back() << x);
        else val.push_back(val.back() | val.back() >> x);
        v.push_back(x);
    }
    int pop() {
        int x = v.back();
        val.pop_back();
        v.pop_back();
        return x;
    }
    bitset<MAXM> top() {
        return val.back();
    }
    bool empty() {
        return v.empty();
    }
} s1, s2;

void remove() {
    if (s1.empty()) {
        while (!s2.empty()) s1.push(s2.pop(), 1);
    }
    s1.pop();
}

int main() {
    scanf("%d%d", &n, &m);
    v.resize(n);
    for (auto &x : v) scanf("%d", &x);
    int l = 0, ans = n + 1;
    s1.init(0);
    s2.init(m);
    for (int r = 0; r < n; ++r) {
        s2.push(v[r], 0);
        while ((s1.top() & s2.top()).any()) {
            remove();
            ans = min(ans, r - l + 1);
            l++;
        }
    }
    if (ans > n) ans = -1;
    printf("%d\n", ans);
    return 0;
}