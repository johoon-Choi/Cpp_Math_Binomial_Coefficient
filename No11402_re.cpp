#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

vector<ull> N_p_jinsu;
vector<ull> K_p_jinsu;
vector<vector<ull>> C;
ull N, K;
ull P;

void calCombination(vector<vector<ull>>& vec, ull p) {
	vec.assign(2001, vector<ull>(2001, 1));

	for (ull i = 2; i <= 2000; i++) {
		for (ull j = 1; j < i; j++) {
			vec[i][j] = (vec[i - 1][j - 1] % p + vec[i - 1][j] % p) % p;
		}
	}
}

ull power(ull num, ull jisu) {
	if (!jisu) return 1; // num^0 = 1 이므로
	if (jisu % 2)
		return (power(num, jisu - 1) * num);

	ull half = power(num, jisu / 2);
	return (half * half);
}

void makePjinsu(vector<ull>& vec, ull num, ull p) {
	ull start_jisu = 0;
	//vector<ull> jisu;

	start_jisu = (log(num) / log(p));

	vec.assign(start_jisu + 1, 0);

	while (num && (start_jisu >= 0)) {
		ull power_temp = power(p, start_jisu);
		ull gyesu = num / power_temp;

		vec[start_jisu] += gyesu;

		num -= gyesu * power_temp;
		start_jisu--;
	}
}

int main() {
	cin >> N >> K >> P;
	calCombination(::C, P); // dynamic programming

	ull ans = 1;

	makePjinsu(::N_p_jinsu, N, P);
	makePjinsu(::K_p_jinsu, K, P);

	ull cur_jisu = min(N_p_jinsu.size(), K_p_jinsu.size());
	// K_p_jinsu에 

	while (cur_jisu--) {
		ull curN = N_p_jinsu[cur_jisu];
		ull curK = K_p_jinsu[cur_jisu];
		// curN, curK 's max value = 1,999 (P진법 이므로)

		if (curN == curK) continue; // nCn = 1 이므로
		else if (curN < curK) {
			ans = 0;
			break;
		}

		ans *= C[curN][curK] % P;
	}

	cout << ans % P;

	//ull ans = (A * (power(B, P - 2))) % P;

	//cout << ans;
}