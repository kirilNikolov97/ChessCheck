#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <vector>
#include "basedef.h"

class Figure
{
protected:
	bool team;  // true - white figure
                // false - black figure
	int x;
	int y;

public:
    // Constructors
	Figure();
	Figure(int, int, bool);

	// Destructor
	virtual ~Figure(){};

	// Setters
	void set_x(int);
    void set_y(int);
    void set_team(bool);

    // Getters
	int get_x();
	int get_y();
	bool get_team();

    //=================================================================================================================
    /// @fn       is_threat_for_king
    ///
    /// @brief    Checks if the current figure is a threat for the passed king
    ///
    /// @param    x_king, y_king
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
	virtual bool is_threat_for_king(int, int) = 0;


    //=================================================================================================================
    /// @fn       can_step_on_coordinates
    ///
    /// @brief
    ///
    /// @param    all_figures, x_figure, y_figure
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
	virtual bool can_step_on_coordinates(std::vector<Figure*>&, int, int) = 0;


    //=================================================================================================================
    /// @fn       check_if_figure_between
    ///
    /// @brief    Checks if there is a figure between the current figure and the passed king
    ///
    /// @param    all_figures, x_king, y_king, x_other_king, y_other_king
    ///
    /// @return   bool
    /// @details
    //=================================================================================================================
	virtual bool check_if_figure_between(std::vector<Figure*>&, int, int, int, int) = 0;
};

#endif // FIGURE_H_INCLUDED
