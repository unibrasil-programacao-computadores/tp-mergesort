#include "sort.h"
#include "input.h"

int main()
{
    sort_base_array(quicksort, "Quicksort");
    sort_ordered_arrays(quicksort, "Quicksort");
    sort_reverse_ordered_arrays(quicksort, "Quicksort");
    sort_uniform_arrays(quicksort, "Quicksort");

    sort_base_array(mergesort, "mergesort");
    sort_ordered_arrays(mergesort, "mergesort");
    sort_reverse_ordered_arrays(mergesort, "mergesort");
    sort_uniform_arrays(mergesort, "mergesort");

    return 0;
}
