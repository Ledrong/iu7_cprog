#include <stdio.h>
#include <math.h>

#define OK 0
#define INPUT_ERROR 1
#define INCORRECT_N 3
#define N_NOT_IN_SCOPE 4


int input_check_array(int *arr, int const count)
{
    for (int i = 0; i < count; i++)
        if (scanf("%d", &arr[i]) != 1)
            return INPUT_ERROR;
    return OK;
}

int sum(int *A, int *B, int *C, int n)
{
	char sa, sb;

    for (int i =0; i < n; i++)
	{
		sa += A[i];
		sb += B[i];
	}
	int k1 = (int)sa;
	int k2 = (int)sb;
	int k3 = k1 + k2;

	for (int i = n - 1; i >= 0; i--)
	{
        C[i] = k3 % 10;
		k3 /= 10;
	}
	return *C;
}

int main(void)
{
    int n;
    int rc = scanf("%d", &n);
    if (rc == EOF || rc != 1)
    {
        printf("You can input only integer numbers as N.");

        return INCORRECT_N;
    }

    if (0 >= n)
    {
        printf("N must be more, than zero and less, than eleven");

        return N_NOT_IN_SCOPE;
    }

    int A[n], B[n], C[n];

    if (input_check_array(A, n))
    {
        printf("Inputted incorect array");
	    
        return INPUT_ERROR;
    }

    if (input_check_array(B, n))
    {
        printf("Inputted incorect array");
	    
        return INPUT_ERROR;
    }

    C = sum(A, B, C, n);

    for (int i = 0; i < n; i++)
		printf("%d", C[i]);

    return OK;
}
