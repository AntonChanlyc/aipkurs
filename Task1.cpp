#include <stdio.h>
int main() {
    double v1, v2, d;
    printf("Введите скорость первого дрона в (м/с), второго дрона в (м/с), задержку старта второго в (с): ");
    scanf("%lf %lf %lf", &v1, &v2, &d);

    if (v2 <= v1) {
        printf("Второй дрон не догонит первый.\n");
        return 0;
    }

    double t = 0.0, s1 = v1 * d, s2 = 0.0;
    while (s2 < s1) {
        t += 0.01;
        s1 = v1 * (t + d);
        s2 = v2 * t;
    }

    printf("Время до перехвата: %.2f с\n", t);
    printf("Расстояние до перехвата: %.2f м\n", s2);

    return 0;
}