#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "DatabaseView.h"

class DatabaseModel
{
public:
	DatabaseModel();
	~DatabaseModel();

	void Update();

	const std::stack<std::string>& GetMoves() { return m_moves; }

private:

	std::stack<std::string> m_moves;
	
};

