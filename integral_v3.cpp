#include <iostream>
#include <math.h>
#include <assert.h>

float func_calculation(int m, float x1, float x2)
{
//    assert (m >= 5);
    float sum1 = 0;
    float sum2 = 0;
    float g;

    for (int i = 1; i <= m; ++i)
    {
        sum1 += i * cos((i + 1) * x1 + 1);
        sum2 += i * cos((i + 1) * x2 + 1);
    }

    g = - sum1 * sum2;
    std::cout << "Result for f(" << x1 << ", " << x2 << ") and m=" << m << " : " << g << std::endl;
    return g;
}

float integration(int n, int m, float a, float b)
{
    assert (m >= 5);
    float sum = 0;
    for (int i = 0; i < n; ++i)
    {
        float x1 = a + (b - a) * i / n;
        float x2 = a + (b - a) * (i + 1) / n;
        sum += func_calculation(m, x1, x2);
    }
    std::cout << "Result: " << sum << std::endl;

    return sum;

}

int main()
{
    integration(100, 5, 1, 5);
    return 0;
}
