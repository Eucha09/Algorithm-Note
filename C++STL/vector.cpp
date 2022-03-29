// vector 헤더파일
#include <vector>
using namespace std;

int idx, value;

int main()
{
  // vector 생성
  vector<int> v;

  // 길이가 5인 vector 생성
  vector<int> v(5);

  // 길이가 5면서 1로 초기화된 vector 생성
  vector<int> v(5, 1);

  // v를 복사한 vector 생성
  vector<int> v2(v);

  // idx번째 원소 참조
  v[idx];

  // 첫 번째 원소 반환
  v.front();

  // 마지막 원소 반환
  v.back();

  // 마지막 원소 뒤에 value 삽입
  v.push_back(value);

  // 마지막 원소 제거
  v.pop_back();

  // 모든 원소 제거
  v.clear();

  // vector 길이 반환
  v.size();

  // vector가 비어있다면(size가 0) true 반환
  v.empty();

  // vector 첫 번째 원소의 주소(iterator)를 반환
  v.begin();

  // vector 마지막 원소의 다음 주소(iterator)를 반환
  v.end();`
}
