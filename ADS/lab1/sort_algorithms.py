def bubble_sort(arr):
    n = len(arr)
    bubble_comp = 0
    bubble_swap = 0
    swapped = True
    i = 0
    while swapped:
        swapped = False
        for j in range(0, n - i - 1):
            bubble_comp += 1
            if arr[j] > arr[j + 1]:
                bubble_swap += 1
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        i += 1
    return bubble_comp, bubble_swap


def comb_sort(arr):
    len_a = len(arr)
    gap_k = 1.2473309
    gap = int(len_a / gap_k) if len_a > 1 else 0
    comb_comp = 0
    comb_swap = 0
    while gap:
        swapped = False
        for i in range(len_a - gap):
            comb_comp += 1
            if arr[i + gap] < arr[i]:
                comb_swap += 1
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True
        gap = int(gap / gap_k) or swapped

    return comb_comp, comb_swap
