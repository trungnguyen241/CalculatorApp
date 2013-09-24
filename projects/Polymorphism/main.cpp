// pointers to base class
#include <iostream>
using namespace std;

class CPolygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
		{ width=a; height=b; }

	int area ()
      { return (0); }
  };

class CRectangle: public CPolygon {
  public:
    int area ()
      { return (width * height); }
  };

class CTriangle: public CPolygon {
  public:
    int area ()
      { return (width * height / 2); }
  };

int main () {
	CPolygon poly;
	CRectangle rect;
	CTriangle trgl;

	poly.set_values (4,5);
	rect.set_values (4,5);
	trgl.set_values (4,5);

	cout << poly.area() << endl;
	cout << rect.area() << endl;
	cout << trgl.area() << endl;
	return 0;
}