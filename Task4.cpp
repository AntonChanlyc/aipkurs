#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Проверяет, успела ли Алина добежать до края плиты за время t при скорости u
bool canEsc(double L, double v, double tau, double t, double u) {
    double pos = 0.0;  // Позиция Алины относительно начала плиты
    double time_pas = 0.0;
    double dt = 0.001;  // Маленький шаг времени для точности

    while (time_pas < t && pos < L) {
        double curr_u = (time_pas < tau) ? 0.75 * u : u;  // Замедление в первые tau секунд
        pos += (curr_u - v) * dt;  // Движение относительно земли
        time_pas += dt;
    }

    return pos >= L;  // Успела ли добежать?
}

// Бинарный поиск минимальной скорости u
double minSpeed(double L, double v, double tau, double t) {
    double low = 0.0;
    double high = 1e6;  // Достаточно большая начальная скорость

    for (int i = 0; i < 100; ++i) {  // Итерации для точности
        double mid = (low + high) / 2;
        if (canEsc(L, v, tau, t, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main() {
    double L, v, tau, t;

    cout << "Введите длину плиты L (м): ";
    cin >> L;

    cout << "Введите скорость плиты v (м/с): ";
    cin >> v;

    cout << "Введите время замедления tau (с): ";
    cin >> tau;

    cout << "Введите общее время движения t (с): ";
    cin >> t;

    if (t <= 0.25 * tau) {
        cerr << "Ошибка: Время t должно быть больше 0.25 * tau!" << endl;
        return 1;
    }

    double u = minSpeed(L, v, tau, t);
    cout << fixed << setprecision(6);
    cout << "Исходная скорость Алины относительно плиты u = " << u << " м/с" << endl;

    return 0;
}