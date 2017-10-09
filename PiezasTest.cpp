/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	Piezas board;
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropOutOfBoundsLessThan)
{
	Piezas board;
	Piece drop;
	
	drop = board.dropPiece(-1);
	
	ASSERT_EQ(drop, Invalid);
}

TEST(PiezasTest, dropOutOfBoundsGreaterThan)
{
	Piezas board;
	
	Piece drop = board.dropPiece(5);
	
	ASSERT_EQ(drop, Invalid);
}

TEST(PiezasTest, dropFirstPieceCol0)
{
	Piezas board;
	
	Piece turn = board.dropPiece(0);
	
	ASSERT_EQ(X, turn);
}

TEST(PiezasTest, dropSecondPieceCol0)
{
	Piezas board;
	
	board.dropPiece(0);
	Piece turn = board.dropPiece(0);
	
	ASSERT_EQ(O, turn);
}

TEST(PiezasTest, dropThirdPieceCol0)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	Piece turn = board.dropPiece(0);
	
	ASSERT_EQ(X, turn);
}

TEST(PiezasTest, dropFourthPieceCol0)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	Piece turn = board.dropPiece(0);
	
	ASSERT_EQ(Invalid, turn);
}

TEST(PiezasTest, dropSecondPieceRow2)
{
	Piezas board;
	
	board.dropPiece(0);
	Piece turn = board.dropPiece(1);
	
	ASSERT_EQ(O, turn);
}

TEST(PiezasTest, dropThirdPieceRow2)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(1);
	Piece turn = board.dropPiece(2);
	
	ASSERT_EQ(X, turn);
}

TEST(PiezasTest, dropFourthPieceRow2)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	Piece turn = board.dropPiece(3);
	
	ASSERT_EQ(O, turn);
}

TEST(PiezasTest, dropFifthPieceRow2)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	Piece turn = board.dropPiece(4);
	
	ASSERT_EQ(Invalid, turn);
}
 
TEST(PiezasTest, checkPieceInvalidRowDown)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(-5,2);
	
	ASSERT_EQ(Invalid, test);
}

TEST(PiezasTest, checkPieceInvalidRowUp)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(15,2);
	
	ASSERT_EQ(Invalid, test);
}

TEST(PiezasTest, checkPieceInvalidColumnDown)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(1,-6);
	
	ASSERT_EQ(Invalid, test);
}

TEST(PiezasTest, checkPieceInvalidColumnUp)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(1,78);
	
	ASSERT_EQ(Invalid, test);
}

TEST(PiezasTest, fillBoard)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece turn = board.dropPiece(3);
	
	ASSERT_EQ(O, turn);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard20)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(2,0);
	
	ASSERT_EQ(X, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard10)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(1,0);
	
	ASSERT_EQ(O, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard00)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(0,0);
	
	ASSERT_EQ(X, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard21)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(2,1);
	
	ASSERT_EQ(O, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard11)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(1,1);
	
	ASSERT_EQ(X, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard01)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(0,1);
	
	ASSERT_EQ(O, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard22)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(2,2);
	
	ASSERT_EQ(X, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard12)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(1,2);
	
	ASSERT_EQ(O, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard02)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(0,2);
	
	ASSERT_EQ(X, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard23)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(2,3);
	
	ASSERT_EQ(O, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard13)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(1,3);
	
	ASSERT_EQ(X, test);
}

/**
 *	X  O  X  O
 *	O  X  O  X
 *  X  O  X  O
 **/
 
TEST(PiezasTest, checkBoard03)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece test = board.pieceAt(0,3);
	
	ASSERT_EQ(O, test);
}

TEST(PiezasTest, reset)
{
	Piezas board;
	
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	board.reset();
	Piece test = board.pieceAt(0,2);
	
	ASSERT_EQ(Blank, test);
}


