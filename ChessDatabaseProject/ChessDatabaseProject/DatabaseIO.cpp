#include "DatabaseIO.h"



DatabaseIO::DatabaseIO()
{
}


DatabaseIO::~DatabaseIO()
{
}

const std::vector<std::string> DatabaseIO::GetPossibleMoves(const std::queue<std::string>& m_moves) const
{
	std::ifstream inFile("Database.txt");
	std::string strOneLine;
	std::vector<std::string> possibleMoves;
	std::string startPlace;
	bool initialMoves = false;
	std::queue<std::string> movesCopy = m_moves;

	bool expectingClosingTag = false;

	if (!inFile) {
		std::cout << "Can't open file!" << std::endl;
	}
	
	if (movesCopy.empty()) {
		initialMoves = true;

	}

	int openTags = 0;
	if (inFile) {
		do
		{
			getline(inFile, strOneLine);

			trim(strOneLine);

			// if not the move expected, ignore line and proceed to next until move is found.
			if (!movesCopy.empty()) {
				if (movesCopy.front() == strOneLine) {
					movesCopy.pop();
				}
				continue;
			}

			// if no more moves to look for, we are ready to collect all current moves.
			if (strOneLine.find("</White>") != std::string::npos || strOneLine.find("</Black>") != std::string::npos) {
				openTags++;
				if (strOneLine.find("move=\"") != std::string::npos) {
					std::string move;
					std::size_t start = strOneLine.find("\"");
					std::size_t end = strOneLine.find("\"", start + 1);
					move = strOneLine.substr(start + 1, end - start - 1);

					possibleMoves.push_back(move);
				}
			}
			else {
				openTags--;
			}


			// if end of file or outside
			if (inFile.eof() || openTags == -1)
				break;

		} while (!inFile.eof());
	}

	inFile.close();

	return possibleMoves;
}
