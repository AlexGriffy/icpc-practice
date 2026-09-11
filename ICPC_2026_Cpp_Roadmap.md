# ICPC 2026 — C++ Study Roadmap

**North America Regional Contest** | Target date: Saturday, November 7, 2026
For a Python/Java programmer learning contest C++ from scratch (~9-week plan)

---

## The Contest at a Glance

| | |
|---|---|
| **Format** | 5 hours, team of 3, ONE shared computer |
| **Languages** | C++, Java, Python 3, or Kotlin (use C++ for speed & STL) |
| **Problems** | ~10–13 problems, sorted roughly easy to hard |
| **Scoring** | Rank by problems solved; ties broken by total time + 20 min penalty per wrong submission |
| **Path** | Regional → North America Championship (NAC) → World Finals. Div 1 advances; Div 2 is for less experience. |
| **Warmup** | NAQ online qualifier ~Oct 3, 2026 (optional) — enter it for calibration |
| **Judge** | Kattis (open.kattis.com) — the actual regional judge; practice there |

**Honest expectation:** 9 weeks from zero C++ to winning a Div 1 regional is a stretch goal against teams with years of experience. Aim to become a fast, reliable contributor and place well; let "first place" drive the intensity of the regimen.

---

## Phase 1 — Contest C++ Conversion (Weeks 1–2)

You already think in code. You only need the **competitive subset** of C++, not the whole language. Learn this and nothing more to start:

### Learn

- **Fast I/O:** `ios_base::sync_with_stdio(false); cin.tie(nullptr);` then use `cin`/`cout`. Keep `scanf`/`printf` as backup.
- **Types & overflow:** use `long long` by default for anything you multiply. `int` overflows near 2.1e9 — this is the #1 beginner bug.
- **STL containers:** vector, pair, array, string, map / unordered_map, set / unordered_set, stack, queue, deque, priority_queue.
- **STL algorithms:** sort, lower_bound / upper_bound, next_permutation, __gcd, max_element, min_element, accumulate, reverse, unique.
- **Idioms:** range-based for, auto, structured bindings, custom comparators, emplace_back, vector of vectors for grids/graphs.
- **Your template:** build one snippet (macros, typedefs, fast I/O) you paste at the top of every problem.

### Skip (not needed for ICPC)

Manual memory management, writing your own classes/inheritance, templates you author yourself, move semantics, smart pointers. Ignore these for now.

### How to convert fastest

- Port ~40 problems you can *already* solve conceptually from Python/Java into C++. Muscle memory beats reading syntax guides.
- Reference: **Competitive Programmer's Handbook** (Laaksonen, free PDF) chapters 1–3 for C++ & STL.

---

## Phase 2 — Algorithm Topic Roadmap

Layered by priority. Master a tier before moving up. Each topic = learn it, then solve 8–15 problems on it.

### Tier 1 — Foundations (Weeks 3–4)

| Topic | What to master |
|---|---|
| Complexity | Big-O, estimating if a solution fits in the time limit (~1e8 ops/sec) |
| Sorting & searching | std::sort, custom comparators, binary search, lower/upper_bound |
| Two pointers / sliding window | Contiguous subarray problems, meeting-in-the-middle intuition |
| Prefix sums | 1D and 2D range-sum queries in O(1) |
| Greedy | Interval scheduling, exchange-argument reasoning |
| Basic math | GCD/LCM, modular arithmetic, sieve of Eratosthenes, fast exponentiation |

### Tier 2 — Core (Weeks 5–6)

| Topic | What to master |
|---|---|
| Graph traversal | BFS, DFS, connected components, cycle detection, grid graphs |
| Shortest paths | Dijkstra, BFS on 0/1 weights; Bellman-Ford / Floyd-Warshall basics |
| Union-Find (DSU) | Path compression + union by rank; Kruskal's MST |
| Topological sort | Kahn's algorithm, DAG ordering, dependency problems |
| Intro DP | Knapsack, coin change, LIS, edit distance, grid path DP |

### Tier 3 — Advanced (Weeks 7–8)

| Topic | What to master |
|---|---|
| Advanced DP | DP on trees, bitmask DP, digit DP, DP optimizations |
| Range structures | Fenwick (BIT) tree, segment tree (point + range updates) |
| Trees | LCA, subtree aggregates, tree diameter, Euler tour |
| Number theory | Modular inverse, combinatorics (nCr mod p), CRT basics |
| Strings | Hashing, KMP, Z-algorithm, trie |
| Geometry (light) | Cross product, orientation, convex hull, point-in-polygon |

**Rule of thumb:** depth over breadth. A team that reliably nails Tiers 1–2 fast beats one that half-knows Tier 3. Don't chase exotic algorithms you can't implement cleanly under pressure.

---

## Phase 3 — 9-Week Calendar (Sep → Nov 7)

| Wk | Dates (approx) | Individual focus | Team focus |
|---|---|---|---|
| 1 | Sep 8–14 | C++ syntax + STL; port easy problems | First mock on an easy set |
| 2 | Sep 15–21 | Finish C++ conversion; build template | Weekly 5h mock + upsolve |
| 3 | Sep 22–28 | Tier 1: sorting, greedy, two pointers | Weekly mock + upsolve |
| 4 | Sep 29–Oct 5 | Tier 1: prefix sums, math; NAQ Oct 3 | NAQ online contest as a team |
| 5 | Oct 6–12 | Tier 2: graphs (BFS/DFS, DSU) | Weekly mock + upsolve |
| 6 | Oct 13–19 | Tier 2: shortest paths, intro DP | Weekly mock + upsolve |
| 7 | Oct 20–26 | Tier 3: adv DP, segment/Fenwick trees | Mock on a past regional set |
| 8 | Oct 27–Nov 2 | Tier 3: trees, number theory, strings | Full 5h mock on past regional |
| 9 | Nov 3–7 | Taper: review templates, light problems | One final mock; rest 2 days before |

---

## Individual Daily Regimen (~2–3 hrs weekdays)

- **Warmup (30–45 min):** 1–2 problems at your comfort level, coded fast & clean for speed.
- **Stretch (60–90 min):** 1 problem just above your level. Struggle; read the editorial only after 45 min stuck.
- **Drill (15 min):** re-implement one algorithm from your topic list from scratch, no reference.
- **Log everything** on Codeforces so your rating gives an objective progress signal.

**Weekends:** longer sessions + the team mock + upsolving. Upsolving (solving every problem you missed in a mock) is where the most improvement happens — never skip it.

---

## Team Roles & Role-Based Training

One keyboard, three people — roles bias each person's focus but everyone must be able to code. Keep roles fluid enough to substitute mid-contest.

### Coder / Implementer

- **Job:** Fastest, cleanest typist. Owns the keyboard most; converts agreed solutions to correct code quickly.
- **Trains:** Volume of easy-medium problems solved fast; template mastery; typing accuracy; debugging under pressure.

### Algorithms / Hard Solver

- **Job:** Strongest at theory. Attacks the 1–2 hardest problems while others clear the easy ones.
- **Trains:** Depth on graphs, DP, number theory, geometry. Harder Codeforces problems (Div2 E/F, Div1 C+).

### Strategist / Debugger

- **Job:** Best reader & verifier. Reads problems first, sorts by difficulty, catches misreads, manages clock & reference sheet.
- **Trains:** Fast statement reading; edge-case & stress-test generation; math proofs; second pair of eyes on code.

**Contest flow:** Strategist reads and triages all problems in the first 10–15 min while Coder sets up the template and knocks out the obvious easy problem. Solver goes deep on the hard ones. Rotate the keyboard by who has a *ready* solution, never by ego. Always have someone reading ahead so no problem sits unread.

---

## Team Practice (Non-Negotiable)

- **One 5-hour mock contest per week** — 3 people, 1 computer, on past regional/NAC sets or Codeforces Gym virtual contests. This trains the real skill: shared-computer strategy.
- **Upsolve after every mock** — solve every problem you didn't get during the round.
- **Build a printed reference (25-page team notebook)** of your code templates — printed material is allowed at the contest; a clean, tested reference wins problems.

---

## Core Resources

| Resource | Where | Use |
|---|---|---|
| Codeforces | codeforces.com | Daily problems, ratings, Gym for team virtual contests |
| Kattis | open.kattis.com | ICPC's actual judge; regionals run here — practice on it |
| CP Handbook | cses.fi/book/book.pdf | Laaksonen's free book; the ICPC bible, read cover to cover |
| CSES Problem Set | cses.fi/problemset | 300 curated problems covering every core topic |
| USACO Guide | usaco.guide | Best structured topic-by-topic path with problems |
| Past ICPC sets | icpc.global / regional sites | Realistic 5-hour team mocks |

**Two priorities if time is short:** (1) build and test a shared team reference notebook you can print; (2) log more 5-hour team mocks than any other activity. For ICPC specifically, coordination and upsolving beat solo grinding.

---

*Confirm your exact regional date, division (1 vs 2), and registration on your regional's ICPC site — dates and rules can change.*
