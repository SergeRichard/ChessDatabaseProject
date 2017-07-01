#pragma once
#include"DatabaseModel.h"

class DatabaseController
{
public:
	DatabaseController();
	~DatabaseController();

	void Update();

private:
	DatabaseModel m_databaseModel;
	DatabaseView m_view;


};

