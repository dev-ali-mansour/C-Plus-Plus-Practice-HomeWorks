
#ifndef HOMEWORKS_SUM_H
#define HOMEWORKS_SUM_H

int sum_1_n(int n) {
    int sum = 0;

    for (int i = 0; i < n; ++i)
        sum += i;

    return sum;
}

#endif //HOMEWORKS_SUM_H