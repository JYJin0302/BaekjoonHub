// test
#include <iostream>
#include <memory.h>

bool g_arrPrime[1000001];

bool Solve(int n)
{
    for (int i = n - 3; i > 2; i -= 2) {
        if (g_arrPrime[i] == true && g_arrPrime[n - i] == true) {
            std::cout << n << " = " << n - i << " + " << i << "\n";
            return true;
        }
    }

    std::cout << "Goldbach's conjecture is wrong.";
    return false;
}

int main()
{

    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int n = 0;

    // 1000000이하의 자연수
    memset(g_arrPrime, true, sizeof(g_arrPrime));
    g_arrPrime[1] = false;
    g_arrPrime[2] = true;

    // 에라토스테네스의 체
    for (int i = 2; i * i < 1000001; ++i) {
        if (g_arrPrime[i] == false)
            continue;

        for (int j = i + i; j < 1000001; j += i)
            g_arrPrime[j] = false;
    }

    while (true) {
        std::cin >> n;
        if (n == 0)
            break;

        Solve(n);
    }

    return 0;
}
