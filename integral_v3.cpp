#include <iostream>
#include <math.h>
#include <assert.h>
#include <mutex>
#include <thread>
using namespace std;

mutex mx;

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
    mx.lock();
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
    mx.unlock();
    std::cout << "Result: " << sum << std::endl;

    return sum;

}

int main()
{
    int num_of_threads;
    std::cout << "Please enter the number of threads: " << std::endl;
    std::cin >> num_of_threads;

    thread threads[num_of_threads];
    // choose random numbers   --   later: read from configuration file
    float x0 = 0;
    float x = 1;
    float y0 = 0;
    float y = 1;
    int m = 5;
    float pr = 0.05;

    float x_step = (x - x0) / (pr * num_of_threads);
    float x_start = x0;
//    float x_end = x_start + x_step;

    float y_step = (y - y0) / (pr * num_of_threads);
    float y_start = y0;
//    float y_end = y_start + y_step;


    for (int i = 0; i < num_of_threads; ++i)
    {
        threads[i] = thread(integration, x_start, x_start + x_step, y_start, y_start + y_step, m, pr);
        x_start += x_step + 1;
        y_start += y_step + 1;
    }
    for (int i = 0; i < num_of_threads; ++i)
    {
        threads[i].join();
    }

    std::cout << "----------------\n";
    integration(0, 1, 0, 1, 5, 0.05);

    return 0;
}
