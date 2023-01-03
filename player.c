#include "deck.h"
#include "card.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void printlist2(struct hand *head) { //prints linked list
        struct hand *temp = head;
        while (temp != NULL) {
                printf("%s%c ", (temp->top).rank, (temp->top).suit);
                temp = temp->next;
        }
}

int add_card(struct player* target, struct card* new_card) {  //adds new card

        struct hand *head = (*target).card_list;
        (*target).card_list = (struct hand*)malloc(sizeof(struct hand));
	if ((*target).card_list == NULL) { return -1; }
        (*target).card_list->top = (*new_card);
        (*target).card_list->next = NULL;
        (*target).card_list->next = head;
        head = (*target).card_list;
	return 0;
}

int remove_card(struct player* target, struct card* old_card) { // removes card from target list
	struct hand* temp = (*target).card_list;
	struct hand* prev = NULL;

	if (temp == NULL) {
		return 1;
	}

	while (temp->top.suit != (*old_card).suit || temp->top.rank[0] != (*old_card).rank[0] || temp->top.rank[1] != (*old_card).rank[1]) {
		prev = temp;
		temp = temp->next;
		if (temp == NULL) {
			return 1;
		}
	}

	if (prev != NULL) {
		prev->next = temp->next;
	}

	else {
		(*target).card_list = temp->next;
	}

	free(temp);
	return 0;
}

int delete_card_book_helper(struct player* target, char a) { // deletes card of one rank, helper for book
        struct hand* temp;
        temp = (*target).card_list;
        while ( temp != NULL ) { //scans through list and finds rank
		if (temp->top.rank[0] == a) {
			remove_card(target, &temp->top);
		}
		temp = temp->next;
	}
	return 0;
}

int delete_card_book_helper2(struct player* target, char a, char b) { // deletes card of rank 10, helper for book
        struct hand* temp;
        temp = (*target).card_list;
        while ( temp != NULL ) { //scans through hand and finds 10
                if ((temp->top.rank[0] == a) && (temp->top.rank[1] == b)) {
                        remove_card(target, &temp->top);
                }
                temp = temp->next;
        }
        return 0;
}

int find_index(struct player* target) { // finds next index of book, helper for book
	int a;
	int counter = 0;
        char l[13][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	for(a=0; a < 7; a++) {
		if ((*target).book[a][0] == l[0][0]) { //increments counter if rank is found
			counter++;
		}
                else if ((*target).book[a][0] == l[1][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[2][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[3][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[4][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[5][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[6][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[7][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[9][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[10][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[11][0]) {
                        counter++;
                }
                else if ((*target).book[a][0] == l[12][0]) {
                        counter++;
                }
		else if (((*target).book[a][0] == l[8][0]) && ((*target).book[a][1] == l[8][1])) {
			counter++;
		}
	}
	return counter;
}

char check_add_book(struct player* target) { // checks if a hand has a book and if so adds the rank to their book
	int c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, c10=0, cJ=0, cQ=0, cK=0, cA=0;
	char list_ranks[13][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	struct hand* temp;
	temp = (*target).card_list;
	int i = find_index(target);

	while ( temp != NULL ) { //scans through list
  		if (temp->top.rank[0] == '2') { //checks if each rank is equal to rank list
			c2++;
			if (c2 == 4) { //if there are four cards adds it to book and calls delete helper
				strcpy((*target).book[i], list_ranks[0]);
				delete_card_book_helper(target, '2');
				return '2';
				break;
			}
		}
                else if (temp->top.rank[0] == '3') {
			c3++;
                        if (c3 == 4) {
				strcpy((*target).book[i], list_ranks[1]);
                                delete_card_book_helper(target, '3');
				return '3';
                                break;
                        }
		}
                else if (temp->top.rank[0] == '4') {
			c4++;
                        if (c4 == 4) {
  				strcpy((*target).book[i], list_ranks[2]);
                                delete_card_book_helper(target, '4');
				return '4';
                                break;
                        }
		}
                else if (temp->top.rank[0] == '5') {
			c5++;
                        if (c5 == 4) {
                        	strcpy((*target).book[i], list_ranks[3]);
                                delete_card_book_helper(target, '5');
				return '5';
                                break;
                        }
		}
                else if (temp->top.rank[0] == '6') {
			c6++;
                        if (c6 == 4) {
                        	strcpy((*target).book[i], list_ranks[4]);
                                delete_card_book_helper(target, '6');
				return '6';
                                break;
                        }
		}
                else if (temp->top.rank[0] == '7') {
			c7++;
                        if (c7 == 4) {
                        	strcpy((*target).book[i], list_ranks[5]);
                                delete_card_book_helper(target, '7');
				return '7';
                                break;
                        }
		}
                else if (temp->top.rank[0] == '8') {
			c8++;
                        if (c8 == 4) {
                        	strcpy((*target).book[i], list_ranks[6]);
                                delete_card_book_helper(target, '8');
				return '8';
                                break;
                        }
		}
                else if (temp->top.rank[0] == '9') {
			c9++;
                        if (c9 == 4) {
                       		strcpy((*target).book[i], list_ranks[7]);
                                delete_card_book_helper(target, '9');
				return '9';
                                break;
                        }
		}
                else if ((temp->top.rank[0] == '1') && (temp->top.rank[1] == '0')) {
			c10++;
                        if (c10 == 4) {
                        	strcpy((*target).book[i], list_ranks[8]);
                                delete_card_book_helper2(target, '1', '0');
				return '1';
                                break;
                        }
		}
                else if (temp->top.rank[0] == 'J') {
			cJ++;
                        if (cJ == 4) {
                        	strcpy((*target).book[i], list_ranks[9]);
                                delete_card_book_helper(target, 'J');
				return 'J';
                                break;
                        }
		}
                else if (temp->top.rank[0] == 'Q') {
			cQ++;
                        if (cQ == 4) {
                        	strcpy((*target).book[i], list_ranks[10]);
                                delete_card_book_helper(target, 'Q');
				return 'Q';
                                break;
                        }
		}
                else if (temp->top.rank[0] == 'K') {
			cK++;
                        if (cK == 4) {
                        	strcpy((*target).book[i], list_ranks[11]);
                                delete_card_book_helper(target, 'K');
				return 'K';
                                break;
                        }
		}
                else if (temp->top.rank[0] == 'A') {
			cA++;
                        if (cA == 4) {
                        	strcpy((*target).book[i], list_ranks[12]);
                                delete_card_book_helper(target, 'A');
				return 'A';
                                break;
                        }
		}
		temp = temp->next;
	}
	return '0';
}

int search(struct player* target, char rank) { //searches for card rank in targets hand
        struct hand* temp;
        temp = (*target).card_list;
        while ( temp != NULL ) { // scans through hand of target
                if (temp->top.rank[0] == rank) {
                        return 1;
                }
                temp = temp->next;
        }
        return 0;
}

int transfer_cards(struct player* src, struct player* dest, char rank) { //transfers card, idk if this works
	struct hand* temp;
        temp = (*src).card_list;
        while ( temp != NULL ) { // scans through hand of target
                if (temp->top.rank[0] == rank) {
			if(((*src).card_list->top.rank == computer.card_list->top.rank) && ((*src).card_list->top.suit == computer.card_list->top.suit)) {
				printf("Player 2 has %s%c\n", temp->top.rank, temp->top.suit); // checks if the source is computer
			}
			else { // if it is not computer then the source is user
				printf("Player 1 has %s%c\n", temp->top.rank, temp->top.suit);
			}
			add_card(dest, &temp->top);
			remove_card(src, &temp->top);
                }
                temp = temp->next;
        }
        return 0;
}

int game_over(struct player* target) { // check if book has 7 ranks
	int a;
    	int counter = 0;
        char l[13][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        for(a=0; a < 7; a++) { //scans through book
                if ((*target).book[a][0] == l[0][0]) { // increments counter if there is a rank in there
                        counter++;
			if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[1][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[2][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[3][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[4][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[5][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[6][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[7][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[9][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[10][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[11][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if ((*target).book[a][0] == l[12][0]) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
                else if (((*target).book[a][0] == l[8][0]) && ((*target).book[a][1] == l[8][1])) {
                        counter++;
                        if (counter == 7) { return 1; }
                }
        }
        return 0;
}

int reset_player(struct player* target) { //frees memory of leftover cards and reintialize book
        struct hand* temp;
        temp = (*target).card_list;
        while ( temp != NULL ) { // scans through hand and frees memory
		free(temp);
                temp = temp->next;
        }
	int i;
	for (i=0; i < 7; i++) { // scans through book and sets to null
		(*target).book[i][0] = NULL;
                (*target).book[i][1] = NULL;
	}
        return 0;
}

void print_book(struct player* target) { //prints out book of target
	int i;
	for(i=0; i < 7; i++) {
		printf("%s ", (*target).book[i]);
	}
	printf("\n");
}

char computer_play(struct player* target) { // picks a random rank out of the computers hand
        struct hand* temp;
        temp = (*target).card_list;
	struct hand* iterator;
	iterator = (*target).card_list;
	int index = 0;
	int counter = 0;
        while ( temp != NULL ) { // counts the cards in the computers hand
		counter++;
                temp = temp->next;
        }

	srand( time(NULL) );
	int rand_index;
	rand_index = rand() % counter; //picks a random index
	char play;
	while ( iterator != NULL ) { // finds the rank of that random index
		if (index == rand_index) {
			play = iterator->top.rank[0];
			printf("%c\n", play);
                	return play;
		}
		index++;
		iterator = iterator->next;
	}
}

char user_play(struct player* target) { // user inputs a rank
	char rank2;
	char test;
	scanf("%c", &rank2);
        scanf("%c", &test);

	while(search(&user, rank2) == 0) { // checks if the rank is in the users hand
		printf("Error - must have at least one card from rank to play\n");
		printf("Player's 1 turn, enter a Rank: ");
        	scanf("%c", &rank2);
		scanf("%c", &test);
	}
	return rank2;
}
