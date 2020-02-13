# Poker Game Class Diagram - Landon M Brown
**This is a small diagram of what our poker class should _about_ look like**
### Class Diagram
>
>![Poker Class](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Poker.jpg "Poker Class")
>
>
### Poker Game
>
>![Poker Game](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/PokerGame.jpg "Poker Game")
>*Game class keeps track of number of players, whose turn it is, score, and if someone has won yet. it can start/stop a game and display the scoreboard.*
>
### Player
>
>![Player](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Player.jpg "Player")
>*Each player has a name, hand, bank and possibly a blind on their ante. They can perform normal poker functions.*
>
### Dealer
>
>![Dealer](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Dealer.jpg "Dealer")
>*The dealer inherits attributes of the player class, because we are assuming he/she is one of the players (rotating). They can perform normal player functions as well as dealing cards and turning the flop/turn/river. (Salary shouldn't be there, it was left from a paste)*
>
### Deck
>
>![Deck](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Deck.jpg "Deck")
>*An instance of a deck can have any number of cards from 0-52 (not shown on diagram my bad), and can shuffle itself.*
>
### Card
>
>![Card](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Card.jpg "Card")
>*Any given card will have one suit (S,C,D,H) and one value (1,2,3,4,5,6,7,8,9,10,11,12,13).*
>
### Hand
>
>![Hand](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Hand.jpg "Hand")
>*A player's hand has a size (which may or may not change depending on the type of poker played), and is an array of cards.*
>
### Bank
>
>![Bank](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Bank.jpg "Bank")
>*Each player has a bank that stores money. The bank can be deposited to and withdrawn from.*
>
### Blind
>
>![Blind](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Blind.jpg "Blind")
>*A blind is either **BIG** or *small*, and is given to a different player for each hand that is played. There is always one player with big blind and one with small blind. These rotate each round.
>
### Pot
>
>![pot](https://github.com/Landon-Brown1/2143-OOP-Brown/blob/master/Assignments/H04/Images/Pot.jpg "pot")
>*Winnings here should be an integer, assuming we are just calculating dollars won; could be different depending on bets. i.e. Cars, house, firstborn, etc...*
>
