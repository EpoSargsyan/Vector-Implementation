# <h1> Vector Implementation <h1>

<hr>
  
Vectors in C++ are sequence containers representing arrays that can change their size during runtime. They use contiguous storage locations for their elements just as efficiently as in arrays, which means that their elements can also be accessed using offsets on regular pointers to its elements.
Vectors are the dynamic arrays that are used to store data.It is different from arrays which store sequential data and are static in nature, Vectors provide more flexibility to the program. Vectors can adjust their size automatically when an element is inserted or deleted from it.
Vectors are not ordered in C++. Vector elements are placed in adjacent storage and  can be easily accessed and traversed across using iterators. In vectors, data is inserted at the end when we use push_back() function . Inserting an element at the end of a vector takes differential time, as sometimes there may be a need of extending the vector,  but inserting the element at the beginning or at the middle takes linear time. Removing the last element takes only constant time because no resizing takes place.

<hr>
  
<hr>
  
<h2>The implemented vector functions</h2>
 
at () - Function gets the index of your Value and returns the Value. <br>
front () - Function returns the first element of Vector. <br>
back () - Function returns the last element of Vector. <br>
empty () - Function says is your Vector empty or not. <br>
size () - Function returns the size of the Vector. <br>
capacity () - Function return the capacity of the Vector. <br>
reserve () - Function gets a number and the cahanges the capacity size to entered number. <br>
shrink_to_fit () - Function changes the capacity size to original size. <br>
insert () - Function gets the index where you want to push your element and the element. <br>
push_back () - Function gets the value and pushes it into Vector. <br>
pop_back () - Function delete the last element of the Vector. <br>
erase () - Functio gets the index of element and delete it from Vector. <br>
resize () - Function changes the capacity size when size and capacity of Vector are equal. <br>
emplace () - Function extends the container by inserting a new element at the position. 
  
<hr> 
