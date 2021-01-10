# Space-Vectors

It is class of geometrical vectors, all operations thta are related to them can be easily operated with them
Functions:

1) Create Vector: <Vector a;> or <Vector a(float x,float y, float z);>
2) Set Vector's position: <void a.setPos(float x, float y, float z);>
3) Get Vector's position: <void s.getPos(float &x, float &y, float &z);>
4) Get Vector's length: <float getLength();>
5) Assign one vector to another vector: <a = b;>
6) Scalar production: <a * b;> OR <a* Number;>
7) Compare Vectors equation (a == b OR a != b)
8) Substraction and addition of vectors or numbers <a (+-)= b> or <a (+-) b>
9) Cross production of vectors: <Vector Vector::crossProd(Vector A, Vector B);>
10) Angle between 2 Vectors: <float Vector::vecAngle(Vector& _vec1, Vector& _vec2, <Degree> or <Radian>);>
11) Collinear of 2 vectors: <bool Vector::collinear(Vector& _vec1, Vector& _vec2); >
12) Complanar of 3 vectors: <bool Vector::coplanar(Vector& _vec1, Vector& _vec2, Vector& _vec3);>
