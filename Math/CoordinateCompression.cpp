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
