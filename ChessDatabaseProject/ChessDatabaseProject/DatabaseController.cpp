#include "DatabaseController.h"

DatabaseController::DatabaseController()
{	
}


DatabaseController::~DatabaseController()
{
}

void DatabaseController::Update() {

	m_view.DisplayBoard(m_databaseModel.GetCandidateMoves(), m_databaseModel.GetMovesPlayed());
	std::string playerInput = m_databaseModel.GetPlayerInput();

	m_databaseModel.ProcessPlayerInput(playerInput);
}