int prime_checker(int x)
{   
    int count = 0;
    for (int i = 2; i<=x/2; i++)
    {
        if (x % i == 0)
        {
            count++;
            break;
        }
    }
    if (count == 0)
    {
        return x;
    }
}