#include "DatabaseView.h"



DatabaseView::DatabaseView()
{

}


DatabaseView::~DatabaseView()
{
}

void DatabaseView::DisplayBoard(const std::stack<std::string>& moves) 
{
	if (moves.size() == 0) {
		std::cout << m_board;


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