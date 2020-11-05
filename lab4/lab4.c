//Lab 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Team {
  char name[100];
  int handicap;
};

int myStrStr(char haystack[], char needle[], char buffer[]);
struct Team *game(struct Team *team_a, struct Team *team_b);
struct Team *tournament(struct Team *league[]);

int main() {

  //-----------------PART 1 -----------------------
  printf("Part 1\n\n");
  char haystack[100], needle[100], buffer[100];
  int result;
  strcpy(haystack, "apple");
  strcpy(needle, "ppl");
  result = myStrStr(haystack, needle, buffer);
  printf("haystack: %s, needle: %s, buffer: %s, result: %d\n",
	 haystack, needle, buffer, result);
  
  strcpy(haystack, "orange");
  strcpy(needle, "ge");
  result = myStrStr(haystack, needle, buffer);
  printf("haystack: %s, needle: %s, buffer: %s, result: %d\n",
	 haystack, needle, buffer, result);
  strcpy(haystack, "blueberry");
  strcpy(needle, "ueber");
  result = myStrStr(haystack, needle, buffer);
  printf("haystack: %s, needle: %s, buffer: %s, result: %d\n",
	 haystack, needle, buffer, result);
  
  strcpy(haystack, "strawberry");
  strcpy(needle, "strawberry");
  result = myStrStr(haystack, needle, buffer);
  printf("haystack: %s, needle: %s, buffer: %s, result: %d\n",
	 haystack, needle, buffer, result);
  
  strcpy(haystack, "grapefruit");
  strcpy(needle, "terrible");
  result = myStrStr(haystack, needle, buffer);
  printf("haystack: %s, needle: %s, buffer: %s, result: %d\n",
	 haystack, needle, buffer, result);

  //-----------------PART 2 -----------------------
  printf("\nPart 2\n\n");
  struct Team team1 = {"team1", 5}, team2 = {"team2", 5}, team3 = {"team3", 5},
	      team4 = {"team4", 5}, team5 = {"team5", 0}, team6 = {"team6", 0}, 
	      team7 = {"team7", 0}, team8 = {"team8", 0};
  struct Team *winner;
  struct Team *league[8] = {&team1, &team2, &team3, &team4,
		     &team5, &team6, &team7, &team8};
  
  srand(time(0));
  // game(&team1, &team2);
  winner = tournament(league);
  printf("\nThe winner of the tournament is: %s!!!\n", winner->name);
  return 0;
}

struct Team *tournament(struct Team *league[]) {
  int game_num = 0;
  int i;
  struct Team *winners[7];

  //Round 1
  printf("Round 1:\n");
  for(i = 0; i < 8; i+=2) {
    winners[game_num] = game(league[i], league[i+1]);
    printf("    Game %d: winner is %s\n", game_num + 1, winners[game_num]->name);
    game_num++;
  }

  //Round 2
  printf("\nRound 2:\n");
  for(i = 0; i < 4; i+=2) {
    winners[game_num] = game(winners[i], winners[i+1]);
    printf("    Game %d: winner is %s\n", game_num + 1, winners[game_num]->name);
    game_num++;
  }

  //Round 3
  printf("\nRound 3:\n");
  winners[game_num] = game(winners[4], winners[5]);
  printf("    Game %d: winner is %s\n", game_num + 1, winners[game_num]->name);
  
  return winners[game_num];
}

struct Team *game(struct Team *team_a, struct Team *team_b) {
  int score_a, score_b;
  struct Team *winner;
  score_a = rand() % 20;
  score_b = rand() % 20;
  //winner = score_a > score_b ? team_a : team_b;
  winner = score_a + team_a->handicap > score_b + team_b->handicap ? team_a : team_b;
  printf("Game: %s vs %s, score: %d+%d:%d+%d, winner: %s\n", 
	 team_a->name, team_b->name, score_a, team_a->handicap,
	 score_b, team_b->handicap, winner->name); 
  return winner;
}

int myStrStr(char haystack[], char needle[], char buffer[]) { 
  int i, j;
  for(i = 0; i < strlen(haystack); i++) {
    int p = i;
    for(j = 0; j < strlen(needle); j++) {
	if (haystack[p] == needle[j]) {
	  buffer[j] = needle[j];
	  if(j == strlen(needle) - 1) {
	    buffer[j+1] = '\0';
	    return 1;
	  }
	  p++;
	}
    }
  }
  return 0;
}

