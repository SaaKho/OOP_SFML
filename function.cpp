// Function.cpp file
//Definition of Member functions, constructers, destructer of  Classes
//----------------------------------------------------------------------

//----------------------- Including Header File ------------------------
#include"Header.h"
#include<fstream>
//------------------------  Global Variables  --------------------------
string password, username;   // For asking login credentials of admin
int shirt_num;   // For asking user for shirt number of player
int rand1, rand2; // Random numbers for generating teams index
int toss_rand; // Random number for Toss
int match_rand = 0;
int choice_team1, choice_team2;
int type_choice;  // For asking tournament and match type from user
int team1_score = 0, team2_score = 0;
//----------------------------------------------------------------------
// Defining Constructors  and  Destructors
// of Player Class
Player::Player() {
	player_name = NULL;   shirt_no = NULL;
	total_runs_t20 = nullptr, total_runs_odi = nullptr, total_runs_test = nullptr, total_wickets_t20 = nullptr, total_wickets_odi = nullptr, total_wickets_test = nullptr;
	matches_played_t20 = nullptr, matches_played_odi = nullptr, matches_played_test = nullptr;
	bat_ranking_t20 = nullptr, bat_ranking_odi = nullptr, bat_ranking_test = nullptr, bowl_ranking = nullptr, bowl_ranking_odi = nullptr, bowl_ranking_test = nullptr;
	bat_average_t20 = nullptr, bat_average_odi = nullptr, bat_average_test = nullptr, bowl_average_t20 = nullptr, bowl_average_odi = nullptr, bowl_average_test = nullptr;
}
Player::~Player() {}
// of Team Class
Team::Team() {
	for (int i = 0; i <= 4; i++)
	{
		team_name[i] = "\0"; captain_name[i] = "\0"; coach_name[i] = "\0"; admin_username[i] = "\0"; admin_password[i] = "\0";
		team_rank_t20[i] = NULL, team_rank_odi[i] = NULL, team_rank_test[i] = NULL; matches_won_t20[i] = NULL, matches_won_odi[i] = NULL,
			matches_won_test[i] = NULL;
		matches_lost_t20[i] = NULL, matches_lost_odi[i] = NULL, matches_lost_test[i] = NULL;
	}
	for (int j = 0; j < 4; j++) {
		num_of_players[j] = NULL;
		total_matches_t20[j] = NULL, total_matches_odi[j] = NULL, total_matches_test[j] = NULL;
	}
}
Team::~Team() {}
//----------------------------------------------------------------------
// This function is for initializing team data
void Team::set_team(int index, string name, string captain, string coach, string admin, string admin_pass, int num_of_players, int total_t20, int total_odi, int total_test, int won_t20, int won_odi, int won_test, int lost_t20, int lost_odi, int lost_test)
{
	team_name[index] = name;  // Team name

	captain_name[index] = captain;  // Team details
	coach_name[index] = coach;
	this->num_of_players[index] = num_of_players;

	admin_username[index] = admin;  // Admin cradentials
	admin_password[index] = admin_pass;

	total_matches_t20[index] = total_t20;  // Total matches played by a team in each format
	total_matches_odi[index] = total_odi;
	total_matches_test[index] = total_test;

	matches_won_t20[index] = won_t20;   // Total matches won by a team in each format
	matches_won_odi[index] = won_odi;
	matches_won_test[index] = won_test;

	matches_lost_t20[index] = lost_t20;  // Total matches lost by a team in each format
	matches_lost_odi[index] = lost_odi;
	matches_lost_test[index] = lost_test;

	team_rank_t20[index] = matches_won_t20[index] / total_matches_t20[index];  // Team ranking aggregate
	team_rank_odi[index] = matches_won_odi[index] / total_matches_odi[index];
	team_rank_test[index] = matches_won_test[index] / total_matches_test[index];
}

// This function is for initializing player data
void Team::set_player(int index, string name, int shirt, int t20_run, int odi_run, int test_run, int t20_wicket, int odi_wicket, int test_wicket, int t20_played, int odi_played, int test_played)
{
	player_name[index] = name;   // Player name
	shirt_no[index] = shirt;   // Player shirt number

	total_runs_t20[index] = t20_run;   // Runs Scored in each format
	total_runs_odi[index] = odi_run;
	total_runs_test[index] = test_run;

	total_wickets_t20[index] = t20_wicket;   // Wickets taken in each format
	total_wickets_odi[index] = odi_wicket;
	total_wickets_test[index] = test_wicket;

	matches_played_t20[index] = t20_played;   // Matches played by player of each format
	matches_played_odi[index] = odi_played;
	matches_played_test[index] = test_played;

	bat_average_t20[index] = total_runs_t20[index] / matches_played_t20[index];   // Batting average of player in each format
	bat_average_odi[index] = total_runs_odi[index] / matches_played_odi[index];
	bat_average_test[index] = total_runs_test[index] / matches_played_test[index];

	bowl_average_t20[index] = total_wickets_t20[index] / matches_played_t20[index];   // Bowling average of player in each format
	bowl_average_odi[index] = total_wickets_odi[index] / matches_played_odi[index];
	bowl_average_test[index] = total_wickets_test[index] / matches_played_test[index];
}
//----------------------------------------------------------------------
//  Cric Buzz Method  (Major Function)
// In this function, Dynamic arrays are created to store the details of players of all teams
// Setters of All the teams are called in this Function
void Team::cricbuzz()
{
	player_name = new string[44];  // Dynamic arrays to store player details.
	shirt_no = new int[44];

	total_runs_t20 = new int[44];  // Dynamic arrays to store total runs scored by player in each format
	total_runs_odi = new int[44];
	total_runs_test = new int[44];

	total_wickets_t20 = new int[44];  // Dynamic arrays to store total wickets taken by player in each format
	total_wickets_odi = new int[44];
	total_wickets_test = new int[44];

	matches_played_t20 = new int[44];  // Dynamic arrays to store total matches played by player of each format
	matches_played_odi = new int[44];
	matches_played_test = new int[44];

	bat_average_t20 = new float[44]; // Dynamic arrays to store batting average of player in each format
	bat_average_odi = new float[44];
	bat_average_test = new float[44];

	bowl_average_t20 = new float[44]; // Dynamic arrays to store bowling average of player in each format
	bowl_average_odi = new float[44];
	bowl_average_test = new float[44 ];

	set_pak();
	set_ind();  // Calling Setter functions of teams
	set_eng();
	set_aus();
}
//----------------------------------------------------------------------
// Setting Squads
// Adding players to each squad through setter functions
// Different function for each team
// In these setters player details are assigned to every player of each team.
// Complete details of team are assigned to a team.
//----------------------------------------------------------------------
						//Team 1..Pakistan
//----------------------------------------------------------------------
void Team::set_pak()
{
	ifstream read;
	read.open("Pakistan.txt");
	string str;
	bool stop = false;
	while (!read.eof() && !stop) {
		getline(read, str);
			cout << str << endl;
	}
}
//----------------------------------------------------------------------
						//	Team 2.. India
//----------------------------------------------------------------------
void Team::set_ind()
{
	ifstream read2;
	read2.open("India.txt");
	string str;
	bool stop = false;
	while (!read2.eof() && !stop) {
		getline(read2, str);
			cout << str << endl;
	}
}
//----------------------------------------------------------------------
						// Team 3.. England
//----------------------------------------------------------------------
void Team::set_eng()
{

	ifstream read2;
	read2.open("England.txt");
	string str;
	bool stop = false;
	while (!read2.eof() && !stop) {
		getline(read2, str);
			cout << str << endl;
	}
}
//----------------------------------------------------------------------
						// Team 4..Australia
//----------------------------------------------------------------------
void Team::set_aus()
{
	ifstream read2;
	read2.open("Australia.txt");
	string str;
	bool stop = false;
	while (!read2.eof() && !stop) {
		getline(read2, str);
			cout << str << endl;
	}
}
//----------------------------------------------------------------------
						// Team 5..Newzealand
//----------------------------------------------------------------------

void Team::display_player(int index) {
	cout << player_name[index] << "  " << shirt_no[index] << "  " << total_runs_t20[index] << "  " << total_runs_odi[index] << "  " << total_runs_test[index]
		<< "  " << total_wickets_t20[index] << "  " << total_wickets_odi[index] << "  " << total_wickets_test[index]
		<< "  " << matches_played_t20[index] << "  " << matches_played_odi[index] << "  " << matches_played_test[index]
		<< "  " << bat_average_t20[index] << "  " << bat_average_odi[index] << "  " << bat_average_test[index]
		<< "  " << bowl_average_t20[index] << "  " << bowl_average_odi[index] << "  " << bowl_average_test[index] << "\n";
}
//----------------------------------------------------------------------
		// Function for taking individual player data as input
//----------------------------------------------------------------------
void Team::input_player(int index) {
	cin >> player_name[index] >> shirt_no[index] >> total_runs_t20[index] >> total_runs_odi[index] >> total_runs_test[index]
		>> total_wickets_t20[index] >> total_wickets_odi[index] >> total_wickets_test[index]
		>> matches_played_t20[index] >> matches_played_odi[index] >> matches_played_test[index]
		>> bat_average_t20[index] >> bat_average_odi[index] >> bat_average_test[index]
		>> bowl_average_t20[index] >> bowl_average_odi[index] >> bowl_average_test[index];
}
//----------------------------------------------------------------------
	// Function for Initializing individual player data with Null
//----------------------------------------------------------------------
void Team::null_player(int index) {
	player_name[index] = "\0"; shirt_no[index] = NULL;  total_runs_t20[index] = NULL; total_runs_odi[index] = NULL; total_runs_test[index] = NULL;
	total_wickets_t20[index] = NULL;  total_wickets_odi[index] = NULL;  total_wickets_test[index] = NULL;
	matches_played_t20[index] = NULL;  matches_played_odi[index] = NULL; matches_played_test[index] = NULL;
	bat_average_t20[index] = NULL; bat_average_odi[index] = NULL; bat_average_test[index] = NULL;
	bowl_average_t20[index] = NULL; bowl_average_odi[index] = NULL; bowl_average_test[index] = NULL;
}
//----------------------------------------------------------------------
	// Function for Displaying Team's Squad with team management
//----------------------------------------------------------------------
//----------------------------------------------------------------------
						 // Admin Method
//----------------------------------------------------------------------
// It asks admin for login credentials
// Allows the admin to access specific functions 
//----------------------------------------------------------------------
			  // Now defining functions accesible by Admin
//----------------------------------------------------------------------
// Add player Method
// This function is for adding a player in place of a present player 
void Team::add_player(string team_name) {
	
	if (team_name == "Pakistan"){
		cout << "Enter shirt no. :   ";
		cin >> shirt_num;
		// cout<<"You are adding new player in place of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now enter new player data
	}
	if (team_name == "India") {
		set_ind();
		cout << "Enter shirt no. :   ";
		cin >> shirt_num;
		// cout<<"You are adding new player in place of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now enter new player data
	}
	if (team_name == "England") {
		set_eng();
		cout << "Enter shirt no. :   ";
		cin >> shirt_num;
		// cout<<"You are adding new player in place of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now enter new player data
	}
	if (team_name == "Australia") {
		set_aus();
		cout << "Enter shirt no. :   ";
		cin >> shirt_num;
		// cout<<"You are adding new player in place of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now enter new player data
	}
}
// Remove PLayer Method
// For removing the data of a specific player
void Team::remove_player() {
	if (password == admin_password[0]) {
		set_pak();
		cin >> shirt_num;
		// cout<<"You are removing data of this player: "<<player_name[shirt_num-1];
		null_player(shirt_num - 1);  // data removed
	}
	else if (password == admin_password[1]) {
		set_ind();
		cin >> shirt_num;
		// cout<<"You are removing data of this player: "<<player_name[shirt_num-1];
		null_player(shirt_num - 1);  // now enter new player data
	}
	else if (password == admin_password[2]) {
		set_eng();
		cin >> shirt_num;
		// cout<<"You are removing data of this player: "<<player_name[shirt_num-1];
		null_player(shirt_num - 1);  // data removed
	}
	else if (password == admin_password[3]) {
		set_aus();
		cin >> shirt_num;
		// cout<<"You are removing data of this player: "<<player_name[shirt_num-1];
		null_player(shirt_num - 1); // data removed
	}
}
// Update Player Method
// For updating a specific player
void Team::update_player() {
	if (password == admin_password[0]) {
		set_pak();
		cin >> shirt_num;
		// cout<<"You are updating data of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now update player data
	}
	else if (password == admin_password[1]) {
		set_ind();
		cin >> shirt_num;
		// cout<<"You are updating data of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now update player data
	}
	else if (password == admin_password[2]) {
		set_eng();
		cin >> shirt_num;
		// cout<<"You are updating data of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now update player data
	}
	else if (password == admin_password[3]) {
		set_aus();
		cin >> shirt_num;
		// cout<<"You are updating data of this player: "<<player_name[shirt_num-1];
		input_player(shirt_num - 1);  // now update player data
	}
}
// Update Captain Method
// For updating Captain of a specific team
void Team::update_captain() {
	if (password == admin_password[0]) {
		cin >> captain_name[0];
	}
	else if (password == admin_password[1]) {
		cin >> captain_name[1];
	}
	else if (password == admin_password[2]) {
		cin >> captain_name[2];
	}
	else if (password == admin_password[3]) {
		cin >> captain_name[3];
	}
}
// Update Coach Method
// For updating Coach of a specific team
void Team::update_coach() {
	if (password == admin_password[0]) {
		cin >> coach_name[0];
	}
	else if (password == admin_password[1]) {
		cin >> coach_name[1];
	}
	else if (password == admin_password[2]) {
		cin >> coach_name[2];
	}
	else if (password == admin_password[3]) {
		cin >> coach_name[3];
	}
}
//----------------------------------------------------------------------
				   // Search player Method
//----------------------------------------------------------------------
// For searching a specific player of any team 
void Team::search_player() {
	cin >> shirt_num;
	display_player(shirt_num - 1);
}
//----------------------------------------------------------------------
//			         >>>  MATCH CLASS  <<<
//----------------------------------------------------------------------
// Major function of match class
void Match::ranking() {

	ifstream read3;
	read3.open("Rankings.txt");
	string str;
	bool stop = false;
	while (!read3.eof() && !stop) {
		getline(read3, str);
		cout << str << endl;
	}
}
void Match::players_ranking() {
	ifstream read4;
	read4.open("Player's Ranking.txt");
	string str;
	bool stop = false;
	while (!read4.eof() && !stop) {
		getline(read4, str);
		cout << str << endl;
	}
}
void Match::conduct_matchs() {
	venue = new string[2];
	match_type = new string[2];
	tournament_name = new string[2];   // Arrays for match details
	commentators = new string[2];
	umpires = new string[2];
	match_status = new string[2];

	cricbuzz();
	match_details();
	conduct_match();
}
//Function for setting match details like date of match , match type, commentators name, umpires
void Match::set_match_details(int index, string _venue, string mat_type, string commentator, string umpire, string mat_status) {
	venue[index] = _venue;
	match_type[index] = mat_type;
	commentators[index] = commentator;
	umpires[index] = umpire;
	match_status[index] = mat_status;
}
//Initializing match details
void Match::match_details() {
	set_match_details(0, "Lahore-Gaddafi-Stadium", "T20", "Ramiz-Raja", "Aleem-Dar", "Live");
	set_match_details(1, "National-Stadium-Karachi", "One-day", "Bazid-Khan", "Shozab-Raza", "Previous");
}
// Displaying match details
void Match::display_match_details() {

	//set_match_details(0, "Lahore-Gaddafi-Stadium", "T20", "Ramiz-Raja", "Aleem-Dar", "Live");
	//set_match_details(1, "National-Stadium-Karachi", "One-day", "Bazid-Khan", "Shozab-Raza", "Previous");
}
//----------------------------------------------------------------------
				   // Function for Toss
//----------------------------------------------------------------------
// This function will decide which team will play first and wether it choose bowling or batting
void Match::toss() {
	srand(time(NULL));

	rand1 = rand() % 10;  // Random numbers for generating teams index
	rand2 = rand() % 10;
	toss_rand = rand() % 2; // For deciding team will choose batting or bowling

	if (rand1 == rand2)  // if both variables are equal 
	{
		rand2 = rand2 - 1;  // decrease 2nd variable by 1
		if (rand2 == 0)
			rand2 = rand2 + 2;
	}
}
void Match::schedule_toss() {
	cin >> choice_team1 >> choice_team2;
	rand1 = rand() % 10;  // Random numbers for generating teams index
	rand2 = rand() % 10;
	toss_rand = rand() % 2; // For deciding team will choose batting or bowling

	if (rand1 == rand2)  // if both variables are equal 
	{
		rand2 = rand2 - 1;  // decrease 2nd variable by 1
		if (rand2 == 0)
			rand2 = rand2 + 2;
	}
	if (rand1 > rand2) {
		cout << "Team :" << team_name[choice_team1] << "has won the toss";
		if (toss_rand == 0) {
			cout << "Team :" << team_name[choice_team1] << "has choosen bowling";
		}
		else {
			cout << "Team :" << team_name[choice_team1] << "has choosen batting";
		}
	}
	else {
		cout << "Team :" << team_name[choice_team2] << "has won the toss";
		if (toss_rand == 0) {
			cout << "Team :" << team_name[choice_team2] << "has choosen bowling";
		}
		else {
			cout << "Team :" << team_name[choice_team2] << "has choosen batting";
		}
	}
}
//----------------------------------------------------------------------
						// Set date Method
//----------------------------------------------------------------------
// Function for displaying match date
void Match::set_date() {
	int day, month;
	day = (rand() % 31) + 1;
	month = (rand() % 12) + 1;
	if (month == 2 && day > 29)
	{
		day = 28;
	}
	cout << day << " / " << month << " / " << "2021";
}
//----------------------------------------------------------------------
				//  Method for batting of team 1
//----------------------------------------------------------------------
void Match::team1_bat1(int over_balls) {
	int score1 = 0, score2 = 0, score = 0, prev = 0, prev1 = 2, prev_player = 0, prev_player1 = 1, wickets_fall = 0;
	int sco1 = 0, sco2 = 0;


	for (int i = 1; i <= over_balls; i++)
	{
		cout << "\n";
		score = rand() % 9;
		if (prev % 2 == 0 || i == 0 || prev1 % 2 != 0)  // for changing strike
		{
			if (score == 8)  // for changing batsman after weicket
			{
				score1 = 0;
				cout << "\nWicket fallen, " << team1[prev_player] << "  New batsman: " << team1[wickets_fall + 2] << "\n";
				prev_player = wickets_fall + 2;
				wickets_fall++;
				score = 0;
			}
			else
			{
				score1 = score1 + score;
				cout << "*" << team1[prev_player] << ": " << score1 << "  " << team1[prev_player1] << ": " << score2 << "\n";
				prev = score; // for changing batsman 
				if (prev % 2 != 0)
					prev1 = 2;
			}

		}
		else if (prev % 2 != 0 || prev1 % 2 == 0)
		{
			if (score == 8)  // for changing batsman after weicket
			{
				wickets_fall++;
				score2 = 0;
				cout << "\nWicket fallen, " << team1[prev_player1] << "  New batsman: " << team1[wickets_fall + 1] << "\n";
				prev_player1 = wickets_fall + 1;
				score = 0;
			}
			else {
				score2 = score2 + score;
				cout << "* " << team1[prev_player1] << ": " << score2 << "   " << team1[prev_player] << ": " << score1 << "\n";
				prev1 = score; // for changing batsman
				if (prev1 % 2 != 0)
					prev = 2;
			}
		}
		if (i <= 6)
		{
			sco1 = sco1 + score;
			cout << "* " << team2[8] << " : " << sco1;
			if (i == 6)
			{
				cout << "\n----------------- 2nd Over --------------------";
				swap(prev_player, prev_player1);
				swap(score1, score2);
			}
		}
		if (i > 6 && i <= 12)
		{
			sco2 = sco2 + score;
			cout << "* " << team2[9] << " : " << sco2;
		}
		team1_score = sco1 + sco2;
		if (toss_rand == 0) {  // for checking winner

			if (team1_score > team2_score)
			{
				i = 13;
				cout << "\nTeam " << team_name[rand1] << " wins";
			}
			else if ((i == 12 && team1_score < team2_score) || wickets_fall == 10)
			{
				cout << "\nTeam " << team_name[rand2] << " wins";
			}
		}
	}
	cout << "\n\nteam: " << team1_score << " /" << wickets_fall << "\n";
}
//----------------------------------------------------------------------
				//  Method for batting of team 2
//----------------------------------------------------------------------
void Match::team2_bat1(int over_balls) {
	int score1 = 0, score2 = 0, score = 0, prev = 0, prev1 = 2, prev_player = 0, prev_player1 = 1, wickets_fall = 0;
	int sco1 = 0, sco2 = 0;


	for (int i = 1; i <= over_balls; i++)
	{
		cout << "\n";
		score = rand() % 9;
		if (prev % 2 == 0 || i == 0 || prev1 % 2 != 0)  // for changing strike
		{
			if (score == 8)  // for changing batsman after weicket
			{
				score1 = 0;
				cout << "\nWicket fallen, " << team2[prev_player] << "  New batsman: " << team2[wickets_fall + 2] << "\n";
				prev_player = wickets_fall + 2;
				wickets_fall++;
				score = 0;
			}
			else
			{
				score1 = score1 + score;
				cout << "*" << team2[prev_player] << ": " << score1 << "  " << team2[prev_player1] << ": " << score2 << "\n";
				prev = score; // for changing batsman 
				if (prev % 2 != 0)
					prev1 = 2;
			}

		}
		else if (prev % 2 != 0 || prev1 % 2 == 0)
		{
			if (score == 8)  // for changing batsman after weicket
			{
				wickets_fall++;
				score2 = 0;
				cout << "\nWicket fallen, " << team2[prev_player1] << "  New batsman: " << team2[wickets_fall + 1] << "\n";
				prev_player1 = wickets_fall + 1;
				score = 0;
			}
			else {
				score2 = score2 + score;
				cout << "* " << team2[prev_player1] << ": " << score2 << "   " << team2[prev_player] << ": " << score1 << "\n";
				prev1 = score; // for changing batsman
				if (prev1 % 2 != 0)
					prev = 2;
			}
		}
		if (i <= 6)
		{
			sco1 = sco1 + score;
			cout << "* " << team1[8] << " : " << sco1;
			if (i == 6)
			{
				cout << "\n----------------- 2nd Over --------------------";
				swap(prev_player, prev_player1);
				swap(score1, score2);
			}
		}
		if (i > 6 && i <= 12)
		{
			sco2 = sco2 + score;
			cout << "* " << team1[9] << " : " << sco2;
		}

		team2_score = sco1 + sco2;
		if (toss_rand == 1) {  // for checking winner

			if (team2_score > team1_score)
			{
				cout << "\nTeam " << team_name[rand2] << " wins";
				break;
			}
			else if ((i == 12 && team2_score < team1_score) || wickets_fall == 10)
			{
				cout << "\nTeam " << team_name[rand1] << " wins";
			}
		}
	}
	cout << "\n\nteam: " << team2_score << " /" << wickets_fall << "\n";
}
//----------------------------------------------------------------------
				// Run Match Method
//----------------------------------------------------------------------
void Match::run_match() {
	setteam1();
	setteam2();
	switch (toss_rand) {
	case 0:
		cout << "Team : " << team_name[rand1] << " has won the toss & choosen bowling \n" << "Team " << team_name[rand2] << " is batting first\n";
		team2_bat1(12);   // for team winning toss and bowling first 
		team1_bat1(12);
		break;
	case 1:
		cout << "Team : " << team_name[rand1] << " has won the toss & choosen batting\n" << "Team " << team_name[rand2] << " is bowling\n";
		team1_bat1(12);
		team2_bat1(12);	 // for team winning toss and batting first
		break;
	default:
		break;
	}

}
//----------------------------------------------------------------------
				// Conduct Match Method
//----------------------------------------------------------------------
// for conducting previously scheduled match
void Match::conduct_match() {
	toss();
	// Now Displaying team squads after toss   
	//display_team(rand1);
	//display_team(rand2);
	//display_match_details();
	//pause
	cout<<"Press 0\t\tFor T20 match\nPress 1\t\tFor ODI match\n";
	switch (match_rand) {
	case 0://for t20
		run_match();
		break;
	case 1:  // for odi
		//run_match(300);
		break;
	}
}
void Match::conduct_match(int match_type) {    // Function overloading  for tournament
	switch (match_type)
	{
	case 0:
		for (int team1 = 0; team1 <= 8; team1++)
		{
			for (int team2 = team1 + 1; team2 <= 9; team2++)     // T20 tournament
			{
				for (int i = 1; i <= 120; i++)
				{
					toss();
					// Now Displaying team squads after toss
					//display_team(team1);
					//display_team(rand2);
					//display_match_details();

				}
			}
		}
		break;
	case 1:
		for (int team1 = 0; team1 <= 8; team1++)
		{
			for (int team2 = team1 + 1; team2 <= 9; team2++)
			{
				for (int i = 1; i <= 300; i++)       // ODI tournament
				{
					toss();
					// Now Displaying team squads after toss
					//display_team(team1);
					//display_team(rand2);
					//display_match_details();

				}
			}
		}
	}
}
//----------------------------------------------------------------------
				// Schedule Match Method
//----------------------------------------------------------------------
// for conducting user scheduled match
void Match::schedule_match() {
	cin >> type_choice;
	switch (type_choice)
	{
	case 0:
		for (int i = 1; i <= 120; i++)
		{
			schedule_toss();
			// Now Displaying team squads after toss
			//display_team(rand1);
			//display_team(rand2);
			//display_match_details();
		}
		break;
	case 1:
		for (int i = 1; i <= 300; i++)
		{

		}
		break;
	}
}
//----------------------------------------------------------------------
				// Conduct  Tournament 
//----------------------------------------------------------------------
void Match::conduct_tournament() {
	cin >> type_choice;
	switch (type_choice)
	{
	case1:
		conduct_match(1);  // t20 tournament
		break;
	case2:
		conduct_match(2);   // Odi tournament
		break;
	}

}

//----------------------------------------------------
//set team number 1	
//----------------------------------------------------
void Match::setteam1()
{
	team1 = new string[11];

	int a = 0;

	switch (rand1)
	{
	case(0):
	{
		for (int i = 0, a = 0; i <= 10; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}

	case(1):
	{
		for (int i = 11, a = 0; i <= 21; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	case(2):
	{
		for (int i = 22, a = 0; i <= 32; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	case(3):
	{
		for (int i = 33, a = 0; i <= 43; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}

	case(4):
	{
		for (int i = 44, a = 0; i <= 54; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	case(5):
	{
		for (int i = 55, a = 0; i <= 65; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	case(6):
	{
		for (int i = 66, a = 0; i <= 76; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	case(7):
	{
		for (int i = 77, a = 0; i <= 87; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	case(8):
	{
		for (int i = 88, a = 0; i <= 98; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	case(9):
	{
		for (int i = 99, a = 0; i <= 109; a++, i++)
		{
			team1[a] = player_name[i];
		}
		break;
	}
	}
}

//------------------------------------------------
	// set team number 2
//------------------------------------------------
void Match::setteam2()
{
	team2 = new string[11];
	int a = 0;

	switch (rand2)
	{
	case(0):
	{
		for (int i = 0, a = 0; i <= 10; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}

	case(1):
	{
		for (int i = 11, a = 0; i <= 21; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	case(2):
	{
		for (int i = 22, a = 0; i <= 32; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	case(3):
	{
		for (int i = 33, a = 0; i <= 43; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}

	case(4):
	{
		for (int i = 44, a = 0; i <= 54; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	case(5):
	{
		for (int i = 55, a = 0; i <= 65; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	case(6):
	{
		for (int i = 66, a = 0; i <= 76; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	case(7):
	{
		for (int i = 77, a = 0; i <= 87; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	case(8):
	{
		for (int i = 88, a = 0; i <= 98; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	case(9):
	{
		for (int i = 99, a = 0; i <= 109; a++, i++)
		{
			team2[a] = player_name[i];
		}
		break;
	}
	default:cout << "Wrong input\n";
	}
}