#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

extern vector<long long> build_teams(vector<int> A1, vector<int> B1, vector<int> A2, vector<int> B2, vector<int> L1, vector<int> R1, vector<int> L2, vector<int> R2);

void input_assert(bool x) {
	if (!x) {
		puts("Invalid input");
		exit(0);
	}
}

void output_assert(bool x) {
	if (!x) {
		puts("Invalid output");
		exit(0);
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int N, M, Q;
	input_assert(scanf("%d %d", &N, &M) == 2);

	vector<int> A1(N), B1(N), A2(M), B2(M);
	for (int i = 0; i < N; i++) {
		input_assert(scanf("%d %d", &A1[i], &B1[i]) == 2);
	}
	for (int i = 0; i < M; i++) {
		input_assert(scanf("%d %d", &A2[i], &B2[i]) == 2);
	}

	input_assert(scanf("%d", &Q) == 1);
	vector<int> L1(Q), R1(Q), L2(Q), R2(Q);
	for (int i = 0; i < Q; i++) {
		input_assert(scanf("%d %d %d %d", &L1[i], &R1[i], &L2[i], &R2[i]) == 4);
	}

	vector<long long> D = build_teams(A1, B1, A2, B2, L1, R1, L2, R2);

	output_assert(int(D.size()) == Q);
	for (int i = 0; i < Q; i++) {
		printf("%lld\n", D[i]);
	}

	return 0;
}