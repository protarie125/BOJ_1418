#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

auto primes = vi{};
auto isPrime = vb{};

void listPrimes(int n) {
	for (auto i = 2; i <= n; ++i) {
		if (isPrime[i]) {
			primes.push_back(i);

			auto j = i + i;
			while (j <= n) {
				isPrime[j] = false;
				j += i;
			}
		}
	}
}

int getMaxFactor(int n, int k) {
	if (1 == n) {
		return 1;
	}

	auto ans = int{ -1 };
	for (const auto& p : primes) {
		if (0 == n % p) {
			ans = p;

			if (k < ans) {
				return ans;
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto n = int{};
	cin >> n;

	isPrime = vb(n + 1, true);
	if (0 <= n) {
		isPrime[0] = false;
	}
	if (1 <= n) {
		isPrime[1] = false;
	}

	listPrimes(n);

	auto k = int{};
	cin >> k;

	auto ans = int{ 0 };
	for (auto i = 1; i <= n; ++i) {
		auto mxP = getMaxFactor(i, k);
		if (mxP <= k) {
			++ans;
		}
	}

	cout << ans;

	return 0;
}