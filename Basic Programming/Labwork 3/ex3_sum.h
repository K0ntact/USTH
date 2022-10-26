float sum(float n)
{
    if (n == 1)
        return 1;
    else
        return 1/n + sum(n-1);
         
}