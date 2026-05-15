#include <stdio.h>
#include <unistd.h>
int is_valid_base(char *base)
    {
        if(base[0] == '\0' || base[1] == '\0')
        {
            return (0);
        }
        int i = 0;

        while(base[i] != '\0')
        {
            if(base[i] == '+' || base[i] == '-')
            {
                return (0);
            }
            int j = i + 1;

            while(base[j] != '\0')
            {
                if(base[i] == base[j])
                {
                    return (0);
                }
            j++;
            }
            i++;
        }
        return (1);
    }

void ft_putnbr_base(int nbr, char *base)
{
    if(is_valid_base(base) == 0)
    {
        return;
    }
    int len_base = 0;
    char c;
    long int n;
    n = nbr;

    int i = 0;
    while(base[i] != '\0')
    {
        len_base++;
        i++;    
    }
    if(n < 0)
    {
        write(1, "-",1);
        n = -n;
    }
    if(n >= len_base)
    {
        ft_putnbr_base((n / len_base), base);
    }
    c = base[n % len_base];
    write(1, &c, 1);
}

int main(void)
{
    ft_putnbr_base(42, "0123456789");
    printf("\n");
    ft_putnbr_base(-2147483648, "0123456789");
    printf("\n");
    ft_putnbr_base(42, "01");
    printf("\n");
    ft_putnbr_base(-42, "01");
    printf("\n");
    ft_putnbr_base(255, "0123456789ABCDEF");
    printf("\n");
    ft_putnbr_base(42, "poneyvif");
    printf("\n");
    ft_putnbr_base(42, "");
    printf("\n");
    ft_putnbr_base(42, "1");
    printf("\n");
    ft_putnbr_base(42, "012-45");
    printf("\n");
    ft_putnbr_base(42, "012340");
    printf("\n");
}