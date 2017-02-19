#include <stdio.h>

void sort(int a[], int left, int right)
{
	if (right <= left)
		return;

	int i = left;
	int j = right;
	int temp = a[i];

	while( i<j )
	{
		while (i<j && temp <= a[j])
			j--;

		a[i] = a[j];

		while (i<j && a[i] <= temp)
			i++;

		a[j] = a[i];
	}
	a[i] = temp;

	sort(a, left, i-1);
	sort(a, i+1, right);
}

int main()
{
	int a[] = {2,5,7,1,-1,999,-999,144,-2};
	int len = sizeof(a)/sizeof(int);

	sort(a, 0, len-1); // 升序

	int i = 0;
	for (i = 0; i<len; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
