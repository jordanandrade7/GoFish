//#include "player.h"
#include "deck.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int shuffle() {

        char suits[5]={'D','S','C','H'};
        char ranks[13][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	deck_instance = *(struct deck*)malloc(sizeof(struct deck)); // creates deck

	int i;
	int j;
	int k=0;
	for (i=0; i < 13; i++) { // assigns ranks and suits to card
		for (j=0; j < 4; j++) {
			strcpy(deck_instance.list[k].rank, ranks[i]);
			deck_instance.list[k].suit = suits[j];
			k++;
		}
	}

	srand( time(NULL) ); // shuffles deck
	int t;
	int deck_size = 52;
	for (t=0; t < 52; t++) {
		int rand_index = rand() % deck_size;
		struct card temp = deck_instance.list[t];
		deck_instance.list[t] = deck_instance.list[rand_index];
		deck_instance.list[rand_index] = temp;
	}
	return 0;
}

size_t deck_size() { //returns deck size
        int counter=0;
	int index=0;
        while (deck_instance.list[index].suit != NULL) { // scans through deck and increments counter
                counter++;
                index++;
        }
	return 0;
}

void printlist(struct hand *head) { //prints linked list
        struct hand *temp = head;
        while (temp != NULL) {
                printf("%s%c ", (temp->top).rank, (temp->top).suit);
                temp = temp->next;
	}
}

int deal_player_cards(struct player* target) { // deals target 7 cards

	int i; // creates linked list for target
	struct hand *head = NULL;
	for(i=0; i < 7; i++) { // assigns 7 cards to target
		(*target).card_list = (struct hand*)malloc(sizeof(struct hand));
		(*target).card_list->top = deck_instance.list[i];
		(*target).card_list->next = NULL;
		(*target).card_list->next = head;
		head = (*target).card_list;
	}

	int decrease_deck=53; // deletes seven cards from deck list
	int s=0;
	int p;
	for (p=0; p < 7; p++) {
		decrease_deck = decrease_deck - 1;
		s=0;
        	for(s=0; s < decrease_deck; s++) {
                	deck_instance.list[s] = deck_instance.list[s+1];
                	deck_instance.list[s] = deck_instance.list[s+1];
        	}
	}
	return 0;
}

struct card* next_card( ) { // pointer to next card and deletes it
	deck_instance.top_card = deck_instance.list[0];
	int decrease_deck = 52;
	int s = 0;
	for (s=0; s<decrease_deck; s++) {
		deck_instance.list[s] = deck_instance.list[s+1];
	}
	return &deck_instance.top_card;
}
