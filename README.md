## Algorithm-Note

알고리즘 노트 (대회 준비 용, ACM-ICPC Team Note)

* Euichan Jeong (정의찬)
  * Baekjoon OJ : [define_chan](https://www.acmicpc.net/user/define_chan)
  * Atcoder : [defineChan](https://atcoder.jp/)

## Contens

0. default
    1. Template
0. Math
    1. 에라토스테네스의 체
    1. 좌표 압축
0. Graph
0. Tree
0. String
0. Geometry
0. C++ STL
    1. algorithm
    1. vector
    1. stack
    1. queue
    1. deque
    1. string
    1. map

## 0. default

### 0-1. Template

```cpp
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#define INF 987654321
#define MOD 1000000007
#define ZERO 1.0e-10
using namespace std;
typedef long long ll;

int main()
{

	return 0;
}
```

## 1. Math

### 1-1. 에라토스테네스의 체

```cpp
int num[1000006]; // 찾을 소수 범위 (1 ~ 1000006)
vector<int> primeNumver; // 소수

void Eratosthenes()
{
  for (int i = 2; i < 1000006; i++)
  {
    if (num[i])
      continue;
    primeNumver.push_back(i);
    for (int j = i * 2; j < 1000006; j += i)
      num[j] = 1;
  }
}
```

### 1-2. 좌표 압축

```cpp
int arr[1000006];
vector<int> v;

int getidx(int x)
{
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main()
{
  int n;

  scanf(" %d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf(" %d", arr + i);
    v.push_back(arr[i]);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  // arr[i] : 원래 좌표
  // getidx(arr[i]) : 압축된 좌표
}
```

## 6. C++ STL

### 6-1. algorithm

```cpp
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
```

### 6-2. vector

```cpp
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
```
