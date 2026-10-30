#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double fa(double x);
double fb(double x);

int main() {
    setlocale(LC_CTYPE, "RUS");
    double x;
    puts("Введите x:");
    scanf("%lf", &x);
    printf("\nx =%.0lf", x);
    printf("\nfa(x)=%.4lf , fb(x)=%.4lf ", fa(x), fb(x));
    printf("\nПроизведение: %.4lf Разность квадратов:%.4lf Удвоенная сумма:%.4lf", fa(x) * fb(x), (fa(x) - fb(x)) * (fa(x) - fb(x)),(fa(x)+fb(x))*2);
    return 0;
}

double fa(double x) {
    double y;
    if (x <= 3) {
        y = x * x - 3 * x + 9;
    }
    else {
        y = 1.0 / (x * x * x + 3);
    }
    return y;
}

double fb(double x) {
    double y;
    y = x * exp(sin(x * x));
    return y;
}
