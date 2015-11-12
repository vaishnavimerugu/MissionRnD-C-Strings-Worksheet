/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
int mystrlen(char *s)
{
	int len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return len;
}
char KthIndexFromEnd(char *str, int K) 
{
	if (str == '\0' || str == "" || K < 0)
		return '\0';
	int len = mystrlen(str);
	if (K>len)
		return '\0';
	return str[len - K-1];
}