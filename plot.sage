def readFile(filename):
    v = []
    with open('data/'+filename) as f :
        for line in f:
            v.append([float(x) for x in line.split()])
    return v

g1 = line(readFile('stdSort1.data'), color='red', legend_label='stdSort', linestyle='-')
g2 = line(readFile('stdSort2.data'), color='red', linestyle='--')
g3 = line(readFile('stdSort3.data'), color='red', linestyle='-.')
stdSort = g1 + g2 + g3

g1 = line(readFile('bubbleSort1.data'), color='blue', legend_label='bubbleSort', linestyle='-')
g2 = line(readFile('bubbleSort2.data'), color='blue', linestyle='--')
g3 = line(readFile('bubbleSort3.data'), color='blue', linestyle='-.')
bubbleSort = g1 + g2 + g3

g1 = line(readFile('insertionSort1.data'), color='green', legend_label='insertionSort', linestyle='-')
g2 = line(readFile('insertionSort2.data'), color='green', linestyle='--')
g3 = line(readFile('insertionSort3.data'), color='green', linestyle='-.')
insertionSort = g1 + g2 + g3

g1 = line(readFile('quicksort1.data'), color='violet', legend_label='quicksort', linestyle='-', title='Temps de tous les algorithmes regroupés')
g2 = line(readFile('quicksort2.data'), color='violet', linestyle='--')
g3 = line(readFile('quicksort3.data'), color='violet', linestyle='-.')
quicksort = g1 + g2 + g3

g1 = line(readFile('quicksort1.data'), color='violet', legend_label='quicksort', linestyle='-', title='Temps des algorithmes rapides')
g2 = line(readFile('quicksort2.data'), color='violet', legend_label='quicksort', linestyle='--', title='Temps des algorithmes lents')
quicksort_fast = g1
quicksort_slow = g2 + g3

g1 = line(readFile('modifQuicksort1.data'), color='orange', legend_label='modifiedQuicksort', linestyle='-')
g2 = line(readFile('modifQuicksort2.data'), color='orange', linestyle='--')
g3 = line(readFile('modifQuicksort3.data'), color='orange', linestyle='-.')
modifQuicksort = g1 + g2 + g3

stdSort.axes_labels(['éléments à trier', 'temps exécution(ms)'])
stdSort.fontsize(5)
stdSort.show()
stdSort.save('plots/individual/stdSort.png')

bubbleSort.axes_labels(['éléments à trier', 'temps exécution(ms)'])
bubbleSort.fontsize(5)
bubbleSort.show()
bubbleSort.save('plots/individual/bubble_sort.png')

insertionSort.axes_labels(['éléments à trier', 'temps exécution(ms)'])
insertionSort.fontsize(5)
insertionSort.show()
insertionSort.save('plots/individual/insertion_sort.png')

quicksort.axes_labels(['éléments à trier', 'temps exécution(ms)'])
quicksort.fontsize(5)
quicksort.show()
quicksort.save('plots/individual/quicksort.png')

modifQuicksort.axes_labels(['éléments à trier', 'temps exécution(ms)'])
modifQuicksort.fontsize(5)
modifQuicksort.show()
modifQuicksort.save('plots/individual/modified_quicksort.png')

all = stdSort + bubbleSort + insertionSort + quicksort + modifQuicksort
all.axes_labels(['éléments à trier', 'temps exécution(ms)'])
all.fontsize(5)
all.show()
all.save('plots/all_plots.png')

fast = stdSort + modifQuicksort + quicksort_fast
fast.axes_labels(['éléments à trier', 'temps exécution(ms)'])
fast.fontsize(5)
fast.show()
fast.save('plots/fast_running_time.png')

slow = bubbleSort + insertionSort + quicksort_slow
slow.axes_labels(['éléments à trier', 'temps exécution(ms)'])
slow.fontsize(5)
slow.show()
slow.save('plots/slow_running_time.png')


# stdSort1.data bubbleSort1.data insertionSort1.data quicksort1.data modifQuicksort1.data
# stdSort2.data bubbleSort2.data insertionSort2.data quicksort2.data modifQuicksort2.data
# stdSort3.data bubbleSort3.data insertionSort3.data quicksort3.data modifQuicksort3.data
