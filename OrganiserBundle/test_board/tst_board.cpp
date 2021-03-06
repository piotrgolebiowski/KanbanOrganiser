
#include "tst_board.h"

test_board::test_board()
{

}

test_board::~test_board()
{

}

void test_board::addColumnToBoard()
{
    Board board;

    BoardColumn* column = new BoardColumn("Title");
    BoardColumn* columnOther = new BoardColumn("Title2");

    board.AddColumn(column);

    BoardColumn* columnFromBoard = board.GetColumnAt(0);


    QVERIFY(column->isEqual(columnFromBoard));
    QVERIFY(columnOther != columnFromBoard);
}

void test_board::getColumnOutOfRangeException()
{
    Board board;

    BoardColumn* column = new BoardColumn("Title");
    board.AddColumn(column);

    try
    {
        board.GetColumnAt(-1);
        board.GetColumnAt(2);
        QFAIL("Failed to catch exception in GetCardAt");
    }
    catch (GeneralException exception)
    {

    }
}

void test_board::deleteColumnFromBoard()
{
    Board board;


    BoardColumn* column = new BoardColumn("Title");
    board.AddColumn(column);

    BoardColumn* column2 = new BoardColumn("Title2");
    board.AddColumn(column2);

    board.DeleteColumn(0);

    BoardColumn* column2FromNotes = board.GetColumnAt(0);

    QVERIFY(board.GetColumnCount() == 1);

    QVERIFY(!column->isEqual(column2FromNotes));
    QVERIFY(column2->isEqual(column2FromNotes));

    try
    {
        board.DeleteColumn(-1);
        board.DeleteColumn(2);
        QFAIL("Failed to catch exception in DeleteCard");
    }
    catch (GeneralException exception)
    {

    }
}

void test_board::editColumnNameInBoard()
{
    Board board;

    BoardColumn* column = new BoardColumn("Title");
    board.AddColumn(column);

    board.EditColumnName(0,"TitleOther");
    BoardColumn* column2FromNotes = board.GetColumnAt(0);

    QVERIFY(!column->isEqual(column2FromNotes));
}

void test_board::addCardToColumnInBoard()
{
    Board board;
    BoardColumn* column = new BoardColumn("Title");
    board.AddColumn(column);

    Card* card = new Card("Title","Desc", QDateTime(QDate(2020,1,1),QTime(10,10)));
    board.AddCardToColumn(0,card);

    BoardColumn* column2FromNotes = board.GetColumnAt(0);

    Card* cardFromColumn = column2FromNotes->GetCardAt(0);

    QVERIFY(card->IsEqual(cardFromColumn));
}

void test_board::replaceCardInColumnInBoard()
{
    Board board;
    BoardColumn* column = new BoardColumn("Title");
    board.AddColumn(column);

    Card* card = new Card("Title","Desc", QDateTime(QDate(2020,1,1),QTime(10,10)));
    board.AddCardToColumn(0,new Card(card));

    Card* cardOther = new Card("TitleOther","DescOther", QDateTime(QDate(2020,1,1),QTime(10,10)));
    board.ReplaceCardInColumn(0,0,cardOther);

    BoardColumn* column2FromNotes = board.GetColumnAt(0);

    Card* cardFromColumn = column2FromNotes->GetCardAt(0);

    QVERIFY(!card->IsEqual(cardFromColumn));
    QVERIFY(cardOther->IsEqual(cardFromColumn));
}

void test_board::deleteCardFromColumnInBoard()
{
    Board board;
    BoardColumn* column = new BoardColumn("Title");
    board.AddColumn(column);

    Card* card = new Card("Title","Desc", QDateTime(QDate(2020,1,1),QTime(10,10)));
    board.AddCardToColumn(0,card);

    board.DeleteCardFromColumn(0,0);

    BoardColumn* column2FromNotes = board.GetColumnAt(0);

    QVERIFY(column2FromNotes->GetCardsCount() == 0);
}

void test_board::moveCardToOtherColumnInSameBoard()
{
    Board board;
    BoardColumn* column = new BoardColumn("Title");
    board.AddColumn(column);
    BoardColumn* column2 = new BoardColumn("Title2");
    board.AddColumn(column2);


    Card* card = new Card("Title","Desc", QDateTime(QDate(2020,1,1),QTime(10,10)));
    board.AddCardToColumn(0,new Card(card));


    board.MoveCard(0,0,1);

    Card* cardFromColumn = board.GetColumnAt(1)->GetCardAt(0);


    QVERIFY(board.GetColumnAt(0)->GetCardsCount() == 0);
    QVERIFY(board.GetColumnAt(1)->GetCardsCount() == 1);

    QVERIFY(cardFromColumn != nullptr);
    QVERIFY(card->IsEqual(cardFromColumn));

}

QTEST_APPLESS_MAIN(test_board)

