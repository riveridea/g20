/*
O(n) 时间的排序

某公司几万名员工排序， O(n)时间， O(1)的辅助空间。
*/

int sortAges(int ages[], int length)
{
	if (ages == NULL || length <= 0)
		return -1;

	const int oldestAge = 99;
	int occursOfAge[oldestAge + 1];

	for (int i = 0; i <= oldestAge; i++) {
		occursOfAge[i] = 0;
	}

	for (int i = 0; i < length; i++) {
		if (ages[i] < 0 || ages[i] > oldestAge) {
			return -1;
		}

		++ occursOfAge[ages[i]];
	}

	int index = 0;

	for (int i = 0; i <= oldestAge; i++) {
		for (int j = 0; j < occursOfAge[i]; j++) {
			ages[index] = i;
			index++;
		}
	}

	return 1;
}