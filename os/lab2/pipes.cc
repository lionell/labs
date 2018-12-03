#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

const char *kFifo = "/tmp/fifo";

void writePipe(bool res) {
  int fd = open(kFifo, O_WRONLY | O_NONBLOCK);
  write(fd, &res, sizeof(bool));
  close(fd);
}

bool readPipe() {
  int fd = open(kFifo, O_RDONLY);
  bool res;
  read(fd, &res, sizeof(bool));
  close(fd);
  return res;
}
