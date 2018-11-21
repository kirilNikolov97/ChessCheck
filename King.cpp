#include "King.h"
#include <stdlib.h>

// Constructors
King::King() : Figure(){};
King::King(int p_x_int, int p_y_int, bool p_team_int) : Figure(p_x_int, p_y_int, p_team_int) {}

// Destructor
King::~King(){};

bool King::can_step_on_coordinates(std::vector<Figure*>& p_figures, int p_x_int, int p_y_int)
{
    return is_threat_for_king(p_x_int, p_y_int);
}

bool King::is_threat_for_king(int p_dummy_x_int, int p_dummy_y_int)
{
    return false;
}

bool King::check_if_figure_between(std::vector<Figure*>& p_dummy, int p_dummy_one_int, int p_dummy_two_int, int p_dummy_three_int, int p_dummy_four_int)
{
    return false;
}

int King::is_check( std::vector<Figure*> &p_figures, std::vector<Figure*> &p_possible, King p_other_king)
{
    int l_cnt_check_int = 0;

    // Check how many figures are making check to the king
    for(std::vector<Figure*>::iterator it = p_possible.begin(); it != p_possible.end(); ++it)
    {
        if( false == (*it)->check_if_figure_between( p_figures, x, y, p_other_king.get_x(), p_other_king.get_y()) )
        {
            l_cnt_check_int++;
        }
    }

    if( 1 < l_cnt_check_int)
    {
        return 1;
    }
    else if( 1 == l_cnt_check_int )
    {
        // Only one check was made
        // so we must check if the attacking figure can be taken
        Figure* l_threat_to_king;
        std::vector<Figure*> l_possible_for_the_threat;

        // Find the attacking figure
        for(std::vector<Figure*>::iterator it = p_possible.begin(); it != p_possible.end(); ++it)
        {
            if( false == (*it)->check_if_figure_between( p_figures, x, y, p_other_king.get_x(), p_other_king.get_y()) )
            {
                l_threat_to_king = (*it);
                break;
            }
        }

        // Get the figures that might take the attacking figure
        for (std::vector<Figure*>::iterator it = p_figures.begin() ; it != p_figures.end(); ++it)
        {
            if( this->get_team() == (*it)->get_team() && (*it)->is_threat_for_king(l_threat_to_king->get_x(), l_threat_to_king->get_y()))
            {
                l_possible_for_the_threat.push_back((*it));
            }
        }

        // Check if some of the figures
        // can actually take the attacking figure
        l_cnt_check_int = 0;
        for(std::vector<Figure*>::iterator it = l_possible_for_the_threat.begin(); it != l_possible_for_the_threat.end(); ++it)
        {
            if( false == (*it)->check_if_figure_between( p_figures, l_threat_to_king->get_x(), l_threat_to_king->get_y(), p_other_king.get_x(), p_other_king.get_y()) )

            {
                l_cnt_check_int++;
            }
        }

        if( 0 < l_cnt_check_int)
        {
            // The attacking figure can be taken by a figure from the other team
            return 0;
        }

        if(true == if_can_block_the_check(p_figures, l_threat_to_king, p_other_king))
        {
            return 0;
        }
        // The attacking figure can NOT be taken by a figure from the other team
        return 1;

    }

    // The king is not in a position of a check
    return -1;
}


bool King::is_checkmate( std::vector<Figure*> &p_figures, King p_other_king)
{
    int l_cnt_int = 0;

    std::vector<Figure*> l_tmp_possible;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(0 == i && 0 == j)
            {
                // The current position of the king
                continue;
            }
            if(get_x() + i > 7 || get_x() + i < 0 || get_y() + j > 7 || get_y() + j < 0 )
            {
                // Steps outside of the table
                l_cnt_int++;
                continue;
            }
            set_x(get_x() + i);
            set_y(get_y() + j);
            fill_possible_vectors(p_figures, l_tmp_possible);
            if(
                ( -1 != is_check(p_figures, l_tmp_possible, p_other_king) )
               || (true == is_on_same_team_figure(p_figures))
               || (true == check_if_kings_coordinates_conflict(p_other_king))
               )
            {
                l_cnt_int++;
            }

            l_tmp_possible.clear();
            // Return to original coordinates
            set_x(get_x() - i);
            set_y(get_y() - j);
        }
    }

    if(8 == l_cnt_int)
    {
        // The King can not step on any of the surrounding fields
        return true;
    }

    return false;
}


void King::fill_possible_vectors(std::vector<Figure*> &figures, std::vector<Figure*> &p_possible)
{
    for (std::vector<Figure*>::iterator it = figures.begin() ; it != figures.end(); ++it)
    {
        if( get_team() != (*it)->get_team() && true == (*it)->is_threat_for_king(get_x(), get_y()))
        {
            p_possible.push_back((*it));
        }
    }
}

bool King::is_on_same_team_figure( std::vector<Figure*> &figures)
{
    for(std::vector<Figure*>::iterator it = figures.begin(); it != figures.end(); ++it)
    {
        if(get_x() == (*it)->get_x() && get_y() == (*it)->get_y() && get_team() == (*it)->get_team())
        {
            return true;
        }
    }
    return false;
}

bool King::check_if_kings_coordinates_conflict(King p_other_king)
{
    if(p_other_king.get_x() == -1)
    {
        // The second king is not initialized
        return false;
    }
    if( abs(get_x() - p_other_king.get_x()) > 1 || abs(get_y() - p_other_king.get_y()) > 1 )
    {
        return false;
    }
    return true;
}

bool King::if_can_block_the_check(std::vector<Figure*> &p_figures, Figure* p_threat_to_king, King p_other_king)
{
    std::vector<std::pair<int, int> > l_all_coordinates;

    // Fill all the coordinates between the King and the attacking figure
    if(x < p_threat_to_king->get_x() && y == p_threat_to_king->get_y())
    {
        for(int i = x; i < p_threat_to_king->get_x(); i++)
        {
            l_all_coordinates.push_back(std::make_pair(i, y));
        }
    }
    else if(x > p_threat_to_king->get_x() && y == p_threat_to_king->get_y())
    {
        for(int i = p_threat_to_king->get_x(); i < x; i++)
        {
            l_all_coordinates.push_back(std::make_pair(i, y));
        }
    }
    else if(y < p_threat_to_king->get_y() && x == p_threat_to_king->get_x())
    {
        for(int i = y; i < p_threat_to_king->get_y(); i++)
        {
            l_all_coordinates.push_back(std::make_pair(x, i));
        }
    }
    else if(y > p_threat_to_king->get_y() && x == p_threat_to_king->get_x())
    {
        for(int i = p_threat_to_king->get_y(); i < y; i++)
        {
            l_all_coordinates.push_back(std::make_pair(x, i));
        }
    }
    else if(y < p_threat_to_king->get_y() && x < p_threat_to_king->get_x())
    {
        for(int i = 0; i < p_threat_to_king->get_x() - x; i++)
        {
            l_all_coordinates.push_back(std::make_pair(p_threat_to_king->get_x() - i, p_threat_to_king->get_y() - i));
        }
    }
    else if(y < p_threat_to_king->get_y() && x > p_threat_to_king->get_x())
    {
        for(int i = 0; i < x - p_threat_to_king->get_x(); i++)
        {
            l_all_coordinates.push_back(std::make_pair(p_threat_to_king->get_x() + i, p_threat_to_king->get_y() - i));
        }
    }
    else if(y > p_threat_to_king->get_y() && x < p_threat_to_king->get_x())
    {
        for(int i = 0; i < p_threat_to_king->get_x() - x ; i++)
        {
            l_all_coordinates.push_back(std::make_pair(p_threat_to_king->get_x() - i, p_threat_to_king->get_y() + i));
        }
    }
    else if(y > p_threat_to_king->get_y() && x > p_threat_to_king->get_x())
    {
        for(int i = 0; i < x - p_threat_to_king->get_x(); i++)
        {
            l_all_coordinates.push_back(std::make_pair(p_threat_to_king->get_x() + i, p_threat_to_king->get_y() + i));
        }
    }

    for(std::vector<Figure*>::iterator it = p_figures.begin(); it != p_figures.end(); ++it)
    {
        if((*it)->get_team() == team)
        {
            for(int i = 0; i < (int) l_all_coordinates.size(); i++)
            {
                if(
                   true == (*it)->can_step_on_coordinates(p_figures ,l_all_coordinates.at(i).first, l_all_coordinates.at(i).second)
                   && false == (*it)->check_if_figure_between
                                                        (
                                                         p_figures, l_all_coordinates.at(i).first,
                                                         l_all_coordinates.at(i).second, p_other_king.get_x(),
                                                         p_other_king.get_y()
                                                         )
                   )
                {
                    return true;
                }
            }
        }
    }

    return false;
}
