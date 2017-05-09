//Jinhao Chen
#include "Maze.h"
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;


void Maze::print_dfsExitPath()
{
	stack<Position> path;
	Position current, nbr;
	// FILL IN MISSING CODE
	current = start;
	setState(current, VISITED);
	path.push(current);
	direction d = DOWN;
	while (! (current == exitpos)&& !(path.empty()) )
	{
		
		while (getState(current.Neighbor(DOWN)) == OPEN || getState(current.Neighbor(UP)) == OPEN || getState(current.Neighbor(LEFT)) == OPEN || getState(current.Neighbor(RIGHT)) == OPEN)
		{
			
			nbr = current.Neighbor(d);
		//	d = next_direction(d);

			while (getState(nbr) == OPEN)
			{


				current = nbr;
				setState(current, VISITED);
				path.push(current);
				nbr = current.Neighbor(d);

			}
		//	/*
			nbr = current.Neighbor(LEFT);
			while (getState(nbr) == OPEN)
			{
				
				current = nbr;
				setState(current, VISITED);

				path.push(current);
				nbr = current.Neighbor(LEFT);

			}
			nbr = current.Neighbor(UP);
			while (getState(nbr) == OPEN)
			{
			
				current = nbr;
				setState(current, VISITED);

				path.push(current);
				nbr = current.Neighbor(UP);

			}
			nbr = current.Neighbor(RIGHT);
			if (getState(nbr) == OPEN)
			{
				
				current = nbr;
				setState(current, VISITED);

				path.push(current);
				nbr = current.Neighbor(RIGHT);
			} 
		//	*/
		}

		path.pop();
		
		if (path.size() > 0)
           current = path.top();
	}

	if (path.empty())
	{
		cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\n";
	}
	else {
		cout << "Remy, here is a sequence of positions to escape the maze:\n";
		printBottomToTop(path);
	}

}

void Maze::printShortestPath()
{
	queue<Position> Q;
	Position current, nbr;
	// Allocate the two dimensional predecessor array
	// The predecessor of Position P is given by
	// predecessor[P.row][P.col]
	Position** predecessor = new Position *[size];
	for (int i = 0; i < size; ++i) {
		predecessor[i] = new Position[size];
		for (int j = 0; j < size; ++j)
			predecessor[i][j] = NULLPOS;
	}
	// FILL IN MISSING CODE
	setState(start, VISITED);
	Q.push(start);
	current = Q.front();
	while (!Q.empty()&& !(current == exitpos))
	{

			nbr = current.Neighbor(DOWN);

			if (getState(nbr) == OPEN)
			{

				setState(nbr, VISITED);
				Q.push(nbr);
				 predecessor[nbr.getRow()][nbr.getCol()] = current;

			}

			nbr = current.Neighbor(LEFT);
			if (getState(nbr) == OPEN)
			{

				setState(nbr, VISITED);

				Q.push(nbr);
				 predecessor[nbr.getRow()][nbr.getCol()] = current;

			}
			nbr = current.Neighbor(UP);
			if (getState(nbr) == OPEN)
			{

				setState(nbr, VISITED);

				Q.push(nbr);
				 predecessor[nbr.getRow()][nbr.getCol()] = current;

			}
			nbr = current.Neighbor(RIGHT);
			if (getState(nbr) == OPEN)
			{
				setState(nbr, VISITED);

				Q.push(nbr);
				predecessor[nbr.getRow()][nbr.getCol()] = current;
			}
			Q.pop();
			if (Q.size() > 0)
			current = Q.front();
	}


	
	if (Q.empty())
	{
		cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\n";
	}
	else {
		cout << "Remy, here is a sequence of positions to escape the maze:\n";
		printPredecessorPath(predecessor, exitpos);
	}

}

