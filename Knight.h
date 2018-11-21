#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include "Figure.h"

class Knight : public Figure
{
public:
    // Constructor
	Knight(int p_x_int, int p_y_int, bool p_team_int);
	// Destructor
	~Knight();


	// Implemented virtual functions
	bool is_threat_for_king(int , int );
	bool check_if_figure_between(std::vector<Figure*>& , int , int , int , int );
    bool can_step_on_coordinates(std::vector<Figure*>& , int , int );
};


#endif // KNIGHT_H_INCLUDED
