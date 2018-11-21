#include "Queen.h"


// Constructor
Queen::Queen(int p_x_int, int p_y_int, bool p_team_int) : Figure(p_x_int, p_y_int, p_team_int) {}
// Destructor
Queen::~Queen(){};


bool Queen::check_coordinates(int p_x_int, int p_y_int)
{
    if(p_x_int >= 8 || p_x_int < 0 || p_y_int >= 8 || p_y_int < 0)
    {
        return false;
    }
    return true;
}

bool Queen::check_if_king_on_coordinates(int p_x_fig_int, int p_y_fig_int, int p_x_king_int, int p_y_king_int)
{
    if((p_x_fig_int == p_x_king_int) && (p_y_fig_int == p_y_king_int))
    {
        return true;
    }
    return false;
}

bool Queen::is_threat_for_king(int p_x_king_int, int p_y_king_int)
{
    if( x == p_x_king_int && y == p_y_king_int)
    {
        return false;
    }
    if( p_x_king_int > 7 || p_x_king_int < 0 || p_y_king_int > 7 || p_y_king_int < 0)
    {
        return true;
    }
    int x_fig = x;
    int y_fig = y;
    if(x_fig == p_x_king_int || y_fig == p_y_king_int)
    {
        return true;
    }

    for(int i = 0; i < 8; i++)
    {
        x_fig++;
        y_fig++;

        // if coordinates are not valid -> break
        if(check_coordinates(x_fig, y_fig) == false)
        {
            break;
        }

        if(true == check_if_king_on_coordinates(x_fig, y_fig, p_x_king_int , p_y_king_int))
        {
            return true;
        }
    }

    x_fig = x;
    y_fig = y;
    for(int i = 0; i < 8; i++)
    {
        x_fig++;
        y_fig--;

        if( false == check_coordinates(x_fig, y_fig) )
        {
            break;
        }
        if( true == check_if_king_on_coordinates(x_fig, y_fig, p_x_king_int , p_y_king_int) )
        {
            return true;
        }
    }

    x_fig = x;
    y_fig = y;
    for(int i = 0; i < 8; i++)
    {
        x_fig--;
        y_fig--;

        if( false == check_coordinates(x_fig, y_fig) )
        {
            break;
        }
        if( true == check_if_king_on_coordinates(x_fig, y_fig, p_x_king_int , p_y_king_int) )
        {
            return true;
        }
    }

    x_fig = x;
    y_fig = y;
    for(int i = 0; i < 8; i++)
    {
        x_fig--;
        y_fig++;

        if( false == check_coordinates(x_fig, y_fig) )
        {
            break;
        }
        if( true == check_if_king_on_coordinates(x_fig, y_fig, p_x_king_int , p_y_king_int) )
        {
            return true;
        }
    }

    return false;
}


bool Queen::check_if_figure_between(std::vector<Figure*>& p_figures_VECTOR, int p_x_king_int, int p_y_king_int, int p_x_other_king_int, int p_y_other_king_int)
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
                //std::cout << (*it)->get_x() << std::endl;
                continue;
            }
            else if((*it)->get_y() > y && (*it)->get_y() < p_y_king_int )
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
    else if( x < p_x_king_int && y > p_y_king_int )
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

bool Queen::can_step_on_coordinates(std::vector<Figure*>& p_figures, int x, int y)
{
    return is_threat_for_king(x, y);
}
