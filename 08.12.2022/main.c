#include <stdio.h>
#include <limits.h>

#define PRINT_TYPE_SPCIFICATIONS(X, T, TU, SM, SMIN, UM) printf("%-20s %-20s %-20tu %-20"#T"%-20"#T" %-20s %-10"#TU" \n", #X, "%"#T, sizeof(X), SM, SMIN, "%"#TU, UM);

int main()
{
    PRINT_TYPE_SPCIFICATIONS(int, d, u, INT_MAX, INT_MIN, UINT_MAX);
    PRINT_TYPE_SPCIFICATIONS(short, hd, hu, SHRT_MAX, SHRT_MIN, USHRT_MAX);
    PRINT_TYPE_SPCIFICATIONS(long, ld, lu, LONG_MAX, LONG_MIN, ULONG_MAX);
    PRINT_TYPE_SPCIFICATIONS(long long, lld, llu, LLONG_MAX, LLONG_MIN, ULLONG_MAX);
    return 0;
}