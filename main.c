#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double fa(double x);
double fb(double x);
double ln_n(double x, int N);
double ln_eps(double x, double eps);

int main() {
    setlocale(LC_CTYPE, "RUS");
    
    double x;
    puts("Введите x:");
    scanf("%lf", &x);
    printf("\nx =%.0lf", x);
    printf("\nfa(x)=%.4lf , fb(x)=%.4lf ", fa(x), fb(x));
    printf("\nПроизведение: %.4lf Разность квадратов:%.4lf Удвоенная сумма:%.4lf\n", fa(x) * fb(x), (fa(x) - fb(x)) * (fa(x) - fb(x)), (fa(x) + fb(x)) * 2);

    printf("\n==================================================\n");

    double x2;
    puts("\nВведите x (x > 0) для вычисления ln(x):");
    scanf("%lf", &x2);

    int N = 10;               
    double eps = 1e-5;        

    if (x2 <= 0) {
        printf("Ошибка: аргумент логарифма должен быть больше 0 (x > 0).\n");
        return 1;
    }

    printf("Вычисление ln(%.2f)\n", x2);
    printf("==================================================\n");

    double std_ln = log(x2);
    printf("1. Стандартная функция log(x): %.8f\n\n", std_ln);

    printf("2. Вычисление через ряд (ln_n):\n");
    printf("  N  |    ln_N     |   отклонение (эталон - ln_N)\n");
    printf("---------------------------------------------------\n");
    
    for (int i = 1; i <= N; i++) {
        double current_ln = ln_n(x2, i);
        printf("%3d  |  %.6f   |  %+e\n", i, current_ln, std_ln - current_ln);
    }
    printf("\n");

    printf("3. Вычисление с заданной точностью (ln_eps, eps = %e):\n", eps);
    double eps_ln = ln_eps(x2, eps);
    printf("ln_eps(%.2f, %e) = %.8f\n", x2, eps, eps_ln);
    printf("Отклонение от стандартной функции: %+e\n", std_ln - eps_ln);

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

double ln_n(double x, int N) {
    double y = (x - 1.0) / (x + 1.0);
    double y2 = y * y;
    double term = y;  
    double sum = 0.0;
    
    for (int n = 0; n < N; ++n) {
        sum += term;
        term *= y2 * (2.0 * n + 1.0) / (2.0 * n + 3.0);
    }
    
    return 2.0 * sum;
}

double ln_eps(double x, double eps) {
    double y = (x - 1.0) / (x + 1.0);
    double y2 = y * y;
    double term = y;
    double sum = 0.0;
    int n = 0;
    
    while (fabs(2.0 * term) > eps) {
        sum += term;
        term *= y2 * (2.0 * n + 1.0) / (2.0 * n + 3.0);
        n++;
    }
    
    return 2.0 * sum;
}
