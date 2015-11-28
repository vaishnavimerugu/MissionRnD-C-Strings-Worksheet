/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
char * mystrtok(char *s, char delim)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == delim)
		{
			return &s[++i];
		}
		else
			i++;
	}
	return NULL;
}
char ** commonWords(char *str1, char *str2)
{
	if (str1 == NULL&&str2 == NULL)
		return NULL;
	char *pos1; pos1 = str1;
	int j = 0;
	char **result = (char **)malloc(10 * sizeof(char *));
	while (pos1 != NULL)
	{
		char *pos2; pos2 = str2;
		while (pos2 != NULL)
		{
			char *temp1, *temp2;
			temp1 = pos1; temp2 = pos2;
			int count = 0, flag = 1;
			while (*temp1 != ' ' && *temp2 != ' ')
			{
				if (*temp1 != *temp2)
				{
					flag = 0;
					break;
				}
				temp1++;
				temp2++;
				count++;
			}
			if (count > 0 && flag)
			{
				char *temp;
				temp = pos1; int k = 0;
				result[j] = (char *)malloc(31 * sizeof(char));
				while (count > 0)
				{
					result[j][k] = *temp;
					k++;
					temp++;
					count--;
				}
				result[j++][k] = '\0';

			}
			pos2 = mystrtok(pos2, ' ');
		}
		pos1 = mystrtok(pos1, ' ');
	}
	if (j == 0)
		return NULL;
	else
		return result;
}