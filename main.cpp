#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Figure.h"
#include "Pawn.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"

void my_pause()
{
    int x;
    std::cin >> x;
}

//=================================================================================================================
/// @fn       check_if_kings_coordinates_conflict
///
/// @brief    Checks if the two kings have more than one step between them
///
/// @param    black_king, white_king
///
/// @return   bool
/// @details
//=================================================================================================================
bool check_if_kings_coordinates_conflict(King p_white_king, King p_black_king)
{
    // Check if some of the kings are not initialized
    if(p_white_king.get_x() == -1 || p_black_king.get_x() == -1)
    {
        return false;
    }
    // Checks if the two kings have more than one step between them
    if(abs(p_white_king.get_x() - p_black_king.get_x()) > 1 || abs(p_white_king.get_y() - p_black_king.get_y()) > 1)
    {
        return false;
    }
    return true;
}


//=================================================================================================================
/// @fn       read_file
///
/// @brief    Read from file and create the object figures
///
/// @param    figures, black_king, white_king, path
///
/// @return   void
/// @details
//=================================================================================================================
void read_file(std::vector<Figure*> &p_figures, King& p_black_king, King& p_white_king, char* p_path_CHAR)
{
	CHAR* l_path_CHAR = p_path_CHAR;

	// Read from the file and add every figure in the vector
	std::ifstream l_ifs ( l_path_CHAR );
	if(l_ifs.is_open())
	{
		int l_curr_x_int = -1;
		int l_curr_y_int = 0;

		// Flags to check if kings are initialized
		bool l_flag_if_init_black_king = false;
		bool l_flag_if_init_white_king = false;

		CHAR l_curr_CHAR = l_ifs.get();
		while (l_ifs.good()) {
			// Calculate the x and y of the figure
			if((l_curr_CHAR >= 'a' && l_curr_CHAR <= 'z')
					|| (l_curr_CHAR >= 'A' && l_curr_CHAR <= 'Z')
					|| (l_curr_CHAR == ' '))
			{
				l_curr_x_int++;
			}
			else if(l_curr_CHAR == '\n')
			{
				l_curr_y_int++;
				l_curr_x_int = -1;
			}

			// Create figure objects
			if( 'P' == l_curr_CHAR )
			{
			    // Check if WHITE Pawn is on correct coordinates
			    if(l_curr_y_int == 7)
                {
                    std::cout << "Wrong position of the WHITE pawn" << std::endl;
                    my_pause();
                    return;
                }
				Figure* p = new Pawn( l_curr_x_int, l_curr_y_int, true );
				p_figures.push_back(p);
			}
			else if( 'p' == l_curr_CHAR )
			{
			    // Check if BLACK Pawn is on correct coordinates
			    if(l_curr_y_int == 0)
                {
                    std::cout << "Wrong position of the BLACK pawn" << std::endl;
                    my_pause();
                    return;
                }
				Figure* p = new Pawn( l_curr_x_int, l_curr_y_int, false );
				p_figures.push_back(p);
			}
			else if( 'Q' == l_curr_CHAR )
			{
				Figure* q = new Queen( l_curr_x_int, l_curr_y_int, true);
				p_figures.push_back(q);
			}
			else if( 'q' == l_curr_CHAR )
			{
				Figure* q = new Queen( l_curr_x_int, l_curr_y_int, false);
				p_figures.push_back(q);
			}
			else if( 'N' == l_curr_CHAR )
			{
				Figure* q = new Knight( l_curr_x_int, l_curr_y_int, true);
				p_figures.push_back(q);
			}
			else if( 'n' == l_curr_CHAR )
			{
				Figure* q = new Knight( l_curr_x_int, l_curr_y_int, false);
				p_figures.push_back(q);
			}
			else if( 'R' == l_curr_CHAR )
			{
				Figure* q = new Rook( l_curr_x_int, l_curr_y_int, true);
				p_figures.push_back(q);
			}
			else if( 'r' == l_curr_CHAR )
			{
				Figure* q = new Rook( l_curr_x_int, l_curr_y_int, false);
				p_figures.push_back(q);
			}
			else if( 'B' == l_curr_CHAR )
			{
				Figure* q = new Bishop( l_curr_x_int, l_curr_y_int, true);
				p_figures.push_back(q);
			}
			else if( 'b' == l_curr_CHAR )
			{
				Figure* q = new Bishop( l_curr_x_int, l_curr_y_int, false);
				p_figures.push_back(q);
			}
			else if( 'K' == l_curr_CHAR )
			{
                if(true == l_flag_if_init_white_king)
                {
                    std::cout << "No more than 1 WHITE king" << std::endl;
                    my_pause();
                    return;
                }
                l_flag_if_init_white_king = true;
				p_white_king = King(l_curr_x_int, l_curr_y_int, true);
			}
			else if( 'k' == l_curr_CHAR )
			{
			    if(true == l_flag_if_init_black_king)
                {
                    std::cout << "No more than 1 BLACK king" << std::endl;
                    my_pause();
                    return;
                }
                l_flag_if_init_black_king = true;
				p_black_king = King(l_curr_x_int, l_curr_y_int, false);
			}

			// Get the next figure
			l_curr_CHAR = l_ifs.get();
		}
	}
	l_ifs.close();

	if( true == check_if_kings_coordinates_conflict(p_white_king, p_black_king) )
    {
        std::cout << "Incorrect positions of the kings!" << std::endl;
        my_pause();
        return;
    }
}

//=================================================================================================================
/// @fn       fill_possible_vectors
///
/// @brief    Iterate through the figures and if it is possible the figure to make check,
///             add the figure in a "possible" vector
///
/// @param    figures, white_possible, black_possible, black_king, white_king
///
/// @return   void
/// @details
//=================================================================================================================
void fill_possible_vectors(std::vector<Figure*> &p_figures, std::vector<Figure*> &p_white_possible, std::vector<Figure*> &p_black_possible, King& p_black_king, King& p_white_king)
{

	for (std::vector<Figure*>::iterator it = p_figures.begin() ; it != p_figures.end(); ++it)
	{
		// check if it is possible the WHITE figure to check the BLACK king
		if( true == (*it)->get_team() && true ==  (*it)->is_threat_for_king(p_black_king.get_x(), p_black_king.get_y()))
		{
			p_white_possible.push_back((*it));
		}
		// check if it is possible the BLACK figure to check the WHITE king
		else if( false == (*it)->get_team() && (*it)->is_threat_for_king(p_white_king.get_x(), p_white_king.get_y()))
		{
			p_black_possible.push_back((*it));
		}
	}
}

//=================================================================================================================
/// @fn       is_initialized
///
/// @brief    Checks if the passed king is initialized
///
/// @param    king
///
/// @return   bool
/// @details
//=================================================================================================================
bool is_initialized(King p_king)
{
    if( -1 != p_king.get_x() && -1 != p_king.get_y())
    {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {

	std::vector<Figure*> l_figures;           // contains all figures on the table
	std::vector<Figure*> l_white_possible;    // contains all the figures that are possible to be a threat to the BLACK king
	std::vector<Figure*> l_black_possible;    // contains all the figures that are possible to be a threat to the WHITE king

	CHAR* l_path_CHAR = (CHAR*) "docs/table.txt";

	King l_black_king;
	King l_white_king;

	int l_result_check_black_king;
	int l_result_check_white_king;

	// Read from file and push_back all figures in the vector "l_figures"
	if( 1 == argc)
    {
        read_file( l_figures, l_black_king, l_white_king, l_path_CHAR );
    }
    else
    {
        read_file( l_figures, l_black_king, l_white_king, argv[1]);
    }

    // Check if the two kings are initialized
    if( false == is_initialized(l_black_king) || false == is_initialized(l_white_king))
    {
        std::cout << "One or the two kings are missing!" << std::endl;
        my_pause();
        return EXIT_SUCCESS;
    }

	fill_possible_vectors(l_figures, l_white_possible, l_black_possible, l_black_king, l_white_king);

    l_result_check_black_king = l_black_king.is_check(l_figures, l_white_possible, l_white_king);
    l_result_check_white_king = l_white_king.is_check(l_figures, l_black_possible, l_black_king);

	if( 1 == l_result_check_black_king )
    {
        // The check is made with more than 1 figure
        std::cout << "BLACK king is in check";
        if( true == l_black_king.is_checkmate(l_figures, l_white_king) )
        {
            std::cout << "mate";
        }
        std::cout << std::endl;
    }
    else if( 0 == l_result_check_black_king )
    {
        std::cout << "BLACK king is in check" << std::endl;
    }

    if( 1 == l_result_check_white_king )
    {
        std::cout << "WHITE king is in check";
        if( true == l_white_king.is_checkmate(l_figures, l_black_king))
        {
            std::cout << "mate";
        }
        std::cout << std::endl;
        my_pause();
        return EXIT_SUCCESS;
    }
    else if( -1 == l_result_check_white_king )
    {
        my_pause();
        return EXIT_SUCCESS;
    }
    else if( 0 == l_result_check_white_king )
    {
        std::cout << "WHITE king is in check" << std::endl;
        my_pause();
        return EXIT_SUCCESS;
    }

    my_pause();
	return EXIT_SUCCESS;
}
