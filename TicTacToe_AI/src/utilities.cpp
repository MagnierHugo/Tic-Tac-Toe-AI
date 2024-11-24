#include <string>
#include <algorithm>
#include <cctype>


void Str_ToLower(std::string& str) {
	std::transform(
		str.begin(), str.end(), str.begin(),
		[](unsigned char c) { return std::tolower(c); }
	);
}


std::string Str_GetLower(std::string str) {
	std::transform(
		str.begin(), str.end(), str.begin(),
		[](unsigned char c) { return std::tolower(c); }
	);
	return str;
}