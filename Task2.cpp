#include <stdio.h>
int main() {
    double L, v1, v2;
    printf(" Введите длину тоннеля в (м), скорость первого поезда в (м/с), второго поезда в (м/с): ");
    scanf("%lf %lf %lf", &L, &v1, &v2);

    double t = 0.0, s1 = 0.0, s2 = 0.0;
    while ((s1 + s2) < L) {
        t += 0.01;
        s1 = v1 * t;
        s2 = v2 * t;
    }

    printf("Время до встречи поездов: %.2f с\n", t);

    return 0;
}