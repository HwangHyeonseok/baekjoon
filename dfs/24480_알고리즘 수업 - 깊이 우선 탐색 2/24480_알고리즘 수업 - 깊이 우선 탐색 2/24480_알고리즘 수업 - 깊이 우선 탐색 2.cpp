// 24480_알고리즘 수업 - 깊이 우선 탐색 2 [소요 시간 : 20분 43초]
// #dfs + 정렬

// 새로 알게 된 점 : 그래프에 자료를 넣을 때 2차원 배열이 아니라 vector<int> Graph[] 형태로 넣어 관리 해야 한다는 점이 신선했다.
// Graph[1] - 2,4...  -> 1번 노드와 연결된 노드는 2번,4번 노드
// Graph[2] - 1,4,3 .... -> 2번 노드와 연결된 노드는 1,4,3번 노드


// 스택+구조체(클래스) 풀이 - 11332KB, 96ms
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define VERTAX_MAX 100001 // 정점의 최댓값
#define EDGE_MAX 200001 // 간선의 최댓값
using namespace std;

stack<int> dfs_stack; // dfs 연산을 위한 스택
vector<int> Graph[EDGE_MAX]; // 노드들의 연결 정보를 담는 그래프
vector<int> visited(VERTAX_MAX, 0); // 노드들의 방문 여부를 체크하는 배열
int counts = 1; // 방문 순서를 나타내기 위한 변수

// dfs 스택으로 구현

void dfs(int node) {
	dfs_stack.push(node); // 처음 루트 노드를 스택에 담는다.

	while (!dfs_stack.empty()) {
		int current_Node = dfs_stack.top(); // 현재 노드는 dfs_stack의 최상위 노드
		dfs_stack.pop();

		if (visited[current_Node]) // 해당 이미 방문한 적이 있는 노드라면 패스
			continue;
		// 해당 노드를 방문한 적이 없는 노드라면 - 방문 처리, 노드 탐색
		visited[current_Node] = counts; // 방문 처리, 해당 노드의 방문 순위 기록
		counts++;
		
		// 다음 노드 탐색 - A) 현재 노드와 연결이 되어 있고, B) 다음 노드가 될 노드는 과거에 방문하지 않았어야 한다.
		for (int next_node : Graph[current_Node]) { // A)
			if (visited[next_node] == 0) // 다음 노드가 될 후보가 과거에 방문된 적이 없는 노드라면 dfs_stack에 push(next_node을 방문)
				dfs_stack.push(next_node);

			// 다음 노드가 될 후보가 이미 방문된 노드라면 패스

		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int vertax, edge, root; // vertax : 정점의 수, edge : 간선의 수, root : 시작 정점
	
	cin >> vertax >> edge >> root;
	// 1. 입력받은 노드 연결 정보들을 Graph 배열에 넣는다.
	for (int i = 0; i < edge; i++) {
		int start_node, arrive_node;
		cin >> start_node >> arrive_node;
		Graph[start_node].push_back(arrive_node);
		Graph[arrive_node].push_back(start_node); // 1 4 가 연결된 것은 1 4 나 4 1 이나 같은 의미이다.
	}
	
	// 2. 내림차순으로 그래프를 탐색해야 하므로 Graph[i] 안에 있는 원소들(i와 연결된 노드들 순서)를 내림차순으로 정렬한다.
	for (int i = 1; i <= edge; i++) {
		sort(Graph[i].begin(), Graph[i].end());
	}
	
	// 3. dfs 방식으로 그래프를 탐색한다. (루트 노드는 root 변수에 담겨있다.)
	dfs(root);

	// 4. 각 노드의 방문 순서를 노드 번호 순서대로 출력한다.
	for (int i = 1; i <= vertax; i++) {
		cout << visited[i] << "\n";
	}
	return 0;
}


/*
// 재귀적 풀이 - 성능 : 10932KB, 84ms
#include <iostream>
#include <vector>
#include <algorithm>

#define VERTAX_MAX 100001
#define EDGE_MAX 200001
using namespace std;

vector<int> Graph[VERTAX_MAX]; // 그래프 연결 상태를 나타내는 Graph 배열
vector<int> visited(VERTAX_MAX, 0); // 각 노드의 방문 여부를 체크하는 배열
int counts = 1; // 몇 번째로 방문했는지 체크하기 위한 변수

// 재귀적 dfs 구현
// 1. 현재 노드를 방문처리한다.
// 2. 다음 노드를 찾는다. 
// 다음 노드가 될 조건 : A) 현재 노드와 연결된 노드 중에서 B) 이전에 방문하지 않았던 노드가 다음 노드가 될 수 있는 조건이다.
void dfs(int node) {
	visited[node] = counts; // 방문 처리 + 몇 번째로 방문했는지 표현
	counts++;

	for (int next_node : Graph[node]) { // A) 현재 노드와 연결된 노드 중에서
		if (visited[next_node]) // 이미 방문한 노드라면 패스 | B) 이전에 방문하지 않았던 노드가 다음 노드가 될 수 있는 조건이다.
			continue;

		dfs(next_node); // 다음 노드의 조건이 되므로 dfs를 재귀적으로 실행
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int vertax, edge, root; // vertax : 정점의 수, edge : 간선의 수, root : 시작 정점

	cin >> vertax >> edge >> root;
	// 노드의 연결 상태를 입력하고 Graph 배열에 저장한다.
	for (int i = 0; i < edge; i++) {
		int start_node, arrive_node;
		cin >> start_node >> arrive_node;
		Graph[start_node].push_back(arrive_node);
		Graph[arrive_node].push_back(start_node);
	}
	// 각 Graph[i] 번째 원소를 내림차순 정렬한다.
	// Ex. 1번 노드와 연결된 노드는 4,2 순
	// Ex. 2번 노드와 연결된 노드는 4,3,1 순 ....
	for (int i = 1; i <= vertax; i++) {
		sort(Graph[i].begin(), Graph[i].end(), greater<int>());
	}
	// 지정한 root노드부터 dfs을 실행한다. 
	dfs(root);
	
	// 각 노드가 몇 번째로 방문했는지 출력한다.
	for (int i = 1; i <= vertax; i++) {
		cout << visited[i] << "\n";
	}

}
*/