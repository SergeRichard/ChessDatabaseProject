#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "DatabaseView.h"
#include "DatabaseIO.h"

class DatabaseModel
{
public:
	DatabaseModel();
	~DatabaseModel();

	void Update();

	const std::vector<std::string> GetCandidateMoves();
	const std::queue<std::string> GetMovesPlayed() { return m_movesPlayed; }
	std::string GetPlayerInput();
	void ProcessPlayerInput(std::string move);

private:
	DatabaseIO m_databaseIO;
	std::queue<std::string> m_movesPlayed;
	std::vector<std::string> m_currentPossibleMoves;
	
};

