#include "Rook.h"

// Constructor
Rook::Rook(int p_x_int, int p_y_int, bool p_team_int) : Figure(p_x_int, p_y_int, p_team_int) {}
// Destructor
Rook::~Rook(){};


bool Rook::is_threat_for_king(int p_x_king_int, int p_y_king_int)
{
    if( x == p_x_king_int && y == p_y_king_int)
    {
        return false;
    }
    if( p_x_king_int > 7 || p_x_king_int < 0 || p_y_king_int > 7 || p_y_king_int < 0)
    {
        return true;
    }
    if(x == p_x_king_int || y == p_y_king_int)
    {
        return true;
    }
    return false;
}

bool Rook::check_if_figure_between(std::vector<Figure*>& p_figures_VECTOR, int p_x_king_int, int p_y_king_int, int p_x_other_king_int, int p_y_other_king_int)
{
    if(x == p_x_king_int && y < p_y_king_int)
    {
        if( p_x_other_king_int == p_x_king_int && p_y_other_king_int > y && p_y_other_king_int < p_y_king_int)
        {
            return true;
        }
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            if((*it)->get_x() != x)
            {
                continue;
            }
            else if((*it)->get_y() > y && (*it)->get_y() < p_y_king_int)
            {
                return true;
            }
        }
    }
    else if(x == p_x_king_int && y > p_y_king_int)
    {
        if( p_x_other_king_int == p_x_king_int && p_y_other_king_int < y && p_y_other_king_int > p_y_king_int)
        {
            return true;
        }
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            if((*it)->get_x() != x)
            {
                continue;
            }
            else if((*it)->get_y() < y && (*it)->get_y() > p_y_king_int)
            {
                return true;
            }
        }
    }
    else if( y == p_y_king_int && x < p_x_king_int)
    {
        if( p_y_other_king_int == p_y_king_int && p_x_other_king_int > x && p_x_other_king_int < p_x_king_int)
        {
            return true;
        }
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            if((*it)->get_y() != y)
            {
                continue;
            }
            else if((*it)->get_x() > x && (*it)->get_x() < p_x_king_int)
            {
                return true;
            }
        }
    }
    else if( y == p_y_king_int && x > p_x_king_int)
    {
        if( p_y_other_king_int == p_y_king_int && p_x_other_king_int < x && p_x_other_king_int > p_x_king_int)
        {
            return true;
        }
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            if((*it)->get_y() != y)
            {
                continue;
            }
            else if((*it)->get_x() < x && (*it)->get_x() > p_x_king_int)
            {
                return true;
            }
        }
    }
    return false;
}

bool Rook::can_step_on_coordinates(std::vector<Figure*>& p_figures, int x, int y)
{
    return is_threat_for_king(x, y);
}
