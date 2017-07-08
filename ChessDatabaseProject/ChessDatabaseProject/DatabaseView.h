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
		{ "WR","WR","WR","WR","WR","WR","WR","WR" }
	};
};

