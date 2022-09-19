#include<stdio.h>
void swap(int* num1, int* num2)
  {
     int tp = *num1;
	*num1 = *num2;
	*num2 = tp;
   }

void min_heap(int ar[], int N, int x)
{
	int least = x;
	int l = 2*x+1;
	int r = 2*x+2;

	if (l < N && ar[l] < ar[least])
    least = l;

	if (r < N && ar[r] < ar[least])
		least = r;

	if (least != x) {

		swap(&ar[x], &ar[least]);

		min_heap(ar, N, least);
	}
}

void min_heap_sort(int ar[], int N)
{
    for (int x = N / 2 - 1; x >= 0; x--)
		min_heap(ar, N, x);
}


int find_min_cost(int ar[], int N)
{
	int sum=0,k,j=0;
	while(N>1)
	{
		min_heap(ar, N, 0);		
		j = ar[0]+ar[1];
		sum += j;
		ar[1] = j;
		for(k=0; k<N-1; k++)
        {
            ar[k] = ar[k + 1];
        }
        N--;
	}
	return sum;

}

int main()
{
	int sum, ar[] = {5,8,2,1};
    int N = sizeof(ar) / sizeof(ar[0]);
	min_heap_sort(ar, N);
	sum = find_min_cost(ar, N);
	printf("Minimum cost will be %d", sum);
		
}