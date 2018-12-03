#include <bits/stdc++.h>
#include "pipes.cc"

using namespace std;

int main() {
  int delay;
  bool result;
  cin >> delay >> result;
  this_thread::sleep_for(chrono::seconds(delay));
  writePipe(result);
  return 0;
}
