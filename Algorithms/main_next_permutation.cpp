#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

////////////////////////// templates

template<class U>
void PRINT(std::vector<U> &x) {
    for (int i=0;i<x.size();++i) {
        cout << x[i];
    }
}

template<class U>
void PRINTLN(std::vector<U> &x) {
    PRINT<U>(x);
    cout << endl;
}

template <typename It>
bool next_permutation(It begin, It end)
{
    if (begin == end)
        return false;

    It i = begin;
    ++i;
    if (i == end)
        return false;

    i = end;
    --i;
    // 最も右の桁にセット

    while (true)
    {
        // 現在の桁位置をjにセット
        It j = i;
        // 左隣に移動
        --i;
        // 右隣の桁より小さければ
        if (*i < *j)
        {
            // 現在の桁より小さくない桁を右端から探す
            // これは*i < *j という条件下なので必ず存在する.
            It k = end;
            while (!(*i < *--k));
            // 見つけた桁と値を交換する
            iter_swap(i, k);
            // jより右の桁の並びを逆にする
            // 意味: この部分列は降順の"最大値"となっているので、"最小値"に対する並び順を得るために逆にする
            reverse(j, end);
            return true;
        }
        // 右の桁全て以上の値　かつ　もっとも左の桁であれば
        if (i == begin)
        {
            reverse(begin, end);
            return false;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    iota(X.begin(), X.end(), 0);
    PRINTLN(X);

    for (int i=0;i<N;++i) cin >> X[i];

    do {
        PRINTLN(X);
    } while (::next_permutation(X.begin(), X.end()));
    PRINTLN(X);

    return 0;
}