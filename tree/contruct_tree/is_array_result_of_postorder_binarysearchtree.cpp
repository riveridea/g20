/*
输入一个整数数组，判断这个数组是不是某二元查找树的后序遍历
的结果。如果是，返回TURE，否者返回FALSE

这道题也是错的~
*/

#define TRUE 1
#define FALSE 0

int verifySeqOfBST(int sequence[], int length)
{
	if (NULL == Sequence || length <= 0) {
		return FALSE;
	}

	int root = sequence[length - 1];

	int i = 0;

	for (i = 0; i < length - 1; i++) {
		if (sequence[i] > root) {
			break;
		}
	}

	int j = i;

	for (j = i; j < length -1; j++) {
		if (sequence[j] < root) {
			return FALSE;
		}
	}
}