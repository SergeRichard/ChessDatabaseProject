#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "DatabaseView.h"

class DatabaseModel
{
public:
	DatabaseModel();
	~DatabaseModel();

	void Update();

	const std::queue<std::string>& GetMoves() { return m_moves; }

private:

	std::queue<std::string> m_moves;
	std::vector<std::string> m_currentPossibleMoves;
	
};

