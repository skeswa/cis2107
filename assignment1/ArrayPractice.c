#include <stdio.h>

void evenOnLeft(int[], int);
void printA(int[], int);
void reverse(int[], int);
float average(int[], int);
int secondLargest(int[], int);
void rotateRight(int[], int, int);

int main(int argc, char **argv)
{
  int A[] = {9, 21, 321, 117, 27, 64, 13, 9, 12, 208};
  printA(A, 10);

  printf("The average of A[] is %f\n", average(A,10));

  reverse(A, 10);
  printA(A, 10);

  evenOnLeft(A, 10);
  printA(A, 10);

  printf("The second largest item in A[] is %d\n", secondLargest(A, 10));

  rotateRight(A, 10, 3);
  printA(A, 10);

  return 0;
}

/* prints A[] inside parentheses with each value separated
   by commas to stdout (which will be the screen) */
void printA(int A[], int length)
{
  int i;
  printf("[");
  for (i = 0; i < length; i++) {
    if (i > 0) printf(", ");
    printf("%d", A[i]);
  }
  printf("]\n");
}

/* returns the average of the items in A[] or 0.0 if A is empty */
float average(int A[], int length)
{
  int i;
  float sum;

  for (i = 0; i < length; i++) {
    sum += (float) (A[i]);
  }

  return sum / (float) length;
}

/* Reverses the values in A[].  For example, if before the function,
   A[] contained [1,2,3,4,5], after the function, A[] contains
   [5,4,3,2,1] */
void reverse(int A[], int length)
{
  int temp[length];
  int i;
  
  for (i = 0; i < length; i++) {
    temp[i] = A[i];
  }
  for (i = 0; i < length; i++) {
    A[length - 1 - i] = temp[i];
  }
}

/* returns the second largest item in A[], or -1 if len < 2 */
int secondLargest(int A[], int length)
{
  int i, first, second;
  if (length < 2) return -1;
  for (i = 0; i < length; i++) {
    if (i == 0) {
      first = A[i];
    } else if (i == 1) {
      if (A[i] > first) {
	second = first;
	first = A[i];
      } else {
	second = A[i];
      }
    } else {
      if (A[i] > first) {
	second = first;
	first = A[i];
      } else if (A[i] > second) {
	second = A[i];
      }
    }
  }
  return second;
}

/* rotates the values in the array numPlaces to the right */
/* for example, if A[] is initially 10,20,30,40,50, and numPlaces=2 */
/* after the function finishes, A[] would be 40,50,10,20,30 */
void rotateRight(int A[], int length, int numPlaces)
{
  int temp[length];
  int i;

  for (i = 0; i < length; i++) {
    temp[i] = A[i];
  }
  for (i = numPlaces; i < (length + numPlaces); i++) {
    A[i % length] = temp[i - numPlaces];
  }
}

/* Moves all of the even integers in A to the left hand side of A
   and the odd integers to the right hand side

   For example, if before the function, A[] contained [1,2,3,4,5],
   after the function A[] could contain [2,4,1,3,5] */
void evenOnLeft(int A[], int length)
{
  int i, j, temp;
  if (length <= 1) return;
  for (i = 0; i < length; i++) {
    if (A[i] % 2 != 0) {
      for (j = i + 1; j < length; j++) {
	if (A[j] % 2 == 0) {
	  temp = A[i];
	  A[i] = A[j];
	  A[j] = temp;
	  break;
	}
      }
      return;
    }
  }
}
