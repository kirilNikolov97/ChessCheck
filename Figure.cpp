#include "Figure.h"

// Constructors
Figure::Figure()
{
    x = -1;
    y = -1;
    team = false;
}
Figure::Figure(int p_x_int, int p_y_int, bool p_team_int)
{
    this->x = p_x_int;
    this->y = p_y_int;
    this->team = p_team_int;
}

// Setters
void Figure::set_x(int p_x)
{
    x = p_x;
}
void Figure::set_y(int p_y)
{
    y = p_y;
}
void Figure::set_team(bool p_team)
{
    team = p_team;
}

// Getters
int Figure::get_x()
{
    return x;
}
int
 Figure::get_y()
{
    return y;
}
bool Figure::get_team()
{
    return team;
}
