#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long ll;
#define size_t ll
#define double long double
#define all(obj) (obj).begin(), (obj).end()
const double PI = 3.141592653589793;
const ll INF = 1e18, MOD = 1000000007;
template <class T>
inline bool chmax(T &a, T b);
template <class T>
inline bool chmin(T &a, T b);
ll roundup(ll a, ll b); // 切り上げ
ll comb(ll n, ll r);    // nCr 組み合わせ
template <class T>
ll my_lower_bound(vector<T> &vec, T key);

// ==================================================================== //

int main()
{
    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    vector<vector<ll>> a(M + 2, vector<ll>(N + 2));
    vector<vector<bool>> ff(N + 2, vector<bool>(N + 2));

    for (size_t i = 1; i < M + 1; i++)
    {
        for (size_t j = 1; j < N + 1; j++)
        {
            cin >> a[i][j];
        }
    }

    for (size_t i = 1; i < M + 1; i++)
    {
        for (size_t j = 1; j < N + 1; j++)
        {
            ff[a[i][j]][a[i][j - 1]] = true;
            ff[a[i][j]][a[i][j + 1]] = true;
        }
    }
    for (size_t i = 1; i < N + 1; i++)
    {
        for (size_t j = i + 1; j < N + 1; j++)
        {
            if (!ff[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

// ==================================================================== //

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

ll roundup(ll a, ll b)
{
    return ((a + b - 1) / b);
}

ll comb(ll n, ll r)
{
    if (r < 1 || n < r)
        return 0;
    double ans = 1.0;
    for (size_t i = 1; i <= r; i++)
        ans *= (double)(n - i + 1) / (double)(i);
    return (ll)ans;
}

template <class T>
ll my_lower_bound(vector<T> &vec, T key)
{
    auto it = lower_bound(all(vec), key);
    return (it - vec.begin());
}
