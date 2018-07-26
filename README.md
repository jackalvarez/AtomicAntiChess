# Explosive Anti Chess

Chess variation where the winner is the first player who runs out of pieces to move. Also, pieces explode.

## Rules

This chess variation has many similarities with regular chess. Bishops move diagonally, rooks move in straight lines, knights move in L shapes, the main difference is in the objective of the game.

In regular chess, the winner is the one who can checkmate the opponents king, usually the one with more pieces is the one leading. In this variant, the winner is the one whose pieces have been all taken (hence 'anti' chess). The other important change is that if a piece captures another piece, all the 8 squares around the capture square explode, meaning that if a piece was in a cell immediately besides the capturing square, the piece explodes and is removed from the board (except if the piece still has health*).

Because the winner is the one that runs out of pieces, a player is not advised to take the opponent's piece, especially if that pieces is surrounded by other opponent's pieces, as all of them will explode, thus helping your opponent get nearer to winning.

**\* Health:** Not all pieces are immediately destroyed by an explosion. Each piece has a different resistance to explosions, in other words, each piece can stand a different number of explosions before having to be removed from the board. The health of the different pieces goes as follows:
- Pawns 1
- Bishops/knights 2
- Rooks 3
- Queen 4
- King 5

So, if a pawn is within the radius of a explosion, it will always be removed from the board, but other pieces may not, depending on how much lives they have left.

`Image before a explosion. The white pawn on f4 will take the black pawn on e5`
![](/preexplosion_screenshot.png)

`Image during the explosion. The 8 squares around the capturing square explode.`
![](/explosion_screenshot.png)

`Image after the explosion. The exploded pieces have been removed from the board`
![](/postexplosion_screenshot.png)

**5 moves rule:** As it is not within the player's benefit to take all of the opponent's pieces, the situation may occur in which both players move pieces back and forth without ever capturing, taking the fun out of the game. To avoid this problem, each player is required to make at least one capture every 5 moves. If the player does not capture within 5 moves, he automatically loses.


## Notes

This is a project for the Programming II course of Computer Science in the UCR (Universidad de Costa Rica). As such, it will have two evaluations, which will consist on the following milestones:
- **First milestone:** The board and the images for the pieces will be created. The pawn's behavior will be programmed, such that they can move two squares to the front in the first move, and one move to the front in the following moves.
They will also be able to capture a piece as usual (one square diagonally) and this capture will produce an explosion of the 8 squares surrounding the capturing square. For this milestone, the explosion will kill any piece within its radius and all of the pieces but the pawns will be disabled. The animations will be programmed during this milestone.

- **Second milestone:** The rest of the pieces will be enabled (i.e. Knight, Bishop, Rook, Queen, King). The health dynamics of the pieces be program, such that each peace will have its own "health" (how many explosions it can stand). With this milestone a new rule is introduced,

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/jackalvarez/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [Github](http://github.com/) for versioning. For the versions available, see the [tags on this repository](https://github.com/jackalvarez/AtomicAntiChess).

## Authors

* **Jostin Alvarez** - *Initial work* - [jackalvarez](https://github.com/jackalvarez)

* **Gabriel Alvarez** - *Graphics and such* - [Gabo141298](https://github.com/Gabo141298)

See also the list of [contributors](https://github.com/jackalvarez/AtomicAntiChess/settings/collaboration) who participated in this project.

## Acknowledgments

* PhD. Jeisson Hidalgo for providing help with the concepts
* Pixabay - OpenClipart-Vector for the images
