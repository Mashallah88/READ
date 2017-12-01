#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	FILE *data;
	if (argc < 2)
		printf("You did not enter a file name. Please enter it!\n");
	else
	{
		data = fopen(argv[1], "rb");
		if (data==NULL)
			printf("This file does not exist in this folder.\n");
	} 
	
	char arr[255];
	while (fgets (arr, 255, data) != NULL) 
	{
		printf("%s\n", arr);
	}


	rewind(data);
	long size;
	fseek(data, 0L, SEEK_END);
	size = ftell(data);
	printf("The file size is %d bytes!", size);
	fclose(data);

	return 0;
}