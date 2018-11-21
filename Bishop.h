#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED

#include "Figure.h"

class Bishop : public Figure
{
public:
    // Constructor
	Bishop(int p_x_int, int p_y_int, bool p_team_int);
	// Destructor
	~Bishop();


	bool is_threat_for_king(int, int);

	bool check_if_figure_between(std::vector<Figure*>&, int, int, int, int);

	bool can_step_on_coordinates(std::vector<Figure*>&, int, int);

private:
    //=================================================================================================================
    /// @fn       check_coordinates
    ///
    /// @brief    Checks if the passed coordinates are inside the chess table
    ///
    /// @param    x_figure, y_figure
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
	bool check_coordinates(int, int);

	//=================================================================================================================
    /// @fn       check_if_king_on_coordinates
    ///
    /// @brief    Checks if king is on the passed coordinates
    ///
    /// @param    x_figure, y_figure, x_king, y_king
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
	bool check_if_king_on_coordinates(int, int, int, int );

};

#endif // BISHOP_H_INCLUDED
