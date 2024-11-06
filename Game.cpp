#include "Game.h"

#include <iostream>
#include <string>
#include <vector>




void Game::CreateGameBoard()
{
	std::cout << "     " << m_nodes[0] << "-----" << m_nodes[1] << "-----" << m_nodes[2] << std::endl;
	std::cout << "     | \\" << "   |" << "    /|" << std::endl;
	std::cout << "     |  \\  " << "|" << "   / |" << std::endl;
	std::cout << "     |   \\" << " |" << "  /  |" << std::endl;
	std::cout << "     |    \\" << "|" << " /   |" << std::endl;
	std::cout << "     " << m_nodes[3] << "-----" << m_nodes[4] << "-----" << m_nodes[5] << std::endl;
	std::cout << "     |   / "    << "|" << " \\   |" << std::endl;
	std::cout << "     |  /  "    << "|" << "  \\  |" << std::endl;
	std::cout << "     | /   "    << "|" << "   \\ |" << std::endl;
	std::cout << "     |/    "    << "|" << "    \\|" << std::endl;

	std::cout <<"     " << m_nodes[6] << "-----" << m_nodes[7] << "-----" << m_nodes[8] << std::endl;
}
void Game::GetPlayerInput()
{
	
	do {
		std::cout << "Enter Number (1-9): ";
		std::cin >> m_choice;
;
	} while (m_choice <= 0 || m_choice > 9 || (SetPlayer() == false));

	

}
int Game::GenerateComputerChoice()
{
	srand(time(0));


	return (rand() % 9);

	
}

int Game::CheckWinner()
{	

	
	if (m_nodes[0] ==  m_nodes[1] && m_nodes[1] == m_nodes[2]  && m_nodes[0] == m_player)
		return 1;
	else if (m_nodes[3] == m_nodes[4] && m_nodes[4] == m_nodes[5] && m_nodes[3] == m_player)
		return 1;
	else if (m_nodes[6] == m_nodes[7] && m_nodes[7] == m_nodes[8] && m_nodes[6] == m_player)
		return 1;
	else if (m_nodes[0] == m_nodes[3] && m_nodes[3] == m_nodes[6] && m_nodes[0] == m_player)
		return 1;
	else if (m_nodes[1] == m_nodes[4] && m_nodes[4] == m_nodes[7] && m_nodes[1] == m_player)
		return 1;
	else if (m_nodes[2] == m_nodes[5] && m_nodes[5] == m_nodes[8] && m_nodes[2] == m_player)
		return 1;
	else if (m_nodes[6] == m_nodes[4] && m_nodes[4] == m_nodes[2] && m_nodes[6] == m_player)
		return 1;
	else if (m_nodes[0] == m_nodes[4] && m_nodes[4] == m_nodes[8] && m_nodes[0] == m_player)
		return 1;
	else {
		if (m_nodes[0] == m_nodes[1] && m_nodes[1] == m_nodes[2] && m_nodes[0] == m_computer)
			return 2;
		else if (m_nodes[3] == m_nodes[4] && m_nodes[4] == m_nodes[5] && m_nodes[3] == m_computer)
			return 2;
		else if (m_nodes[6] == m_nodes[7] && m_nodes[7] == m_nodes[8] && m_nodes[6] == m_computer)
			return 2;
		else if (m_nodes[0] == m_nodes[3] && m_nodes[3] == m_nodes[6] && m_nodes[0] == m_computer)
			return 2;
		else if (m_nodes[1] == m_nodes[4] && m_nodes[4] == m_nodes[7] && m_nodes[1] == m_computer)
			return 2;
		else if (m_nodes[2] == m_nodes[5] && m_nodes[5] == m_nodes[8] && m_nodes[2] == m_computer)
			return 2;
		else if (m_nodes[6] == m_nodes[4] && m_nodes[4] == m_nodes[2] && m_nodes[6] == m_computer)
			return 2;
		else if (m_nodes[0] == m_nodes[4] && m_nodes[4] == m_nodes[8] && m_nodes[0] == m_computer)
			return 2;
		else
			return 0;
	}

}
void Game::GetInputAfterThree()
{	
	
	do {
		std::cout << "Enter Value You want to move  (1-9): ";
		std::cin >> s_old_location;

		std::cout << "Enter new for move (1-9): ";
		std::cin >> s_new_location;
	} while ((s_old_location > 9 || s_old_location <= 0) || (s_new_location > 9 || s_new_location <= 0));

	s_old_location = s_old_location - 1;
	s_new_location = s_new_location - 1;

	
	ChangePosition();

}
bool Game::IsRestricted()
{

	if (IsRestrictedMovement(s_old_location, s_new_location) == true)
	{
		return true;
	}
	
}
bool Game::IsNodeTaken()
{
	for (int i = 0; i < 9; i++) {
		if ((m_nodes[s_old_location] != " ") || (m_nodes[s_old_location] != " "))
			return true;
	}
	return false;
}

bool Game::IsRestrictedMovement(int old_location,int new_location)
{
	// available position to nodes at an index

	
	std::vector<int>node0 = { 1,3,4 };
	std::vector<int>node1 = { 0,2,4 };
	std::vector<int>node2 = { 1,5,4 };
	std::vector<int>node3 = { 0,4,6 };
	std::vector<int>node4 = { 0,1,2,3,5,6,7,8 };
	std::vector<int>node5 = { 2,4,8,0 };
	std::vector<int>node6 = { 3,4,7,0 };
	std::vector<int>node7 = { 4,6,8 };
	std::vector<int>node8 = { 4,5,7 };

	if (old_location == 0 ) {
		if (SetLocation(node0,  new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 1 ) {
		if (SetLocation(node1,  new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 2 ) {
		if (SetLocation(node2,  new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 3 ) {
		if (SetLocation(node3, new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 4 ) {
		if (SetLocation(node4, new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 5 ) {
		if (SetLocation(node5, new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 6 ) {
		if (SetLocation(node6, new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 7 ) {
		if (SetLocation(node7, new_location) == 1)
			return true;
		return false;
	}
	else if (old_location == 8 ) {
		if (SetLocation(node8, new_location) == 1)
			return true;
		return false;
	}
	
}


int SetLocation(const std::vector<int>& arr,int newNum)
{
	for (int i = 0; i < arr.size(); i++) {
		
		if (arr[i] == newNum)
			return 1;
	
	}
	return 0;
} 
void Game::Run()
{
	
	int i = 0;
		do {

			CreateGameBoard();
			GetPlayerInput();

			GetComputerChoice();
			CreateGameBoard();
			DisplayWinner();
			i++;

			
		} while (i < 3);
		int num = 0;
		while (s_running ) {

		
			CreateGameBoard();
			GetInputAfterThree();
			

			CreateGameBoard();
			DisplayWinner();
			GetNewComputerPosition();

		}

}
void Game::GetComputerChoice()
{	
	while (true) {
		m_computer_choice = GenerateComputerChoice();
		if (m_nodes[m_computer_choice] == " ") {
			m_nodes[m_computer_choice] = m_computer;
			break;
		}
		

	}
	

}

bool Game::SetPlayer()
{
	m_player_choice = m_choice - 1;
	
	if (m_nodes[m_player_choice] == " ") {
		m_nodes[m_player_choice] = m_player;
		return true;
		
	}
	else {
		return false;
	}

}
void Game::DisplayWinner()
{
	if (CheckWinner() == 1) {
		std::cout << "Player Won" << std::endl;
		s_running = false;
	}
	else if (CheckWinner() == 2) {
		std::cout << "Computer Won" << std::endl;
		s_running = false;
	}

}
void Game::ChangePosition() {
	if (IsRestrictedMovement(s_old_location, s_new_location)) {
		if (m_nodes[s_old_location] == m_player && m_nodes[s_new_location] == " ") {
			m_nodes[s_old_location] = " ";
			m_nodes[s_new_location] = m_player;
		}	
	}
	else {
		GetInputAfterThree();
	}
	
}
void Game::ChangeComputerPosition() {
	
	if (IsRestrictedMovement(m_comp_old_location, m_comp_new_location)) {
		if (m_nodes[m_comp_old_location] == m_computer && m_nodes[m_comp_new_location] == " ") {
			m_nodes[m_comp_old_location] = " ";
			m_nodes[m_comp_new_location] = m_computer;
		}
	}
	else {
		GetNewComputerPosition();
	}
}
void Game::GetNewComputerPosition() {
	do {
		m_comp_old_location = GenerateComputerChoice();
		m_comp_new_location = GenerateComputerChoice();
	} while (m_nodes[m_comp_old_location] != m_computer || m_nodes[m_comp_new_location] != " ");
	ChangeComputerPosition();
	
}