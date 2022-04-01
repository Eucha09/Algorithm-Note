// string 헤더파일
#include <string>
using namespace std;

int idx;

int main()
{
	// string 생성 및 초기화
	string str = "Hello World!"; // str = "Hello World!"

	// 길이가 4고 'A'로 모두 초기화
	string str2(4, 'A'); // str2 = "AAAA"

	// 덧셈 연산
	str + str2; // "Hello World!AAAA"

	// idx번째 문자 참조
	str[idx];

	// 첫 번째 문자 반환
	str.front();

	// 마지막 문자 반환
	str.back();

	// string의 길이 반환
	str.size();

	// string이 비어있다면(size가 0) true 반환
	str.empty();

	// char*로 변환하여 반환
	str.c_str();
	printf("%s\n", str.c_str());

	// 모든 문자 제거
	str.clear();

	// string 첫 번째 문자의 주소(iterator)를 반환
	str.begin();

	// string 마지막 문자의 다음 주소(iterator)를 반환
	str.end();
}
