#include <bits/stdc++.h>

using namespace std;

const string DICT_PATH = "/home/lionell/dev/labs/zavadsky/fibonacci_codes/decode/res/dic.txt";
const string INPUT_PATH = "/home/lionell/dev/labs/zavadsky/fibonacci_codes/decode/res/in.txt";
const string OUTPUT_PATH = "/home/lionell/dev/labs/zavadsky/fibonacci_codes/decode/res/out.txt";

const int MAX_N = 30;

int f3[MAX_N];
int s3[MAX_N];

void init_common() {
    f3[0] = 1;
    f3[1] = 2;
    f3[2] = 4;
    s3[0] = 2;
    s3[1] = 4;
    s3[2] = 8;

    for (int i = 3; i < MAX_N; ++i) {
        f3[i] = f3[i - 1] + f3[i - 2] + f3[i - 3];
        s3[i] = s3[i - 1] + f3[i];
    }
}

std::map<int, std::string> read_dict(std::string path) {
    std::string v;
    int k;
    std::map<int, std::string> res;

    std::ifstream in(path);

    while (in >> v >> k) {
        res[k] = v;
    }

    in.close();
    return res;
}

bool next_bit(std::ifstream &in) {
    char c;
    in >> c;
    return c - '0';
}

int next(std::ifstream &in) {
    bool bits[4];

    bits[3] = next_bit(in);
    bits[2] = next_bit(in);
    bits[1] = next_bit(in);

    if (bits[1] && bits[2] && bits[3]) {
        return 1;
    }

    bits[0] = next_bit(in);

    if (bits[0] && bits[1] && bits[2]) {
        return 2;
    }

    int q = 0;
    int pos = 0;
    do {
        if (bits[3]) {
            q += f3[pos];
        }
        pos++;
        bits[3] = bits[2];
        bits[2] = bits[1];
        bits[1] = bits[0];
        bits[0] = next_bit(in);
    } while (!(bits[0] && bits[1] && bits[2]));

    return q + s3[pos - 1] + 1;
}

std::vector<int> decode(std::string path) {
    std::vector<int> ans;

    std::ifstream in(path);

    while (!in.eof()) {
        int num = next(in);
        ans.emplace_back(num);
    }

    in.close();
    return ans;
}

int main() {
    init_common();

//    map<int, string> dict = read_dict(DICT_PATH);
    vector<int> decoded = decode(INPUT_PATH);

    for (int x : decoded) {
        cout << x << " ";
    }

    return 0;
}
