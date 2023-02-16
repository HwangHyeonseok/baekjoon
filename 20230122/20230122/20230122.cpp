//20230122 백준 문제풀이
// 1920번 - 수 찾기 (S4) [전략1 | 소요 시간 : 5분 44초] || [전략2 |소요 시간 : 9분 48초]
// 풀이 전략1 - set 함수를 통해 2번째 줄에 먼저 입력된 정보를 기준으로 4번째 줄에 들어오는 정보를 set 함수의 find 메서드를 이용해 비교한다.
// 성능 : 6776KB, 92ms

// 풀이 전략2 - vector로 정보를 담고 그 정보를 binary_search을 통해 비교한다. 
// 실수주의 : 이진 탐색 전에 반드시 sort을 해주어야 한다.
// 성능 : 2916KB, 48ms
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> input_data;

int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 정보 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input_data.push_back(x);
	}
	// 2. 이분 탐색을 통해 정보 비교
	sort(input_data.begin(), input_data.end()); //오름차순 정렬
	cin >> m;
	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;
		if (binary_search(input_data.begin(), input_data.end(), y)) {  // y값이 이미 존재한다면
			cout << "1\n";
		}
		else cout << "0\n";
	}

	return 0;
}

/*
// [풀이 전략1]
#include <iostream>
#include <set>
using namespace std;

set<int> input_data;

int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 정보 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input_data.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;
		if (input_data.find(y) != input_data.end()) { // 이미 들어가있는 데이터가 아닌 경우
			cout << "1\n";
		}
		else { cout << "0\n"; }
	}
	return 0;
}
*/
//================================================================================================================
/*
// 8. 4153번 - 직각삼각형(B3) 
// 풀이 전략 : 피타고라스의 정리 공식을 사용한다. [소요 시간 : 8분 31초]
// 오답노트 : 6 8 10(x^2+y^2 = z^2은 고려했으나) 10 6 8 , 6 10 8 의 경우는 고려하지 못했었다.
// 성능 : 2020KB, 0ms

#include <iostream>
#include <math.h>
using namespace std;
int main(void) {
	int x, y, z;
	while (1) {
		cin >> x >> y >> z;
		if ((x == 0) && (y == 0) && (z == 0)) break;
		
		if ((pow(x, 2) + pow(y, 2) == pow(z, 2)) || pow(x,2) == pow(y,2) + pow(z,2) || pow(x,2)+pow(z,2) == pow(y,2)) cout << "right" << "\n";
		else cout << "wrong" << "\n";
	}
	return 0;
}
*/
//================================================================================================================
/*
// 7. 10250번 - ACM 호텔(B3) [소요 시간 : 12분 46초]
// 해결 아이디어 : 호수를 우선적으로 구하고 층수를 구한다.
// 성능 : 2020KB, 0ms
#include <iostream>

using namespace std;
int main(void) {
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int testcase;
	int h, w, n;

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int height = 1;
		int width = 1;
		cin >> h >> w >> n;
		while (n > h) { // 호수 먼저 구하기
			n = n - h;
			width++;
		}
		height = n; // 남은 n은 층수
		cout << height * 100 + width << "\n";
	}
	return 0;
}
*/
//================================================================================================================
/*
// 6. 1085번 - 직사각형에서 탈출 (B3) [소요 시간 : 14분 20초]
// 해결 아이디어 : 1) w와 h의 차이 2) x와 y의 차이 3) x와의 차이 4) y와의 차이 네 사분면에 닿는 경우를 계산해 최솟값을 출력하면 된다. 
// 성능 : 2020KB, 0ms
#include <iostream>
#include <math.h>
using namespace std;
int main(void) {
	int w, x, h, y;
	int answer = 99999999;
	cin >> x >> y >> w >> h;
	//answer = min((w - x), (h - y));
	//answer = min(answer, x);
	//answer = min(answer, y);
	
	answer = min(min(min((w - x), (h - y)), x), y);
	cout << answer;
	return 0;
}
*/
//================================================================================================================
/*
// 5. 1037번 - 약수 (B1) [소요 시간 : 23분 3초]
// 풀이 전략 : 입력한 약수 개수가 1개, 짝수개, 홀수개인 경우를 분류하고, 
// 약수를 오름차순하면 서로 대칭 구조임을 이용하여 인덱스에 접근한다. (ex. 24의 약수는 1 2 4 8 12 24 , 1*24, 2*12, 4*8, 8*4, 12*2, 24*1)
// 성능 : 2024KB, 0ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	vector<int> numbers;

	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		numbers.push_back(x);
	}

	sort(numbers.begin(), numbers.end()); // 오름차순 정렬
	if ((numbers.size()) % 2 == 0) { // 약수 개수가 짝수인 경우
		cout << numbers[(numbers.size()) / 2] * numbers[(numbers.size()) / 2 - 1];
	}
	else { // 약수 개수가 홀수인 경우
		if (numbers.size() == 1) { // 입력한 약수 개수가 1개인 경우
			cout << numbers[0] * numbers[0];
		}
		else {
			cout << numbers[numbers.size() / 2 - 1] * numbers[numbers.size() / 2 + 1];
		}
	}
	return 0;
}
*/
//================================================================================================================
/*
// 4. 9020번 - 골드바흐의 추측(S2) [소요 시간 : 48분 54초]
// 풀이 아이디어 : 입력받은 수를 나눴을 때 그 값이 소수이면 그 소수인 값 2개를 출력하면 된다.
// 그 값이 소수가 아니라면 그 입력받은 수를 기준으로 -n, +n을 하면서 둘 다 소수에 해당하는 값을 찾으면 된다.
// 성능 : 2100KB, 288ms

#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int sosu[20001] = { 0 }; // 0~5000까지 소수인지 아닌지 판별 0 : 소수 1 : 소수X
int main()
{
	int n;
	int input;


	// 1. 에라토스테네스의 체를 통해 sosu 배열 0~5001이 소수에 해당하는지 체크
	for (int i = 2; i <= sqrt(20001); i++) {
		if (sosu[i] == 0) {
			int j = 2;
			while (i * j <= 20001) {
				sosu[i * j] = 1;
				j++;
			}
		}
	}
	// 2. 입력 받고 조건 검사
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (sosu[input / 2] == 0) { // case 1: 나눴을 때 바로 소수인 경우
			cout << input / 2 << " " << input / 2 << "\n";
		}
		else {
			int k = 0;
			while (sosu[input / 2 - k] != 0 || sosu[input / 2 + k] != 0) { // case 2 : 나눴을 때 바로 소수가 나오지 않아 양쪽으로 탐색해야 하는 경우 (30 입력시 13+17)
				k++;
			}
			cout << input / 2 - k << " " << input / 2 + k << "\n";
		}
	}
	return 0;
}
*/
//================================================================================================================
/*
// 3. 4948번 - 베르트랑 공준 (S2) [ 해결 시간 : 29분 24초 ]
// 문제 해석 : n~2n 까지의 소수 개수를 구하시오.
// 문제 전략 : 범위 기반(n~2n)의 소수의 개수를 구해야 하므로 에라토스테네스의 체 알고리즘(2~sqrt(n))을 사용한다.
// 주의사항 - 0~n까지가 아니고, n~2n까지 범위이므로 이에 맞게 에라토스테네스의 체 알고리즘을 수정해야 한다.
// 퍼포먼스 - 3000KB / 40ms

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> check(246913, 1); // 크기가 246913인 배열을 모두 1로 초기화 -> 일단 모두 소수라고 가정

int main(void) {
	int n; 
	int answer = 0;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (1)
	{
		// 1. 입력 받기
		cin >> n;
		if (n == 0) break;
		// 2. 에라토스테네스의 체 알고리즘 -> 소수 구하기
		for (int i = 2; i <= sqrt(2 * n); i++) { // 일단 2~sqrt(2n)까지의 모든 소수를 구한다.
			if (check[i] == 1) { // 아직 걸러지지 않은 수 인 경우
				int j = 2;
				while (i * j <= 2*n) {
					check[i * j] = 0;
					j++;
				}
			}
		}

		// 3. 소수 개수 출력 -> 1보다는 값이 커야한다. (예외 처리)
		for (int i = n+1; i <= 2 * n; i++) {
			if (check[i] == 1 && i > 1) answer++;
		}
		cout << answer << "\n";
		answer = 0;
	}
	return 0;
}
*/
//================================================================================================================
/*
// 2. 10815번 - 숫자 카드 (S5) [ 해결 시간 : 9분 29초 ]
// 문제 해석 : 상근이가 가지고 있는 카드를 테스트 케이스가 가지고 있는 카드가 가지고 있는지 체크하는 문제
// 문제 전략1 : set 자료구조를 통해 있는지 없는지 확인하고 출력한다.
// 퍼포먼스 : 메모리 25256KB, 시간 460ms

// 문제 전략2 : 이진 탐색(binary search)을 통해 일일이 확인하고 출력한다. (vector 사용)
// 퍼포먼스 : 메모리 5220KB, 시간 212ms

// 의문 문제 전략3 : 만약 set 자료구조 + 이진 탐색 이라면 퍼포먼스가 어떻게 될까?
// 퍼포먼스 : 시간 초과

// 의문 문제 전략4 : 이진 탐색을 직접 구현한다.
// 퍼포먼스 : 메모리 8296KB, 시간 220ms
// 의문점 : 문제전략 4의 3. 이진 검색 구현에서 have_card로 받으면 시간초과인데, &have_card(참조자)로 받으면 정답이다. 왜지?

// [테스트 문제 전략4 풀이] - 이진 탐색 직접 구현
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
// 스택이 많으므로 vector는 힙으로 옮겨놓는다.
vector<int> have_card; // 상근이가 가지고 있는 카드
vector<int> compare_card; // 비교해야 할 카드

// 3. 이진 검색 구현
int binarysearch(vector<int> &have_card, int start, int end, int input) { // have_card로 받으면 시간초과인데, &have_card(참조자)로 받으면 정답이다. 왜지?
	while (start <= end) {
		int mid = (start + end) / 2;
		if (have_card[mid] == input) return 1;
		else if (have_card[mid] > input) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 가지고 있는 카드를 입력받는다.
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		have_card.push_back(x);
	}
	// 2. 상근이가 가지고 있는 카드일지 아닐지를 검사해야되는 테스트케이스를 입력받는다.
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		compare_card.push_back(x);
	}
	sort(have_card.begin(), have_card.end()); // 오름차순 정렬

	for (int i = 0; i < m; i++) {
		cout << binarysearch(have_card, 0, n - 1, compare_card[i]) << " ";
	}

	return 0;
}


// [테스트 문제 전략3 풀이] - set + 이진 탐색 => 시간 초과
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> sanggeun_card;

int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	// 1. 입력 받기
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sanggeun_card.insert(x);
	}

	// 2. 이진 탐색 이용
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (binary_search(sanggeun_card.begin(), sanggeun_card.end(), x) == true) { // 상근이가 가지고 있는 카드와 일치할 경우
			cout << "1 ";
		}
		else { // 일치하지 않은 경우
			cout << "0 ";
		}
	}
	return 0;
}


//[문제 전략2 풀이]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sanggeun_card;

int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	// 1. 입력 받기
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sanggeun_card.push_back(x);
	}

	// 2. 이진 탐색 이용
	sort(sanggeun_card.begin(), sanggeun_card.end()); // 오름차순 정렬
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (binary_search(sanggeun_card.begin(), sanggeun_card.end(), x) == true) { // 상근이가 가지고 있는 카드와 일치할 경우
			cout << "1 ";
		}
		else { // 일치하지 않은 경우
			cout << "0 ";
		}
	}
	return 0;
}

// [문제 전략1 풀이]
#include <iostream>
#include <set>

using namespace std;

set<int> sanggeun_card;

int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	// 1. 입력 받기
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sanggeun_card.insert(x);
	}
	
	// 2. 상근이가 가진 카드와 비교하기
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (sanggeun_card.find(x) != sanggeun_card.end()) { // 같은 것을 찾은 경우
			cout << "1 ";
		}
		else { // 같은 것이 없을 경우
			cout << "0 ";
		}
	}


	return 0;
}
*/
//================================================================================================================
/*
// 1. 1764번 - 듣보잡 (S4) - 해결시간 : 19분 7초
// 문제 해석 : 듣도 못한 사람 명단과 보도 못한 사람 명단이 주어지고 두 명단에 모두 포함되는 사람이면 출력을 해야 한다. (듣도 못한 사람 명단 자체와 보도 못한 사람 명단 자체에서 중복은 없다했으므로 이는 고려하지 않는다.)
// 문제 전략1 : set 자료구조를 통해 듣도 못한 사람과 보도 못한 사람의 중복을 검사하고(2번 코드) 중복이면 정답 벡터에 넣어 출력한다.
// 새롭게 알게 된 점 : 고속 입출력에서 cout.tie(nullptr); 을 추가하는 것이 코드 시간 절약에 좋다. (52ms->44ms)
// 퍼포먼스 : 메모리 7580KB, 시간 44ms

// 문제 전략2 : 이진 탐색을 통해 하나씩 검사를 진행한다.
// 새롭게 알게 된 점 : [주의사항] 이진 탐색 하기 전에는 반드시 그 배열을 정렬을 해야 한다.
// 퍼포먼스 : 시간초과

// [문제 전략2 풀이] 
#include <iostream>
#include <set>
#include <algorithm> // binary_search 함수를 사용하기 위해 필요한 헤더파일

using namespace std;
set<string> dedo; // set은 자동정렬 된다.
set<string> answer;

int main(void) {

	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	// 1. 입력받기
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		dedo.insert(name);
	}
	// 2. 이진 탐색을 통해 듣도, 보도 입력 받은 문자열이 같은지 체크 -> 같으면 answer 벡터(배열)에 삽입
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		if (binary_search(dedo.begin(), dedo.end(), name) == true) {  // 이진 탐색 전에는 반드시 정렬 필요
			answer.insert(name);
		}
	}
	// 3. 결과값 출력
	cout << answer.size() << "\n";
	set<string>::iterator iter;
	for (iter = answer.begin(); iter != answer.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}


// [문제 전략1 풀이]
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string> lists;
vector<string> answer;

int main(void) {
	int n, m;
	int answer_count = 0;
	
	// 0.고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 

	cin >> n >> m;
	// 1. 입력 받기
	for (int i = 0; i < n; i++) { 
		string name;
		cin >> name;
		lists.insert(name);
	}

	// 2. 중복되는 명단인지 검사하고 중복되는 명단이면 answer 벡터(배열)에 넣어준다.
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		if (lists.find(name) != lists.end()) { // 이미 있는 경우
			answer_count++;
			answer.push_back(name);
		}
	}

	// 3. 정답을 출력한다. (정답은 사전순, 오름차순으로 출력)
	sort(answer.begin(), answer.end());
	cout << answer_count << "\n";
	for (int i = 0; i < answer_count; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}
*/