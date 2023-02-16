//20230121 백준 문제풀이
/*
// 4. 1269번 - 대칭 차집합

// 전략2 : set을 이용한다. - 중복 허용 X
// set 하나를 만들고 collection에 원소를 다 넣는다.
// B의 원소 삽입 시에 collection을 확인하여 새로운 원소이면 삽입하고 이미 있는 원소와 같으면 그 원소를 A에서도 지운다.
// set의 크기(collection)가 정답이다.
#include <iostream>
#include <set>

using namespace std;

set<int> collection;

int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	// 1. A 원소 입력 받기
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		collection.insert(x);
	}
	// 2. B 원소 입력 받기 -> A 원소와 중복되면 
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (collection.count(x) == 0) { // A원소와 중복되지 않은 원소 -> set에 삽입
			collection.insert(x);
		}
		else { // A원소와 중복되는 원소 -> 지워버린다.
			collection.erase(x);
		}
	}

	// 3. 결과 출력
	cout << collection.size();
	return 0;
}

*/

/*
// 전략1[시간초과] : 같은지 검사하기 위해 이진 탐색을 사용한다. (시간복잡도 : O(log N))

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> collect_a; // 집합 a
vector<int> collect_b; // 집합 b

int binarysearch(vector<int> b, int left, int right, int input) { // 겹치면 2 리턴, 아니면 0 리턴
	while (left <= right) {
		int mid = (left + right) / 2;
		if (b[mid] == input) return 2;
		else if (b[mid] > input) right = mid - 1;
		else left = mid + 1;
	}
	return 0;
}

int main(void) {
	int a,b; // 집합 a,b
	int answer = 0; 
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	// 1. 입력받기 -> 입력받는대로 일단 대칭 차집합 원소 개수로 카운트 한다.
	for (int i = 0; i < a; i++) {
		int x;
		cin >> x;
		collect_a.push_back(x);
		answer++;
	}
	for (int i = 0; i < b; i++) {
		int x;
		cin >> x;
		collect_b.push_back(x);
		answer++;
	}
	sort(collect_b.begin(), collect_b.end()); // 오름차순 정렬

	// 2. 집합 a와 b가 같은 숫자 나오면 대칭 차집합이 아니므로 각각 -1씩 뺀 -2을 빼준다.
	for (int i = 0; i < a; i++) {
		answer = answer - binarysearch(collect_b, 0, b-1, collect_a[i]);
	}

	cout << answer;
	return 0;
}
*/


/*
// 3. 17219번 - 비밀번호 찾기
// 순서는 상관이 없으므로 unordered_map 을 사용한다.
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, string> info;

int main(void) {
	// 0. 고속입력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;
	// 1. 정보 입력받기
	for (int i = 0; i < n; i++) {
		string site, password;
		cin >> site >> password;
		info.insert(make_pair(site, password));
	}

	// 2. 해당 사이트의 비밀번호 출력
	for (int i = 0; i < m; i++) {
		string find_site;
		cin >> find_site;
		if (info.find(find_site) != info.end()) {
			cout << info.find(find_site)->second << "\n";
		}
		//auto answer = info.find(find_site);
		//cout << answer->second << "\n";
	}

	return 0;
}
*/

/*
// 2. 1620번 - 나는야 포켓몬 마스터 이다솜
// map 사용 -> 순서가 상관 있으므로 map 자료구조 사용
// 이제 문자열 -> 정수 변환 함수로 atoi 함수 대신 stoi 함수를 사용한다. (C++ 11 버전 이상, 더 빠르다.)
// isdigit() 함수 -> 입력된 값이 문자라면 0, 숫자라면 0이 아닌 값이 반환된다.
// auto 자료형 -> 문맥에 맞게 알아서 자료형을 추정하여 정해준다.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
map<string, int> p; // 포켓몬 도감
string pokemon[100001];

int main(void) {
	int n, m; // n : 포켓몬 개수, m : 맞춰야 하는 문제 수
	int quiz_number;
	string quiz_string;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	// 1. 입력받아야 하는 포켓몬 개수만큼 입력받는다.
	for (int i = 0; i < n; i++) {
		cin >> pokemon[i];
		p.insert(make_pair(pokemon[i], i));
	}
	
	// 2. m 만큼 퀴즈를 푼다.
	for (int i = 0; i < m; i++) {
		cin >> quiz_string;
		// 2-1. 입력된 것이 숫자인 경우
		if (isdigit(quiz_string[0]) != 0) {
			quiz_number = stoi(quiz_string) - 1; // 숫자로 바꾼다.
			cout << pokemon[quiz_number] << "\n";
		}
		// 2-2. 입력된 것이 문자인 경우
		else {
			auto index =  p.find(quiz_string);
			cout << index->second + 1 << "\n";
		}

	}
	return 0;
}
*/


/*
// 1. [다시 풀어보기]
// 풀이 전략 : 숫자 카드를 일일이 비교할 경우 최악의 경우 50만회 * 50만회 = 2500만회에 달하는 연산을 해야하므로
// 2초안에 해결하기 위해서 순차 탐색보다 이진 탐색을 쓰는 것이 좋다.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
// 스택이 많으므로 vector는 힙으로 옮겨놓는다.
vector<int> have_card; // 상근이가 가지고 있는 카드
vector<int> compare_card; // 비교해야 할 카드

// 3. 이진 검색 구현
int binarysearch(vector<int> have_card, int start, int end, int input) {
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
*/