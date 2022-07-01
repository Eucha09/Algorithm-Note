## 5. String

### Contens

1. [KMP](https://github.com/Eucha09/Algorithm-Note/tree/main/String#5-1-kmp)
1. [Trie](https://github.com/Eucha09/Algorithm-Note/tree/main/String#5-2-trie)

### 5-1. KMP

```cpp
char input[1000006];
string T, P;

vector<int> getPi(string p)
{
	int m = p.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (p[begin + matched] == p[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmp(string s, string p)
{
	int n = s.size(), m = p.size();
	vector<int> ret;
	vector<int> pi = getPi(p);
	int begin = 0, matched = 0;
	while (begin <= n - m)
	{
		if (matched < m && s[begin + matched] == p[matched])
		{
			matched++;
			if (matched == m)
				ret.push_back(begin);
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main()
{
	getline(cin, T);
	getline(cin, P);

	vector<int> matched = kmp(T, P);

	printf("%d\n", matched.size());
	for (int i = 0; i < matched.size(); i++)
		printf("%d ", matched[i] + 1);
	return 0;
}
```

### 5-2. Trie

```cpp
const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'a'; }
 
struct TrieNode {
	TrieNode* children[ALPHABETS];
	bool terminal;
 
	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}
 
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}
 
	void insert(const char* key) {
		if (*key == 0)
			terminal = true;
		else {
			int next = toNumber(*key);
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}
 
	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL)
			return NULL;
		return children[next]->find(key + 1);
	}
};

trie = new TrieNode();
```