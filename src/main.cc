#include "guard.h"
#include "utils.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	showProjectInfo();


	string password;
	cout << "Enter your password: ";
	cin >> password;

	cout << check(password) << endl;

	return 0;
}
