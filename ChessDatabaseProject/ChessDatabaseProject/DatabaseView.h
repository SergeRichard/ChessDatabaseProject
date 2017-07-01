#pragma once
#include <string>
#include <iostream>
#include <vector>

class DatabaseView
{
public:
	DatabaseView();
	~DatabaseView();

	void DisplayBoard(const std::vector<std::string>& moves);

	friend std::ostream& operator<< (std::ostream& stream, const std::string board[8][8]);

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

