#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	char action;
	char hit;
	int repeater = 1;
	int a = 1;
	int b = 1;
	int pace = 0;
	int dace = 0;
	int dpiccheck = 0;
	int dacecheck = 0;
	int hitno = 0;
	int dhitno = 0;
	int player = 0;
	int playertemp = 0;
	int dealer = 0;
	int dcheck = 0;
	while (repeater == 1) {
		while (a == 1) {
			printf("blackjack.\n Rules\n 1. d for draw to start the game\n 2. h for hit\n 3. s for stand\n 4. x to close the game\n");
			std::cin >> action;
			if (action == 'd') {
				printf("\ndrawing\n");
				int pone = (rand() % 13) + 1;
				if (pone == 11) {
					std::cout << "your first card is j" << std::endl;
					pone = 10;
				}
				else if (pone == 12) {
					std::cout << "your first card is q" << std::endl;
					pone = 10;
				}
				else if (pone == 13) {
					std::cout << "your first card is k" << std::endl;
					pone = 10;
				}
				else if (pone == 1) {
					std::cout << "your first card is a" << std::endl;
					pone = 11;
					pace = pace + 1;
				}
				else {
					std::cout << "your first card is " << pone << std::endl;
				}
				int ptwo = (rand() % 13) + 1;
				if (ptwo == 10) {
					std::cout << "your second card is 10" << std::endl;
					ptwo = 10;
					if (pone == 11) {
						printf("blackjack! you win\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				else if (ptwo == 11) {
					std::cout << "your second card is j" << std::endl;
					ptwo = 10;
					if (pone == 11) {
						printf("blackjack! you win\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				else if (ptwo == 12) {
					std::cout << "your second is q" << std::endl;
					ptwo = 10;
					if (pone == 11) {
						printf("blackjack! you win\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				else if (ptwo == 13) {
					std::cout << "your second card is k" << std::endl;
					ptwo = 10;
					if (pone == 11) {
						printf("blackjack! you win\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				else if (ptwo == 1) {
					std::cout << "your second card is a" << std::endl;
					ptwo = 11;
					pace = pace + 1;
					if (pone == 10) {
						printf("blackjack! you win\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				else {
					std::cout << "your second card is " << ptwo << std::endl;
				}
				player = pone + ptwo;
				playertemp = player;
				int done = (rand() % 13) + 1;
				dcheck = (rand() % 13) + 1;
				if (done == 11) {
					std::cout << "dealer's first card is j" << std::endl;
					done = 10;
					if (dcheck == 1) {
						std::cout << "dealer's second card is a" << std::endl;
						printf("dealer blackjack. you lose\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				else if (done == 12) {
					std::cout << "dealer's first card is q" << std::endl;
					done = 10;
					if (dcheck == 1) {
						std::cout << "dealer's second card is a" << std::endl;
						printf("dealer blackjack. you lose\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				else if (done == 13) {
					std::cout << "dealer's first card is k" << std::endl;
					done = 10;
					if (dcheck == 1) {
						std::cout << "dealer's second card is a" << std::endl;
						printf("dealer blackjack. you lose\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
					else {
						dacecheck = 1;
					}
				}
				else if (done == 1) {
					std::cout << "dealer's first card is a" << std::endl;
					done = 11;
					dace = dace + 1;
					if (dcheck == 11) {
						std::cout << "dealer's second card is j" << std::endl;
						printf("dealer blackjack. you lose\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
					else if (dcheck == 12) {
						std::cout << "dealer's second card is q" << std::endl;
						printf("dealer blackjack. you lose\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
					else if (dcheck == 13) {
						std::cout << "dealer's second card is k" << std::endl;
						printf("dealer blackjack. you lose\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
					else if (dcheck == 10) {
						std::cout << "dealer's second card is 10" << std::endl;
						printf("dealer blackjack. you lose\n\n");
						a = 0;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
					else {
						dpiccheck = 1;
					}
				}
				else {
					std::cout << "dealer's first card is " << done << std::endl;
				}
				a = a + 1;
				dealer = done;
			}
			else if (action == 'x') {
				repeater = repeater + 1;
				a = a + 1;
				return 1;
			}
			else {
				printf("no\n");
			}
		}
		while (a == 2) {
			std::cin >> hit;
			if (hit == 's') {
				b = 2;
			}
			if (hit == 'h' && b == 1) {
				player = playertemp;
				int phit = (rand() % 13) + 1;
				if (phit == 11) {
					std::cout << "your draw is j" << std::endl;
					phit = 10;
				}
				else if (phit == 12) {
					std::cout << "your draw is q" << std::endl;
					phit = 10;
				}
				else if (phit == 13) {
					std::cout << "your draw is k" << std::endl;
					phit = 10;
				}
				else if (phit == 1) {
					std::cout << "your draw is a" << std::endl;
					phit = 11;
					pace = pace + 1;
				}
				else {
					std::cout << "your draw is " << phit << std::endl;
				}
				player = player + phit;
				playertemp = player;
				if (player > 21 && pace > 0) {
					player = player - 1;
					if (player > 21 && pace > 0) {
						player = player - 9;
						if (player > 21 && pace > 1) {
							player = player - 1;
							if (player > 21 && pace > 1) {
								player = player - 9;
							}
						}
					}
				}
				hitno = hitno + 1;
				if (hitno == 3 && player <= 21) {
					std::cout << "your hand  is " << player << std::endl;
					printf("you win\n\n");
					a = 1;
					repeater = 1;
					b = 1;
					hitno = 0;
					dhitno = 0;
					pace = 0;
					dace = 0;
					dpiccheck = 0;
					dacecheck = 0;
				}
				if (player > 21) {
					b = b + 1;
				}
			}
			else if (hit == 's' && b == 2) {
				int dtwo = dcheck;
				if (dtwo == 11) {
					std::cout << "dealer's second card is j" << std::endl;
					dtwo = 10;
				}
				else if (dtwo == 12) {
					std::cout << "dealer's second card is q" << std::endl;
					dtwo = 10;
				}
				else if (dtwo == 13) {
					std::cout << "dealer's second card is k" << std::endl;
					dtwo = 10;
				}
				else if (dtwo == 1) {
					std::cout << "dealer's second card is a" << std::endl;
					dtwo = 11;
					dace = dace + 1;
				}
				else {
					std::cout << "dealer's second card is " << dtwo << std::endl;
				}
				dealer = dealer + dtwo;
				while (dealer < 13) {
					int dhit = (rand() % 13) + 1;
					if (dhit == 11) {
						std::cout << "dealer hits and drew j" << std::endl;
						dhit = 10;
					}
					else if (dhit == 12) {
						std::cout << "dealer hits and drew q" << std::endl;
						dhit = 10;
					}
					else if (dhit == 13) {
						std::cout << "dealer hits and drew k" << std::endl;
						dhit = 10;
					}
					else if (dhit == 1) {
						std::cout << "dealer hits and drew a" << std::endl;
						dhit = 11;
						dace = dace + 1;
					}
					else {
						std::cout << "dealer hits and drew " << dhit << std::endl;
					}
					dealer = dealer + dhit;
					if (dealer > 21 && dace > 0) {
						dealer = dealer - 1;
							if (dealer > 21 && dace > 0) {
								dealer = dealer - 9;
								if (dealer > 21 && dace > 1) {
									dealer = dealer - 1;
									if (dealer > 21 && dace > 1) {
										dealer = dealer - 9;
									}
								}
							}
					}
					dhitno = dhitno + 1;
					if (dhitno == 3 && dealer <= 21) {
						std::cout << "dealer's hand  is " << dealer << std::endl;
						printf("you lose\n\n");
						a = 1;
						repeater = 1;
						b = 1;
						hitno = 0;
						dhitno = 0;
						pace = 0;
						dace = 0;
						dpiccheck = 0;
						dacecheck = 0;
					}
				}
				if (player > 21 && dealer <= 21) {
					std::cout << "your hand  is " << player << std::endl;
					std::cout << "dealer's hand  is " << dealer << std::endl;
					printf("bust\n you lose\n\n");
				}
				else if (player <= 21 && dealer > 21) {
					std::cout << "your hand  is " << player << std::endl;
					std::cout << "dealer's hand  is " << dealer << std::endl;
					printf("dealer busts\n you win\n\n");
				}
				else if (player > 21 && dealer > 21) {
					std::cout << "your hand  is " << player << std::endl;
					std::cout << "dealer's hand  is " << dealer << std::endl;
					printf("both bust\npush\n\n");
				}
				else if (player > dealer) {
					std::cout << "your hand  is " << player << std::endl;
					std::cout << "dealer's hand  is " << dealer << std::endl;
					printf("you win\n\n");
				}
				else if (player < dealer) {
					std::cout << "your hand  is " << player << std::endl;
					std::cout << "dealer's hand  is " << dealer << std::endl;
					printf("you lose\n\n");
				}
				else if (player = dealer) {
					std::cout << "your hand  is " << player << std::endl;
					std::cout << "dealer's hand  is " << dealer << std::endl;
					printf("push\n\n");
				}
				a = 1;
				repeater = 1;
				b = 1;
				hitno = 0;
				dhitno = 0;
				pace = 0;
				dace = 0;
				dpiccheck = 0;
				dacecheck = 0;
			}
			else {
				printf("no\n");
			}
		}
	}
}