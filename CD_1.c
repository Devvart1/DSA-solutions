#include<stdio.h>
#include<iostream>

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char str[] = "aab";
	int i = 0;
	int state = 0;
	while (str[i] != '\0')
	{

		if (str[i] == 'a')
		{
			state = 0;

		}
		else if (str[i] == 'b')
			state = 1;

	}

	if (state = 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}