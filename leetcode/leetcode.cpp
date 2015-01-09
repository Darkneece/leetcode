// leetcode.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;


// Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
string longestCommonPrefix(vector<string> &strs)
{
	if (strs.empty())
	{
		return "";
	}

	int end = strs.at(0).size();

	for (int i = 0; i < strs.size(); i++)
	{
		end = min(end, (int)strs.at(i).size());
	}
		for (int i = 0; i < strs.size(); i++)
	{
		for (int j = 0; j < end; j++)
		{
			if (strs.at(0).at(j) != strs.at(i).at(j))
			{
				end = j;
			}
		}
	}

	return strs.at(0).substr(0, end);
}

static const vector<string> testCase1 =
{
	"abcdefg",
	"abc",
	"abcd",
	"abcdddd",
	"abddddd"
};



// Letter Combinations of a Phone Number
/*Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.*/
static const string table[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

vector<string> letterCombinations(string digits)
{
	vector<string> ret;
	const int size = digits.size();

	char *num = new char[size];

	// generate a "number" string
	for (int i = 0; i < size; i++)
	{
		num[i] = 0;
	}

	while (true)
	{
		string next = "";
		ret.push_back(next);
		
		for (int j = 0; j < size; j++)
		{
			// generate a string
			ret.back().append(table[digits.at(j) - '0'].substr(num[j], 1));
		}

		// step up
		num[size - 1]++;

		// carry check
		for (int i = size - 1; i >= 0; i--)
		{
			if (num[i] >= table[digits.at(i) - '0'].size())
			{
				num[i] = 0;
				if (i != 0)
				{
					num[i - 1]++;
				}
				else
				{
					delete num;
					return ret;
				}
			}
		}
	}

	delete num;
	return ret;
}

static const string testCase2 = "111";

// Decode Ways
/*  A message containing letters from A-Z is being encoded to numbers using the following mapping:
	'A' -> 1'B' -> 2...'Z' -> 26
	Given an encoded message containing digits, determine the total number of ways to decode it.
	For example,
	Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
	The number of ways decoding "12" is 2.
*/
class NumDecodings 
{
public:
	int numDecodings(string s)
	{
		int n = s.size();

		int ways = 0;
		int prev = 1;
		int prev2 = 1;

		for (int i = 1; i <= n; i++)
		{
			ways = 0;

			if (s[i - 1] != '0')
			{
				ways += prev;
			}

			if (i >= 2)
			{
				int dig = stoi(s.substr(i - 2, 2));

				if ((dig >= 10) && (dig <= 26))
				{
					ways += prev2;
				}

				prev2 = prev;
			}
			prev = ways;
		}
		return ways;
	}
		
	const string testCase = "12";
};

// Count and Say
/* The count-and-say sequence is the sequence of integers beginning as follows:
	1, 11, 21, 1211, 111221, ...

	1 is read off as "one 1" or 11.
	11 is read off as "two 1s" or 21.
	21 is read off as "one 2, then one 1" or 1211.
	Given an integer n, generate the nth sequence.

	Note: The sequence of integers will be represented as a string.
*/
class CountAndSay
{
public:
	string solution(int n)
	{
		if (n < 1)
		{
			return "";
		}
		else if (n == 1)
		{
			return "1";
		}

		string result;
		string ret;
		string temp;

		result.append("1");
		ret.append("1, ");

		for (int i = 2; i <= n; i++)
		{
			temp.clear();
			for (int j = 0; j < result.size(); j++)
			{
				temp.append(readTable[result[j] - '0']);
			}

			result.assign(temp);

			for (int j = 0; j < result.size(); j++)
			{
				ret.append(table[result[j] - '0']);
			}
			ret.append(", ");
		}

		return ret;
	}

	const int testCase = 5;
	
private:
	static const char * const table[];
	static const char * const readTable[];
};

const char * const CountAndSay::table[] = { "", "1", "11", "21", "1211" };
const char * const CountAndSay::readTable[] = { "", "2", "3", "131" };


class PerfectShuffle
{
public:
	void solution()
	{
		for (int i = 0; i < m_length; i++)
		{
			int temp = m_testCase[0];

			getNewPos(temp);

		}
	};

private:
	int getNewPos(int oldPos)
	{
		return (2 * oldPos) % (2 * m_length + 1);
	}

	static const int m_testCase[6];
	const int m_length = sizeof(m_testCase) / sizeof(int);
};

const int PerfectShuffle::m_testCase[] = {1, 2, 3, 4, 5, 6};


class Subsets
{
public:
	vector<vector<int> > solution()
	{
		vector<int> S = m_testCase;
		vector<vector<int> > result;
		vector<int> sub;     // sub : save very result(subset) into a vector
		int len = S.size();
		result.push_back(vector<int>(0)); // empty subset

		std::sort(S.begin(), S.end());
		helper(0, len, S, sub, result);
		return result;
	}

private:
	void helper(int start, int length, vector<int> &S, vector<int> &sub, vector<vector<int> > &result)
	{
		for (int i = start; i < length; ++i)
		{
			sub.push_back(S[i]);
			result.push_back(sub);
			helper(i + 1, length, S, sub, result);
			sub.pop_back();
		}
	}

	static vector<int> m_testCase;
	const int m_length = sizeof(m_testCase) / sizeof(int);
};

vector<int> Subsets::m_testCase = { 1, 2, 3 };

int _tmain(int argc, _TCHAR* argv[])
{
	//string result = longestCommonPrefix(gTestCase);
	//cout << "longestCommonPrefix = " << result << endl;

	/*
	vector<string> result = letterCombinations(testCase2);
	
	cout << "letterCombinations for "<< testCase2 << " = " << endl;
	cout << "[";
	for (int i = 0; i < result.size(); i++)
	{
		cout << '\"' << result.at(i) << "\", ";
	}

	cout << "]"<<endl;

	cout << "total = " << result.size()<<endl;
	*/


//	NumDecodings test;
//	cout << "NumDecodings = " << test.numDecodings(test.testCase) << endl;


//	CountAndSay test;
	//cout << "CountAndSay = " << test.solution(test.testCase) << endl;

	Subsets test;
	cout << "Subsets = ";
	vector<vector<int>> result = test.solution();
	cout << endl;



	return 0;
}

