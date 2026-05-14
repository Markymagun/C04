#include <stdio.h>
int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while(str[i] == ' '|| str[i] == '\t'|| str[i] == '\n'|| str[i] == '\v'|| str[i] == '\f'|| str[i] == '\r')
    {
        i++;
    }
    while(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            sign = sign * -1;
        }
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

int main(void)
{
    char *c1 = "42";
    printf("Case 1: %d\n\n", ft_atoi(c1));

    char *c2 = "-42";
    printf("Case 2: %d\n\n", ft_atoi(c2));

    char *c3 = " \t\n \r\v\f  42";
    printf("Case 3: %d\n\n", ft_atoi(c3));

    char *c4 = "---+--+1234ab567";
    printf("Case 4: %d\n\n", ft_atoi(c4));

    char *c5 = "42Bangkok";
    printf("Case 5: %d\n\n", ft_atoi(c5));

    char *c6 = "   ++--  ";
    printf("Case 6: %d\n\n", ft_atoi(c6));
}