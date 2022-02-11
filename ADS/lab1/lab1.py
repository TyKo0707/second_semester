# Массив: лучший, хороший, нормальный
# Таймер
#

import time
import matplotlib.pyplot as plt
import random
from sort_algorithms import *


class TimerError(Exception):
    """A custom exception used to report errors in use of Timer class"""


class Timer:
    def __init__(self):
        self._start_time = None

    def start(self):

        if self._start_time is not None:
            raise TimerError(f"Timer is running. Use .stop() to stop it")

        self._start_time = time.perf_counter()

    def result(self):

        if self._start_time is None:
            raise TimerError(f"Timer is not running. Use .start() to start it")

        elapsed_time = time.perf_counter() - self._start_time
        self._start_time = None
        return elapsed_time


def check_b(matrix, algo: str):
    res = []
    for i in range(3):
        t.start()
        if algo == 'b':
            bubble_sort(matrix[i])
        elif algo == 'c':
            comb_sort(matrix[i])
        time_b = t.result()
        res.append(time_b)
    return res


if __name__ == "__main__":
    arr_num = [10, 100, 1000, 5000, 10000, 20000, 50000]
    res_bubble = []
    res_comb = []
    t = Timer()
    for i in range(len(arr_num)):
        best = [x for x in range(1, arr_num[i] + 1)]
        worst = [y for y in range(arr_num[i], 0, -1)]
        norm = random.sample(range(1, arr_num[i] + 1), arr_num[i])
        if i == 0 or i == 1:
            print(f'\nBest array: {best}, {len(best)}\n'
                  f'Worst array: {worst}, {len(worst)}\n'
                  f'Norm array: {norm}, {len(norm)}\n')
        matrix = [best, worst, norm]
        bubble_best, bubble_worst, bubble_norm = check_b(matrix, 'b')
        print(f'Time for bubble sort(best): {bubble_best}\n'
              f'Time for bubble sort(worst): {bubble_worst}\n'
              f'Time for bubble sort(normal): {bubble_norm}')
        if i == 0 or i == 1:
            print(f'Best array after sort: {matrix[0]}, {len(matrix[0])}\n'
                  f'Worst array after sort: {matrix[1]}, {len(matrix[1])}\n'
                  f'Norm array after sort: {matrix[2]}, {len(matrix[2])}\n')
        comb_best, comb_worst, comb_norm = check_b(matrix, 'c')
        print(f'Time for comb sort(best): {comb_best}\n'
              f'Time for comb sort(worst): {comb_worst}\n'
              f'Time for comb sort(normal): {comb_norm}')
