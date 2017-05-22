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

private:
	DatabaseView m_view;
	std::stack<std::string> m_moves;
	
};

