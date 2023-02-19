// 이코테_음료수 얼려 먹기

/*문제 설명
N * M 크기의 얼음 틀이 있습니다. 구멍이 뚫려 있는 부분은 0, 칸막이가 존재하는 부분은 1로 표시됩니다.
구멍이 뚫려 있는 부분끼리 상, 하, 좌, 우로 붙어 있는 경우 서로 연결되어 있는 것으로 간주합니다.
이때 얼음 틀의 모양이 주어졌을 때 생성되는 총 아이스크림의 개수를 구하는 프로그램을 작성하세요. 
다음의 4*5 얼음 틀 예시에서는 아이스크림 3개 생성됩니다.
*/
/*입출력 조건
입력 조건 :
1. 첫 번째 줄에 얼음 틀의 세로 길이 N과 가로 길이 M이 주어진다. (N,M은 1보다 크거나 같고 1000보다 작거나 같다.)
2. 두 번째 줄부터 N+1번째 줄까지 얼음 틀의 형태가 주어진다.
3. 이때 구멍이 뚫려있는 부분은 0, 그렇지 않은 부분은 1이다.


출력 조건 :
1. 한 번에 만들 수 있는 아이스크림의 개수를 출력한다.


입력 예시 :
4 5
00110
00011
11111
00000

출력 예시 :
3

*/

/*문제 분석
어떤 영역을 기반으로 연결된 것을 찾아가야하는 DFS 알고리즘을 사용하는 것이 적합하다.

문제에서 1은 벽으로 간주한다. (지나갈 수 없다.)
N과 M은 최악의 경우 1000 이므로 2차원 배열을 사용해도 메모리 제한에 걸리지 않는다.

*/

#include <iostream>
#include <vector>

using namespace std;
#define MAX_NM 1001 // 최대 N,M의 개수


int n, m; // n*m의 얼음판

int Move[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} }; // 우 좌 상 하 이동을 위한 배열
//
//vector<vector<int>> Graph(MAX_NM, vector<int>(MAX_NM, -1)); // 노드들의 연결 상태를 나타내는 그래프 배열 
//vector<vector<bool>> visited(MAX_NM, vector<bool>(MAX_NM, false)); // 각 노드의 방문 여부를 체크한다. - 오류 발생
int Graph[MAX_NM][MAX_NM]; // 노드들의 연결 상태를 나타내는 그래프 배열 - 전역 범위 초기화 default : 자동으로 모든 원소 0 저장
bool visited[MAX_NM][MAX_NM]; // 각 노드의 방문 여부를 체크한다. - 전역 범위 초기화 default : 자동으로 모든 원소 false 저장

// dfs 재귀 구현
// 1. 방문 처리 + 노드 탐색
// 2. 다음 노드가 될 조건에 맞는 노드에 대해 다음 노드 순회
// 다음 노드가 될 조건 : A) 다음 노드가 될 노드는 이전에 방문한 적이 없는 노드여야 한다. B) 지정한 n*m 맵에서 벗어나지 않아야 한다. 
// C) 현재 노드와 연결이 되어있는 노드여야 한다. D) 그 다음 노드는 벽(1)이 아니어야 한다.
void dfs(int x_pos, int y_pos) {
	int next_location_x = x_pos; // 현재 x 위치 temp 저장
	int next_location_y = y_pos; // 현재 y 위치 temp 저장

	visited[x_pos][y_pos] = true; // 방문 처리
	Graph[x_pos][y_pos] = 1; // 얼음판을 채워준다.

	for (int i = 0; i < 4; i++) {
		next_location_x = x_pos + Move[i][0]; // 다음 x 좌표 후보 // C조건 자동 OK
		next_location_y = y_pos + Move[i][1]; // 다음 y 좌표 후보 // C조건 자동 OK
		
		if (visited[next_location_x][next_location_y] == true) continue; // !A)
		if (next_location_x < 0 || next_location_x >= n || next_location_y < 0 || next_location_y >= m) continue; // !B)
		if (Graph[next_location_x][next_location_y] == 1) continue; // !D)

		// 다음 노드가 될 조건을 모두 충족한 경우에만 dfs 순회 실시
		dfs(next_location_x, next_location_y);
	}
}

int main(void) {
	int ice_cream = 0; // 얼음판에서 한 번에 만들 수 있는 아이스크림 개수

	cin >> n >> m;

	// 각 얼음판에 대한 상태를 입력 받는다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int condition; // 구멍이 뚫렸는지, 뚫리지 않았는지 상태 변수
			scanf_s("%1d", &condition); // ★ 정수를 붙여서 1개 단위로 끊어서 받아야 한다. 12347 입력 시 1 / 2 / 3 / 4 / 7 이 입력되도록 해야 하므로 해당 코드 사용 -> 해당 코드는 C 입출력 문장이므로 ios_base::sync_with_stdio(false);을 사용하지 못한다.
			Graph[i][j] = condition;
		}
	}

	// 구멍이 뚫린 경우에는 dfs 탐색을 통하여 채워준다. (아이스크림 생성)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Graph[i][j] == 0) { // 구멍이 뚫린 경우에 그 주변 노드들을 탐색
				dfs(i, j);
				ice_cream++;
			}
		}
	}
	// 얼음판으로 한 번에 만들 수 있는 아이스크림 개수를 출력해준다.
	cout << ice_cream;

}