#include "DatabaseModel.h"

DatabaseModel::DatabaseModel()
{
}

DatabaseModel::~DatabaseModel()
{
}

void DatabaseModel::Update()
{

}

const std::vector<std::string>& DatabaseModel::GetCandidateMoves() { 
	std::vector<std::string> candidateMoves = m_databaseIO.GetPossibleMoves(m_movesPlayed);

	return candidateMoves;

}
