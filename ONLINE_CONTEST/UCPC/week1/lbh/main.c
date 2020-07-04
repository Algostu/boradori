#include <stdio.h>

int main()
{
	int n, k, p, w;
	int maxim;

	scanf_s("%d%d%d%d", &n, &k, &p, &w);
	maxim = (p / w) + 1;
	
	printf("%d", maxim);

	return 0;
}d