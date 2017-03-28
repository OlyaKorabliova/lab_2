#include <iostream>
#include <math.h>
#include <assert.h>
//#include <mutex>
//#include <thread>

float func_calculation(int m, float x1, float x2)
{
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

float integration(float x0, float x, float y0, float y, int m, float pr)
{
    assert (m >= 5);
    float sum = 0;
    float x_i = x0;
    while (x_i < x)
    {
        float y_i = y0;
        while (y_i < y)
        {
            sum += func_calculation(m, x_i + pr / 2.0, y_i + pr / 2.0) * pow(pr, 2.0);
            y_i += pr;
        }
        x_i += pr;

    }
    std::cout << "Result: " << sum << std::endl;

    return sum;

}

int main()
{
    integration(0, 1, 0, 1, 5, 0.005);
    return 0;
}
