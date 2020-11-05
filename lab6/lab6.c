#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//structs for linked list
struct Train {
  struct Car *first_car;
  struct Car *last_car;
};

struct Car {
  int weight;
  struct Car *next_car;
  struct Car *prev_car;
};


struct Train *create_train();
struct Car *create_car(int weight);
void print_train(struct Train *train);
void add_car(struct Train *train, int weight);
struct Car *front(struct Train *train);
struct Car *insert(struct Train *train, int index, int weight);
int delete(struct Train *train, int removal_place);
void search_forward(struct Train *train, int weight);
void search_backwards(struct Train *train, int weight);
void push(struct Train *stack, int value);
struct car *pop(struct Train *stack);

int main() {
  int num_cars, cargo_weight, search_weight;
  struct Train *train; 
  struct Car *car;
  int i, p;
  
  printf("Enter the number of cars: ");
  scanf("%d", &num_cars);
  printf("Enter the weight for the %d cars: ", num_cars);
  scanf("%d", &cargo_weight);

  // Create Train of specified length and weights
  train = create_train();
  for(i=0; i<num_cars; i++) {
    add_car(train, cargo_weight);
    cargo_weight++;
  }
  printf("You created:\n");
  print_train(train);
  printf("Your train with 10 random numbers added to the end of it:\n");
  //generate 10 random numbers 
  srand(time(0));
  for(i=0; i<10; i++) {
    p = rand() % 30;
    if(insert(train, num_cars+i, p) != 0) {
	print_train(train);
    }
  }
   
  /*
  // Insert a new train at position 4
  printf("Insert at pos. 4\n");
  if (insert(train, 4, 6) != 0) {
    print_train(train);
  }
 
  // Delete at postion 2
  printf("Delete at pos. 2\n");
  if (delete(train, 2) != 0) {
    print_train(train);
  }
  */
  printf("Enter a weight to search in the linked list: ");
  scanf("%d", &search_weight);
  search_forward(train, search_weight);
  search_backwards(train, search_weight);
 
  for(i=0; i<10; i++) {
    if (delete(train, num_cars) != 0) {
       print_train(train);
    }
  }

    //delete(train, 5);
    // print_train(train);
  // Stack input work in progress
  /*
  int n1, n2, n3, n3, n4, n5;
  struct Train *stack; 
  stack = create_train();

  printf("Enter 5 integers to be added to a stack");
  scanf("%d %d %d %d %d\n", &n1, &n2, &n3, &n4, &n5);
  
  push(stack, n1);
  push(stack, n2);
  push(stack, n3);
  push(stack, n4);
  push(stack, n5);
  printf("Reverse order:\n");
  printf("%d ", pop(stack));
  printf("%d ", pop(stack));
  printf("%d ", pop(stack));
  printf("%d ", pop(stack));
  printf("%d ", pop(stack));
  printf("\n");  
  */
}

struct Car *front(struct Train *train) {
  return train->first_car;
}

struct Car *end(struct Train *train) {
  return train->last_car;
}

struct Train *create_train() {
  struct Train *newTrain = (struct Train*) malloc(sizeof(struct Train));
  newTrain->first_car = NULL;
  newTrain->last_car = NULL;
  return newTrain;
}

struct Car *create_car(int weight) {
  struct Car *car = (struct Car*) malloc(sizeof(struct Car));
  car->weight = weight;
  car->next_car = NULL;
  car->prev_car = NULL;
  return car;
}

void print_train(struct Train *train) {
  struct Car *current_car = train->first_car;
  printf("Train: ");
  while(current_car != NULL) {
    printf("%d, ", current_car->weight);
    current_car = current_car->next_car;
  }
  if(current_car == NULL) {
  printf("NULL\n");
  }
}

void add_car(struct Train *train, int weight) {
  struct Car *current_car = front(train);
  struct Car *new_car;

  if (current_car == NULL) {
    train->first_car = create_car(weight);
  }
  else {
    while(current_car->next_car != NULL) {
      current_car = current_car->next_car;
    }
    new_car = create_car(weight);
    current_car->next_car = new_car;
    new_car->prev_car = current_car;
    train->last_car = new_car;
  }
}
      
struct Car *insert(struct Train *train, int insert_place, int weight) {
  struct Car *new_car = create_car(weight);
  struct Car *current_car = front(train);

  if (insert_place == 0) {
    new_car->next_car = current_car;
    train->first_car = new_car;
  }
  int index = 1;
  while(index < insert_place && current_car->next_car != NULL) {
    current_car = current_car->next_car;
    index++;
  }
  if (index < insert_place) {
    printf("The train is too small to put a car there, input a smaller number!\n");
    return 0;
  }
  new_car->next_car = current_car->next_car;
  current_car->next_car = new_car;
  return new_car;
}

/* Delete from train car at position removal_place
   Return 1 on success, 0 on fail
 */
int delete(struct Train *train, int removal_place) {
  struct Car *current_car = front(train);
  
  int index = 0;
  // printf("current_car weight: %d\n", current_car->weight);
  while(index < removal_place && current_car->next_car != NULL) {
    //printf("index: %d, removal_place: %d\n", index, removal_place);
    current_car = current_car->next_car;
    index++;
  }

  if (index < removal_place) {
    printf("The train is too small to delete that car, input a smaller number!\n");
    return 0;
  }
  // temp_node = current_car->next_car;
  current_car->next_car = current_car->next_car->next_car;
  return 1; // true;
}

/* Search for a car with a given weight
   in Train 
*/
void search_forward(struct Train *train, int weight) {
  struct Car *car = front(train);
  int pos = 0;
  int found = 0;

  while(car) {
    if (car->weight == weight) {
      printf("Search Forward: %d steps to find Car with weight: %d\n", pos, weight);
      found = 1;
      break;
    }     
    car = car->next_car;
    pos++;
  }
  if (!found) {
    printf ("Search Forward: Car with weight %d not found\n", weight);
  }
}
/* Search backwards for a car with a given weight
   in Train 
*/

void search_backwards(struct Train *train, int weight) {
  struct Car *car = end(train);
  int pos = 0;
  int found = 0;

  while(car) {
    if (car->weight == weight) {
      printf("Search Backwards: %d steps to find Car with weight: %d\n", pos, weight);
      found = 1;
      break;
    }     
    car = car->prev_car;
    pos++;
  }
  if (!found) {
    printf ("Search Forward: Car with weight %d not found\n", weight);
  }
}

/* work in progress 
void push(struct Train *stack, int value) {
  add_car(stack, value);
}
struct car *pop(struct Train *stack) {
  return stack->last_car;
  // still need to call delete(stack, unk);
}
*/
