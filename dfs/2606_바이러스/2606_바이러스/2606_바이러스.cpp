// 2606_바이러스 [소요 시간 : 16분 16초]
// #dfs(재귀) #dfs(스택)

// 결국 연결된 영역을 따지는 것이므로 dfs로 풀면 될 것 같다는 생각을 하였다.

// 변수 분석
// 문제에서 정점(노드)의 역할을 하는 것은 컴퓨터의 수 - computer_amount
// 간선의 역할을 하는 것은 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수 - connect_computer_amount
// 루트 노드의 역할을 하는 것은 1번 컴퓨터가 웜 바이러스에 걸렸다고 가정하고 웜 바이러스를 걸리는 컴퓨터의 개수를 세는 것이므로 1번 컴퓨터가 루트 노드에 해당한다. -dfs(1)

// 답안 출력 시 주의사항 : 단, 1번 컴퓨터에 의해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 것이 목표이므로 1번 컴퓨터는 제외해야한다.
// 컴퓨터의 수는 최악의 경우 100개 이므로 2차원 배열을 써도 메모리 초과가 일어나지 않지만, 2차원 배열보다 vector<> [] 문법을 사용하려고 한다.

// 풀이2 : 스택으로 재귀를 구현한다. - 성능 : 2028KB, 0ms
#include <iostream>
#include <stack>
#include <vector>
#define MAX_COMPUTER 100

using namespace std;

vector<int> Graph[MAX_COMPUTER];
stack<int> dfs_stack; // dfs 연산을 위한 스택
vector<bool> visited(MAX_COMPUTER, false); // 노드들이 이전에 방문했는지 여부를 체크하는 배열
int answer = 0; // 감염된 컴퓨터의 개수

void dfs(int node) {
	dfs_stack.push(node); // 루트 노드를 스택에 삽입한다.

	while (!dfs_stack.empty()) { // 스택이 빌 때까지 무한 반복
		int current_node = dfs_stack.top(); // 현재 노드 저장
		dfs_stack.pop(); // 현재 노드 pop
		
		if (!visited[current_node]) { // 이전에 방문한 적이 없는 노드인지 체크 -> 방문한 적이 없다면 방문처리 + 노드 탐색
			visited[current_node] = true;
			answer++; // 감염된 컴퓨터 수 1 증가
		}

		// dfs에서 다음 노드가 될 조건 : A) 현재 노드와 연결이 되어 있어야 한다. && B) 다음 노드가 될 노드는 이전에 방문한 적이 없어야 된다.
		for (int next_node : Graph[current_node]) { // A) 현재 노드와 연결되어 있는 노드를 next_node 에 하나씩 삽입한다.
			if (!visited[next_node]) { // B) 방문한 적이 없는 노드라면 -> 다음 노드가 될 조건 충족 (dfs_stack에 push)
				dfs_stack.push(next_node);
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int computer_amount, connect_computer_amount;
	// 컴퓨터 대수와 연결되어 있는 컴퓨터 간선의 개수를 입력 받는다.
	cin >> computer_amount;
	cin >> connect_computer_amount;
	// 간선의 정보를 입력 받는다.
	for (int i = 0; i < connect_computer_amount; i++) {
		int start_node, arrive_node;
		cin >> start_node >> arrive_node;
		Graph[start_node].push_back(arrive_node);
		Graph[arrive_node].push_back(start_node);
	}
	// root 노드가 1인 dfs을 실행한다.
	dfs(1);
	
	// 1번 컴퓨터로 인해 바이러스에 감염된 컴퓨터 대수를 출력한다.
	cout << answer - 1;


	return 0;
}



/*
// 풀이1 : dfs 재귀로 구현한다. - 성능 : 2024KB, 0ms

// 성능 : 2024KB, 0ms
#include <iostream>
#include <vector>

using namespace std;
#define MAX_COMPUTER 101

vector<int> Graph[MAX_COMPUTER]; // 간선의 연결 정보(네트워크 상에서 연결되어 있는 컴퓨터의 정보)를 담는 배열
vector<bool> visited(MAX_COMPUTER, false); // 노드가 방문이 되었는지 체크하기 위한 배열
int answer = 0; // 감염된 컴퓨터 수

// 재귀로 dfs 구현
void dfs(int node) {

	if (visited[node] == false) { // 방문하지 않았던 노드면
		visited[node] = true; // 방문 처리
		answer++; // 감염된 컴퓨터 추가
	}
	
	// 다음 노드가 될 조건은 A) 현재 노드와 연결이 되어 있어야 하고, B) 다음 노드가 될 노드는 이전에 방문한 적이 없는 노드여야 한다.
	for (int next_node : Graph[node]) { // A)
		if (visited[next_node] == false) { // B)
			dfs(next_node); // 재귀적 호출을 통해 다음 노드 방문
		}
	}


}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int computer_amount, connect_computer_amount;

	cin >> computer_amount; // 컴퓨터의 수를 입력 받는다. - 정점 수
	cin >> connect_computer_amount; // 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수를 입력 받는다. - 간선 수
	
	// 간선의 연결 정보를 입력 받아 Graph 배열에 넣어준다.
	for (int i = 0; i < connect_computer_amount; i++) {
		int start_computer, arrive_computer; // 연결 정보를 입력 받는다. 1 2 면 1번 컴퓨터와 2번 컴퓨터가 연결됨.
		cin >> start_computer >> arrive_computer;
		
		Graph[start_computer].push_back(arrive_computer);
		Graph[arrive_computer].push_back(start_computer); // 1 2 면 1번 컴퓨터와 2번 컴퓨터가 연결된 것과 2번 컴퓨터와 1번 컴퓨터와 연결된 것은 같은 의미를 지닌다.
	}
	
	dfs(1); // 1번 컴퓨터가 웜 바이러스가 걸렸을 때
	
	cout << answer-1; // 감염된 컴퓨터의 수를 출력 (단, 1번 컴퓨터에 의해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 것이 목표이므로 1번 컴퓨터는 제외해야한다.)
	return 0;
}
*/