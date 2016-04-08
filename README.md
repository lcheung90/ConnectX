# Luis Cheung
## Quiz 3
### Bug List

###ConnectX::at

* potential corrupt memory access `board[h][w]` should be `board[w][h]`
* this causes invalid `w` function arguments to not return `INVALID` (-1)

###ConnectX::showBoard

* prints `' '` for invalid spot

###ConnectX::placePiece

* double free or corruption when `column` = -1
* needs extra inspection, but it seems like accesses restricted memory space
