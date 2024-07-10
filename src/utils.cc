#include "guard.h"
#include "utils.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

vector<string> split(string &s, const char *splitBy)
{
	vector<string> parts;

	string currentString = "";

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == *splitBy) {
			parts.push_back(currentString);
			currentString = "";
		} else {
			currentString = currentString + s[i];
		}
	}
	parts.push_back(currentString);

	return parts;
}


void showProjectInfo()
{	// Show the project information.
	cout << "Password-security-guard v" << VERSION << " | " << DESCRIPTION << endl;
	cout << "This is a software with ABSOLUTELY NO WARRANTY." << endl;
}

