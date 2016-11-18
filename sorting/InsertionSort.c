/*
Insertion Sort: in-place, simple but inefficient for large sets of data.
*/

void insertion_sort(element list[], int n)
{
	int i, j;
	element next;

	for (i = 1; i < n; i++) {
		next = list[i];

		for (j = i -1; j >= 0 && next.key < list[l].key; j--) {
			list[j + 1] = list[j];
		}

		list[j + 1] = next;
	}

}