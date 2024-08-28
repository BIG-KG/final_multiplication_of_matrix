#include <stdio.h>

using namespace std;

int *element(int * current_arr, int x_size_arr, int terg_y, int targx){

}

int main()
{
    FILE *input_file = fopen("input.txt", "r");
    int not_const_matrix_1_y = 0, not_const_matrix_1_x = 0;
    fscanf(input_file, "%d %d", &not_const_matrix_1_y, &not_const_matrix_1_x);

    const int matrix_1_y = not_const_matrix_1_y;
    const int matrix_1_x = not_const_matrix_1_x;



    int not_const_matrix_2_y = 0, not_const_matrix_2_x = 0;
    fscanf(input_file, "%d %d", &not_const_matrix_2_y, &not_const_matrix_2_x);

    const int matrix_2_y = not_const_matrix_2_y;
    const int matrix_2_x = not_const_matrix_2_x;

}
