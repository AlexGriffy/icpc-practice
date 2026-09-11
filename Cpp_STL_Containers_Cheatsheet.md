# C++ STL Containers Cheat Sheet — ICPC Prep

All examples assume `#include <bits/stdc++.h>` and `using namespace std;`.

Complexity notes: O(1) = constant, O(log n) = balanced tree / heap, avg O(1) = hash.

---

## vector<T> — dynamic array

Default container for a list of things. Access O(1), `push_back` amortized O(1).

```cpp
vector<int> v;                  // empty
vector<int> v2 = {5, 2, 8};     // initialized
vector<int> v3(5, 0);           // size 5, all zeros

v.push_back(10);                // add to end
v.push_back(20);
cout << v[0] << "\n";           // 10  (index access)
cout << v.size() << "\n";       // 2
v.pop_back();                   // remove last
cout << v.back() << "\n";       // 10  (last element)
cout << v.front() << "\n";      // 10  (first)
cout << v.empty() << "\n";      // 0 = false

sort(v.begin(), v.end());       // sort ascending
reverse(v.begin(), v.end());    // reverse

for (int x : v) cout << x << " ";      // iterate
for (int i = 0; i < v.size(); i++)     // index loop
    cout << v[i] << " ";

vector<vector<int>> grid(3, vector<int>(4, 0));  // 3x4 grid of 0s
```

---

## pair<A,B> — two values glued together

Sorts by `.first`, then `.second`. Great for coordinates, (weight,node) edges, returning two values.

```cpp
pair<int,int> p = {3, 5};
cout << p.first << " " << p.second << "\n";   // 3 5
p.first = 10;

vector<pair<int,int>> vp;
vp.push_back({4, 2});
sort(vp.begin(), vp.end());     // by first, then second
for (auto [a, b] : vp) cout << a << " " << b << "\n";  // structured binding
```

For 3+ values use `tuple<int,int,int>` (access with structured bindings or `get<0>(t)`).

---

## string — text; behaves like a vector of chars

```cpp
string s = "hello";
cout << s.length() << "\n";     // 5  (.size() identical)
cout << s[0] << "\n";           // h
s += " world";                  // concatenate
cout << s.substr(0, 5) << "\n"; // hello  (start, length)
cout << s.substr(6) << "\n";    // world  (to end)

int n = stoi("42");             // string -> int
long long m = stoll("9999999999");
string t = to_string(123);      // int -> string

sort(s.begin(), s.end());       // works like vector
reverse(s.begin(), s.end());
if (s.find("lo") != string::npos) cout << "found\n";  // search

// --- Comparing (lexicographic, by ASCII) ---
string a = "apple", b = "banana";
if (a == b) {}                  // equal? (a != b also works)
if (a < b)  {}                  // dictionary order; sort() uses this too
// NOTE: uppercase < lowercase ('A'=65 < 'a'=97), so "Zoo" < "apple"
int c = a.compare(b);           // three-way: neg / 0 / pos

// --- Case conversion (no built-in method; transform each char) ---
string s = "Hello";
for (char &ch : s) ch = tolower(ch);   // "hello"  (&ch = in place)
for (char &ch : s) ch = toupper(ch);   // "HELLO"
// one-liner form (:: picks the C function):
transform(s.begin(), s.end(), s.begin(), ::tolower);

// --- Case-insensitive compare (lowercase both, then ==) ---
for (char &ch : a) ch = tolower(ch);
for (char &ch : b) ch = tolower(ch);
if (a == b) {}
```

---

## stack<T> — LIFO

O(1) push/pop/top. Matching brackets, iterative DFS, monotonic-stack tricks.

```cpp
stack<int> st;
st.push(1);
st.push(2);
st.push(3);
cout << st.top() << "\n";       // 3  (peek)
st.pop();                       // removes 3, returns nothing
cout << st.top() << "\n";       // 2
cout << st.size() << "\n";      // 2
while (!st.empty()) { cout << st.top() << " "; st.pop(); }  // 2 1
```

---

## queue<T> — FIFO

O(1). Main use: BFS.

```cpp
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
cout << q.front() << "\n";      // 1  (next out)
cout << q.back() << "\n";       // 3
q.pop();                        // removes 1, returns nothing
cout << q.front() << "\n";      // 2
while (!q.empty()) { cout << q.front() << " "; q.pop(); }   // 2 3
```

---

## deque<T> — double-ended queue

Push/pop both ends O(1), plus index access. Sliding-window max/min, 0-1 BFS.

```cpp
deque<int> dq;
dq.push_back(2);
dq.push_back(3);
dq.push_front(1);               // 1 2 3
cout << dq.front() << "\n";     // 1
cout << dq.back() << "\n";      // 3
cout << dq[1] << "\n";          // 2  (index access, unlike stack/queue)
dq.pop_front();                 // removes 1
dq.pop_back();                  // removes 3
```

---

## priority_queue<T> — heap

Max-heap by default. push/pop O(log n), top O(1). Dijkstra, "always grab largest/smallest."

```cpp
priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(5);
cout << pq.top() << "\n";       // 5  (largest)
pq.pop();                       // removes 5
cout << pq.top() << "\n";       // 3

// min-heap:
priority_queue<int, vector<int>, greater<int>> mn;
mn.push(3); mn.push(1); mn.push(5);
cout << mn.top() << "\n";       // 1  (smallest)
```

---

## set<T> / multiset<T> — sorted, balanced BST

All ops O(log n). `set` = unique keys, `multiset` = duplicates allowed.
Use when you need sorted order + fast insert/erase + "next larger element" queries.

```cpp
set<int> s;
s.insert(5);
s.insert(2);
s.insert(5);                    // ignored — duplicate
cout << s.size() << "\n";       // 2
cout << s.count(5) << "\n";     // 1  (present?)
s.erase(2);                     // remove by value
if (s.find(5) != s.end()) cout << "has 5\n";

auto it = s.lower_bound(3);     // first element >= 3
if (it != s.end()) cout << *it << "\n";

for (int x : s) cout << x << " ";   // ascending order

multiset<int> ms;               // allows duplicates
ms.insert(5); ms.insert(5);
cout << ms.count(5) << "\n";    // 2
ms.erase(ms.find(5));           // erase ONE 5 (erase(5) removes all)
```

---

## map<K,V> — sorted key → value

O(log n). Counting/grouping when you want keys sorted, or keys aren't small ints.

```cpp
map<string,int> m;
m["apple"] = 3;
m["banana"] = 5;
m["apple"]++;                   // now 4
cout << m["apple"] << "\n";     // 4
cout << m.count("banana") << "\n";  // 1  (key exists?)

// gotcha: m["x"] on a missing key CREATES it with value 0
if (m.find("cherry") != m.end()) cout << "found\n";  // safe check

for (auto [key, val] : m)       // iterates in sorted key order
    cout << key << " " << val << "\n";

// frequency count idiom:
map<int,int> freq;
for (int x : {1,2,2,3,2}) freq[x]++;   // {1:1, 2:3, 3:1}
```

---

## unordered_set / unordered_map — hash

Average O(1), worst O(n), no ordering. Faster when you don't need sorted keys.
Caution: adversarial cases can force collisions → TLE. Prefer `map`/`set` if order matters or hacking is a risk (Codeforces).

```cpp
unordered_map<string,int> um;
um["x"] = 1;
um["y"] = 2;
cout << um["x"] << "\n";        // 1
cout << um.count("y") << "\n";  // 1
// same interface as map, but iteration order is arbitrary

unordered_set<int> us;
us.insert(10);
us.insert(10);                  // ignored
cout << us.count(10) << "\n";   // 1
```

---

## Two recurring traps

1. `stack` / `queue` / `priority_queue` `.pop()` returns **void** — read `.top()` / `.front()` first, then pop.
2. `map` / `unordered_map` `operator[]` on a missing key silently **inserts** it with value 0 — use `.count()` or `.find()` when you only want to check.

---

## Quick picks

| Need | Use |
|------|-----|
| Just a list | `vector` |
| Sorted + fast lookup | `set` / `map` |
| Fast lookup, order irrelevant | `unordered_set` / `unordered_map` |
| Best/worst repeatedly | `priority_queue` |
| BFS | `queue` |
| DFS / brackets | `stack` |
| Two values together | `pair` |
| Both ends fast | `deque` |
