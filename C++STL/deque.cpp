// deque 헤더파일
#include <deque>
using namespace std;

int value;

int main()
{
	// deque 생성
	deque<int> d;

	// deque 맨 뒤에 value 삽입
	d.push_back(value);

	// deque 맨 앞에 value 삽입
	d.push_front(value);

	// deque 맨 뒤에 있는 원소 제거
	d.pop_back();

	// deque 맨 앞에 있는 원소 제거
	d.pop_front();

	// deque 맨 앞에 있는 원소 반환
	d.front();

	// deque 맨 뒤에 있는 원소 반환
	d.back();

	// deque 길이 반환
	d.size();

	// deque이 비어있다면(size가 0) true 반환
	d.empty();
}
