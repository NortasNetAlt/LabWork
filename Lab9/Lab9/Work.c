#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define ROW 4
#define COL 10

int check(double x, double y);
int check1(double x, double y);
int draw();
int task1();
int task2lab9();

int main() {
    setlocale(LC_CTYPE, "RUS");
    char command;
    int running = 1;

    while (running) {
        printf("d - нарисовать область\n");
        printf("p - проверить координаты точки (x, y)\n");
        printf("n - закрыть программу\n");
        printf("Выберите действие: ");
        if (scanf(" %c", &command) != 1) {
            continue;
        }

        switch (command) {
        case 'd':
            draw();
            break;
        case 'p':
            task1();
            break;
        case 'n':
            printf("\nЗавершение работы программы...\n");
            running = 0;
            break;
        default:
            printf("Неверная команда! Попробуйте еще раз.\n");
            break;
        }
    }
    system("pause");
    return 0;
}


int check(double x, double y) {
    if (x >= 0 && y <= -x && (x * x + y * y) <= 2 && (x > y)) {
        return 1;
    }
    return 0;
}


int draw() {
    char simv;
    printf("Введите символ для рисунка: ");
    if (scanf(" %c", &simv) != 1) {
        simv = '*';
    }
    printf("\nРисунок\n");
    for (double y = 0.2; y >= -1.6; y -= 0.1) {
        for (double x = -0.2; x <= 1.6; x += 0.05) {
            if (check(x, y)) {
                printf("%c", simv);
            }
        }
        printf("\n");
    }
    return 0;
}

int task1() {
    double x, y;
    printf("Введите координаты точки (x y): ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("Ошибка ввода координат.\n");
        while (getchar() != '\n'); 
        return;
    }
    check1(x, y);
}


int check1(double x, double y) {
    if (x < y) {
        if (check(x, y)) {
            printf("\nТочка (%.2lf, %.2lf) Принадлежит заштрихованной области\n", x, y);
        }
        else {
            printf("\nТочка (%.2lf, %.2lf) Не принадлежит заштрихованной области\n", x, y);
        }
    }
    else
    {
        printf("x больше или равен y\n");
        return 0;
    }
    return 0;
}

int task2lab9() {
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row) {
        for (col = 1; col <= COL; col++) {
            printf("%5d", col);
        }
        printf("\n");
    }
    return 0;
}
