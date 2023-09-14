#include "CppStrings.h"

int main()
{
	string s1 = "456 - 433 = ?; 12 - 3 = ?; 8767 - 686 = ?; -453 - 3 = ?;";
	string s2 = "456,433,12,3,8767,686,-453,3";
	cout << ParseMathString(s1, s2) << '\n';

	string s3 = "a1,bb2,ccc3,dddd4,eeeee5,ffffff6,ggggggg7,hhhhhhhh8,iiiiiiiii9,jjjjjjjjjj10";

	auto substrings = SplitString(s3, ',');
	for (auto& substring : substrings)
	{
		cout << substring << '\n';
	}

	system("pause");
}

string ParseMathString(const string& s1, const string& s2)
{
	auto strNumbers = SplitString(s2, ',');
	string result = s1;
	size_t searchOffset = 0;

	for (size_t i = 0; i < strNumbers.size(); i += 2)
	{
		int firstOperand = stoi(strNumbers[i]);
		int secondOperand = stoi(strNumbers[i + 1]);

		size_t questionMarkIndex = result.find('?', searchOffset);

		result.replace(questionMarkIndex, 1, to_string(firstOperand - secondOperand));

		searchOffset = questionMarkIndex + 1;
	}

	return result;
}

vector<string> SplitString(const string& str, char separator)
{
	vector<string> result;

	for (size_t i = 0; i < str.length(); )
	{
		size_t substrLength = GetSubstringLength(str, i, separator);

		result.push_back(str.substr(i, substrLength));

		i += substrLength + 1;
	}

	return result;
}

size_t GetSubstringLength(const string& str, size_t startIndex, char lastChar)
{
	size_t substrLength = 0;
	size_t j = startIndex;

	while (str[j] != lastChar && str[j] != str.length())
	{
		if (j == str.length())
		{
			break;
		}

		substrLength++;
		j++;
	}

	return substrLength;
}