#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::to_string;

string ParseMathString(const string& s1, const string& s2);

vector<string> SplitString(const string& str, char delimiter);

/// <summary>
/// Возвращает длину подстроки в строке <paramref name="str"/>, 
/// начиная с индекса <paramref name="startIndex"/> и до первого попавшегося
/// символа <paramref name="lastChar"/>.
/// </summary>
size_t GetSubstringLength(const string& str, size_t startIndex, char lastChar);