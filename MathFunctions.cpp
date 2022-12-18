//
// Created by Ayushi Saha on 18-12-2022.
//

#include "MathFunctions.h"

//Calculates n! using recursion.
uint32_t factorial(uint32_t n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// Calculates nPk: n!/(n-k)!.
uint32_t pick(uint32_t n, uint32_t k)
{
    return factorial(n) / factorial(n - k);
}

//Calculates nCk: n!/((n-k)!*k!).
uint32_t choose(uint32_t n, uint32_t k)
{
    return (n < k)
           ? 0
           : factorial(n) / (factorial(n - k) * factorial(k));
}