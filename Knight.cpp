#include "Knight.h"

// Constructor
Knight::Knight(int p_x_int, int p_y_int, bool p_team_int) : Figure(p_x_int, p_y_int, p_team_int) {};
// Destructor
Knight::~Knight(){};


bool Knight::is_threat_for_king(int p_x_king_int, int p_y_king_int)
{
    if(x - 1 == p_x_king_int && y - 2 == p_y_king_int)
    {
        return true;
    }
    else if( x - 2 == p_x_king_int && y - 1 == p_y_king_int)
    {
        return true;
    }
    else if( x - 2 == p_x_king_int && y + 1 == p_y_king_int)
    {
        return true;
    }
    else if( x - 1 == p_x_king_int && y + 2 == p_y_king_int)
    {
        return true;
    }
    else if( x + 1 == p_x_king_int && y + 2 == p_y_king_int)
    {
        return true;
    }
    else if( x + 2 == p_x_king_int && y + 1 == p_y_king_int)
    {
        return true;
    }
    else if( x + 2 == p_x_king_int && y - 1 == p_y_king_int)
    {
        return true;
    }
    else if( x + 1 == p_x_king_int && y - 2 == p_y_king_int)
    {
        return true;
    }

    return false;
}

bool Knight::check_if_figure_between(std::vector<Figure*>& dummy, int dummy_one, int dummy_two, int p_x_other_king_int, int p_y_other_king_int)
{
    return false;
}

bool Knight::can_step_on_coordinates(std::vector<Figure*>& p_figures, int x, int y)
{
    return is_threat_for_king(x, y);
}
