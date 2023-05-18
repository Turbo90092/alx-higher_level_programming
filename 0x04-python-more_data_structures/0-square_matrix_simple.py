#!/usr/bin/python3
def square_matrix_simple(matrix=[]):
    # Create a new matrix with the same size as the input matrix
    result = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]

    # Iterate over each element in the input matrix
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            # Square the value and assign it to the corresponding position in the result matrix
            result[i][j] = matrix[i][j] ** 2

    return result
