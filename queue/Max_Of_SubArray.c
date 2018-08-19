#include "deque.h"

void maxOfSubarray(int arr[], int n, int k);


void maxOfSubarray(int arr[], int n, int k)
{
	int i = 0, j, max;

	/*iterate throughout the array*/
	while(i < n - k)
	{	
		j = 1;
		max = arr[i];
		while(j < k)
		{
			if(arr[i + j] > max)
				max = arr[i + j];

			j++;
		}

		printf("%d, ", max);
		i++;
	}

	printf("\n");
}


/*We create a Dequeue, deque of capacity k, that stores only useful elements of current window of k elements. 
  An element is useful if it is in current window and is greater than all other elements on left side of it 
  in current window. We process all array elements one by one and maintain deque to contain useful elements 
  of current window and these useful elements are maintained in sorted order. The element at front of the 
  deque is the largest and element at rear of deque is the smallest of current window. 
*/

/*printKMax: A Deque based method to print max of all subarrays of size k*/
void printKMax(int arr[], int n, int k)
{
	struct Deque *deque = createQueue();

	int i;

	for(i = 0; i < k; i++)
	{
		/*for every element, the previous smaller element is useless,
		  so remove it from queue */
		while(!isEmpty(deque) && arr[i] >= arr[getRear(deque)])
			deleteLast(deque);

		/*add new element to rear of queue*/
		insertLast(deque, i);
	}


	//processs rest of elements
	for( ; i <n; i++)
	{	
		/*the element at the front is the largest element of previous window*/
		printf("%d, ", arr[getFront(deque)]);

		/*remove element which are out of this window*/
		while(!isEmpty(deque) && getFront(deque) <= i-k)
			deleteFront(deque);

		/*remove all the elements smaller than the 
		  currently being added element*/
		while(!isEmpty(deque) && arr[i] >= arr[getRear(deque)])
			deleteLast(deque);

		//add the element to the rear of queue
		insertLast(deque, i);
	}

	//print the max element of the last window
	printf("%d\n", arr[getFront(deque)]);
}



int main(int argc, char const *argv[])
{
	int arr1[] = {12, 1, 78, 90, 57, 89, 56};
	int arr2[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};

	int n = sizeof(arr1) / sizeof(arr1[0]);
	printKMax(arr1, n, 3);

	n = sizeof(arr2) / sizeof(arr2[0]);
	printKMax(arr2, n, 3);
	return 0;
}