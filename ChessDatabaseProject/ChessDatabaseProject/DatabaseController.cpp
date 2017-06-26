#include "DatabaseController.h"

DatabaseController::DatabaseController()
{	
}


DatabaseController::~DatabaseController()
{
}

void DatabaseController::Update() {
	m_view.DisplayBoard(databaseModel.GetMoves());


}