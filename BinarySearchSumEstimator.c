#include <stdio.h>
#include <math.h>

long long calculateSum(long long n) {
    return (long long)n * (n + 1) * (2 * n + 1) / 6;
}

long long binarySearch(long long M) {
    long long low = 1, result = -1;
    long long high = (long long)cbrtl(6.0 * M);

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sum = calculateSum(mid);

        if (sum >= M) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    long long T;
    scanf("%lld", &T);
	
	long long caseNumber;
    for (caseNumber = 1; caseNumber <= T; ++caseNumber) {
        long long M;
        scanf("%lld", &M);

        long long N = binarySearch(M);

        printf("Case #%lld: %lld\n", caseNumber, N);
    }

    return 0;
}

