#include <cstdio>

int absolute_value(int x)
{
	return (x >= 0) ? x : -x;
}

int sum(int a, int b){
	return a + b;
}

int main(int argc, char *argv[])
{
	int value = -12;
	int a = 12, b = 13;
	printf("|%d| = %d\n", value, absolute_value(value));
	
	printf("%d + %d = %d\n", a, b, sum(a,b));
	return 0;
}