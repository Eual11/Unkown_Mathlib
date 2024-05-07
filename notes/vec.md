### Vectors 
- the vector structures are classifed into 3 catagories, vec2, vec3 and vec4, depending with the number of dimensions they represent 
- vec2 is 2d, vec3 is 3d and so on... 


#### Operation on vector structures 

###### subscripting 

```cpp 
vec3 a(1,2,3);
a[0] //valid access the first element, the x component
a[1]; //valid accesses the second, the y comoment

```

###### incrementing/decrementing by another vector 

```cpp 

vec2 a(1,2);
vec2 b(2,2);

b-=a; // b = (2-1, 2-2) 

b+=a; // b = (2-1, 2-2) 
```
###### compound multiplication and division by a scalar 
```cpp 

vec4 a(1,2,3,4);
a*=2; //a = (2,4,6,8)
a/=2; //a =(1,2,3,4)
```

###### vector negation 
```cpp

vec3 a(1,2,3);
vec3 b =-a; // b = (-1, -2, -3)
```
###### vector addition and subtraction 
```cpp 
vec3 a(1,1,1);
vec3 b(1,1,1);
vec3 c = a+b; //a+b returns a new vector c = (2,2,2)
c= a-b//same as above but substraction
```
###### magnitude and normalization 
```cpp 
vec3 a(1,2,3);
a.normalize(); //a is now normalized i.e the magnitude is 1 
a.magnitude(); //the vector magnitude of vector a
```

