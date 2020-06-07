/*Eric Kahn*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b) { //swap function for sorting algorithm
   int temp= *a;
   *a= *b;
   *b= temp;
   return;
}

int main(){
	int length;
	int i, c, a, b, t ,d, e, f, g;
	int *ptrB1;//pointer to point to beginning of ascending array
	int *ptrE1;//pointer to point to the end of ascending array
	int *ptrB2;//pointer for beginning of descending array
	int *ptrE2;//pointer for end of descending array

	srand(time(0));
	printf("How many numbers would you like in the array?: ");

	scanf("%d", &length);//scanning in user's choice for number of ints

	int *array1= (int*) malloc(length*sizeof(int));
	for(i=0; i<length; i++) {//populating array
		array1[i]=rand() %10 +1;
	}
	int *array2= (int*) malloc(length*sizeof(int));//allocating memory for array2
	int *array3= (int*) malloc(length*sizeof(int));//allocating memory for array3
	for(c=0; c<length; c++) {//making 2 copies of array1
		array2[c]=array1[c];
		array3[c]=array1[c];
	}
	ptrB1= array2;//pointing ptrB1 at beginning of array2
	ptrE1= &array2[length-1];//pointing ptrE1 at end of array2

	ptrB2= array3;//point ptrB2 at beginning of array3
	ptrE2= &array3[length-1];//pointing ptrE2 at end of array3

	/*sort algorithm. Outer for loop increments beginning pointer one index each
	iteration*/
	for(a=1; a<=length; a++) {
		/*inner for loop compares each following index to the one ptrB is at and
		  if the value at PtrE isless, swap function is called
		*/
		for(b=0; b<length-a; b++) {
			if(*ptrE1<*ptrB1) {
				swap(ptrE1, ptrB1);
			}
			ptrE1--;//inside inner for loop, ptrE is decremented
		}
		ptrB1++;//at the end of the outer for loop, ptrB is incremented
		ptrE1=&array2[length-1];//ptrE is set back to the end
	}
/*lines 55-64 is the exact same lines as 40-49, except there is a ">" sign in
line 53 so that this sorts array3 in descending order, instead of sorting array3
in ascending order. 
*/
	for(e=1; e<=length; e++) {
		for(f=0; f<length-e; f++) {
			if(*ptrE2 > *ptrB2) {
			   swap(ptrE2, ptrB2);
			}
			ptrE2--;
		}
		ptrB2++;
		ptrE2=&array3[length-1];
	}
	printf("Original Array:\n");
	for(t=0; t< length; t++) {//original array is printed
		printf("%d\n", array1[t]);
	}
	printf("\nAscending Array\n");

	for (d=0; d<length; d++) {//ascending array is printed
		printf("%d\n", array2[d]);
	}
	printf("\nDescending Array\n");

	for(g=0; g<length; g++) {//descending array is printed
		printf("%d\n", array3[g]);
	}

	free(array1);
	free(array2);
	free(array3);

	return 0;
}
