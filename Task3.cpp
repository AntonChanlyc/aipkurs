#include <stdio.h>

int main() {
    double d, vp, vb;
    printf(" Введите расстояние между автобусом и пассажиром в (м), скорость пассажира в (м/с), скорость автобуса в (м/с): ");
    scanf("%lf %lf %lf", &d, &vp, &vb);

    if (vp <= vb) {
        printf("Пассажир не догонит автобус.\n");
        return 0;
    }

    double t = 0.0, sp = 0.0, sb = d;
    while (sp < sb) {
        t += 0.01;
        sp = vp * t;
        sb = vb * t + d;
    }

    printf("Пассажир догонит автобус через %.2f секунд.\n", t);

    return 0;
}
