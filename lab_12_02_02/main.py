from ctypes import c_int, POINTER
import ctypes

lib = ctypes.CDLL('fibonacci.dll')

_fibonacci = lib.fibonacci
_fibonacci.argtypes = (POINTER(c_int), c_int)

_first_entries_into_array = lib.first_entries_into_array
_first_entries_into_array.argtypes = (POINTER(c_int), POINTER(c_int), c_int)

def fibonacci(array, n):
    array1 = (c_int * n)(*array)
    fibonacci(array1, n)
    return list(arr)


def first_entries_into_array(array1, array2, n):
    arr1 = (c_int * n)(*array1)
    arr2 = (c_int * n)(*array2)
    first_entries_into_array(arr1, arr2, n)

    return arr2

if __name__ == '__main__':
    array1 = list(map(int, input('Enter array: ').split()))
    n = int(input('Input size of array: '))
    print ('Filling by fibonacci: ')
    print('Result array: ', fibonacci(array1, n))

    array2 = []
    print('Result array: ', first_entries_into_array(array1, array2, n))