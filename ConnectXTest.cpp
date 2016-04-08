/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, outBoundsOverTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(10);
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, outBoundsUnderTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(-10);
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, outBoundsAtPosXTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(0);
  ASSERT_TRUE( c.at(10,0) == -1 );
}

TEST(ConnectXTest, outBoundsAtNegXTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(0);
  ASSERT_TRUE( c.at(-10,0) == -1 );
}

TEST(ConnectXTest, outBoundsAtPosYTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(0);
  ASSERT_TRUE( c.at(0,10) == -1 );
}

TEST(ConnectXTest, outBoundsAtNegYTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(0);
  ASSERT_TRUE( c.at(0,-10) == -1 );
}

TEST(ConnectXTest, constructorDefaultDimsWidthTest)
{
  ConnectX c = ConnectX(0,5,1);
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(0,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,0) == 0 );
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, constructorNegWidthTest)
{
  ConnectX c = ConnectX(-1,5,1);
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(0,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,0) == 0 );
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, constructorDefaultDimsHeightTest)
{
  ConnectX c = ConnectX(5,0,1);
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(0,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,0) == 0 );
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, constructorNegHeightTest)
{
  ConnectX c = ConnectX(5,-1,1);
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(0,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,0) == 0 );
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, constructorDefaultToWinTest)
{
  ConnectX c = ConnectX(5,6,0);
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(0,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,0) == 0 );
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, constructorNegWinTest)
{
  ConnectX c = ConnectX(5,6,-1);
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(0,DEFAULT_HEIGHT-1) == 0 );
  ASSERT_TRUE( c.at(DEFAULT_WIDTH-1,0) == 0 );
  ASSERT_TRUE( c.at(0,0) == 0 );
}

TEST(ConnectXTest, occupiedTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(0);
  c.placePiece(0);
  ASSERT_TRUE( c.at(0,0) == 2); //black
}

TEST(ConnectXTest, missTurnTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(-10);
  c.placePiece(0);
  ASSERT_TRUE( c.at(0,0) == 1); //white
}

TEST(ConnectXTest, initTurnCheckTest)
{
  ConnectX c = ConnectX(1,1,1);
  ASSERT_TRUE( c.whoseTurn() == 2 );
}

TEST(ConnectXTest, toggleTurnCheckTest)
{
  ConnectX c = ConnectX(1,1,1);
  c.placePiece(0);
  ASSERT_TRUE( c.whoseTurn() == 1 );
}
