#define MAX_TRY_COUNT 11

int check_enter_int(const char * const printing_str ){

    int right_enter = 1, try_counter = 0;
    int output = 0;
	int drop = 0;
	char last_char = 0;

    do{
		drop = 0;
        if (right_enter != 1){
            printf("ERROR try again\n");

            for(drop = 0; (drop = getchar()) != '\n' && drop != EOF;)
            ;
		}

		printf("%s", printing_str);
		right_enter = scanf("%d%c", &output, &last_char);


		if(last_char != '\n' && last_char != ' '){
            printf("\nYOU CAN ENTER ONLY NUMBERS\n");
			right_enter = 0;
		}

		try_counter ++;
    }while( (right_enter == 0 || (last_char != '\n' && last_char != ' ')) && try_counter < MAX_TRY_COUNT);

    if(right_enter == 0){
        return 0;
    }

    return output;
}
