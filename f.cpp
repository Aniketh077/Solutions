/*

f)
What is dot product and cross product? Explain use cases of where det product is used and.

cross product is used in graphics environment. Add links to places where you studied this

information and get back with the understanding Bonus-How do you calculate the intersection between a ray and a plane/sphere/triangle?

*/


/*  

Dot product of two vectors is a scalar value that represents the cosine of the angle between the two vectors multiplied by their magnitudes. 
It is calculated by multiplying the corresponding components of the two vectors and adding them up. The formula for the dot product of two vectors a and b is:
a ⋅ b = a₁b₁ + a₂b₂ + a₃b₃
Cross product of two vectors is a vector that is perpendicular to both vectors and its direction follows the right-hand rule. It is calculated by taking 
the determinant of a 3x3 matrix that is formed by the unit vectors i, j, and k, and the components of the two vectors. 
The formula for the cross product of two vectors a and b is: a x b = (a₂b₃ - a₃b₂)i - (a₁b₃ - a₃b₁)j + (a₁b₂ - a₂b₁)k
dot product and cross product are mathematical operations that are commonly used to perform a variety of tasks, 
such as 3D transformations, lighting computations, and collision detection.
Links I have used:
https://www.haroldserrano.com/blog/vectors-in-computer-graphics
https://www.gatevidyalay.com/3d-translation-in-computer-graphics-definition-examples/#:~:text=3D%20Transformation%20in%20Computer%20Graphics%2D&text=Transformation%20is%20a%20process%20of,more%20complex%20than%202D%20Transformations.
Ray-sphere intersection:
Given a ray with an origin point P and a direction vector D, and a sphere with center C and radius r, you can calculate the intersection point(s) between the ray and the sphere using the following formula:
t = -D · (P - C) ± sqrt [(D · (P - C))^2 - ||P - C||^2 + r^2]
where "·" denotes the dot product, "|| ||" denotes the magnitude of a vector, and "±" indicates that there may be two intersection points (if the discriminant under the square root is positive) or no intersection points 
(if the discriminant is negative). The parameter "t" represents the distance from the origin point P to the intersection point(s).
Ray-plane intersection:
Given a ray with an origin point P and a direction vector D, and a plane with a normal vector N and a point on the plane Q, you can calculate the intersection point between the ray and the plane using the following formula:
t = (Q - P) · N / (D · N)
where "·" denotes the dot product, and "t" represents the distance from the origin point P to the intersection point. If the denominator (D · N) is zero, it means the ray is parallel to the plane and there is no intersection.
Ray-rectangle intersection:
Given a ray with an origin point P and a direction vector D, and a rectangle with corners (x0, y0, z0) and (x1, y1, z1), you can calculate the intersection point between the ray and the rectangle using the following algorithm:
Compute the plane that the rectangle lies in, using any three of the four corners.
Calculate the intersection point between the ray and the plane, as described in step 2.
Check if the intersection point lies within the rectangle, by comparing its coordinates to the coordinates of the rectangle's corners. If the intersection point lies within the rectangle, it is a valid intersection point.


*/