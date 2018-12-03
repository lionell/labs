#include <bits/stdc++.h>

using namespace std;

int count(const string &s) {
  set<char> chrs;
  for (char c : s) {
    chrs.insert(c);
  }
  return chrs.size();
}

bool forbidden(char c) {
  return !isalnum(c);
}

int main() {
  string s;
  set<string> ans;
  int best = -1;
  while (cin >> s) {
    s.erase(remove_if(s.begin(), s.end(), &forbidden), s.end());
    int cur = count(s);
    if (cur > best) {
      best = cur;
      ans.clear();
    }
    if (cur == best) {
      ans.insert(s);
    }
  }
  cout << "Count: " << best << endl;
  for (const string &s : ans) {
    cout << s << endl;
  }
  return 0;
}
