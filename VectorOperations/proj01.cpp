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



glm::vec3
WhatPartOfALivesInBDir( glm::vec3 a, glm::vec3 b )
{
    glm::vec3 normal_b = normalize(b);

    float a_dot_b = glm::dot(a,normal_b);

	return a_dot_b*normal_b;
}


glm::vec3
WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{

    glm::vec3 normal_b = glm::normalize(b);

    float a_dot_b = glm::dot(a,normal_b);

	return a-(a_dot_b*normal_b);


}


glm::vec3
UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{

    return glm::normalize(glm::cross(r-q, s-q));

}


float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
    glm::vec3 my_cross = glm::cross(r-q, s-q);
    return 0.5*glm::length(my_cross);
}


bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{

    glm::vec3 n = glm::cross((r-q), (s-q));
    glm::vec3 nq = glm::cross((r-q), (p-q));
    glm::vec3 nr = glm::cross((s-r), (p-r));
    glm::vec3 ns = glm::cross((q-s), (p-s));


    float n_nq = glm::dot(n, nq);
    float n_nr = glm::dot(n, nr);
    float n_ns = glm::dot(n, ns);

    if(n_nq > 0 && n_nr > 0 && n_ns > 0)
        {return true;}
    else
        {return false;}

}



float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{

    glm::vec3 norm = glm::normalize(glm::cross(r-q, s-q));
    return glm::dot(p-q, norm);
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "John Kaufman";
	yourEmailAddress = "kaufmjoh@oregonstate.edu" ;
}

