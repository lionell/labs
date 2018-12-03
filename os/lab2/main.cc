#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "pipes.cc"

using namespace std;

int main() {
  mkfifo(kFifo, 0666 /* read, write permissions */);
  cout << "Waiting for the first result..." << endl;
  bool res = readPipe();
  cout << "Got: " << res << endl;
  if (!res) {
    cout << "Waiting for the second result..." << endl;
    res = readPipe();
    cout << "Got: " << res << endl;
  }
  cout << "Final result: " << res << endl;
  return 0;
}
