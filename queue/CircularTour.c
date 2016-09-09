#include <stdio.h>
#include <stdlib.h>

/*Ref: http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/*/

/*Problem Statement: Suppose there is a circle. 
There are n petrol pumps on that circle. You are given two sets of data.

1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Calculate the first point from where a truck will be able to complete the circle 
(The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n). 
Assume for 1 litre petrol, the truck can go 1 unit of distance.

For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as 
{4, 6}, {6, 5}, {7, 3} and {4, 5}. 
The first point from where truck can make a circular tour is 2nd petrol pump.
Output should be “start = 1″ (index of 2nd petrol pump).
 */





/*A Petrol Pump has petrol and distance to next petrol pump*/
struct Pump {
	int petrol;
	int pump_distance;
};

struct Pump *createPump(int petrol, int distance);
int findFirstCircularTour(struct Pump *pump[], int n);


/*allocates memory for pump and initialize its values*/
struct Pump *createPump(int petrol, int distance)
{
	struct Pump *pump = (struct Pump *)malloc(sizeof(struct Pump));
	pump->petrol  = petrol;
	pump->pump_distance = distance;
	return pump;
}

/*findFirstCircularTour: this functions returns first starting point if there is a possible solution,
					      otherwise returns -1*/
int findFirstCircularTour(struct Pump *pumps[], int n)
{	
	int i, j, start, total_petrol, total_distance;
	i = 0;

	/*iterate throughout the array*/
	while(i < n)
	{

		start = j = i;	//pick current index as starting point
		total_distance = pumps[start]->pump_distance;
		total_petrol = pumps[start]->petrol;
		j++;

		/*iterate until we doesnot reach at stating position*/
		while(start != j)
		{
			if(total_distance > total_petrol)
				break;

			total_petrol += pumps[j]->petrol;
			total_distance += pumps[j]->pump_distance;


			/*reached end of array, need to start from begining*/
			if(j + 1 == n)
				j = 0;
			else 
				j++;
		}

		if(start == j)
			return start;

		i++;
	}

	return -1;

}

int main(int argc, char const *argv[])
{
	struct Pump *pump1 = createPump(4, 6);
	struct Pump *pump2 = createPump(6, 5);
	struct Pump *pump3 = createPump(7, 3);
	struct Pump *pump4 = createPump(4, 5);
	
	struct Pump *pumps[] = {pump1, pump4, pump2, pump3};

	int pos = findFirstCircularTour(pumps, 4);

	printf("If we start from %d position than we can cover the circle\n", pos);
	
	return 0;
}