#include "Bishop.h"

// Constructor
Bishop::Bishop(int p_x_int, int p_y_int, bool p_team_int) : Figure(p_x_int, p_y_int, p_team_int) {}

// Destructor
Bishop::~Bishop(){};


bool Bishop::check_coordinates(int p_x_int, int p_y_int)
{
    if(p_x_int >= 8 || p_x_int < 0 || p_y_int >= 8 || p_y_int < 0)
    {
        return false;
    }
    return true;
}


bool Bishop::check_if_king_on_coordinates(int p_x_fig_int, int p_y_fig_int, int p_x_king_int, int p_y_king_int)
{
    if((p_x_fig_int == p_x_king_int) && (p_y_fig_int == p_y_king_int))
    {
        return true;
    }
    return false;
}


bool Bishop::is_threat_for_king(int p_x_king_int, int p_y_king_int)
{
    int l_x_fig_int;
    int l_y_fig_int;

    // If the passed coordinates are the coordinates of the current figure
    if( x == p_x_king_int && y == p_y_king_int)
    {
        return false;
    }

    // Iterate through all 4 possible sides the Bishop can move
    // Right and Down move
    l_x_fig_int = x;
    l_y_fig_int = y;
    for(int i = 0; i < 8; i++)
    {
        l_x_fig_int++;
        l_y_fig_int++;

        // if coordinates are not valid -> break
        if(check_coordinates(l_x_fig_int, l_y_fig_int) == false)
        {
            break;
        }
        if(true == check_if_king_on_coordinates(l_x_fig_int, l_y_fig_int, p_x_king_int , p_y_king_int))
        {
            return true;
        }
    }

    // Right and Up move
    l_x_fig_int = x;
    l_y_fig_int = y;
    for(int i = 0; i < 8; i++)
    {
        l_x_fig_int++;
        l_y_fig_int--;

        if( false == check_coordinates(l_x_fig_int, l_y_fig_int) )
        {
            break;
        }
        if( true == check_if_king_on_coordinates(l_x_fig_int, l_y_fig_int, p_x_king_int , p_y_king_int) )
        {
            return true;
        }
    }

    // Left and Up move
    l_x_fig_int = x;
    l_y_fig_int = y;
    for(int i = 0; i < 8; i++)
    {
        l_x_fig_int--;
        l_y_fig_int--;

        if( false == check_coordinates(l_x_fig_int, l_y_fig_int) )
        {
            break;
        }
        if( true == check_if_king_on_coordinates(l_x_fig_int, l_y_fig_int, p_x_king_int , p_y_king_int) )
        {
            return true;
        }
    }

    // Left and Down move
    l_x_fig_int = x;
    l_y_fig_int = y;
    for(int i = 0; i < 8; i++)
    {
        l_x_fig_int--;
        l_y_fig_int++;

        if( false == check_coordinates(l_x_fig_int, l_y_fig_int) )
        {
            break;
        }
        if( true == check_if_king_on_coordinates(l_x_fig_int, l_y_fig_int, p_x_king_int , p_y_king_int) )
        {
            return true;
        }
    }

    return false;
}

bool Bishop::check_if_figure_between(
                                     std::vector<Figure*>& p_figures_VECTOR,
                                     int p_x_king_int,
                                     int p_y_king_int,
                                     int p_x_other_king_int,
                                     int p_y_other_king_int
                                     )
{
    // Check if there is a blocking figure between
    // Right Up from the current figure and
    // Left Down form the King
    if( x < p_x_king_int && y > p_y_king_int )
    {
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            int l_tmp_x_int = x;
            int l_tmp_y_int = y;
            for(int i = 0; i < p_x_king_int - x - 1; i++)
            {
                l_tmp_x_int++;
                l_tmp_y_int--;
                if(p_x_other_king_int == l_tmp_x_int && p_y_other_king_int == l_tmp_y_int)
                {
                    return true;
                }
                if( (*it)->get_x() == l_tmp_x_int && (*it)->get_y() == l_tmp_y_int )
                {
                    return true;
                }
            }
        }
    }
    // Check if there is a blocking figure between
    // Right Down from the current figure and
    // Left Up form the King
    else if( x < p_x_king_int && y < p_y_king_int )
    {
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            int l_tmp_x_int = x;
            int l_tmp_y_int = y;
            for(int i = 0; i < p_x_king_int - x - 1; i++)
            {
                l_tmp_x_int++;
                l_tmp_y_int++;
                if(p_x_other_king_int == l_tmp_x_int && p_y_other_king_int == l_tmp_y_int)
                {
                    return true;
                }
                if( (*it)->get_x() == l_tmp_x_int && (*it)->get_y() == l_tmp_y_int )
                {
                    return true;
                }
            }
        }
    }
    // Check if there is a blocking figure between
    // Left Down from the current figure and
    // Right Up form the King
    else if( x > p_x_king_int && y < p_y_king_int )
    {
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            int l_tmp_x_int = x;
            int l_tmp_y_int = y;
            for(int i = 0; i < x - p_x_king_int -  1; i++)
            {
                l_tmp_x_int--;
                l_tmp_y_int++;
                if(p_x_other_king_int == l_tmp_x_int && p_y_other_king_int == l_tmp_y_int)
                {
                    return true;
                }
                if( (*it)->get_x() == l_tmp_x_int && (*it)->get_y() == l_tmp_y_int )
                {
                    return true;
                }
            }
        }
    }
    // Check if there is a blocking figure between
    // Left Up from the current figure and
    // Right Down form the King
    else if( x > p_x_king_int && y > p_y_king_int )
    {
        for(std::vector<Figure*>::iterator it = p_figures_VECTOR.begin(); it != p_figures_VECTOR.end(); ++it)
        {
            int l_tmp_x_int = x;
            int l_tmp_y_int = y;
            for(int i = 0; i < x - p_x_king_int - 1; i++)
            {
                l_tmp_x_int--;
                l_tmp_y_int--;
                if(p_x_other_king_int == l_tmp_x_int && p_y_other_king_int == l_tmp_y_int)
                {
                    return true;
                }
                if( (*it)->get_x() == l_tmp_x_int && (*it)->get_y() == l_tmp_y_int )
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Bishop::can_step_on_coordinates(std::vector<Figure*>& p_figures, int p_x_int, int p_y_int)
{
    return is_threat_for_king(p_x_int, p_y_int);
}
