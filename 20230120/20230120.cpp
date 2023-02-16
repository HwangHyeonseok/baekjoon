
// 2023/01/20 백준 문제풀이

// 4. 5086번 : 배수와 약수
// 풀이 전략 : x < y 이고 x와 y를 나눴을 때 나누어 떨어지면 factor
// x > y 이고 x와 y를 나눴을 때 나누어 떨어지면 multiple
// 둘 다 아니라면 neither
#include <iostream>

using namespace std;
int main(void) {
	int x, y;

	while (1)
	{
		cin >> x >> y;
		if (x == 0 && y == 0) // 0 0 입력시 프로그램 종료
			break;

		else {
			if (x < y && y % x == 0) cout << "factor" << "\n";
			else if (x > y && x % y == 0) cout << "multiple" << "\n";
			else cout << "neither" << "\n";
		}
	}
	return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------
/*
// 3. 1436번 : 영화감독 숌 (오답노트)
// 오답노트 : 핵심 아이디어 -> 숫자에서 생각하지말고 문자열에서 생각했으면 더 쉬웠을 것이다.

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int check = 666; // 666 부터 증가하면서 검사한다.
	string check_target; // 체크할 숫자를 문자열로 바꿔준다.
	int n; // 666이 나와야 하는 횟수
	int count = 0; // 666이 나온 횟수

	// 0. 고속 입출력을 위한 작업
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	while (n != count) {
		check_target = to_string(check); // 체크할 숫자를 문자열로 바꿔준다. ex. 667 -> "667"

		for (int j = 0; j < check_target.length() - 2; j++) {
			if (check_target[j] == '6' && check_target[j + 1] == '6' && check_target[j + 2] == '6') { // 연속 3개 6이라면
				count++;
				break;
			}
		}

		check++;
	}
	cout << check - 1;

	return 0;
	
}
*/
//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------
// 2. 10814번 : 나이순 정렬
// 풀이 전략1(구조체,클래스 + vector) : 정렬을 따질 조건이 단순히 일차원적인(1개에 대한) 오름차순/내림차순 정렬이 아닌 3차원적인(나이, 이름, 가입 순서)에 따른 오름차순/내림차순 정렬이므로 
// sort 메서드에 3번째 인자로 compare 함수를 넣어 정렬 커스텀마이징을 한다.
// 이때 클래스나 구조체를 만들어 이 클래스나 구조체를 vector(가변 배열)로 만들어 입력한 데이터를 관리한다.

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class member {
public:
	static int idCounter;
	member() : old(0), name(), id(0) { };
	member(int old, string name) : old(old), name(name), id(idCounter++) { };
	const int Getold() const { return old; }
	const string Getname() const { return name; }
	const int Getid() const { return id; }

private:
	int old;
	string name;
	int id; // 가입 번호
};
int member::idCounter = 1;
// 2. 조건에 맞게 정렬할 compare 함수를 선언 및 정의한다.
	//[우선순위1] - 나이 : 회원들의 나이를 오름차순으로 정렬
	//[우선순위2] - 가입한 순서 : 먼저 가입한 순서로 오름차순 정렬
bool compare(member a, member b) {
	if (a.Getold() == b.Getold()) { // 나이가 같은 경우
		return a.Getid() < b.Getid(); // id 순(먼저 가입 한 순으로)으로 오름차순 정렬
	}
	else { // 나이가 다른 경우
		return a.Getold() < b.Getold(); // 나이 순으로 오름차순 정렬
	}
}

int main(void) {
	int n; 
	vector<member> members;
	// 0. 고속 입출력을 위한 코드 작성 (시간 단축)
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	// 1. 입력받은 member 정보를 클래스 배열인 members에 넣는다.
	for (int i = 0; i < n; i++) {
		int input_old;
		string input_name;
		cin >> input_old >> input_name;
		members.push_back(member(input_old, input_name));
	}

	// 2. 조건에 맞게 정렬한다. (조건 : compare 함수에 정의한다.)
	sort(members.begin(), members.end(), compare);
	
	// 3. 출력한다.
	for (int i = 0; i < n; i++) {
		cout << members[i].Getold() << " " << members[i].Getname() << "\n";
	}
	return 0;
}
*/
//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------
/*
// 1. 1929번 : 소수 구하기
// 풀이 전략 : M~N까지의 소수를 출력하므로 에라토스테네스의 체 알고리즘을 이용한다.
// 제한 시간이 2초(200만회 연산) 이고 1~100만개를 입력받으므로 시간 복잡도가 O(N loglog N)인 에라토스테네스의 체 알고리즘을 사용한다.

#include <iostream>
#include <math.h> // sqrt 함수를 사용하기 위해 필요한 라이브러리
#include <vector>

using namespace std;

int main(void) {
	// 0. 시간 복잡도를 따져야 하는 시간 제한이 있는 문제이므로 고속 입출력을 받는다.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// 1. 두 수를 입력받는다. m~n까지 소수를 구한다.
	int m, n;

	cin >> m >> n;
	
	vector<int> numbers(n + 1, true); // 크기가 n+1인 배열을 일단 모두 소수라고 가정한다. true : 소수, false : 소수가 아님 (나누어 떨어지는 수)

	// 2. 에라토스테네스의 체 알고리즘 - 2~sqrt(n) 까지 돌면서 소수인지 검사
	for (int i = 2; i <= sqrt(n); i++) { // 2~sqrt(n) 까지 소수인지 검사 | i는 n의 배수
		int j = 2; // j는 iterator
		while (i * j <= n) { 
			numbers[i * j] = false; 
			j++;
		}
	}
	// 3. 모든 소수를 출력한다. (m~n까지의 범위 안에서이며, 0과 1은 소수가 아니기 때문에 i가 2보다 큰 경우를 따져야 한다.)
	for (int i = m; i <= n; i++) {
		if (numbers[i] == true && i >= 2) {
			cout << i << "\n";
		}
	}
	return 0;
}
*/