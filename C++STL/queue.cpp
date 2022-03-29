// queue 헤더파일
#include <queue>
using namespace std;

int value;

int main()
{
	// queue 생성
	queue<int> q;

	// queue에 value 삽입
	q.push(value);

	// queue에 맨 앞에 들어온 원소 제거
	q.pop();

	// queue에 맨 앞에 들어온 원소 반환
	q.front();

	// queue 길이 반환
	q.size();

	// queue이 비어있다면(size가 0) true 반환
	q.empty();
}
