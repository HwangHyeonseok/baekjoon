// 24479_알고리즘 수업-깊이 우선 탐색1

// 깊이 우선 탐색(DFS)을 구현하는 방법에는 재귀적 방법과, stack을 사용하는 방법이 있는데 이 방법의 경우 정점 i의 방문 순서를 출력해야 하므로 방문 순서대로의 출력이 나와야 한다.
// 방문 순서대로의 출력이 나와야 하는 경우 재귀적 방법이 더 편할 것 같았다.

// 성능 : 14836KB, 112ms
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NODE 100001 // 최대 정점(노드)의 개수
#define MAX_EDGE 200001 // 최대 간선의 개수

using namespace std;

// 노드의 연결 상태를 나타내는 그래프 
vector<int> Graph[MAX_EDGE];
vector<bool> Visited(MAX_NODE, false); // 노드의 방문 여부를 체크하는 배열
vector<int> answer(MAX_NODE, 0); // 정점 i 번째의 방문 번째수 출력 | 방문한 적 없는 원소는 0 출력
int counts = 1; // 방문 순서를 체크하기 위한 변수

// 1. 노드를 방문 처리하고, 방문 번째수를 정답 배열에 저장한 후 방문 카운트를 늘린다.
// 2. 연결된 그래프들을 확인한다.
// 2-1. 아직 방문하지 않은 경우 재귀적으로 탐색한다.
void dfs(int node) {
	Visited[node] = true; // 방문 처리
	answer[node] = counts; // 현재 노드의 방문 번째수를 answer 배열에 저장한다.
	counts++; // 방문 카운트 수를 늘린다.

	// 현재 노드와 연결된 그래프들을 확인한다.
	for (int next_node : Graph[node]) { // 현재 노드에서 연결된 그래프들을 확인하는 과정 : next_node는 현재 노드와 연결된 노드
		if (Visited[next_node]) // 다음 노드가 될 후보 노드 next_node가 이미 방문한 적 있으면 패스
			continue;

		dfs(next_node); //다음 노드가 될 후보 노드 next_node가 처음 방문하는거면 재귀적으로 dfs 함수 호출

	}
	

}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int node_count, edge_count, root; // node_count : 노드(정점) 개수, edge_count : 간선 개수, root : 루트 노드(시작점)

	cin >> node_count >> edge_count >> root;
	// 입력받은 연결을 토대로 그래프에 연결 적용
	for (int i = 0; i < edge_count; i++) {
		int current_node, next_node; // 1 4 라면 1번 노드에서 4번 노드로 | current_node : 시작 노드, next_node : 시작 노드와 연결된 다음 노드
		cin >> current_node >> next_node;
		Graph[current_node].push_back(next_node);
		Graph[next_node].push_back(current_node); // 1 4 가 연결된 경우와 4 1 이 연결된 경우가 같은 의미이기 때문이다.
	}
	for (int i = 1; i <= node_count; i++) {
		sort(Graph[i].begin(), Graph[i].end());
	}
	dfs(root); // 루트 노드부터 dfs 탐색 시작
	
	// 정점 i의 방문 번째수를 출력해준다.
	for (int i = 1; i <= node_count; i++) { // 장점의 개수만큼 출력이 이루어져야 한다.
		cout << answer[i] << "\n";
	}

	return 0;
}