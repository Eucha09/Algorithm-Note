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
