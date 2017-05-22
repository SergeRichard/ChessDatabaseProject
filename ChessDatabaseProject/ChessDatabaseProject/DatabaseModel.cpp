#include "DatabaseModel.h"

DatabaseModel::DatabaseModel()
{
}

DatabaseModel::~DatabaseModel()
{
}

void DatabaseModel::Update()
{
	m_view.DisplayBoard(m_moves);
}


