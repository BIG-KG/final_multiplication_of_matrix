#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "enter.cpp"

struct malloced_arr_wsize{
	int *inner_array = NULL;
	size_t x_size = 0;
	size_t y_size = 0;
};

int *pointer_to_el( const struct malloced_arr_wsize * const curr_mass, const size_t target_y, const size_t target_x){

	assert(curr_mass);

	return curr_mass->inner_array + target_y * curr_mass->x_size + target_x;

}

int make_and_fill_inner_array(struct malloced_arr_wsize *const target_fill_arr, FILE *input ){

	assert(target_fill_arr);
	assert(input);
	//printf("enter how much strings in matrix: ");

	fscanf(input, "%d", &target_fill_arr->y_size);
	fscanf(input, "%d", &target_fill_arr->x_size);

	size_t x_size = target_fill_arr->x_size;
	size_t y_size = target_fill_arr->y_size;

	target_fill_arr->inner_array = (int *)calloc(x_size * y_size, sizeof(int));
	assert(target_fill_arr->inner_array);

	for(int i = 0; i < y_size; i++){
		for(int j = 0; j < x_size; j++){
			if( fscanf(input,  "%d",  pointer_to_el(target_fill_arr, i, j) ) == 0){
				printf("ERROR, CHECK INPUT FILE");
				return 1;
			}
		}
	}
	return 0;
}

struct malloced_arr_wsize multiplication_matrix(struct malloced_arr_wsize *const matrix_a, struct malloced_arr_wsize *const matrix_b){

	assert(matrix_a);
	assert(matrix_b);

	size_t ab_same_size = 0;
	size_t result_x_size = 0;
	size_t result_y_size = 0;
	struct malloced_arr_wsize * matrix_x = NULL;
	struct malloced_arr_wsize * matrix_y = NULL;

	struct malloced_arr_wsize result_matrix;

	if (matrix_a->x_size == matrix_b->y_size){
		matrix_x = matrix_a;
		matrix_y = matrix_b;
	}

	else if(matrix_a->y_size == matrix_b->x_size){
		matrix_x = matrix_b;
		matrix_y = matrix_a;
	}
	else{
		printf("this matrix cannot be multiplicated");
		struct malloced_arr_wsize NAS ={};
		return NAS;

	}

	result_x_size = matrix_y->x_size;
	result_y_size = matrix_x->y_size;
	ab_same_size = matrix_y->y_size;

	result_matrix.x_size = result_x_size;
	result_matrix.y_size = result_y_size;

	result_matrix.inner_array = (int *)calloc(sizeof(int), result_x_size * result_y_size);

	for(int i = 0; i < result_y_size; i++){
		for(int j = 0; j < result_x_size; j++){
			for(int r = 0; r < ab_same_size; r++){
				*pointer_to_el(&result_matrix, i, j) += *pointer_to_el(matrix_x, i, r) * *pointer_to_el(matrix_y, r, j);
			}
		}
	}

	return result_matrix;

}

void printing_matrix(struct malloced_arr_wsize printing_arr){

	for(int i = 0; i < printing_arr.y_size; i++){
		for(int j = 0; j <printing_arr.x_size; j ++){
			printf("%-4d ", *pointer_to_el(&printing_arr, i, j));
		}
		printf("\n");
	}

}


int main()
{
	FILE *input_file = fopen("input.txt", "r");
	assert(input_file);

    struct malloced_arr_wsize matrix_1;
	make_and_fill_inner_array(&matrix_1, input_file);
	//printing_matrix(matrix_1);
	printf("\n");


	struct malloced_arr_wsize matrix_2;
	make_and_fill_inner_array(&matrix_2, input_file);
	//printing_matrix(matrix_2);
	printf("\n");


	struct malloced_arr_wsize result_matrix = multiplication_matrix(&matrix_2, &matrix_1);
	printing_matrix(result_matrix);
	//printf("\n");
}
