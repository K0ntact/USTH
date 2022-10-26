int GCD(int n, int m)
{
    int biggest;
    if (n>m)
    {
        for (int i = 1; i<=m; i++)
        {
            if (n%i == 0 && m%i == 0)
                biggest = i; 
        }
    }
    else if (m>n)
    {
        for (int i = 1; i<=n; i++)
        {
            if (n%i == 0 && m%i == 0)
                biggest = i; 
        }
    }
    return biggest;
}