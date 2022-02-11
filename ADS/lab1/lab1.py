import time
import matplotlib.pyplot as plt
import random
from sort_algorithms import *
import math


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
            bubble_comp, bubble_swap = bubble_sort(matrix[i])
            res.append(bubble_comp)
            res.append(bubble_swap)
        elif algo == 'c':
            comb_comp, comb_swap = comb_sort(matrix[i])
            res.append(comb_comp)
            res.append(comb_swap)
        time_b = t.result()
        res.append(time_b)
    return tuple(res)


if __name__ == "__main__":
    arr_num = [10, 100, 1000, 5000, 10000, 20000, 50000]
    square = [i ** 2 for i in arr_num]
    log_f = [i * math.log2(i) for i in arr_num]
    res_bubble = [[], [], []]
    res_comb = [[], [], []]
    res_bubble_p = [[], [], []]
    res_comb_p = [[], [], []]
    t = Timer()
    with open("result.txt", "w") as file:
        for i in range(len(arr_num)):
            best = [x for x in range(1, arr_num[i] + 1)]
            worst = [y for y in range(arr_num[i], 0, -1)]
            norm = random.sample(range(1, arr_num[i] + 1), arr_num[i])
            matrix = [best[:], worst[:], norm[:]]
            bubble_best_comp, bubble_best_swap, bubble_best, bubble_worst_comp, bubble_worst_swap, bubble_worst, \
            bubble_norm_comp, bubble_norm_swap, bubble_norm = check_b(matrix, 'b')
            res_bubble[0].append(bubble_best)
            res_bubble[1].append(bubble_worst)
            res_bubble[2].append(bubble_norm)
            res_bubble_p[0].append(bubble_best_comp)
            res_bubble_p[1].append(bubble_worst_comp)
            res_bubble_p[2].append(bubble_norm_comp)
            title = f'Array with {arr_num[i]} numbers:\n' \
                    f'\tBest array: {best[:10]}...\n' \
                    f'\tWorst array: {worst[:10]}...\n' \
                    f'\tNorm array: {norm[:10]}...\n'
            stw_bubble = f'\n\tBubble:\n' \
                         f'\t\tNumber of comparisons, number of swaps in bubble sort(best): {bubble_best_comp}, {bubble_best_swap}\n' \
                         f'\t\tTime for bubble sort(best): {bubble_best} s\n' \
                         f'\n\t\tNumber of comparisons, number of swaps in bubble sort(worst): {bubble_worst_comp}, {bubble_worst_swap}\n' \
                         f'\t\tTime for bubble sort(worst): {bubble_worst} s\n' \
                         f'\n\t\tNumber of comparisons, number of swaps in bubble sort(norm): {bubble_norm_comp}, {bubble_norm_swap}\n' \
                         f'\t\tTime for bubble sort(normal): {bubble_norm} s'
            matrix = [best[:], worst[:], norm[:]]
            comb_best_comp, comb_best_swap, comb_best, comb_worst_comp, comb_worst_swap, comb_worst, \
            comb_norm_comp, comb_norm_swap, comb_norm = check_b(matrix, 'c')
            res_comb[0].append(comb_best)
            res_comb[1].append(comb_worst)
            res_comb[2].append(comb_norm)
            res_comb_p[0].append(comb_best_comp)
            res_comb_p[1].append(comb_worst_comp)
            res_comb_p[2].append(comb_norm_comp)
            stw_comb = f'\n\n\tComb:\n' \
                       f'\t\tNumber of comparisons, number of swaps in comb sort(best): {comb_best_comp}, {comb_best_swap}\n' \
                       f'\t\tTime for bubble sort(best): {comb_best} s\n' \
                       f'\n\t\tNumber of comparisons, number of swaps in comb sort(worst): {comb_worst_comp}, {comb_worst_swap}\n' \
                       f'\t\tTime for bubble sort(worst): {comb_worst} s\n' \
                       f'\n\t\tNumber of comparisons, number of swaps in comb sort(norm): {comb_norm_comp}, {comb_norm_swap}\n' \
                       f'\t\tTime for bubble sort(normal): {comb_norm} s\n\n'

            file.write(title)
            file.write(stw_bubble)
            file.write(stw_comb)

    plt.figure()
    ax1 = plt.subplot(2, 2, 1)
    plt.plot(arr_num, res_bubble[0], '-', arr_num, res_bubble[1], '-', arr_num, res_bubble[2], '-')
    plt.title('Bubble sort time')
    plt.xlabel('Number of elements in array')
    plt.ylabel('Time to sort')
    plt.legend(['Best case', 'Worst case', 'Random case'])
    plt.xticks(arr_num)
    ax2 = plt.subplot(2, 2, 2)
    plt.plot(arr_num, res_comb[0], '-', arr_num, res_comb[1], '-', arr_num, res_comb[2], '-')
    plt.title('Comb sort time')
    plt.xlabel('Number of elements in array')
    plt.ylabel('Time to sort')
    plt.legend(['Best case', 'Worst case', 'Random case'])
    plt.xticks(arr_num)
    ax3 = plt.subplot(2, 2, 3)
    plt.plot(arr_num, res_bubble_p[0], '-', arr_num, res_bubble_p[1], '-', arr_num, res_bubble_p[2], '-')
    plt.plot(arr_num, square, '-', alpha=0.5)
    plt.title('Bubble sort performance')
    plt.xlabel('Number of elements in array')
    plt.ylabel('Number of comparisons')
    plt.legend(['Best case', 'Worst case', 'Random case'])
    plt.xticks(arr_num)
    ax4 = plt.subplot(2, 2, 4)
    plt.plot(arr_num, res_comb_p[0], '-', arr_num, res_comb_p[1], '-', arr_num, res_comb_p[2], '-')
    plt.plot(arr_num, log_f, '-', alpha=0.5)
    plt.title('Comb sort performance')
    plt.xlabel('Number of elements in array')
    plt.ylabel('Number of comparisons')
    plt.legend(['Best case', 'Worst case', 'Random case'])
    plt.xticks(arr_num)
    plt.show()
