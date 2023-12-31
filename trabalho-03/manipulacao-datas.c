/* Codigo gerado pelo ChatGPT e modificado por Bruna Caetano - SI - 2023 */

#include <stdio.h>
#include "manipulacao-datas.h"

int daysBetweenDates(Date date1, Date date2) {
    int days1 = date1.year * 365 + date1.day;
    int days2 = date2.year * 365 + date2.day;

    // Adicionar dias extras para os anos bissextos
    days1 += date1.year / 4 - date1.year / 100 + date1.year / 400;
    days2 += date2.year / 4 - date2.year / 100 + date2.year / 400;

    // Adicionar dias para os meses
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < date1.month; i++) {
        days1 += monthDays[i];
    }
    for (int i = 1; i < date2.month; i++) {
        days2 += monthDays[i];
    }

    // Considerar anos bissextos
    if (date1.month <= 2 && (date1.year % 4 == 0 && (date1.year % 100 != 0 || date1.year % 400 == 0))) {
        days1--;
    }
    if (date2.month <= 2 && (date2.year % 4 == 0 && (date2.year % 100 != 0 || date2.year % 400 == 0))) {
        days2--;
    }

    // Calcular a diferença em dias
    int difference = days2 - days1;
    return difference;
}

bool isBetweenDates(Date date, Date startDate, Date endDate) {
    return daysBetweenDates(startDate, date) >= 0 && daysBetweenDates(date, endDate) >= 0;
}
