/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void mystrrev(char *str, int start, int end)
{
	int i, j = end - start;
	end--;
	for (i = 0; i<j / 2; i++)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
void str_words_in_rev(char *input, int len)
{
	mystrrev(input, 0, len);
	int j = 0, i;
	for (i = 0; i <= len; i++)
	{
		if (input[i] == ' ' || input[i] == '\0')
		{
			mystrrev(input, j, i);
			j = i + 1;
		}
	}
}