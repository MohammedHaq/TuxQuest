#include<stdio.h>
#include<stdlib.h>

/**
 *
 *@param The parameter to the function is a pointer indicating a filepath to an ascii art file which needs to be printed
 *@return the function is a void and therefore does not return a value, it only prints the ascii art it is provided the file path to.
 *
 */

void displayImage(const char *filename) {
  char buf[100];
  FILE * fh = fopen(filename,"r");
  while (fgets(buf,sizeof(buf),fh)) {
    printf("%s",buf);
  }
  
  fclose(fh);
}


