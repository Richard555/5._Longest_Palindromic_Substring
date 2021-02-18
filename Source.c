#include <stdio.h>

int expandAroundCenter(char* s, int i, int j)
{
	int len = 0;
	int k = 0;
	if (i == j) //odd
	{
		len = 1;
		for (k = 1;; k++) {
			if ((i - k) < 0 || s[i + k] == '\0') {  //Check if i-k, i+k go out of the string range.
				break;
			}
			else		//Both left and right chars are inside the string
			{
				if (s[i - k] == s[i + k]) {  //If both chars are equal
					len = len + 2;
				}
				else {	//Two chars are not equal
					break;
				}
			}
		}
	}
	else { //Even
		len = 0;
		for (k = 0;; k++) {
			if (s[j] == '\0' || (i - k) < 0 || s[i + k] == '\0') {  //Check if s[j]==0, i-k, i+k go out of the string range.
				break;
			}
			else	//Both left(i) and right(j) are legal characters
			{
				if (s[i-k] == s[j+k]) {
					len = len + 2;	//Both chars are equal
				}
				else {
					break;			//Not equal
				}
			}
		}
	}
	return len;
}

char* longestPalindrome(char* s)
{
	int i = 0;
	int Maxlen = 0;
	int strcp = 0;
	int subStart = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
			int len_odd = 0, len_even = 0;
			len_odd = expandAroundCenter(s, i, i);
			len_even = expandAroundCenter(s, i, i + 1);

			if (len_odd > len_even)
			{
				if (len_odd > Maxlen)
				{
					Maxlen = len_odd;
					strcp = 1;
					subStart = i - len_odd / 2;
				}
			}
			else // odd < even
			{
				if (len_even > Maxlen)
				{
					Maxlen = len_even;
					strcp = 1;
					subStart = i - (len_even / 2 - 1);
				}
			}
	}

	char* dest = (char*)calloc(Maxlen + 1, sizeof(char));
	strncpy(dest, &s[subStart], Maxlen);

	return dest;
}


void main(void)
{
	char* pStringRet;
	char* Src = "babad";
	char* Src2 = "cbbd";
	char* Src3 = "a";
	char* Src4 = "ac";

	pStringRet = longestPalindrome(Src);
	printf("%s\n",pStringRet );
	pStringRet = longestPalindrome(Src2);
	printf("%s\n", pStringRet);
	pStringRet = longestPalindrome(Src3);
	printf("%s\n", pStringRet);
	pStringRet = longestPalindrome(Src4);
	printf("%s\n", pStringRet);

}