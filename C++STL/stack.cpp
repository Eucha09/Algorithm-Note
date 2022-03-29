// stack 헤더파일
#include <stack>
using namespace std;

int value;

int main()
{
	// stack 생성
	stack<int> s;

	// stack에 value 삽입
	s.push(value);

	// stack에 마지막에 들어온 원소 제거
	s.pop();

	// stack에 마지막에 들어온 원소 반환
	s.top();

	// stack 길이 반환
	s.size();

	// stack이 비어있다면(size가 0) true 반환
	s.empty();
}
