#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//structure
struct Names {
  char *first_name;
  char *last_name;
  char *jedi_name;
};

//prototypes
void jedi_name_gen2(struct Names *name);
void jedi_name_gen(char *first, char *last, char *jedi_name);
void add_name();
void print_jedi_names();
void *allocate(unsigned int size);
void *deallocate(void*, int size);

//global variables
int heap_usage = 0;

int main() {
  add_name();
  print_jedi_names();
  return 0;
}

/*===================Part 1 Functions======================*/
//jedi name generator function with pointers using first and last name
//takes first 3 letters of last name and first 2 letters of first name
void jedi_name_gen(char *first, char *last, char *jedi_name) {
  int i;
  char *p, *q;
  q = jedi_name;
  //first 3 letters of last name  
  p = last;
  for(i = 0; i <3; p++, q++, i++) {
    *q=tolower(*p);
  }
  //first 2 letters of first name
  p = first;
  for(i = 0; i < 2; p++, q++, i++) {
    *q=tolower(*p);
  }
   *q = '\0';
}

//function to get and append names from user to end of file
void add_name() {
  char name[100];
  printf("Enter a full name: ");
  fgets(name, 256, stdin);
  FILE *file_ptr;
  file_ptr = fopen("names.txt", "a");
  fprintf(file_ptr, "%s", name);
  fclose(file_ptr);
}

//function to generate the jedi names of the names
void print_jedi_names() {
  char char_indicator;
  FILE *file_ptr;
  struct Names name;
  int results;
  
  name.first_name = (char *)allocate(100*sizeof(char));
  name.last_name = (char *)allocate(100*sizeof(char));
  name.jedi_name = (char *)allocate(100*sizeof(char));

  file_ptr = fopen("names.txt", "r");
  results = fscanf(file_ptr, "%s %s", name.first_name, name.last_name);  
  while(results != EOF) {
    jedi_name_gen2(&name);
    printf("%s %s, %s\n", name.first_name, name.last_name, name.jedi_name);
    results = fscanf(file_ptr, "%s %s", name.first_name, name.last_name);
  }
  fclose(file_ptr);

  deallocate(name.first_name, 100*sizeof(char));
  deallocate(name.last_name, 100*sizeof(char));
  deallocate(name.jedi_name, 100*sizeof(char));
}  

/*===================Part 2 Functions======================*/
//function to allocate memory 
void *allocate(unsigned int size) {
  heap_usage = heap_usage + size;
  printf("Memory allocated: %d\t Memory currently in use: %d\n", 
	 size, heap_usage); 
  return malloc(size);
}

//function to deallocate memory
void *deallocate(void *ptr, int size) {
  heap_usage = heap_usage - size;
  free(ptr);
  printf("Memory freed: %d\t Memory currently in use: %d\n",
	 size, heap_usage); 
  return (void *)NULL;
}

//function to generate the jedi names of the names with names structure
void jedi_name_gen2(struct Names *name) {
  int i, j;
  for(i = 0; i < 3 && i < strlen(name->last_name); i++) {
    if(i==0) {
      name->jedi_name[i] = name->last_name[i];
    }
    else {
      name->jedi_name[i] = tolower(name->last_name[i]);
    }
  }
  for(j = 0; j < 2 && j < strlen(name->first_name); j++) {
    name->jedi_name[i+j] = tolower(name->first_name[j]);
  }
  name->jedi_name[i+j] = '\0';
}
