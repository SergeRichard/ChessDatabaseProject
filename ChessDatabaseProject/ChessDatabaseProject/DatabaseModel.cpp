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
	
	const std::vector<std::string> candMoves = GetCandidateMoves();

	bool inDatabase = false;

	for (auto m : candMoves) {
		if (m == move) {
			inDatabase = true;
			break;
		}
	}
	m_movesPlayed.push_back(move);

	if (!inDatabase) {
		m_databaseIO.AddMoveToDataBase(m_movesPlayed);

	}
	
}