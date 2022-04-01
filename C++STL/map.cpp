// map 헤더파일
#include <map>
#include <string>
using namespace std;

int value;

int main()
{
	// map 생성
	map<string, int> m; // map<key, value>

	// map에 {key, value} 삽입
	m.insert({"AAA", value});

	// key값으로 해당 요소 참조
	m["AAA"];
	// 해당 key값의 요소가 없을 경우 {key, 0}이 자동생성
	// 이점을 이용해서 이런식으로도 삽입가능
	m["BBB"] = value; // m.insert({"BBB", value});

	// 해당 key값의 요소 개수 반환 (사실상 있으면 1 없으면 0 반환)
	m.count("AAA");

	// 요소의 개수 반환
	m.size();

	// 모든 요소 제거
	m.clear();
}
