/*
把一个含有N个元素的数组循环右移K位， 要求时间复杂度为 O(N), 只允许用两个附加变量。
*/

void rightShift1(char *arr, int N, int K);
void reverse(char *arr, int begin, int end);
void rightShift2(char *arr, int N, int K);

int main(void)
{
	char *str = "1234abcd";
	rightShift2(str, 8, 4);
	
	printf("%s", str);


	return 0;
}

void rightShift1(char *arr, int N, int K)
{
	K %= N;

	while (K--)
	{
		int t = arr[N-1];
		int i = N-1;

		for (; i > 0; i--) {
			arr[i] = arr[i - 1];
		}

		arr[0] = t;
	}
}


void reverse(char *arr, int begin, int end)
{
	for (; begin < end; begin++, end--) {
		int temp = arr[end];
		arr[end] = arr[begin];
		arr[begin] = temp;
	}
}

void rightShift2(char *arr, int N, int K)
{
	K %= N;
	reverse(arr, 0, N-K-1);
	reverse(arr, N-K, N-1);
	reverse(arr, 0, N-1);
}