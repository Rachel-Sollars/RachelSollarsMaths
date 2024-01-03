#include "RuntimeTest.h"
#include "RSMaths.h"
#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include <math.h>
auto funcCalls = 1000 * 1000;
auto averageOf = 5;

auto GetTime(int index) {
    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();

    float pos1[]{ 0, 0 };
    float pos2[]{ 3, 3 };
    bool val;
    // replace with function to check
    for (int i = 0; i < funcCalls; i++) {
        val = RSMaths::CloserThanOrEqualTo(pos1, pos2, i);
    }

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    // prints time for user
    if (index < 10)
        std::cout << "Run " << index << " : " << elapsed.count() * 1e-9 << " seconds.\n";
    else
        std::cout << "Run " << index << ": " << elapsed.count() * 1e-9 << " seconds.\n";

    return elapsed;
}

int main() {

    // gets the time "averageOf" number of times and adds them together
    auto x = GetTime(1);
    for (int i = 0; i < averageOf - 1; i++) {
        x += GetTime(i + 2);
    }

    // divides by number of times run to get mean average
    x /= averageOf;

    // prints final average for user
    printf("Final average: %.8f seconds.\n", x.count() * 1e-9);

    return 0;
}