#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate the sum of digits of an integer
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Custom comparator to sort according to the problem's requirements
bool customComparator(int a, int b) {
    int sumA = sumOfDigits(a);
    int sumB = sumOfDigits(b);
    
    if (sumA == sumB) {
        return a < b;
    } else {
        return sumA < sumB;
    }
}

int main() {
    int k;
    std::cin >> k;

    while (k--) {
        int n;
        std::cin >> n;
        std::vector<int> numbers(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> numbers[i];
        }

        std::sort(numbers.begin(), numbers.end(), customComparator);

        for (int i = 0; i < n; ++i) {
            if (i > 0) std::cout << " ";
            std::cout << numbers[i];
        }
        std::cout << std::endl;
    }

    return 0;
}

