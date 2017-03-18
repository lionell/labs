#include <fstream>

#include <glog/logging.h>

class OutStream {
public:
	virtual OutStream& operator<<(const uint32_t &x) = 0;
};

class OutFileStream : public OutStream {
	ofstream out;
public:
	OutFileStream(string file) : out(file) {
		if (!out) {
			LOG(WARNING) << "Switching to dummy mode.";
		}
	}
	OutFileStream& operator<<(const uint32_t &x) {
		if (out)
			out << x << " ";
		return *this;
	}
};
