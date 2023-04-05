#include <iostream>
#include <cmath>
using namespace std;

class Point {
	int X_Coordinate, Y_Coordinate;

	public:
		Point() {
			this->X_Coordinate = 0;
			this->Y_Coordinate = 0;
		}

		Point(int x, int y) {
			this->X_Coordinate = x;
			this->Y_Coordinate = y;
		}

		Point(Point& p) {
			this->X_Coordinate = p.X_Coordinate;
			this->Y_Coordinate = p.Y_Coordinate;
		}

		Point(const Point& p) {
			this->X_Coordinate = p.X_Coordinate;
			this->Y_Coordinate = p.Y_Coordinate;
		}

		int getCoordinate_X() {
			return X_Coordinate;
		}

		int getCoordinate_y() {
			return X_Coordinate;
		}

        void setCoordinate_x(int x) {
            this->X_Coordinate = x;
        }

        void setCoordinate_y(int y) {
            this->Y_Coordinate = y;
        }
};

class Line {
	Point Point_1;
	Point Point_2;

public:
	Line() : Point_1(4, 6), Point_2(2, 4) {
	}

	Line(int x1, int y1, int x2, int y2): Point_1(x1, y1), Point_2(x2, y2) {
    }

    Line(const Point p1, const Point p2): Point_1(p1), Point_2(p2) {

    }

    float findSlope() {
        return (Point_2.getCoordinate_y() - Point_1.getCoordinate_y()) / (Point_2.getCoordinate_X() - Point_1.getCoordinate_X());
    }

    float findLength() {
        return static_cast<float>(sqrt(pow(Point_2.getCoordinate_X() - Point_1.getCoordinate_X(), 2) + pow(Point_2.getCoordinate_y() - Point_1.getCoordinate_y(), 2)));
    }

    Point findMidPoint() {
        Point tempPoint;
        tempPoint.setCoordinate_x(static_cast<float>((Point_1.getCoordinate_X() + Point_2.getCoordinate_y()) / 2));
		tempPoint.setCoordinate_y(static_cast<float>((Point_1.getCoordinate_y() + Point_2.getCoordinate_y()) / 2));
		return tempPoint;
    }
};

int main() {

	Point p1(2, 4);
	Point p2(4, 6);

	Line l1(p1, p2);
	cout << "Slope: " << l1.findSlope() << endl;
	cout << "Length: " << l1.findLength() << endl;
	Point p3 = l1.findMidPoint();
	cout << "Midpoint: (" << p3.getCoordinate_X() << ", " << p3.getCoordinate_y() << ")" << endl;

	return 0;
}