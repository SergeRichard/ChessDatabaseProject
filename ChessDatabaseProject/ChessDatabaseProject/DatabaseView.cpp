#include "DatabaseView.h"
#include "HelperFunctions.h"


DatabaseView::DatabaseView()
{

}


DatabaseView::~DatabaseView()
{
}

void DatabaseView::DisplayBoard(const std::vector<std::string>& candidateMoves, const std::vector<std::string>& movesPlayed) 
{
	ClearScreen();

	ResetBoard();
	ProcessMoves(movesPlayed);

	std::cout << m_board;
	std::cout << std::endl;
	std::cout << "Database moves for white:" << std::endl;
	for (auto cm : candidateMoves) {
		std::cout << cm << std::endl;
	}
	std::cout << "White to move: ";
}
void DatabaseView::ProcessMoves(const std::vector<std::string>& movesPlayed) {
	
	std::string startMove;
	std::string destMove;

	for (auto mp : movesPlayed) {
		std::string delimiters = "-x";
		std::size_t start = mp.find_first_of(delimiters);

		startMove = mp.substr(0, start);
		destMove = mp.substr(start + 1);

		int startCol = ConvertToArrayCol(startMove[0]);
		int startRow = ConvertToArrayRow(startMove[1]);
		int destCol = ConvertToArrayCol(destMove[0]);
		int destRow = ConvertToArrayRow(destMove[1]);

		ProcessMove(startCol, startRow, destCol, destRow);

		int temp = 0;
	}
}
void DatabaseView::ProcessMove(int startCol, int startRow, int destCol, int destRow) {
	m_board[destRow][destCol] = m_board[startRow][startCol];
	m_board[startRow][startCol] = "--";

}
int DatabaseView::ConvertToArrayCol(char colLetter) {
	switch (colLetter)
	{
	case 'a':
		return 0;
		break;
	case 'b':
		return 1;
		break;
	case 'c':
		return 2;
		break;
	case 'd':
		return 3;
		break;
	case 'e':
		return 4;
		break;
	case 'f':
		return 5;
		break;
	case 'g':
		return 6;
		break;
	case 'h':
		return 7;
		break;
	default:
		throw std::invalid_argument("Should only contain letters from a to h");
		break;
	}
	return -1;
}
int DatabaseView::ConvertToArrayRow(char rowLetter) {
	switch (rowLetter)
	{
	case '1':
		return 7;
		break;
	case '2':
		return 6;
		break;
	case '3':
		return 5;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 3;
		break;
	case '6':
		return 2;
		break;
	case '7':
		return 1;
		break;
	case '8':
		return 0;
	default:
		throw std::invalid_argument("Should only contain letters from 1 to 8");
	}
	return -1;
}
void DatabaseView::ClearScreen()
{
	std::cout << std::string(100, '\n');
}
void DatabaseView::ResetBoard() {
	std::string boardTemp[8][8] =
	{
		{ "BR","BN","BB","BQ","BK","BB","BN","BR" },
		{ "BP","BP","BP","BP","BP","BP","BP","BP" },
		{ "--","--","--","--","--","--","--","--" },
		{ "--","--","--","--","--","--","--","--" },
		{ "--","--","--","--","--","--","--","--" },
		{ "--","--","--","--","--","--","--","--" },
		{ "WP","WP","WP","WP","WP","WP","WP","WP" },
		{ "WR","WN","WB","WQ","WK","WB","WN","WR" }
	};
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			m_board[row][col] = boardTemp[row][col];
		}
	}
}
std::ostream & operator<<(std::ostream & stream, const std::string board[8][8])
{
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			stream << board[row][col] << " ";

		}
		stream << std::endl << std::endl;

	}

	return stream;
}