/*
 * @date:2021-05-11 10:55:55
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/I
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define fir first
#define sec second

int N, M;
vector<int> Anc, Len, Siz;

pii findAnc(int x) {
    if (Anc[x] == x) return {x, 0};
    auto y = findAnc(Anc[x]);
    Anc[x] = y.fir;
    Len[x] = (y.sec + Len[x]) % 2;
    return {Anc[x], Len[x]};
}

void merge(int x, int y) {
    auto fx = findAnc(x);
    auto fy = findAnc(y);
    if (Siz[fx.fir] > Siz[fy.fir]) swap(fx, fy);
    Anc[fx.fir] = fy.fir;
    Len[fx.fir] = (1 + fx.sec + fy.sec) % 2;
    Siz[fy.fir] += Siz[fx.fir];
}

int main() {
    scanf("%d%d", &N, &M);
    Anc.resize(N);
    Len.resize(N);
    Siz.resize(N);
    for (int i = 0; i < N; ++i) {
        Anc[i] = i;
        Siz[i] = 1;
    }
    int num = 0;
    for (int i = 1, opt, x, y; i <= M; ++i) {
        scanf("%d%d%d", &opt, &x, &y);
        x = (x + num) % N;
        y = (y + num) % N;
        if (!opt) {
            merge(x, y);
        } else {
            if (findAnc(x) == findAnc(y)) {
                ++num;
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}