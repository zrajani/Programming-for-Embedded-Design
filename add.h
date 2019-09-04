/*
 * add.h
 *
 *  Created on: 05-Jun-2019
 *      Author: Zain Rajani
 */

#ifndef ADD_H_
#define ADD_H_



class add1    // Class Creation
{
public:
	int add(int x, int y)  // Class function of type public
	{
		/* This function checks the value of x and y and depending
		 * upon the conditions satisfied it either
		 * adds or subtracts the two numbers*/
		if (x>y)
			{
			return x + y;
			}
		else
		{
			return x-y;
		}
	}
};

class Point  // Parametrised Constructor Class
{
private:
    int x, y;

public:
    // Parameterized Constructor
    Point(int x1, int y1)
    {
    	// Assigning Values
        x = x1;
        y = y1;
    }

    int getX()
    {
    	// Return the value of x in the function
        return x;
    }
    int getY()
    {
    	// Return the value of y in the function
        return y;
    }
};

#endif /* ADD_H_ */
