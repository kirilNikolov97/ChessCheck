#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "Figure.h"

class King : public Figure {

public:
    // Constructors
	King();
	King(int p_x_int, int p_y_int, bool p_team_int);
	// Destructor
	~King();


	// Implemented virtual functions
	bool is_threat_for_king(int, int );
	bool check_if_figure_between(std::vector<Figure*>& , int , int , int , int );
	bool can_step_on_coordinates(std::vector<Figure*>& , int , int );


	//=================================================================================================================
    /// @fn       is_check
    ///
    /// @brief    checks if the king is in check from the figures in the "possible" vector
    ///
    /// @param    figures, possible_figures, king
    ///
    /// @return   int
    /// @details  returns:  -1 - The king is not in a check or checkmate
    ///                      0 - Check
    ///                      1 - Check with possibility of checkmate
    //=================================================================================================================
	int is_check( std::vector<Figure*> &, std::vector<Figure*> &, King );


    //=================================================================================================================
    /// @fn       is_checkmate
    ///
    /// @brief    Checks if the king is in checkmate
    ///
    /// @param    figures, other_king
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
	bool is_checkmate( std::vector<Figure*> &, King );

private:
    //=================================================================================================================
    /// @fn       fill_possible_vectors
    ///
    /// @brief    Iterate through the figures and if it is possible the figure to make check,
    ///             add the figure in a "possible" vector
    ///
    /// @param    figures, possible_figures
    ///
    /// @return   void
    /// @details
    //=================================================================================================================
    void fill_possible_vectors(std::vector<Figure*> &, std::vector<Figure*> &);


    //=================================================================================================================
    /// @fn       is_on_same_team_figure
    ///
    /// @brief
    ///
    /// @param    figures
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
    bool is_on_same_team_figure( std::vector<Figure*> &);

    //=================================================================================================================
    /// @fn       check_if_kings_coordinates_conflict
    ///
    /// @brief    Check if coordinates of the current and passed figure conflict
    ///
    /// @param    king
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
    bool check_if_kings_coordinates_conflict(King );



    //=================================================================================================================
    /// @fn       if_can_block_the_check
    ///
    /// @brief    Check if the checkmate can be prevented
    ///
    /// @param    figures, attacking_figure, king
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
    bool if_can_block_the_check(std::vector<Figure*> &, Figure* , King );

};






#endif // KING_H_INCLUDED
