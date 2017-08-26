#include "DatabaseIO.h"



DatabaseIO::DatabaseIO()
{
}


DatabaseIO::~DatabaseIO()
{
}
int DatabaseIO::FindIndexToInsertMove(const std::vector<std::string>& movesPlayed) {
	std::ifstream inFile("Database.txt");
	std::string strOneLine;
	std::vector<std::string> possibleMoves;
	std::string startPlace;
	bool initialMoves = false;
	int index = 0;

	bool expectingClosingTag = false;

	std::queue<std::string> queueOfMovesPlayed;

	for (auto m : movesPlayed) {
		queueOfMovesPlayed.push(m);

	}
	


	if (!inFile) {
		std::cout << "Can't open file!" << std::endl;
	}

	if (queueOfMovesPlayed.empty()) {
		initialMoves = true;

	}

	int openTags = 0;
	if (inFile) {
		do
		{
			getline(inFile, strOneLine);

			index++;

			trim(strOneLine);

			// if not the move expected, ignore line and proceed to next until move is found.
			if (queueOfMovesPlayed.size() > 1) { // we do not want to include new move in search of index, since it does not exist in database yet.
				if (strOneLine.find(queueOfMovesPlayed.front()) != std::string::npos) {
					queueOfMovesPlayed.pop();
				}
				continue;
			}

			// if no more moves to look for, we are ready to collect all current moves.
			if (strOneLine.find("</White>") == std::string::npos && strOneLine.find("</Black>") == std::string::npos) {
				if (openTags == 0) {
					if (strOneLine.find("move=\"") != std::string::npos) {
						//std::string move;
						//std::size_t start = strOneLine.find("\"");
						//std::size_t end = strOneLine.find("\"", start + 1);
						//move = strOneLine.substr(start + 1, end - start - 1);

						//possibleMoves.push_back(move);
					}
				}
				openTags++;
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

	return index;


}
std::vector<std::string> DatabaseIO::GetAllTextLinesFromFile() {
	std::ifstream inFile("Database.txt");
	std::string strOneLine;
	std::vector<std::string> linesOfText;



	if (!inFile) {
		std::cout << "Can't open file!" << std::endl;
	}

	if (inFile) {
		do
		{
			getline(inFile, strOneLine);

			trim(strOneLine);
			
			//if (!inFile.eof()) {
				linesOfText.push_back(strOneLine);

			//}


			// if end of file 
			if (inFile.eof())
				break;

		} while (!inFile.eof());
	}

	inFile.close();

	return linesOfText;


}
void DatabaseIO::AddMoveToDataBase(const std::vector<std::string>& movesPlayed) {
	std::vector<std::string> TextLinesFromFile = GetAllTextLinesFromFile();
	int index = FindIndexToInsertMove(movesPlayed);

	int colorToMove = movesPlayed.size() % 2;
	std::string color = colorToMove == 1 ? "White" : "Black";

	std::string openTag = "<" + color + " move=\"" + movesPlayed[movesPlayed.size() - 1] + "\">T";
	std::string closingTag = "</" + color + ">T";

	bool didNotAddMove = true;

	int i = 0;
	for (auto it = TextLinesFromFile.begin(); it != TextLinesFromFile.end(); it++) {
		if (index - 1 == i) {
			TextLinesFromFile.insert(it, openTag);
			didNotAddMove = false;
			break;
		}		
		i++;
	}
	i = 0;
	for (auto it = TextLinesFromFile.begin(); it != TextLinesFromFile.end(); it++) {
		if (index == i) {
			TextLinesFromFile.insert(it, closingTag);
			didNotAddMove = false;
			break;
		}
		i++;
	}

	if (didNotAddMove) {
		TextLinesFromFile.push_back(openTag);
		TextLinesFromFile.push_back(closingTag);

	}

	WriteMovesToDatabase(TextLinesFromFile);
}
void DatabaseIO::WriteMovesToDatabase(const std::vector<std::string>& TextLines) {

	std::ofstream outfile("Database.txt");

	int numOfTabs = 0;

	if (outfile.is_open())
	{	

		for (auto t : TextLines) {
			if (t.find("</White>") != std::string::npos || t.find("</Black>") != std::string::npos) {
				numOfTabs--;
			}
			for (int i = 0; i < numOfTabs; i++) {
				outfile << "\t";
			}
			outfile << t;

			if (t.find("<White") != std::string::npos || t.find("<Black")) {
				numOfTabs++;
			}
			outfile << "\n";
		}

		outfile.close();
	}

}
std::vector<std::string> DatabaseIO::GetPossibleMoves(const std::vector<std::string>& movesPlayed)
{
	std::ifstream inFile("Database.txt");
	std::string strOneLine;
	std::vector<std::string> possibleMoves;
	std::string startPlace;
	bool initialMoves = false;

	bool expectingClosingTag = false;

	std::queue<std::string> queueOfMovesPlayed;

	for (auto m : movesPlayed) {
		queueOfMovesPlayed.push(m);

	}
	

	if (!inFile) {
		std::cout << "Can't open file!" << std::endl;
	}
	
	if (queueOfMovesPlayed.empty()) {
		initialMoves = true;

	}

	int openTags = 0;
	if (inFile) {
		do
		{
			getline(inFile, strOneLine);

			trim(strOneLine);

			// if not the move expected, ignore line and proceed to next until move is found.
			if (!queueOfMovesPlayed.empty()) {
				if (strOneLine.find(queueOfMovesPlayed.front()) != std::string::npos) {
					queueOfMovesPlayed.pop();
				}
				continue;
			}

			// if no more moves to look for, we are ready to collect all current moves.
			if (strOneLine.find("</White>") == std::string::npos && strOneLine.find("</Black>") == std::string::npos) {
				if (openTags == 0) {
					if (strOneLine.find("move=\"") != std::string::npos) {
						std::string move;
						std::size_t start = strOneLine.find("\"");
						std::size_t end = strOneLine.find("\"", start + 1);
						move = strOneLine.substr(start + 1, end - start - 1);

						possibleMoves.push_back(move);
					}
				}
				openTags++;
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
