#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countPalindromes(int cnt, char **a)
{
    char freq[26];
    memset(freq, 26, 0);
    int tot = 0;
    int ec = 0, oc = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (strlen(a[i]) % 2 == 0)
        {
            ec++;
        }
        else
        {
            oc++;
        }
    }
    int epcnt = ec;
    int opcnt = oc;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < strlen(a[i]); j++)
        {
            freq[(int)(a[i][j] - 'a')]++;
        }
    }

    ec = 0;
    oc = 0;
    int total = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 0)
        {
            ec++;
            total += (freq[i]);
        }
        else
        {
            total += (freq[i] / 2) * 2;
            oc++;
        }
    }
}

int main()
{

    return 0;
}