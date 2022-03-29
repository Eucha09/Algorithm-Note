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
