#include <stdio.h>
#include <string.h>

void reverse(char* str) {

  int j = strlen(str)-1;
  int i = 0;

  char tmp;
  
  while (i < j) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;

    i++;
    j--;
  }
  
}

int main() {
  char* my_string = strdup("abc");
  reverse(my_string);
  
  printf("Expected 'cba'\n");
  printf("%s\n", my_string);
  
  return 0;
}
