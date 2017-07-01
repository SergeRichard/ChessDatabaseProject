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

	std::vector<std::string> GetPossibleMoves(const std::queue<std::string>& m_moves);

private:

};

