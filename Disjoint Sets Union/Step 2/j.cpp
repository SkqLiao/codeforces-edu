/*
 * @date:2021-05-11 11:22:06
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/J
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fir first
#define sec second
template<class T> bool chkMax(T &x, T &y) {return y > x ? x = y, 1 : 0;}
template<class T> bool chkMin(T &x, T &y) {return y < x ? x = y, 1 : 0;}

int N, M;
vector<int> Anc, Len, Siz;

pii findAnc(int x) {
    if (Anc[x] == x) return {x, 0};
    auto y = findAnc(Anc[x]);
    Anc[x] = y.fir;
    Len[x] = (y.sec + Len[x]) % 2;
    return {Anc[x], Len[x]};
}

bool merge(int x, int y) {
    auto fx = findAnc(x);
    auto fy = findAnc(y);
    if (fx.fir == fy.fir) return fx.sec != fy.sec;
    if (Siz[fx.fir] > Siz[fy.fir]) swap(fx, fy);
    Anc[fx.fir] = fy.fir;
    Len[fx.fir] = (1 + fx.sec + fy.sec) % 2;
    Siz[fy.fir] += Siz[fx.fir];
    return true;
}

int main() {
    scanf("%d%d", &N, &M);
    Anc.resize(N + 1);
    Len.resize(N + 1);
    Siz.resize(N + 1);
    for (auto i = 1; i <= N; ++i) {
        Anc[i] = i;
        Siz[i] = 1;
    }
    for (int i = 1, x, y; i <= M; ++i) {
        scanf("%d%d", &x, &y);
        if (!merge(x, y)) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}