[![Build Status](https://travis-ci.org/lcheung90/ConnectX.svg?branch=master)](https://travis-ci.org/lcheung90/ConnectX)

[![Coverage Status](https://coveralls.io/repos/github/lcheung90/ConnectX/badge.svg?branch=master)](https://coveralls.io/github/lcheung90/ConnectX?branch=master)

# Luis Cheung
## Quiz 3
### Bug List

###ConnectX::at

* potential corrupt memory access `board[h][w]` should be `board[w][h]`
* this causes invalid `w` function arguments to not return `INVALID` (-1)

###ConnectX::showBoard

* prints `' '` for invalid board spots

###ConnectX::placePiece

* double free or corruption when `column` = -1
* needs extra inspection, but it seems like accesses restricted memory space
