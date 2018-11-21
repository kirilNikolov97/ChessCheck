#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include "Figure.h"

class Queen : public Figure {

private:
	bool check_coordinates(int p_x_int, int p_y_int);
	bool check_if_king_on_coordinates(int p_x_fig_int, int p_y_fig_int, int p_x_king_int, int p_y_king_int);

public:
    // Constructor
	Queen(int p_x_int, int p_y_int, bool p_team_int);
	// Destructor
	~Queen();

	// Implemented virtual functions
	bool is_threat_for_king(int p_x_king_int, int p_y_king_int);
	bool check_if_figure_between(std::vector<Figure*>& p_figures_VECTOR, int p_x_king_int, int p_y_king_int, int p_x_other_king_int, int p_y_other_king_int);
	bool can_step_on_coordinates(std::vector<Figure*>& p_figures, int x, int y);
};


#endif // QUEEN_H_INCLUDED
