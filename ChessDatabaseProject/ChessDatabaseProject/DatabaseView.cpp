#include "DatabaseView.h"



DatabaseView::DatabaseView()
{

}


DatabaseView::~DatabaseView()
{
}

void DatabaseView::DisplayBoard(const std::vector<std::string>& candidateMoves, const std::queue<std::string>& movesPlayed) 
{
	
	if (movesPlayed.size() == 0) {
		std::cout << m_board;
		std::cout << std::endl;
		std::cout << "Database moves for white:" << std::endl;
		for (auto cm : candidateMoves) {
			std::cout << cm << std::endl;
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