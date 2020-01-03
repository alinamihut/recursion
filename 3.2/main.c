#include <stdio.h>
double calculateRecursively (int n, double x);
double calculateNonRecursively( int n, double x);

int main() {

    return 0;
}
double calculateRecursively (int n, double x)
{
    if (n==0) return 1;
    else if (n==1) return 2* x;
    else return 2 * n * calculateRecursively(n-1,x) + 2* (n-1) * calculateRecursively (n-2,x);
}
double calculateNonRecursively( int n, double x)
{
    double a,b,c;
    int i;
    if (n==0) return 1;
    else if (n==1) return 2*x;
    else {
        a=1;
        b=2*x;
        for (i=2;i<n;i++)
        {

        }
    }

}

