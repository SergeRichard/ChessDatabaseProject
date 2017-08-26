#pragma once
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <iostream>
#include "HelperFunctions.h"

class DatabaseIO
{
public:
	DatabaseIO();
	~DatabaseIO();

	std::vector<std::string> GetPossibleMoves(const std::vector<std::string>& m_moves);
	void AddMoveToDataBase(const std::vector<std::string>& movesPlayed);
	int FindIndexToInsertMove(const std::vector<std::string>& movesPlayed);
	std::vector<std::string> GetAllTextLinesFromFile();
	void WriteMovesToDatabase(const std::vector<std::string>& TextLines);

private:

};

