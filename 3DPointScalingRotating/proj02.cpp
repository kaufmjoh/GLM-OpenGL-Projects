#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"

glm::mat4
Multiply( glm::mat4 a, glm::mat4 b )
{
	return a*b;
}



glm::vec3
Multiply( glm::mat4 a, glm::vec3 b )
{
    glm::vec4 c = glm::vec4(b, 1);
    glm::vec4 d = a*c;
    glm::vec3 e = glm::vec3(d);
    return e;
}



glm::vec3
ScalePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::vec3 scale )
{
    glm::vec3 relation = inputPoint - centerPoint;


    glm::vec3 result_point = relation * scale;
    return result_point+centerPoint;
}



glm::vec3
RotatePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::mat4 first, glm::mat4 second, glm::mat4 third )
{
    glm::vec3 relation = inputPoint - centerPoint;

    glm::vec4 temp = glm::vec4(relation, 1);

    glm::mat4 transformation = third*second*first;


    glm::vec4 result_point = transformation*temp;


    glm::vec3 result_cut = glm::vec3(result_point);

    return result_cut+centerPoint;
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "John Kaufman";
	yourEmailAddress = "kaufmjoh@oregonstate.edu" ;
}


void
PrintMatrix( glm::mat4 mat )
{
	for( int row = 0; row < 4; row++ )
	{
		fprintf( stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3] );
	}
}
