## 6. C++ STL

### Contens

1. [algorithm](https://github.com/Eucha09/Algorithm-Note/tree/main/C%2B%2BSTL#6-1-algorithm)
1. [vector](https://github.com/Eucha09/Algorithm-Note/tree/main/C%2B%2BSTL#6-2-vector)
1. [stack](https://github.com/Eucha09/Algorithm-Note/tree/main/C%2B%2BSTL#6-3-stack)
1. [queue](https://github.com/Eucha09/Algorithm-Note/tree/main/C%2B%2BSTL#6-4-queue)
1. [deque](https://github.com/Eucha09/Algorithm-Note/tree/main/C%2B%2BSTL#6-5-deque)
1. [string]()
1. [map]()

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
	v.end(); `
}
```

### 6-3. stack

```cpp
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
```

### 6-4. queue

```cpp
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
```

### 6-5. deque

```cpp
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
```

### 6-6. string

```cpp
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
```

### 6-7. map

```cpp
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
```
