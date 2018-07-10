# Explosive Anti Chess

Chess variation where the winner is the first player who runs out of pieces to move. Also, pieces explode.

## Rules

This chess variation has many similarities with regular chess. Bishops move diagonally, rooks move in straight lines, knights move in L shapes, the main difference is in the objective of the game.

In regular chess, the winner is the one who can checkmate the opponents king, usually the one with more pieces is the one leading. In this variant, the winner is the one whose pieces have been all taken (hence 'anti' chess). The other important change is that if a piece captures another piece, all the 8 squares around the capture square explode, meaning that if a piece was in a cell immediately besides the capturing square, the piece explodes and is removed from the board.

Because the winner is the one that runs out of pieces, a player is not advised to take the opponent's piece, especially if that pieces is surrounded by other opponent's pieces, as all of them will explode, thus helping your opponent get nearer to winning.

## Notes

This is part of the second programming project of Computer Science in the UCR (Universidad de Costa Rica). As such, it will have two evaluations, which will consist of the following commits:
- **First commit:** The board and the images for the pieces will be created. The pawn's behavior will be programmed, such that they can move two squares to the front in the first move, and one move to the front in the following moves.
They will also be able to capture a piece as usual (one square diagonally) and this capture will produce an explosion of the 8 squares surrounding the capturing square. For this commit, the explosion will kill any piece within its radius. For this first commit, all of the pieces but the pawns will be disabled. The animations will be programmed during this commit.

- **Second commit:** With this commit, the project will come to completion. The rest of the pieces will be enabled (i.e. Knight, Bishop, Rook, Queen, King).
Also, each piece will have two extra attributes: health and explosion damage. The health will be how many explosions can the piece stand, the explosion damage is how much health is removed from other pieces when the piece explodes near them.

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/jackalvarez/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [Github](http://github.com/) for versioning. For the versions available, see the [tags on this repository](https://github.com/jackalvarez/AtomicAntiChess).

## Authors

* **Jostin Alvarez** - *Initial work* - [jackalvarez](https://github.com/jackalvarez)

* **Gabriel Alvarez** - *Graphics and such* - [Gabo141298](https://github.com/Gabo141298)

See also the list of [contributors](https://github.com/jackalvarez/AtomicAntiChess/settings/collaboration) who participated in this project.

## License

Pending

## Acknowledgments

* PhD. Jeisson Hidalgo for providing help with the concepts
