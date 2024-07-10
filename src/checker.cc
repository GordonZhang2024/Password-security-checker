#include "guard.h"

using std::string;

bool checkAvailability(string s)
{
	/*
	 * Check if the password is availible.
	 * The password is availible if it contains no space
	 */

	for (int i = 0; i < s.size(); ++i) {
		char currentLetter = s[i];

		if (currentLetter == ' ')
			// The password contains space. Thus, this password is not availible
			return false;
	}

	return true;
}


int checkSafety(string s)
{
	/*
	 * Check if the password is safe or almost safe.
	 */

	if (s.size() <= minPasswdLen)
		// minPasswdLen is defined in guard.h. It is 6 by default.
		return false;

	return true;
}


int getScore(string s)
{
	int score = 0;

	for (int i = 0; i < s.size(); ++i) {
		char currentLetter = s[i];

		if (isdigit(currentLetter))
			score += scoreOfNumber;
		else if (isalpha(currentLetter)) {
			int ascii = currentLetter;

			if (ascii <= 0x5A)  // Upper-case
				score += scoreOfUCaseLetter;
			else
				score += scoreOfLetter;
		} else
			score += scoreOfSpecialChar;
	}

	return score;
}


string check(string s)
{
	/*
	 * This is the main check function.
	 * It returns the safety information.
	 */

	if (!checkAvailability(s))
		return "This password contains spaces. It is not availible.";
	else if (!checkSafety(s))
		return "This password is too short (<= 6). It is not safe.";
	else {  // Safe. Show the safety score.
		char message[9999];
		int score = getScore(s);
		sprintf(message, "This password is safe. Score: %d", score);
		return message;
	}
}

