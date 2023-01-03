#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deck.h"
#include "player.h"

void start_game(){ // starts the game by shuffling the deck and dealing the cards
printf("Shuffling deck...\n\n");
        shuffle();
        deal_player_cards(&user);
        deal_player_cards(&computer);
}

int main(int args, char* argv[])
{
	int turn = 1; // intialize turn variable to determine whose turn it is
	int check_search;
	char rank_picked;
	char play_again;
	char rank_picked2;


	start_game();

	while(1){
		printf("Player 1's Hand - "); //prints out player 1 hand and both players books
		printlist(user.card_list);
		printf("\n");
		printf("Player 1's book - ");
		print_book(&user);
		printf("Player 2's book - ");
		print_book(&computer);

		if (game_over(&user) == 1){ // checks if the game is over for user
			printf("Player 1 wins! %d-%d\n\n", find_index(&user), find_index(&computer));
			printf("Do you want to play again? [Y/N] ");
			scanf("%c", &play_again);
			printf("\n");
			if (play_again == 'Y'){ //promts to play again, if so call start game and reset
				reset_player(&user);
				reset_player(&computer);
				start_game();
				printf("Player 1's Hand - ");
                		printlist(user.card_list);
				printf("\n");
                		printf("Player 1's book - ");
				print_book(&user);
                		printf("Player 2's book - ");
				print_book(&computer);
			}
			else{
				break;
			}
		}
		if (game_over(&computer) == 1){ // checks if the game is over for computer
	                printf("Player 2 wins! %d-%d\n\n", find_index(&computer), find_index(&user));
                        printf("Do you want to play again? [Y/N] "); // prompts to play again
               	        scanf("%c", &play_again);
			printf("\n");
                       	if (play_again == 'Y'){ // if yes call start game and reset
                             	reset_player(&user);
               	                reset_player(&computer);
                                start_game();
                                printf("Player 1's Hand - ");
                       	        printlist(user.card_list);
				printf("\n");
                               	printf("Player 1's book - ");
				print_book(&user);
               	                printf("Player 2's book - ");
				print_book(&user);
                   	        }
			else{
				break;
			}
		}

		if (turn == 1){ // if it is player 1s turn
			printf("Player 1's turn, enter a Rank: "); // ask for input
			rank_picked = user_play(&user);
			check_search = search(&computer, rank_picked);
			if (check_search == 1){ // if computer has the card
				transfer_cards(&computer, &user, rank_picked);
				turn--;
			}
			else{ // if the computer doesnt have the rank
				if (rank_picked == '1') { //special case for 10
					printf("  -Player 2 has no 10's\n", rank_picked);
				}
				else { // says player 2 doesnt have the card
					printf("  -Player 2 has no %c's\n", rank_picked);
				}

				printf("  -Go fish, Player 1 draws %s%c\n", deck_instance.list[0].rank, deck_instance.list[0].suit);
				if (deck_instance.list[0].rank[0] == rank_picked){ // if the player draws a card of the chosen rank
					turn--;
				}
				add_card(&user, next_card());
			}
			char book_added;
			book_added = check_add_book(&user);
			if (book_added != '0'){ // if a book is added
				if (book_added == '1') { // special case for 10
					printf("Player 1 books 10");
				}
				else { // for any other book that was added
					printf("Player 1 books %c\n", book_added);
				}
			}
			turn++;
			if (turn == 1){ // if player chose a rank player 2 has
				printf("\n");
				printf("Player 1 gets another turn\n\n");
			}
			else{ //print statement for player 2 turn
				printf("Player 2's turn\n\n");
				printf("Player 1's Hand - ");
                		printlist(user.card_list);
                		printf("\n");
                		printf("Player 1's book - ");
                		print_book(&user);
                		printf("Player 2's book - ");
                		print_book(&computer);
			}
		}
                if (turn == 2){ // if it is player 2s turn
                        printf("Player 2's turn, enter a Rank:  "); // enter a given rank
			rank_picked2 = computer_play(&computer);
                        check_search = search(&user, rank_picked2);
                        if (check_search == 1){ //if the user has the card
                                transfer_cards(&user, &computer, rank_picked2);
                                turn = turn + 1;
                        }
                        else{ // if the user does not have the card
				if (rank_picked2 == '1') { // special case for 10
					printf("  -Player 1 has no 10's\n");
				}
				else { // if user doesnt have the rank
 					printf("  -Player 1 has no %c's\n", rank_picked2);
				}
                                printf("Go fish, Player 2 draws a card\n"); // computer draws a card
                                if (deck_instance.list[0].rank == rank_picked2){ // if the drawn card is equal to rank
                                        turn = turn + 1;
                                }
                                add_card(&computer, next_card());
                        }
                        char book_added2;
                        book_added2 = check_add_book(&computer);
                        if (book_added2 != '0'){ // if book is added for computer
                                if (book_added2 == '1') { // special case for 10
                                        printf("Player 2 books 10");
				}
                                else { // prints added book
                                        printf("Player 2 books %c\n", book_added2);
                                }
                        }
                        turn = turn - 1;
                        if (turn == 2){ // if they guessed rank correctly they get another turn
                                printf("Player 2 gets another turn\n\n");
                        }
                        else{
                                printf("Player 1's turn\n\n");
                        }

		}
	}
}

