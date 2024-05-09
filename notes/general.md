#### Genral Notes on the design of the library 
- member functions alter the object, free standing functions return a new object instead. for example mat3x3::transpose, transposes the matrix, the matrix will be altered forever, meanwhile Transpose returns a new transposed matrix
- vectors and matrices are rows major and the coordinate system we use is a left handed coordinate !
