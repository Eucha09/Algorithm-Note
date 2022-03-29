// algorithm 헤더파일
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[1000006];
int n, a, b, minIdx, maxIdx;

int main()
{
  // 정렬 - 시간복잡도 O(nlogn)
  sort(arr, arr + n); // 배열일 때
  sort(v.begin(), v.end()); // vector일 때
  sort(arr, arr + n, [](int a, int b)->bool {return a > b; }); // 내림차순 compare 지정

  // 원소들의 순서를 역순으로 뒤집음
  reverse(arr, arr + n);
  reverse(v.begin(), v.end());

  // 두 변수안에 있는 값을 서로 바꿈
  swap(a, b);

  // 두 인자 중 최소값을 반환
  min(a, b);

  // 두 인자 중 최댓값을 반환
  max(a, b);

  // 원소들 중 최소값의 주소(iterator)를 반환
  min_element(arr, arr + n);
  min_element(v.begin(), v.end());
  // 최소값의 Index를 구할 때
  minIdx = min_element(arr, arr + n) - arr;
  minIdx = min_element(v.begin(), v.end()) - v.begin();

  // 원소들 중 최대값의 주소(iterator)를 반환
  max_element(arr, arr + n);
  max_element(v.begin(), v.end());
  // 최대값의 Index를 구할 때
  maxIdx = max_element(arr, arr + n) - arr;
  maxIdx = max_element(v.begin(), v.end()) - v.begin();

  // a 값이 존재하면 true, 아니면 false를 반환
  // 이진탐색을 사용, 정렬이 되어 있어야 함.
  binary_search(arr, arr + n, a);
  binary_search(v.begin(), v.end(), a);

  // a 값보다 같거나 큰 숫자가 처음 등장하는 주소(iterator)를 반환
  // 이진탐색을 사용, 정렬이 되어 있어야 함.
  lower_bound(arr, arr + n, a);
  lower_bound(v.begin(), v.end(), a);

  // a 값보다 큰 숫자가 처음 등장하는 주소(iterator)를 반환
  // 이진탐색을 사용, 정렬이 되어 있어야 함.
  upper_bound(arr, arr + n, a);
  upper_bound(v.begin(), v.end(), a);
}
