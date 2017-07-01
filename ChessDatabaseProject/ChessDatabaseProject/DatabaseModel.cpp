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

const std::vector<std::string> DatabaseModel::GetCandidateMoves() { 
	std::vector<std::string> candidateMoves = m_databaseIO.GetPossibleMoves(m_movesPlayed);

	return candidateMoves;

}
std::string DatabaseModel::GetPlayerInput() {
	std::string input;
	std::cin >> input;
	return input;
}
void DatabaseModel::ProcessPlayerInput(std::string move) {
	m_movesPlayed.push(move);
}