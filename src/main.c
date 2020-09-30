#include <stdio.h>
#include <math.h>
#include <string.h>
const PI = 3.14159;

char answer[6][25];
double a, b;

double rectangle_methode(int n) {
    double x, h, integral = 0;
    h = (b - a) / n;
    x = a;
    for (int i = 0; i < n; i++) {
        integral += sin(x + h / 2) * h;
        x += h;
    }
    return integral;
}

double simpsons_methode(int n) {
    double x, h, integral;
    h = (b - a) / 2 / n;
    integral = sin(a) + sin(b);
    x = a + h;
    for (int i = 1; i < 2 * n; i++) {
        if (i % 2 == 0) integral += 2 * sin(x);
        else integral += 4 * sin(x);
        x += h;
    }
    integral *= h / 3;
    return integral;
}

void view(int a[6]) {
    char intermediate_line[15];
    for (int i = 0; i < 6; i++) {
        int j = 0;
        double integral_rectangle, integral_simpson;
        integral_rectangle = rectangle_methode(a[i]);
        integral_simpson = simpsons_methode(a[i]);
        sprintf(intermediate_line, "%d", a[i]);
        strcat(answer[i], intermediate_line);
        strcat(answer[i], " ");
        sprintf(intermediate_line, "%2.5f", integral_rectangle);
        strcat(answer[i], intermediate_line);
        strcat(answer[i], " ");
        sprintf(intermediate_line, "%2.5f", integral_simpson);
        strcat(answer[i], intermediate_line);
    }
}

void entering_numbers() {
    printf("Enter interval's left border:");
    while (!(scanf("%lf", &a))) {
        printf("Error! Enter again: ");
        while (getchar() != '\n');
    }
    printf("Enter interval's right border:");
    while (!(scanf("%lf", &b))) {
        printf("Error! Enter again: ");
        while (getchar() != '\n');
    }
}

int main() {
    int number_of_segments[] = {5, 10, 20, 100, 500, 1000};
    entering_numbers();
    view(number_of_segments);
    for (int i = 0; i < 6; i++) {
        printf("%s\n", answer[i]);
    }
    return 0;
}
