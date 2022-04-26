# ifndef CARD_H // protects header file
# define CARD_H 

class Card
{
private:
	char rank;
	char suit;
public:
	Card();
	Card(char, char);
	void setCard(char, char);
	int getValue();
	void showCard();
};
# endif // protects header file