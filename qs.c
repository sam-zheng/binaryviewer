/*
 * qs.c
 *
 * two versions of quick sort
 */
void swap(int *a, int *b);

void qs(int * a, int l) {
  if (l <= 1) {
    return;
  }
  int pi = l / 2;
  int p = a[pi];
  int i = 0, j = l - 1;
  while (1) {
    while (j >= i && a[i] <= p)
      i++;

    while (j >= i && a[j] >= p)
      j--;
    if (i < j) {
    	swap(&a[i], &a[j]);
      i++;
      j--;
    } else {
    	int idx = i < pi ? i : j;
    	swap(&a[idx], &a[pi]);
		qs(a, idx);
		qs(a + idx + 1, l - idx - 1);

      break;
    }

   }

}


void swap(int *a, int *b)
{
  int t=*a; *a=*b; *b=t;
}
void sort(int arr[], int beg, int end)
{
  if (end > beg + 1)
  {
    int piv = arr[beg], l = beg + 1, r = end;
    while (l < r)
    {
      if (arr[l] <= piv)
        l++;
      else
        swap(&arr[l], &arr[--r]);
    }
    swap(&arr[--l], &arr[beg]);
    sort(arr, beg, l);
    sort(arr, r, end);
  }
}
