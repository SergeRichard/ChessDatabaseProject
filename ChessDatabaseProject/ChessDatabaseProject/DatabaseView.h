#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>

class DatabaseView
{
public:
	DatabaseView();
	~DatabaseView();

	void DisplayBoard(const std::vector<std::string>& candidateMoves, const std::vector<std::string>& movesPlayed);

	friend std::ostream& operator<< (std::ostream& stream, const std::string board[8][8]);

	void ClearScreen();

	void ProcessMoves(const std::vector<std::string>& movesPlayed);

	void ResetBoard();
	int ConvertToArrayCol(char colLetter);
	int ConvertToArrayRow(char rowLetter);

	void ProcessMove(int startCol, int startRow, int destCol, int destRow, bool whiteMove);

	void ProcessMoveCastling(std::string move, bool whiteMove);

private:
	std::string m_board[8][8] = 
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
};

