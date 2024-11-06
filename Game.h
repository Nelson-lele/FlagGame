#pragma once
#include <string>
#include <ctime>
#include <vector>




int SetLocation(const std::vector<int>& arr, int newNum);
class Game
{
private:
	std::string m_nodes[9] = { " "," "," "," "," "," "," "," "," "};
	std::string m_computer = "O";
	std::string m_player = "X";
	int m_choice;
	int m_player_choice;
	int m_computer_choice;
private:

	int m_comp_old_location;
	int m_comp_new_location;

public:
	bool s_running = true;
	unsigned int s_old_location;
	unsigned int s_new_location;

public:

	int GenerateComputerChoice();
	int CheckWinner();
	

public:
	void Run();
	void GetPlayerInput();
	void CreateGameBoard();

	void ChangeComputerPosition();
	void GetNewComputerPosition();

	void GetComputerChoice();
	void DisplayWinner();

	void ChangePosition();
	void GetInputAfterThree();

public:

	bool IsNodeTaken();
	bool IsRestricted();
	bool IsRestrictedMovement(int old_location,int new_location);
	bool SetPlayer();
};

