/*
Copyright (c) 2024, Gordon Zhang

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

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


bool checkSafety(string s)
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
		return "This password contains spaces. It is not availible.\n\
Perhaps you need to remove them.";
	else if (!checkSafety(s))
		return "This password is too short (<= 6). It is not safe.\n\
Perhaps you need to add more characters.";
	else {  // Safe. Show the safety score.
		char message[9999];
		int score = getScore(s);
		sprintf(message, "This password is safe. Score: %d of 100", score);
		return message;
	}
}

