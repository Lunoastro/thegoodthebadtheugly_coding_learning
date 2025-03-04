#include <stdio.h>

void sequence(int n)
{
	printf("%d ", n);
	if (n != 1)
	{
		int tem;
		if (n % 2 == 0)
		{
			tem = n / 2;
		}
		else
		{
			tem = (3 * n) + 1;
		}
		sequence(tem);
	}
}

int main()
{
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	sequence(n);
	return 0;
}
