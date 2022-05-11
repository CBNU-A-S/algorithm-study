// 걸린시간 : 16분 (+ 버스 안에서 생각함)

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;


	string result;
	cin >> result;

	int hide_idx = 0;
	vector<string> horizontal(n);
	for (int i = 0; i < n; i++) {
		cin >> horizontal[i];

		if (horizontal[i][0] == '?') { // 방금 입력받은 문자열이 감추어진 가로줄이라면
			hide_idx = i; // 감추어진 가로줄의 위치(인덱스) 저장
		}
	}

	string start;
	for (int i = 0; i < k; i++) {
		start += 'A' + i; // k명의 참가자를 등록함 (A ~ 'A' + k 까지)
	}

	// 위부터 아래로 swapping
	for (int y = 0; y < hide_idx; y++) {
		for (int x = 0; x < k - 1; x++) {
			if (horizontal[y][x] == '-') { // 빼기 모양일 경우, 연관된 두 글자가 바뀌어야 함.
				swap(start[x], start[x + 1]); // 따라서 swap 함수 사용
			}
		}
	}

	// 아래부터 위로 swapping
	for (int y = n - 1; y > hide_idx; y--) {
		for (int x = 0; x < k - 1; x++) { 
			if (horizontal[y][x] == '-') { // 빼기 모양일 경우, 연관된 두 글자가 바뀌어야 함.
				swap(result[x], result[x + 1]); // 따라서 swap 함수 사용
			}
		}
	}

	// 감추어진 문자열에 대해 감추어진 문자열을 수행한 후와 수행하기 전으로 나누어 확인을 하고자 함.
	string ans;
	for (int x = 0; x < k - 1; x++) {
 		if (start[x] != result[x]) {  // 감추어진 문자열 이전의 문자열과 이후의 문자열에 대해 x번째의 index가 다르다면, swap 진행
			swap(start[x], start[x + 1]); 
			ans += "-"; // 그리고 이 연산은 뺴기가 나와 수행된 것이므로 ans에 '-'를 추가함.

			x++; // i번째와 i + 1번째가 바뀐 것이며, 빼기는 연속해서 나올 수 없으므로 x를 1 증가시켜줌.
			if (x != k - 1) {
				ans += "*"; // 그리고 빼기 다음엔 또 빼기가 없으므로 '*' 추가 (단, 맨 마지막이 빼기일 경우에는 추가되지 않도록 해야함)
			}
		}
		else {
			ans += "*"; 
		}
	}

	bool is_wrong = false;
	for (int x = 0; x < k - 1; x++) {
		if (start[x] != result[x]) { // 감추어진 문자열을 수행했음에도 start와 result가 다르다면, 이 경우에는 감추어진 가로줄을 어떻게 구성하든 불가능한 case 임
			is_wrong = true;
			break;
		}
	}

	if (is_wrong) {
		// 불가능한 case임을 판별했을 시, '인원 수 - 1' 만큼 x표시를 해줌
		for (int x = 0; x < k - 1; x++) {
			cout << "x";
		}
	}
	else {
		cout << ans;
	}

	return 0;
}
