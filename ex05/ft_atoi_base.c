#include <stdio.h>
int is_valid_base(char *base)
	{
        if(base[0] == '\0' || base[1] == '\0')
        {
            return (0);
        }
        int i = 0;

        while(base[i] != '\0')
        {
            if(base[i] == '+' || base[i] == '-' || base[i] == ' '|| base[i] == '\t'
			|| base[i] == '\n'|| base[i] == '\v'|| base[i] == '\f'|| base[i] == '\r')
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

int	get_char_index(char c, char *base)
{
	int i = 0;
	
	while(base[i] != '\0')
	{
		if(base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str,char *base)
{
	if(is_valid_base(base) == 0)
	{
		return (0);
	}
	int base_len = 0;
	int i = 0;

	while(base[i] != '\0')
	{
		base_len++;
		i++;
	}
	i = 0;
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
    while(get_char_index(str[i], base) != -1)
    {
        result = (result * base_len) + get_char_index(str[i], base);
        i++;
    }
    return (result * sign);
}

int main(void)
{
    // ฐาน 10 ปกติ มีช่องว่างและเครื่องหมายนำหน้า (คาดหวัง: -456)
    printf("Base 10: %d\n", ft_atoi_base(" \t\n -456", "0123456789")); 
    
    // ฐาน 2 (101010 ในฐานสอง คือ 42) (คาดหวัง: 42)
    printf("Base 2 : %d\n", ft_atoi_base("101010", "01")); 
    
    // ฐาน 16 มีเครื่องหมายลบ 3 ตัว = ติดลบ (คาดหวัง: -42)
    printf("Base 16: %d\n", ft_atoi_base("   ---+2A", "0123456789ABCDEF")); 
    
    // ฐาน 8 แบบ Custom ตัว y อยู่ตำแหน่งที่ 4 (คาดหวัง: 4)
    printf("Base 8 (poneyvif): %d\n", ft_atoi_base("y", "poneyvif")); 
	//return 0
    printf("Empty Base: %d\n", ft_atoi_base("42", ""));
    printf("Size 1 Base: %d\n", ft_atoi_base("42", "0"));
    printf("Duplicate Base: %d\n", ft_atoi_base("42", "012340"));
    printf("Base with '+': %d\n", ft_atoi_base("42", "012+4"));
    printf("Base with Space: %d\n", ft_atoi_base("42", "012 4"));

    // เจอตัว z ต้องหยุด แปลงแค่ 42 (คาดหวัง: 42)
    printf("Stop at 'z': %d\n", ft_atoi_base("42z12", "0123456789")); 
    
    // เจอช่องว่างตรงกลางต้องหยุด แปลงแค่ 101 ในฐานสอง (คาดหวัง: 5)
    printf("Stop at space: %d\n", ft_atoi_base("101 01", "01")); 
//พฤติกรรมดั้งเดิมของ atoi คือ "อ่านตัวเลขไปเรื่อยๆ และจะหยุดทันทีที่เจอตัวอักษรแปลกปลอม (ตัวที่ไม่ใช่ตัวเลขในฐานนั้น)"
    return (0);
}