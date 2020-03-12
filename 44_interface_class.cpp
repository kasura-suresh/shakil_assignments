/*************************************************************
    C++ programe to implement interface class
    using virtual function
    author : MD SHAKIL ANSARI ,date : 7 mar , 2020
 *************************************************************/

#include <iostream>
 using namespace std;
class Shape {
	protected :
      int width;
      int height;
   public:
      // pure virtual function providing interface framework.
      virtual int getArea() = 0; // pure virtual function
      void setWidth(int w) {
         width = w;
      }
   
      void setHeight(int h) {
         height = h;
      }
   
   
};
 
// Derived classes
class Rectangle: public Shape {
   public:
      int getArea() // overriding virtual function
	   { 
      
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      int getArea() // overriding virtual function
	  { 
         return (width * height)/2; 
      }
};
 
int main(void) {
   Rectangle Rec;
   Triangle  Tri;
   Rec.setWidth(5);
   Rec.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Rectangle area: " << Rec.getArea() << endl;

   Tri.setWidth(5);
   Tri.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Triangle area: " << Tri.getArea() << endl; 

   return 0;
}
