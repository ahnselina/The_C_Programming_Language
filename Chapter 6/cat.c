#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char * argv[])
{
    FILE *ifp;
	FILE *ofp;
	if(argc == 1)
	   filecopy(stdin, stdout);
	/*else if(argc == 3)
	{
	    if(((ifp = fopen(argv[1], "r")) != NULL) && ((ofp = fopen(argv[2], "a")) != NULL))
		{
		    filecopy(ifp, ofp);
			fclose(ifp);
			fclose(ofp);
		} else
		{
		     printf("ERROR: can't open file");
			 exit(1);
		}
	} */else
	{
	     while(--argc > 0)
		      if((ifp = fopen(*++argv, "r")) == NULL)
			  {
			      printf("cat: can,t open %s\n", *argv);
				  exit(1);
			  } else
			  {
			     filecopy(ifp, stdout);
				 fclose(ifp);
			  }
	}
 
    return 0;
}

void filecopy(FILE * ifp, FILE * ofp)
{
     int c;
	 while((c = getc(ifp)) != EOF)
	       putc(c, ofp);
}