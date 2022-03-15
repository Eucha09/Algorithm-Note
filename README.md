## Algorithm-Note

* Euichan Jeong (정의찬)
  * Baekjoon OJ : [define_chan](https://www.acmicpc.net/user/define_chan)
  * Atcoder : [defineChan](https://atcoder.jp/)

## Contens

0. default
    1. Template
0. Math
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

## 6. C++ STL

### 6-1. algorithm

```cpp
// algorithm 헤더파일
#include <algorithm>
using namespace std;

sort();

reverse();

swap();

min();

max();

min_element();

max_element();

binary_search();

lower_bound();

upper_bound();
```

### 6-2. vector

```cpp
// vector 헤더파일
#include <vector>
using namespace std;

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

// vector 첫 번째 위치 주소를 반환
v.begin();

// vector 마지막 위치의 다음 주소를 반환
v.end();
```
