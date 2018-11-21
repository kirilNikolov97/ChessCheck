#include "Pawn.h"

// Constructor
Pawn::Pawn(int p_x_int, int p_y_int, bool p_team_int) : Figure(p_x_int, p_y_int, p_team_int) {};
// Destructor
Pawn::~Pawn(){};


bool Pawn::is_threat_for_king(int p_x_king_int, int p_y_king_int)
{
    // If WHITE pawn - from the bottom to the top
    if(this->team == true)
    {
        // up and right
        if(this->x + 1 == p_x_king_int && this->y - 1 == p_y_king_int)
        {
            return true;
        }
        // up and left
        else if(this->x - 1 == p_x_king_int && this->y - 1 == p_y_king_int)
        {
            return true;
        }
    }
    // BLACK pawn - from the top to the bottom
    else
    {
        // down and right
        if(this->x + 1 == p_x_king_int && this->y + 1 == p_y_king_int)
        {
            return true;
        }
        else if(this->x - 1 == p_x_king_int && this->y + 1 == p_y_king_int)
        {
            return true;
        }
    }

    return false;
}

bool Pawn::check_if_figure_between(
                                   std::vector<Figure*>& p_figures,
                                   int p_x_king_int,
                                   int p_y_king_int,
                                   int p_x_other_king_int,
                                   int p_y_other_king_int
                                   )
{
    if( true == team )
    {
        // WHITE Pawn
        if(
           (x - 1 == p_x_king_int && y - 1 == p_y_king_int) ||
           (x + 1 == p_x_king_int && y - 1 == p_y_king_int)
           )
        {
            return false;
        }
    }
    if( false == team )
    {
        // BLACK Pawn
        if(
           (x - 1 == p_x_king_int && y + 1 == p_y_king_int) ||
           (x + 1 == p_x_king_int && y + 1 == p_y_king_int)
           )
        {
            return false;
        }
    }
    for(std::vector<Figure*>::iterator it = p_figures.begin(); it != p_figures.end(); ++it)
    {
        if( true == team)
        {
            if((*it)->get_x() == x && (*it)->get_y() == y - 1)
            {
                return true;
            }
        }
        if( false == team)
        {
            if((*it)->get_x() == x && (*it)->get_y() == y + 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool Pawn::can_step_on_coordinates(std::vector<Figure*>& p_figures, int p_x_int, int p_y_int)
{
    if( true == team )
    {
        if(x == p_x_int && y - 1 == p_y_int)
        {
            for(std::vector<Figure*>::iterator it = p_figures.begin(); it != p_figures.end(); ++it)
            {
                if((*it)->get_x() == p_x_int && (*it)->get_y() ==  p_y_int)
                {
                    return false;
                }
            }
            return true;
        }
        else if(x == p_x_int && 6 == y && y - 2 == p_y_int)
        {
            for(std::vector<Figure*>::iterator it = p_figures.begin(); it != p_figures.end(); ++it)
            {
                if((*it)->get_x() == p_x_int && (*it)->get_y() ==  p_y_int)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    else
    {
        if(x == p_x_int && y + 1 == p_y_int)
        {
            for(std::vector<Figure*>::iterator it = p_figures.begin(); it != p_figures.end(); ++it)
            {
                if((*it)->get_x() == p_x_int && (*it)->get_y() ==  p_y_int)
                {
                    return false;
                }
            }
            return true;
        }
        else if(x == p_x_int && 1 == y && y + 2 == p_y_int)
        {
            for(std::vector<Figure*>::iterator it = p_figures.begin(); it != p_figures.end(); ++it)
            {
                if((*it)->get_x() == p_x_int && (*it)->get_y() ==  p_y_int)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}
