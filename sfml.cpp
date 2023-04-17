#include <SFML/Graphics.hpp>
#include<SFML\Audio.hpp>
#include"Header.h"
#include <iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
using namespace sf;
using namespace std;
int main() {
	// OOP Final Project (CricBuzz)
// Coded by Zohaib Shahid(20F-0432) & Sadan Khakher(20F-1105)
//------------------------------------------------------------------
// Main.cpp file (Driver programme) 
//---------------------- Including  Header File ---------------------

	/*Team obj;
	obj.cricbuzz();*/
	//obj.display_player(88);
	Match ob;
	//ob.conduct_match();
	//ob.display_team();
	Team team1;
	int choice, i;
	cout << "**************************Cricbuzz******************************\n";
	string username, password;
	cout << "Sign Up " << endl;
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;
	cout << "\n\n\t Please wait a moment while we generate your ID \n\n\t";
	for (int i = 0; i < 4; i++)
	{
		cout << "*";
		Sleep(1000);
	}
	cout << "\n\t\t Your ID is created succesfully. Login to explore the CRICBUZZ APPLICATION\n\t\t";
	system("CLS");

start:
	cout << "Login " << endl;
	string username1;
	string password1;

	cout << "Enter your Username: ";
	cin >> username1;
	cout << "Enter your password: ";
	cin >> password1;
	if (username1 == username && password1 == password)
	{
		system("CLS");
	}
	else
		if (username1 != username)
		{
			cout << "The Username you have entered is incorrect " << endl;
			Sleep(3000);
			goto start;
		}
		else
			if (password1 != password)
			{
				cout << " The password you have entered is incorrect " << endl;
				Sleep(3000);
				goto start;
			}
	system("CLS");
	for (int i = 0; i < 20; i++) {
		cout << "What did you want for work\n" << "Press 1\t\tTo work with teams\nPress 2\t\tTo work with team's Matches\n" <<
			"Press 3\t\tTo work with players singularly\n\n\n";
		cin >> choice;
		switch (choice) {
		case 1: {cout << "Press 1\t\tTo add player in team\nPress 2\t\tTo remove player from team\nPress 3\t\tTo update player's data" <<
			"\nPress 4\t\tTo update Captain\nPress 5\t\tTo update coach of specfic team\n";
			cin >> i;
			if (i == 1) {
				string team_Name2add;
				cout << "Enter team name in which you want to add player:  ";
				cin.ignore();
				getline(cin, team_Name2add);
				team1.add_player(team_Name2add);
			}
			if (i == 2) {
				string team_Name2remove;
				cout << "Enter team name from which you want to remove player:  ";
				getline(cin, team_Name2remove);
				team1.remove_player();
			}
			if (i == 3) {
				string team_Name2update;
				cout << "Enter team name in which you want to update player's data :   ";
				getline(cin, team_Name2update);
				team1.update_player();
			}
			if (i == 4) {
				string team_Name2updateCap;
				cout << "Enter team name in which you want to update Captain :   ";
				getline(cin, team_Name2updateCap);
				team1.update_captain();
			}
			if (i == 5) {
				string team_Name2updateCou;
				cout << "Enter team name in which you want to Couch :   ";
				getline(cin, team_Name2updateCou);
				team1.update_coach();
			}
		}break;
		case 2: {
			cout << "Press 1\t\tTo Conduct Match\nPress 2\t\tTo display match Details\nPress 3\t\tTo display Ranking of teams\n";
			cin >> i;
			if (i == 1) {
				string team1_Name, team2_Name;
				cout << "Enter team1 name for match:   ";
				cin.ignore();
				getline(cin, team1_Name);
				cout << "Enter team1 name for match:   ";
				getline(cin, team2_Name);
				ob.conduct_matchs();
			}
			if (i == 2) {
				cout << "Match details will be :\n";
				ob.display_match_details();
			}
			if (i == 3) {
				cout << "ICC Team's ranking will be :  ";
				ob.ranking();
			}
		}break;
		case 3: {
			cout << "Press 1\t\tTo Print ICC Player's Ranking\nPress 2\t\tTo display players of a specfic team\n";
			cin >> i;
			if (i == 1) {
				cout << " ICC Plyer's ranking will be :  \n ";
				ob.players_ranking();
			}
			if (i == 2) {
				string strrr;
				cout << "Enter name of team from which you want a player  :   ";
				getline(cin, strrr);
				ob.team1_bat1(6);
			}
		}break;
		default:cout << "You don't follow instructions\n";
		}
	}
		  RenderWindow window(VideoMode(700, 700), "Cricbuzz");

		  RectangleShape Pakistan(Vector2f(700.0f, 700.0f)), India(Vector2f(700.0f, 700.0f)), Front1(Vector2f(700.0f, 700.0f));//declaration
		  Front1.setPosition(0, 0);
		  Texture Front1_texture;
		  Front1_texture.loadFromFile("Front1.png");
		  Front1.setTexture(&Front1_texture);
		  /////////////////////////////////////////////////
		  India.setPosition(0, 0);
		  Texture Team_India_texture;
		  Team_India_texture.loadFromFile("India.png");
		  India.setTexture(&Team_India_texture);
		  /////////////////////////////////////////////////
		  Pakistan.setPosition(0, 0);
		  Texture Team_Pakistan_Texture;
		  Team_Pakistan_Texture.loadFromFile("Pakistan.png");
		  Pakistan.setTexture(&Team_Pakistan_Texture);
		  RectangleShape England_team(Vector2f(700.0f, 700.0f)), World_ranking(Vector2f(700.0f, 700.0f)),
			  Australia_team(Vector2f(700.0f, 700.0f)), Menu(Vector2f(700.0f, 700.0f));//declaration
		  Menu.setPosition(0, 0);
		  Texture Menu_texture;
		  Menu_texture.loadFromFile("Menu.png");
		  Menu.setTexture(&Menu_texture);
		  ////////////////////////////////////////////////
		  World_ranking.setPosition(0, 0);
		  Texture ranking_texture;
		  ranking_texture.loadFromFile("Updated World Ranking.png");
		  World_ranking.setTexture(&ranking_texture);
		  ////////////////////////////////////////////////
		  England_team.setPosition(0, 0);
		  Texture Engl_team_texture;
		  Engl_team_texture.loadFromFile("England.png");
		  England_team.setTexture(&Engl_team_texture);
		  ///////////////////////////////////////////////
		  Australia_team.setPosition(0, 0);
		  Texture Austra_team_texture;
		  Austra_team_texture.loadFromFile("Australia.png");
		  Australia_team.setTexture(&Austra_team_texture);
		  ///////////////////////////////////////////////
		  Music sound;
		  if (!sound.openFromFile("sound.ogg"))
		  {
			  cout << "file not found!\n";
		  }
		  ifstream readrankings;
		  readrankings.open("Rankings.txt");
		  string str4[30];
		  int index = 0;
		  while (!readrankings.eof())
		  {
			  getline(readrankings, str4[index]);
			  index++;
		  }
		  Text rankings[30];
		  int y = 180;
		  Font font;
		  if (!font.loadFromFile("OpenSans-Bold.ttf"))
		  {
			  cout << "file not found!\n";
		  }

		  for (int i = 0; i < 30; i++) {
			  rankings[i].setFont(font);
			  rankings[i].setCharacterSize(25);
			  rankings[i].setOutlineColor(Color::Blue);
			  rankings[i].setFillColor(Color::White);
			  rankings[i].setOutlineThickness(1);
			  rankings[i].setPosition(80, y);
			  rankings[i].setString(str4[i]);
			  y = y + 40;
		  }
		  readrankings.close();
		  while (window.isOpen())
		  {
			  Event event;
			  while (window.pollEvent(event))
			  {
				  if (event.type == Event::Closed)
					  window.close();
			  }

			  if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				  //window.clear();

				  window.draw(Menu);
			  }
			  if (Keyboard::isKeyPressed(Keyboard::Num1)) {
				  //window.clear();

				  window.draw(Front1);
			  }
			  if (Keyboard::isKeyPressed(Keyboard::Num2)) {
				  //window.clear();

				  window.draw(India);
			  }
			  if (Keyboard::isKeyPressed(Keyboard::Num3)) {
				  //window.clear();

				  window.draw(Australia_team);
			  }
			  if (Keyboard::isKeyPressed(Keyboard::Num4)) {
				  //window.clear();

				  window.draw(England_team);
			  }
			  if (Keyboard::isKeyPressed(Keyboard::Num5)) {
				  //window.clear();

				  window.draw(Pakistan);
			  }

			  //if (Keyboard::isKeyPressed(Keyboard::Num8)) {
			  //	//window.clear();
			  //	for (int i = 0; i < 30; i++)
			  //	{
			  //		window.draw(rankings[i]);
			  //	}
			  //}
			  if (Keyboard::isKeyPressed(Keyboard::Space)) {
				  //window.clear();

				  window.draw(World_ranking);
				  for (int i = 0; i < 30; i++)
				  {
					  window.draw(rankings[i]);
				  }
			  }
			  if (Keyboard::isKeyPressed(Keyboard::Num6)) {
				  //window.clear();

				  sound.play();
			  }
			  if (Keyboard::isKeyPressed(Keyboard::Num7)) {
				  //window.clear();

				  sound.pause();
			  }
			  //window.clear();

			  /*window.draw(Pakistan);*/

			  window.display();
		  }
	}
	system("pause");
	return 0;
}