#include <stdio.h>
#include <math.h>

int main() {
    double L, v, t, u, pos = 0;
    int steps = 0;
    
    // Ввод данных
    printf("Введите длину конвейера в метрах, скорость конвейера в м/с и время в секундах: ");
    scanf("%lf %lf %lf", &L, &v, &t);
    
    if (t <= 0 || L<=0 || v <= 0 )  {
        printf("Ошибка: Переменные должны быть больше нуля.\n");
        return 1;
    }
    
    
    for (u = 0.01; u < 100; u += 0.01) {
        pos = 0;
        steps = 0;
        while (steps < t) {
            pos += u;  
            pos -= v;        
            steps++;
            if (pos >= L) break; 
        }
        if (pos >= L) break; 
    }
    
    printf("Скорость робота относительно ленты: %.2f м/с\n", u);
    
    return 0;
}
