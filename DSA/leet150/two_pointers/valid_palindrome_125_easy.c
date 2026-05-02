#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* clean_string(char * input, size_t buffer_size){

    char * output = malloc(buffer_size + 1); // plus one for null terminator
    int output_curr = 0;

    for (int i = 0; i < buffer_size; ++i) {
        if (isalnum(input[i])) {
            output[output_curr] = tolower(input[i]);
            output_curr++;
        }
    }
    output[output_curr] = '\0';
    
    return output;
}

int isPalindrome(char* s) {

  char *cleaned = clean_string(s, strlen(s));
  size_t foward = 0;
  size_t backward = strlen(cleaned) -1;

  // empty string case
  if(cleaned[0] == '\0') 
  {
    free(cleaned); 
    return 1;
  }
  // one from each side until they hit
  while (foward < backward) {
    
    if (cleaned[foward] == cleaned[backward]) {
      foward++;
      backward--;
      continue;
    }
    else 
    {
      // not polindrome
      //printf("NO");
      free(cleaned);
      return 0;
    }
  }
  //printf("yes");
  free(cleaned);
  return 1;
}
