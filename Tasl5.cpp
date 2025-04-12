#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double A = 1.0;   
const double omega = 0.5; 
const double B = 0.1;    

double h_derivative(double x) {
    return A * omega * cos(omega * x) + B;
}

double calculateDistance(double v0, double mu, double dt = 0.001) {
    const double g = 9.81; 
    double x = 0.0;         
    double v = v0;          
    double t = 0.0;         

    while (v > 0) {
        double theta = atan(h_derivative(x));  
        double F_friction = mu * g * cos(theta);
        double a = -F_friction - g * sin(theta);  

        v += a * dt;  
        x += v * dt;  
        t += dt;
    }

    return x;
}

int main() {
    double v0, mu;

    cout << "Введите начальную скорость v0 (м/с): ";
    cin >> v0;

    cout << "Введите коэффициент трения mu: ";
    cin >> mu;

    double L = calculateDistance(v0, mu);
    cout << fixed << setprecision(3);
    cout << "Тело остановится на расстоянии L = " << L << " м" << endl;

    return 0;
}