// 2667_단지번호붙이기

// 오답 노트★ : 단지 수가 최대 25*25개 이므로 그에 맞춘 배열을 만들어주어야 한다. 
// 배열에 어떤 값을 바꿀 때 항상 초기화가 되고 나서 바꿔주어야 한다.
// 붙어있는 숫자를 입력 받을 때는 : scanf("%1d", &input); // ★ 010011 입력 시 0 / 1 / 0 / 0 / 1 / 1 로 입력 받는다.
// sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr) 은 C++ 입출력이 있을 때만 쓰는 것이다. C와 C++ 입출력이 혼용해서 쓰인다면 해당 문구를 사용하면 안된다.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX_MAP 26

using namespace std;
class Point { // 위치 정보 저장
public:
	Point(int x_pos, int y_pos) : x_pos(x_pos), y_pos(y_pos) {};
	int x_pos, y_pos;
};

int Move[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; // 상하좌우로 움직인다.
int Graph[MAX_MAP][MAX_MAP] = {0}; // 지도의 정보를 담는 Graph 2차원 배열 n이 1000 이하이므로 2차원 배열을 해도 메모리 초과가 안난다.
bool visited[MAX_MAP][MAX_MAP] = {false}; // 방문했던 노드(정점)인지 검사하는 배열
int n; // n*n의 지도를 만든다.
vector<int> danji_house((MAX_MAP*MAX_MAP), 0); // 단지내 집 수 // ★ 단지 수가 최대 25*25개 이므로 그에 맞춘 배열을 만들어주어야 한다.

// 재귀 dfs
// 1. 방문 처리 + 노드 칠하기
// 2. 다음 노드가 될 노드를 고르기 
// 다음 노드가 될 조건 : A) 현재 노드와 상하좌우 한 칸의 범위로 인접해있고, B) 방문한 적이 없는 노드이어야 한다.
void dfs(Point node, int color) {
	danji_house[color]++; // 단지 개수 하나 증가
	Point current_location = node;
	// 방문 처리 + 노드 칠하기
	visited[current_location.x_pos][current_location.y_pos] = true;
	Graph[current_location.x_pos][current_location.y_pos] = color;
	
	//다음 노드가 될 노드 고르기
	for (int i = 0; i < 4; i++) { // A)
		current_location.x_pos = node.x_pos + Move[i][0];
		current_location.y_pos = node.y_pos + Move[i][1];
		// 맵을 벗어난 경우 탐색할 수 없다.
		if (current_location.x_pos < 0 || current_location.x_pos >= n || current_location.y_pos < 0 || current_location.y_pos >= n) continue;
		// B) 이미 방문한 적 있는 노드는 탐색할 수 없다.
		if (visited[current_location.x_pos][current_location.y_pos] == true) continue;
		// 아파트가 아닌 경우 노드를 탐색할 수 없다.
		if (Graph[current_location.x_pos][current_location.y_pos] != 1) continue;

		// 위 조건에 해당하지 않는 경우 이동하여 탐색을 실시
		dfs(Point(current_location.x_pos, current_location.y_pos), color);
	}
}

int main(void) {
	// ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); scanf을 사용할 것이므로 사용하면 안된다.
	int danji = 0; // 단지 수
	int color = 1; // dfs 탐색하면서 단지 구분을 위해 그린다.

	cin >> n; // n*n의 Graph 생성

	// 아파트 정보들을 입력 받는다.
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			int input;
			scanf("%1d", &input); // ★ 010011 입력 시 0 / 1 / 0 / 0 / 1 / 1 로 입력 받는 방법
			Graph[x][y] = input;
		}
	}
	
	// 아파트가 있는 단지 중 단지 분포를 확인해야 하는(1) 경우에만 그 주변을 탐색하는 dfs 실행
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (Graph[x][y] == 1) { // 단지 분포를 확인해야 하는 아파트인 경우 범위 우선 탐색 실행
				Point location(x, y);
				dfs(location, ++color);
				danji++;
			}
		}
	}
	
	cout << danji << "\n"; // 단지 수 출력
	sort(danji_house.begin(), danji_house.end(), greater<int>()); // 각 단지내 집의 수를 내림차순으로 정렬
	// 각 단지내 집의 수를 출력
	if (danji >= 1) {
		for (int i = danji - 1; i >= 0; i--) {
			cout << danji_house[i] << "\n";
		}
	}
	


	return 0;
}