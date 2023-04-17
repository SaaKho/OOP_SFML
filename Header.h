#pragma once
// Header.h file
// Declaration of classes
//------------------------------------------------------------------
#pragma once
#ifndef HEADER_H // Prevent multiple inclusions of header file
#define HEADER_H
//------------------------- Header files ---------------------------
#include<iostream>
#include<string>
#include <stdlib.h>  
#include <time.h>
using namespace std;

//---------------------- Declaration of Classes -----------------------

// Player class (It is an abstract class)
// Containg, All the atributes of an individual Player.
// With member functions to edit and search player data.
class Player {
protected:
	string* player_name;
	int* shirt_no;
	// Variables for total runs and wickets of a player in each format
	int* total_runs_t20, * total_runs_odi, * total_runs_test, * total_wickets_t20, * total_wickets_odi, * total_wickets_test;
	// Variable for total matches played by a player in each format
	int* matches_played_t20, * matches_played_odi, * matches_played_test;
	// Variables for batting ranking of player in each format
	float* bat_ranking_t20, * bat_ranking_odi, * bat_ranking_test;
	// Variables for bowling ranking of player in each format
	float* bowl_ranking, * bowl_ranking_odi, * bowl_ranking_test;
	// Variables for Batting and bowling average of player in each format
	float* bat_average_t20, * bat_average_odi, * bat_average_test, * bowl_average_t20, * bowl_average_odi, * bowl_average_test;
public:
	Player();   // Constructor
	~Player();  // Destructor 
	virtual void add_player(string team_Name2add) = 0;
	virtual void remove_player() = 0;  // Pure virtual functions
	virtual void search_player() = 0;
	virtual void update_player() = 0;
	virtual void display_player(int index) = 0;
};

//------------------------------------------------------------------
// Team class (Publically Inherited from Player class)
// Containg, All the atributes of an individual Team.
// This class contains team's data of all previous and upcoming matches 
// Only team Admin can edit the team squad and management.
class Team : public Player {
protected:
	string team_name[4]; // Name of Total 10 teams  
	// Variables for storing name of captain,coach and admin cradentials
	string captain_name[4], coach_name[4], admin_username[4], admin_password[4];
	// Variables for team ranking of every format and total number of players in a team
	float team_rank_t20[4], team_rank_odi[4], team_rank_test[4], num_of_players[10];
	// Variables for storing total matches played , 
	int total_matches_t20[10], total_matches_odi[10], total_matches_test[10];
	// Total wins
	int matches_won_t20[10], matches_won_odi[10], matches_won_test[10];
	// Losses of each format
	int matches_lost_t20[10], matches_lost_odi[10], matches_lost_test[10];
public:
	Team(); // Constructor
	~Team();  // Destructor

	// Major function
	void cricbuzz();
	// These functions are only accessible to admin.
	void add_player(string team_name);
	void remove_player();  // over-rided functions   
	void update_player();
	void update_captain();
	void update_coach();
	// Through this function User can search any specific player
	void search_player();
	// For displaying Data of an individual player
	void display_player(int index);
	// For taking player data as input
	void input_player(int index);
	// For Initializing the data of player with Null
	void null_player(int index);
	// For Setting Team data and player's data
	void set_team(int index, string team_name, string captain, 	string coach, string admin, string admin_pass,
		int num_of_players, int total_t20, int total_odi, int total_test, int won_t20, int won_odi, int won_test, 
		int lost_t20, int lost_odi, int lost_test);
	void set_player(int index, string name, int shirt, int t20_run, int odi_run, int test_run, int t20_wicket, 
		int odi_wicket, int test_wicket, int t20_played, int odi_played, int test_played);
	// For storing Teams squad data
	void set_pak();  // Team 1..Pakistan
	void set_ind();  // Team 2..India
	void set_eng();  // Team 3..England
	void set_aus();  // Team 4..Australia

	// This function will display all previous and upcoming matches along with all details
	//void display_matches()
};

//------------------------------------------------------------------
// Match Class (Inherited from Player and Team class)
// It Conducts both previouly scheduled matches & user scheduled matches
// It contains every detail of a match and a tournament
// It also updates players and team records after every match
class Match : public Team {
protected:
	string* team1, * team2, * date, * venue, * match_type, * tournament_name, * commentators, * umpires, * match_status;
	//Player data;
public:
	//Function for Toss
	void toss();
	void schedule_toss();
	//set team 1 & team2
	void setteam1();
	void setteam2();
	void team1_bat1(int over_balls);
	void team2_bat1(int over_balls);
	//Major function for match class
	void conduct_matchs();
	void ranking();
	void players_ranking();
	// Functions for match details
	void match_details();
	void set_match_details(int index, string _venue, string mat_type, string commentator, string umpire, string mat_status);
	void display_match_details(); // SFML

	// For Displaying Match date
	void set_date();

	// Functions for scheduling matches
	void run_match();
	void conduct_match();
	void conduct_match(int);
	void schedule_match();

	// For conducting tournament
	void conduct_tournament();

	// Functions for updating records and rankings
	//void update_world_records();
	//void update_player_ranking();

	// Functions for displaying previous and upcoming matches.
	//void display_upcoming_matches();
	//virtual void dispaly_recent_matches();
};

//------------------------------------------------------------------
// News class
// User can browse any information of a player or a team
// User can also see ICC rankings for any format.
//class News: public Match {
//public:
//	void dispaly_recent_matches();
//};
#endif