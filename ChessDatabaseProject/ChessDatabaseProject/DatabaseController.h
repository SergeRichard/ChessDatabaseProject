#pragma once
#include"DatabaseModel.h"

class DatabaseController
{
public:
	DatabaseController();
	~DatabaseController();

	void Update();

private:
	DatabaseModel databaseModel;


};

