#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>


#define _USE_MATH_DEFINES
#include <math.h>


// flags to indicate which surface was hit:
// (these are #define'd so that they can be used in a switch statement)

#define NOTHING_HIT     -1
#define HIT_LEFT         0
#define HIT_RIGHT        1
#define HIT_FLOOR1       2
#define HIT_FLOOR2       3

// a tolerance to allow for floating-point roundoff problems:


const float TOL = { 0.1f };

extern float   CoefRest;
extern float   Gravity;
extern float   Vxnow, Vynow;
extern float   Xnow, Ynow;

// the ball radius:

const float RADIUS  = { 0.50f };

// where the walls are:

const float XLEFT   = { -5.f };
const float XRIGHT  = {  5.f };
const float YBOTTOM = { -3.f };

// flags to indicate which surface was hit:
// (these are #define'd so that they can be used in a switch statement)


// a tolerance to allow for floating-point roundoff problems:

const float EPSILON = { 0.001f };

#include <iostream>


// ********** FROM THE START TO HERE WILL BE PROVIDED IN THE GRADING SCRIPT **********

// ********** ONLY TURN IN FROM HERE DOWN, Bounce( ) PLUS WhoAmI() **********

void
Bounce( float dt )
{
	while( dt > EPSILON )
	{
		float tmin = dt;	// minimum time to do something
		int which = NOTHING_HIT; // which reason was it for doing the something

		// these four collision times are computed using your projectile motion equations:



		float tleft; //= ????;	// time to hit the left wall

        tleft = ((XLEFT - Xnow) + RADIUS)/Vxnow;

        if( tleft > EPSILON  &&  tleft < tmin )
		{
			tmin = tleft;
			which = HIT_LEFT;
		}
		float tright ;//= ????;	// time to hit the right wall

        tright = ((XRIGHT - Xnow) - RADIUS)/Vxnow;

        if( tright > EPSILON  &&  tright < tmin )
		{
		    tmin = tright;
            which = HIT_RIGHT;
		}

		// the y collision with the floor involves a quadratic equation
		// thus, there are 2 times to collision, tfloor1 and tfloor2:

        float a = 0.5*Gravity;
        float b = Vynow;
        float c = (Ynow - YBOTTOM)-RADIUS;

        float solution_1 = (-1*b + pow(pow(b, 2)-4*a*c, 0.5))/(2*a);
        float solution_2 = (-1*b - pow(pow(b, 2)-4*a*c, 0.5))/(2*a);


		float tfloor1 ;//= ????;	// time to hit the floor

        if(solution_1 < solution_2){tfloor1 = solution_1;}
        else {tfloor1 = solution_2;}

        if( tfloor1 > EPSILON  &&  tfloor1 < tmin )
		{
		tmin = tfloor1;
        which = HIT_FLOOR1;
		}
		float tfloor2;// = ????;	// time to hit the floor (note there are 2 answers)
        if(solution_1 < solution_2){tfloor2 = solution_2;}
        else {tfloor2 = solution_1;}

		if( tfloor2 > EPSILON  &&  tfloor2 < tmin )
		{
		tmin = tfloor2;
        which = HIT_FLOOR2;

		}

		// 'tmin' is now set to the smallest of:
		//	dt, tleft, tright, tfloor1, tfloor2

		// 'which' is set to:
		//	NOTHING_HIT, HIT_LEFT, HIT_RIGHT, HIT_FLOOR1, or HIT_FLOOR2
		// to show what was the first thing hit

		// take a time step of time length tmin, using the projectile motion equations:
		// if a bounce is going to occur, tmin takes the ball right up next to the surface:
		// BE SURE TO USE tmin HERE, NOT dt:

		Xnow  = Xnow + Vxnow*tmin;
                Vxnow = Vxnow;
                Ynow  = Ynow + Vynow*tmin + 0.5*Gravity*tmin*tmin;
                Vynow = Vynow + Gravity*tmin;

		// a "bounce trick":

		if( Ynow < YBOTTOM+RADIUS )
			Ynow = YBOTTOM+RADIUS;		// floating point roundoff sometimes messes up

		if( Xnow < XLEFT+RADIUS )
			Xnow = XLEFT+RADIUS;

		if( Xnow > XRIGHT-RADIUS )
			Xnow = XRIGHT-RADIUS;


		// depending on what caused the bounce, change the proper velocity component:
		// if nothing was hit in this time step, just return:

		switch( which )
		{
			case NOTHING_HIT:
				return;

			case HIT_LEFT:
			    Vxnow = Vxnow*-1*CoefRest;
				break;

			case HIT_RIGHT:
			    Vxnow = Vxnow*-1*CoefRest;
				break;

			case HIT_FLOOR1:
			    Vynow = Vynow*-1*CoefRest;
				break;

			case HIT_FLOOR2:
			    Vynow = Vynow*-1*CoefRest;
				break;
		}

		dt -= tmin;	// after the bounce, we might still have some time step left
	}
}

void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
        yourName = "John Kaufman";
        yourEmailAddress = "kaufmjoh@oregonstate.edu" ;
}
