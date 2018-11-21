#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include "Figure.h"

class Pawn : public Figure {

public:
    // Constructor
	Pawn(int p_x_int, int p_y_int, bool p_team_int);
	// Destructor
	~Pawn();

	// Implemented virtual functions
	bool is_threat_for_king(int p_x_king_int, int p_y_king_int);
	bool check_if_figure_between(std::vector<Figure*>& p_figures, int p_x_king_int, int p_y_king_int, int p_x_other_king_int, int p_y_other_king_int);
	bool can_step_on_coordinates(std::vector<Figure*>& p_figures, int p_x_int, int p_y_int);

};



#endif // PAWN_H_INCLUDED
