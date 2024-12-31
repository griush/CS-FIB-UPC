#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

struct Team {
    int points = 0;
    int goals = 0;
    int goals_against = 0;

    int team_id = 0;
};

struct League {
    vector<Team> teams;
};

void readInput(League &out_league) {
    for (int i = 0; i < out_league.teams.size(); i++) {
        for (int j = 0; j < out_league.teams.size(); j++) {
            int x, y;
            cin >> x >> y;

            out_league.teams[i].team_id = i;
            out_league.teams[j].team_id = j;

            if (i == j) continue;

            int i_points = 0, j_points = 0;
            if (x == y) {
                i_points = 1;
                j_points = 1;
            } else if (x > y)
                i_points = 3;
            else
                j_points = 3;

            out_league.teams[i].goals += x;
            out_league.teams[i].goals_against += y;
            out_league.teams[i].points += i_points;

            out_league.teams[j].goals += y;
            out_league.teams[j].goals_against += x;
            out_league.teams[j].points += j_points;
        }
    }
}

int main() {
    int n;
    cin >> n;

    League league;
    league.teams = vector<Team>(n);
    readInput(league);

    // Sort the teams
    std::sort(league.teams.begin(), league.teams.end(), [](Team a, Team b) {
        if (a.points != b.points) return a.points > b.points;

        if (a.goals - a.goals_against != b.goals - b.goals_against)
            return a.goals - a.goals_against > b.goals - b.goals_against;

        return a.team_id < b.team_id;
    });
    
    for (Team team : league.teams) {
        cout << team.team_id + 1 << " " << team.points << " " << team.goals << " " << team.goals_against << "\n";
    }

    flush(cout);
    return 0;
}
