#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Team {
    int points = 0;
    int goals = 0;
    int goals_against = 0;

    int team_id = 0;
};

void setupTeamsId(vector<Team>& teams) {
    for (int i = 0; i < teams.size(); i++) {
        teams[i].team_id = i + 1;
    }
}

struct League {
    vector<Team> teams;
};

void readInput(League& out_league, int jornadas) {
    int partits = (out_league.teams.size() / 2) * jornadas;
    while (partits > 0) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        int i_points = 0, j_points = 0;
        if (x == y) {
            i_points = 1;
            j_points = 1;
        } else if (x > y)
            i_points = 3;
        else
            j_points = 3;

        out_league.teams[i-1].points += i_points;
        out_league.teams[i-1].goals += x;
        out_league.teams[i-1].goals_against += y;

        out_league.teams[j-1].points += j_points;
        out_league.teams[j-1].goals += y;
        out_league.teams[j-1].goals_against += x;

        partits--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    League league;
    league.teams = vector<Team>(n);
    setupTeamsId(league.teams);
    readInput(league, m);

    sort(league.teams.begin(), league.teams.end(), [](Team a, Team b) {
        if (a.points != b.points) return a.points > b.points;

        if (a.goals - a.goals_against != b.goals - b.goals_against)
            return a.goals - a.goals_against > b.goals - b.goals_against;

        return a.team_id < b.team_id;
    });

    for (Team team : league.teams) {
        cout << team.team_id << " " << team.points << " " << team.goals << " " << team.goals_against << "\n";
    }

    flush(cout);
    return 0;
}
