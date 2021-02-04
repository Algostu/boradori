#include <functional>
#include <iostream>
#include <string_view>
#include <vector>
using namespace std;
using ll = long long;

#if defined(_WIN32)
int getChar() { return _getchar_nolock(); }
#elif defined(__linux__)
#include <sys/mman.h>
#include <sys/stat.h>
static struct fast_io_t {
    int idx = 0;
    uint8_t* buf;
    fast_io_t() {
        struct stat rstat;
        fstat(0, &rstat);
        size_t size = rstat.st_size;
        buf = (uint8_t*)mmap(0, size, PROT_READ, MAP_FILE | MAP_PRIVATE, 0, 0);

        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
    }
} fast_io;
int getChar() { return fast_io.buf[fast_io.idx++]; }
#else
int getChar() { return getchar(); }
#endif

bool isBlank(char c) {
    constexpr string_view blank_char = "\n\t\r\f\v";
    return find(begin(blank_char), end(blank_char), c) != end(blank_char);
}
int readInt() {
    int number = 0, c = getChar();
    while (isBlank(c)) c = getChar();
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getChar();
    }
    for (; ('0' <= c && c <= '9'); c = getChar())
        number = number * 10 + c - '0';
    return neg ? -number : number;
}
template <size_t... Idx>
constexpr auto readInt_impl(index_sequence<Idx...>) {
    return tuple{[](auto i) { return readInt(); }(Idx)...};
}
template <size_t N>
auto readInt() {
    return readInt_impl(make_index_sequence<N>{});
}

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int left, right, mid, l_num, r_num;
    ll res{1};

    auto [n, x, p] = readInt<3>();
    left = 0;
    right = n;
    r_num = n - x;
    l_num = x - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (p > mid) {
            res = res * l_num % MOD;
            left = mid + 1;
            l_num--;
        } else if (p < mid) {
            res = res * r_num % MOD;
            right = mid;
            r_num--;
        } else {
            left = mid + 1;
        }
    }

    for (int i = 1; i < r_num + l_num + 1; i++) {
        res = res * i % MOD;
    }

    cout << res;

    return 0;
}