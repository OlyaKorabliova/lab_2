#include <iostream>
#include <math.h>
#include <assert.h>

float calculation(int m, float x1, float x2)
{
    assert (m >= 5);
    float sum1 = 0;
    float sum2 = 0;
    float g;

    for (int i = 1; i <= m; ++i)
    {
        sum1 += i * cos((i + 1) * x1 + 1);
        sum2 += i * cos((i + 1) * x2 + 1);
    }

    g = - sum1 * sum2;
    std::cout << "Result for f(" << x1 << ", " << x2 << ") and m=" << m << " : " << g << "\n";
    return g;
}

/*int main()
{
    calculation(5,1,2);
    return 0;
}*/

