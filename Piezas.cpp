#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
   board = std::vector< std::vector<Piece> >(BOARD_ROWS, std::vector<Piece>(BOARD_COLS, Blank));
   
   turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
   for(int i = 0; i < BOARD_ROWS; i++)
   {
      for(int j = 0; j < BOARD_COLS; j++)
      {
         board[i][j] = Blank;
      }
   }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece temp = turn;
    
   //Out of bounds
   if(column < 0 || column > 4)
   {
      return Invalid;  
   }
   
   //Place piece and check for full column
   Piece test = pieceAt(2, column);
   if(test == Blank)
   {
      board[2][column] = turn;
   }
   else
   {
      test = pieceAt(1, column);
      if(test == Blank)
      {
         board[1][column] = turn;
      }
      else
      {
         test = pieceAt(0, column);
         if(test == Blank)
         {
            board[0][column] = turn;
         }
         else
         {
            return Invalid;
         }
      }
   }
   
   //Toggle turn
   if(turn == X)
   {
      turn = O;
   }
   else if(turn == O) //Hard code the other turn in case of invalid or blank value
   {
      turn = X;
   }
   
   return temp;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
   //Out of bounds
   if((row < 0 || row > 4) || (column < 0 || column > 3))
   {
      return Invalid;
   }
   
   //Return piece
   return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
   int numX = 0;
   int numO = 0;
   int maxXs = 0;
   int maxOs = 0;
   
   //Check rows first, larger than columns
   for(int i = 0; i < BOARD_ROWS; i++)
   {
      for(int j = 0; j < BOARD_COLS; j++)
      {
         Piece check = pieceAt(i, j);
         if(check == X)
         {
            numX += 1;
         }
         else if(check == O)
         {
            numO += 1;
         }
         else //Game is not over
         {
            return Invalid;
         }
      }
      
      if(maxXs < numX)
      {
         maxXs = numX;
      }
      
      if(maxOs < numO)
      {
         maxOs = numO;
      }
      
      numX = numO = 0;
   }
   
   //Check columns
   for(int j = 0; j < BOARD_COLS; j++)
   {
      for(int i = 0; i < BOARD_ROWS; i++)
      {
         Piece check = pieceAt(i, j);
         if(check == X)
         {
            numX += 1;
         }
         else if(check == O)
         {
            numO += 1;
         }
         else //Game is not over
         {
            return Invalid;
         }
      }
      
      if(maxXs < numX)
      {
         maxXs = numX;
      }
      
      if(maxOs < numO)
      {
         maxOs = numO;
      }
      
      numX = numO = 0;
   }
   
   if(maxOs > maxXs) //O wins
   {
      return O;
   }
   else if(maxXs > maxOs) //X wins
   {
      return X;
   }
   else //No winner
   {
      return Blank;
   }
}