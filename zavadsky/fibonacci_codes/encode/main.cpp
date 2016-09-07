#include <fstream>
#include <iostream>
#include <cctype>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool notalpha(char c)
{
	return !isalpha(c);
}

bool nextWord(string &next, ifstream &in)
{
	bool correct = false;
	while (!correct)
	{
		if (in >> next)
		{
			next.erase(
				remove_if(next.begin(), next.end(), &notalpha), next.end());
			if (next == "") correct = false;
			else correct = true;
		}
		else return false;
	}
	return true;
}

map<string, int32_t> frequenceMap(ifstream &in)
{
	map<string, int32_t> result;
	string word;
	while (nextWord(word, in))
	{
		if (result.find(word) == result.end())
			result.insert(make_pair(word, 1));
		else
			++result[word];
	}
	return result;
}

vector<pair<string, int32_t>> frequenceVectorFromMap(map<string, int32_t> m)
{
	vector<pair<string, int32_t>> result;
	for (auto x : m)
		result.push_back(make_pair(x.first, x.second));
	return result;
}

bool freqCmp(pair<string, int32_t> &a, pair<string, int32_t> &b)
{
	return a.second > b.second;
}

vector<string> fib3Codes(uint64_t n)
{
	uint64_t number = 1, nextLength = 1;
	vector<vector<string>> codesByLength;
	codesByLength.push_back(vector<string>{""});
	while (number < n)
	{
		codesByLength.push_back(vector<string>());
		for (int32_t k = 1; k < 4; ++k)
			if (nextLength > k - 1)
				for (size_t i = 0;
						i < codesByLength[nextLength - k].size() && number < n;
						++i, ++number)
				{
					codesByLength[nextLength].push_back
						(codesByLength[nextLength - k][i] + string(k - 1, '1') + "0");
				}
		++nextLength;
	}
	vector<string> codes;
	for (auto len : codesByLength)
		for (auto code : len)
			codes.push_back(code);
	return codes;
}

// for further optimization (less memory usage)
map<string, string> fib3CodesMap(vector<pair<string, int32_t>> &freq) // TODO
{
	map<string, string> result;
	vector<string> codes = fib3Codes(freq.size());
	for (size_t i = 0; i < freq.size(); ++i)
	{
		result.insert(make_pair(freq[i].first, codes[i] + "111"));
	}
	return result;
}

void fib3Encode(map<string, string> &dic, ifstream &in, ofstream &out)
{
	in.clear();
	in.seekg(0, ios::beg);
	string word;
	while (nextWord(word, in))
		out << dic[word];
}

uint8_t strBinToUInt8(string strByte)
{
	uint8_t result = 0, powerOfTwo = 1;
	for (auto iter = strByte.rbegin(); iter != strByte.rend(); ++iter)
	{
		result += (*iter - '0' == 1 ? powerOfTwo : 0);
		powerOfTwo *= 2;
	}
	return result;
}

void fib3EncodeBinary(map<string, string> &dic, ifstream &in, ofstream &out)
{
	in.clear();
	in.seekg(0, ios::beg);
	string buffer = "";
	string word;
	while (nextWord(word, in))
	{
		buffer += dic[word];
		while (buffer.length() >= 8)
		{
			uint8_t bit = strBinToUInt8(buffer.substr(0, 8));
			out.write((const char*)&bit, sizeof(uint8_t));
			buffer = buffer.substr(8, buffer.length() - 8);
		}
	}
	if (buffer.length() != 0)
	{
		buffer += string('0', 8 - buffer.length());
		uint8_t bit = strBinToUInt8(buffer.substr(0, 8));
		out.write((const char*)&bit, sizeof(uint8_t));
	}
}

int main()
{
	ifstream input("kjv.txt");
	ofstream outputDic("dic");
	ofstream outputEncoded("encoded");
	ofstream outputEncodedBinary("encodedBinary");
	map<string, int32_t> words = frequenceMap(input);
	vector<pair<string, int32_t>> frequencies = frequenceVectorFromMap(words);
	sort(frequencies.begin(), frequencies.end(), freqCmp);
	map<string, string> dictionary = fib3CodesMap(frequencies);
	for (auto x : dictionary)
		outputDic << x.first << " " << x.second << endl;
	fib3Encode(dictionary, input, outputEncoded);
	fib3EncodeBinary(dictionary, input, outputEncodedBinary);
	system("pause");
}