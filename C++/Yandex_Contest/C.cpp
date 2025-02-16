#include <iostream>

const int MOD = 1000000007;

// Функция для быстрого возведения в степень по модулю
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // Если exp нечетное
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Удваиваем основание
        exp /= 2; // Делим степень на 2
    }
    return result;
}

int main() {
    int n = 5000; // Количество вершин

    // Количество пар среди оставшихся (n-1) вершин
    long long pairs = (long long)(n - 1) * (n - 2) / 2;

    // Количество красивых графов на n вершинах
    long long beautifulGraphs = (n * mod_exp(2, pairs, MOD)) % MOD;

    std::cout << beautifulGraphs << std::endl; // Выводим результат
    return 0;
}
