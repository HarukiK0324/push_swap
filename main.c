#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int main()
{
    printf("%d",ft_strcmp("2137483648","2147483648"));
    return 0;
}