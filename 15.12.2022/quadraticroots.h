#ifndef QR
#define QR

typedef struct {
    double x1;
    double x2;
    char norealroots;
}QuadraticRootsResult;

QuadraticRootsResult findroots(double a, double b, double c);

#endif