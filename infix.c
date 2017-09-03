#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*push the integer elements into stack*/
void push_array(int *arr,int size,int *top, int value)
{
	/*if stack is full then print message*/
		 arr[(*top)++] = value ;
}
/*function to pop the integer elementsfrom the stack*/
int pop_array(int *arr, int *top)
{
		/*get the array elements by decreamenting
		  top*/
		return arr[--(*top)];
}


/*function  to push the char elements into stack*/
void char_push_array(char *arr,int *top,int size, char ch)
{
	/*if stack is full then print message*/
	arr[(*top)++] = ch ;
}
/*functio to pop the char elements from array */
char char_pop_array(char *arr, int *top)
{
	if(*top == 0)
		return '\0';
	else
		return arr[--(*top)];
}

/*function call to peak(find top)of the array element*/
char char_peak_array(char *arr,int top)

{
	if(top == 0)
		return '\0';
	else
		return arr[--top];
}

/*function to set the flag*/
int op_flag(char ch)
{
	/*check for bracket*/
	if (ch == '('|| ch == ')')
		return 0;

	/*check for  add and subtraction*/
	else if (ch == '+' || ch == '-')
		return 1;

	/*check for multiplication and divide*/
	else if (ch == '*' || ch == '/')
		return 2;
}

/*function to convert infix from postfix*/
int infix_postfix_con(char *array , char *ch_array)
{
	char stack[100];
	int size = 100;
	int idx ,jdx = 0 ,stack_flag  ,insert_flag  ,top = 0 ,stop = 0;
	char stack_peak ,ch ,op;

	/*take the all the array elements and loop should run upto 
	 completion of all the elements*/
	for (idx = 0; array[idx] != '\0'; idx++ )
	{	
		/*check that elements lies between 0 to 9
		 and store into another array*/
		if(array[idx] >= '0' && array[idx] <= '9')
		{
			ch_array[jdx++] = array[idx];
		}
		else
		{
			/*check for space*/
			if (ch_array[jdx-1] != ' ')
			{
				ch_array[jdx++] = ' ';
			}
			/*if it opening bracket push the elements
			 to the array*/
			if (array[idx] == '(')

				char_push_array(stack ,&top ,size ,array[idx]);

			/*if it is closing bracket pop the elements from stack
			 and store into the array*/
			else if (array[idx] == ')')
			{
				while((ch = char_pop_array(stack,&top))!='(')
				{
					ch_array[jdx++] = ch;
				}
			}
			else
			{
				/*if top is equal to 0 then push the elements to 
				 array*/
				if (top == 0)

					char_push_array(stack ,&top ,size ,array[idx]);

				else 
				{
					/*assign operator flag(array) to insert flag
					 for checking precidence of operator*/
					insert_flag = op_flag(array[idx]);

					while(1)
					{
						stack_peak = char_peak_array(stack ,top);
						
						/*setting flags for stack*/
						stack_flag = op_flag(stack_peak);

						/*check the precedence of stack operators 
						 array operators*/
						if (stack_flag < insert_flag)
						{
							/*push the elements and break;*/
							char_push_array(stack ,&top ,size ,array[idx]);
							break;
						}
						else
						{
							/*else pop the elements from stack*/
							op = char_pop_array(stack ,&top);
								
							if(op == '\0')
							{
								/*if it is null push the elements to array*/
								char_push_array(stack ,&top ,size ,array[idx]);

								stop = 1;
							}
							else
							{
								/*if it is not eual to NULL then
								 store poped element to array*/
								ch_array[jdx++] = op;

								stop = 0;
							}
						if(stop)
							break;
						}
					}
				}
			}
		}
	}

	/*the elements are popped up to NULL*/
	while((ch = char_pop_array(stack,&top)) != '\0')
	{
		/*store the elements into character array*/
		ch_array[jdx++] = ch;
	}

	/*character array should end with NULL*/
	ch_array[jdx] = '\0';

	/*print the char array*/
	printf("%s\n",ch_array);

}

/*function to evaluate the post fix*/
void post_infix_eval(char *ch_array)
{
	char buffer[100]; 
	int	stack[100];
	int idx = 0 ,jdx = 0 ,val1 ,val2;
	int num ,result = 0 ,top = 0;
	int size = 100;
	
	/*check char array not equql to null and 
	 initialise the index*/
	while (ch_array[idx] != '\0')
	{
		jdx = 0;

		/*check that char array is not equal to null  and space andlies between 0 to 9*/
	while (ch_array[idx] != '\0' && ch_array[idx] != ' ' && ch_array[idx] >= '0' && ch_array[idx] <= '9')
	{
		/*then store that elements to buffer 
		 by increamenting index*/
		buffer[jdx++] = ch_array[idx];

		idx++;
	}

		/*buffer content ended with NULL*/
		buffer[jdx] = '\0';
		
		/*check buffer index not equal to 0*/
		if (jdx != 0)
		{
			/*scan the buffer elements to integers and store into number*/
			sscanf (buffer ,"%d",&num );

			/*push that number into stack*/
			push_array(stack , size , &top ,num);
		}
		if(ch_array[idx] != '\0' && ch_array[idx] != ' ')
		{
			/*pop the two  values from the stack*/
			val1 = pop_array(stack ,&top);
			val2 = pop_array(stack ,&top);

			/*switch statement to select case*/
			switch(ch_array[idx])
			{
				case '+':

					/*if is add then perform the operation and 
					 push the result into stack*/
					result = val1 + val2;

					push_array(stack ,size ,&top ,result);

					break;

				case '-':
					/*if is sub then perform the operation and 
					 push the result into stack*/

					result = val2 - val1;

					push_array(stack ,size ,&top ,result);

					break;

				case '*':
					/*if is multiplication then perform the operation and 
					 push the result into stack*/

					result = val1 * val2;

					push_array(stack ,size ,&top ,result);

					break;

				case '/':
					/*if is division then perform the operation and 
					 push the result into stack*/

					result = val2 / val1;

					push_array(stack ,size ,&top ,result);

					break;
			}
		}
		/*check char array not equal to NULL*/
			if(ch_array[idx] !='\0')
			idx++;
	}
	/*pop the final result and print*/
printf("%d\n",pop_array(stack ,&top));
}


void iterative_reverse( char *str)
{
	int len = 0 , idx;

	int temp = 0;

	//find length of string//
	len = strlen(str);

	//loop to count number of passes//
	for (idx = 0; idx < (len / 2); idx++)

	{
		//swap elements to reverse the string//
		temp = str[idx];

		str[idx] = str[(len - 1) - idx];

		str[(len - 1) - idx]  = temp;

	}
}

int infix_prefix_con(char *insert_array , char *ch_array)
{
	char stack[100];
	int size = 100;
	int idx ,jdx = 0 ,stack_flag  ,insert_flag  ,top = 0 ,stop = 0;
	char stack_peak ,ch ,op;

	iterative_reverse(insert_array);

//	printf("%s",insert_array);

	/*take the all the array elements and loop should run upto 
	 completion of all the elements*/
	for (idx = 0; insert_array[idx] != '\0'; idx++ )
	{	
		/*check that elements lies between 0 to 9
		 and store into another array*/
		if(insert_array[idx] >= '0' && insert_array[idx] <= '9')
		{
			ch_array[jdx++] = insert_array[idx];
		}
		else
		{
			/*check for space*/
			if (ch_array[jdx-1] != ' ')
			{
				ch_array[jdx++] = ' ';
			}
			/*if it opening bracket push the elements
			 to the array*/
			if (insert_array[idx] == ')')

				char_push_array(stack ,&top ,size ,insert_array[idx]);

			/*if it is closing bracket pop the elements from stack
			 and store into the array*/
			else if (insert_array[idx] == '(')
			{
				while((ch = char_pop_array(stack,&top))!=')')
				{
					ch_array[jdx++] = ch;
				}
			}
			else
			{
				/*if top is equal to 0 then push the elements to 
				 array*/
				if (top == 0)

					char_push_array(stack ,&top ,size ,insert_array[idx]);

				else 
				{
					/*assign operator flag(array) to insert flag
					 for checking precidence of operator*/
					insert_flag = op_flag(insert_array[idx]);

					while(1)
					{
						stack_peak = char_peak_array(stack ,top);
						
						/*setting flags for stack*/
						stack_flag = op_flag(stack_peak);

						/*check the precedence of stack operators 
						 array operators*/
						if (stack_flag <= insert_flag)
						{
							/*push the elements and break;*/
							char_push_array(stack ,&top ,size ,insert_array[idx]);
							break;
						}
						else
						{
							/*else pop the elements from stack*/
							op = char_pop_array(stack ,&top);
								
							if(op == '\0')
							{
								/*if it is null push the elements to array*/
								char_push_array(stack ,&top ,size ,insert_array[idx]);

								stop = 1;
							}
							else
							{
								/*if it is not eual to NULL then
								 store poped element to array*/
								ch_array[jdx++] = op;

								stop = 0;
							}
						if(stop)
							break;
						}
					}
				}
			}
		}
	}

	/*the elements are popped up to NULL*/
	while((ch = char_pop_array(stack,&top)) != '\0')
	{
		/*store the elements into character array*/
		ch_array[jdx++] = ch;
	}

	/*character array should end with NULL*/
	ch_array[jdx] = '\0';

	iterative_reverse(ch_array);
	printf("\n");

	/*print the char array*/
	printf("%s\n",ch_array);

}
void pre_infix_eval(char *ch_array)
{
	char buffer[100]; 
	int	stack[100];
	int idx =strlen(ch_array) -1,jdx = 0 ,val1 ,val2;
	int num ,result,top = 0;
	int size = 100;
	
	/*check char array not equql to null and 
	 initialise the index*/
	while (idx >= 0)
	{
		jdx = 0;

		/*check that char array is not equal to null  and space andlies between 0 to 9*/
	while (idx >=  0 && ch_array[idx] != ' ' && ch_array[idx] >= '0' && ch_array[idx] <= '9')
	{
		/*then store that elements to buffer 
		 by increamenting index*/
		buffer[jdx++] = ch_array[idx];
		idx--;

	}

		/*buffer content ended with NULL*/
		buffer[jdx] = '\0';

		iterative_reverse(buffer);
		
		/*check buffer index not equal to 0*/
		if (jdx != 0)
		{
			/*scan the buffer elements to integers and store into number*/
			sscanf (buffer ,"%d",&num );

			/*push that number into stack*/
			push_array(stack , size , &top ,num);
		}
		if(idx >= 0 && ch_array[idx] != ' ')
		{
			/*pop the two  values from the stack*/
			val1 = pop_array(stack ,&top);
			val2 = pop_array(stack ,&top);


			/*switch statement to select case*/
			switch(ch_array[idx])
			{
				case '+':

					/*if is add then perform the operation and 
					 push the result into stack*/
					result = val1 + val2;

					push_array(stack ,size ,&top ,result);

					break;

				case '-':
					/*if is sub then perform the operation and 
					 push the result into stack*/

					result = val1 - val2;

					push_array(stack ,size ,&top ,result);

					break;

				case '*':
					/*if is multiplication then perform the operation and 
					 push the result into stack*/

					result = val1 * val2;

					push_array(stack ,size ,&top ,result);

					break;

				case '/':
					/*if is division then perform the operation and 
					 push the result into stack*/

					result = val1 / val2;

					push_array(stack ,size ,&top ,result);

					break;
			}
		}
		/*check char array not equal to NULL*/
			idx--;
	}
	/*pop the final result and print*/
printf("%d\n",pop_array(stack ,&top));
}

