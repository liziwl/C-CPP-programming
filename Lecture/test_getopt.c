#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int ch=0;
	
	printf("\nargc: %d\n",argc);
	for(int i=0;i<argc;i++)
	{
		printf("argv_%d :%s\n",i,argv[i]);
	}
	
	  getchar();
  
	  printf("test getopt\n");
	  
	  printf("AT very Begining , optind :%d\n\n",optind);
	  while((ch=getopt(argc,argv,"i:s:cde"))!=-1)
	  {
		getchar();
		printf("optind:%d\n",optind);
		printf("optarg:%s\n",optarg);
		printf("opt flag:%c\n",ch);
		switch(ch)
		{
		  case 's':
			printf("the arg of s :'%s'\n",optarg);
			break;
		  case 'i':
			printf("the arg of i :'%s'\n",optarg);
			break;
		  case 'c':
			printf("option c\n");
			break;
		  case 'd':
			printf("option d\n");
			break;
		  case 'e':
			printf("option e\n");
			break;
		  default:
			printf("other option:%c\n",ch);
		}
	  }
		
		getchar();
		printf("To get other part of arg parameters\n");

		// get num for columns
		int iarg = optind, size = 0;
		for (; iarg < argc; iarg++)
		{
			printf("iarg : %d ,argc : %d\n",iarg,argc);
			if (strtol(argv[iarg], NULL, 10) != 0)
			{
				size++;
			}
			else
			{
				break;
			}
		}

		int *rows = (int *)malloc(size * sizeof(int));
		if(NULL == rows)
		{
			printf("!malloc for %d size of int failed,main function return\n",size);
			return 1;
		}
		else
		{
			printf("There is other %d int parameters,malloc %d interger for them\n",size,size);
		}
		// get rows' numbers
		int i = 0;
		for (iarg = optind; iarg < argc; iarg++)
		{
			if (strtol(argv[iarg], NULL, 10) > 0)
			{
				rows[i] = (int)strtol(argv[iarg], NULL, 10);
				printf("rows_%d: %d\n",i,rows[i]);
				i++;
			}
			else
			{
				break;
			}
		}
		free(rows);
		return 0;
		
	}