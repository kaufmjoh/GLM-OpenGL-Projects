/*#include <stdio.h>
#include <string>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"
*/


void
Forward( float th1, float th2, float th3,  float l1, float l2, glm::mat4& m1g, glm::mat4& m2g, glm::mat4& m3g )
{
    //m1g, m2g, and m3g come in as 4x4 identity matrices

    glm::mat4 I = glm::mat4(1);

    //convert from degrees to radians
    float th1_rad = glm::radians(th1);
    float th2_rad = glm::radians(th2);
    float th3_rad = glm::radians(th3);

    //Axis of rotation is the z-axis
    glm::vec3 rot = glm::vec3(0, 0, 1);

    //rotation matrix by rotation radians and axis of rotation
    glm::mat4 rt1 = glm::rotate(I, th1_rad, rot);
    glm::mat4 rt2 = glm::rotate(I, th2_rad, rot);
    glm::mat4 rt3 = glm::rotate(I, th3_rad, rot);

    //Vectorize the translation amount, just lengths in x-direction
    glm::vec3 l1_vec = glm::vec3(l1, 0, 0);
    glm::vec3 l2_vec = glm::vec3(l2, 0, 0);

    //Translation matrix
    glm::mat4 tr2 = glm::translate(I, l1_vec);
    glm::mat4 tr3 = glm::translate(I, l2_vec);

    //m1g is just a rotation
    m1g = rt1;

    //m2g is the first rotation, the length of 1, and another rotation
    m2g = m1g * tr2 * rt2;

    //m3g is the second matrix, the length of 2, and another rotation
    m3g = m2g * tr3 * rt3;


}

void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
    yourName = "John Kaufman";
    yourEmailAddress = "kaufmjoh@oregonstate.edu" ;
}

