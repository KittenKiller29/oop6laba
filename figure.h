#pragma once
#include"container.h"
#include<math.h>
#include<gcroot.h>
#include<windows.h>
ref class Dec {
public:
	System::Drawing::Point point1 = System::Drawing::Point(0, 0);
	System::Drawing::Point point2 = System::Drawing::Point(0, 0);
	System::Drawing::Point point3 = System::Drawing::Point(0, 0);
	System::Drawing::Pen^ pp = gcnew System::Drawing::Pen(System::Drawing::Brushes::Black, 1.0f);
	System::Drawing::Pen^ checkpen = gcnew System::Drawing::Pen(System::Drawing::Brushes::Black, 1.0f);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
	cli::array<System::Drawing::Point>^ points = gcnew cli::array<System::Drawing::Point>(3);
	cli::array<float>^ dash = gcnew cli::array<float>(2);
	Dec() {
		points[0] = point1;
		points[1] = point2;
		points[2] = point3;
		dash[0] = 2;
		dash[1] = 2;
		checkpen->DashPattern = dash;
	}
};
class FigureInterface {
public:
	std::string color="Empty";
	msclr::gcroot<Dec^> point = gcnew Dec;
	float pointx, pointy,h,w,rad;
	bool checked = true;
	void setColor(std::string color) {
		this->color = color;
	}
	virtual void changePos(float x,float y) {
		pointx += x;
		pointy += y;
	}
	virtual bool checkPos(System::Windows::Forms::MouseEventArgs^ e) {
		return false;
	}
	virtual void drawFigure(System::Windows::Forms::PaintEventArgs^ e) {
	}
	void setCheck(bool check) {
		checked = check;
	}
	virtual void drawChecked(System::Windows::Forms::PaintEventArgs^ e) {
		if (checked) {
			e->Graphics->DrawRectangle(point->checkpen, (pointx - w / 2 - 8),(pointy - h / 2 - 8),( w+16),( h+16));
		}
	}
	virtual bool checkBorder(int bordx, int bordy, float x, float y) {
		if (pointx + w / 2 + x > bordx-16 || pointx - w / 2 + x < 1 || pointy - h / 2 + y<1 || pointy + h / 2 + y>bordy-41)
			return false;
		return true;
	}
	virtual void changeSize(float a) {
		if (checked) { h += a; w += a; }
	}
	virtual void changeSizeCorrect(float a,float bordx,float bordy) {
		if (pointx + w / 2 + a > bordx - 16)
			changePos(-2, 0);
		if (pointx - w / 2 + a < 3)
			changePos(2, 0);
		if (pointy - h / 2 + a < 3)
			changePos(0, 2);
		if (pointy + h / 2 + a > bordy - 41)
			changePos(0, -2);
	}
	virtual int isSize() {
		if (h > 86)
			return 1;
		if (h < 30)
			return 2;
	}
};
class Rectang : public FigureInterface {
public:
	int forchecker = 0;
	Rectang(float x, float y, float h, float w) {
		this->h = h;
		this->w = w;
		pointx = x;
		pointy = y;;
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		if (color == "Red")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Red, pointx - w / 2, pointy - h / 2, w, h);
		if (color == "Blue")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Blue, pointx - w / 2, pointy - h / 2, w, h);
		if (color == "Green")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Green, pointx - w / 2, pointy - h / 2, w, h);
		e->Graphics->DrawRectangle(System::Drawing::Pens::Black, pointx - w / 2, pointy - h / 2, w, h);
		if (checked)
			e->Graphics->DrawRectangle(System::Drawing::Pens::Purple, pointx - w / 2, pointy - h / 2, w, h);
	}
	bool checkPos(System::Windows::Forms::MouseEventArgs^ e) override {
		if (e->X >= pointx - w / 2 && e->X <= pointx - w / 2 + w && e->Y >= pointy - h / 2 && e->Y <= pointy - h / 2 + h)
			return true;
		return false;
	}
	void createChecker(System::Windows::Forms::MouseEventArgs^ e) {
		checked = false;
		switch (forchecker) {
		case 0:
			pointx = e->X;
			pointy = e->Y;
			forchecker++;
			break;
		case 1:
			w = e->X - pointx;
			h = e->Y - pointy;
			forchecker++;
			break;
		case 2:
			deleteChecker();
			break;
		}
	}
	void deleteChecker() {
		pointx = -100;
		pointy = -100;
		w = 0;
		h = 0;
		forchecker = 0;
	}
	void drawChecker(System::Windows::Forms::PaintEventArgs^ e) {
		e->Graphics->DrawRectangle(System::Drawing::Pens::Black, pointx , pointy , w, h);
	}
	bool isIn(float x, float y) {
		if (pointx <= x && pointx + w >= x && pointy <= y && pointy + h >= y)
			return true;
		return false;
	}
	void changePosChecker(float x,float y) {
		if (forchecker == 2) {
			changePos(x, y);
		}
	}
};
class Triang : public FigureInterface {
public:
	Triang(float x, float y) {
		pointx = x;
		pointy = y;
		h = 30;
		w = 30;
		point->points[0].X = pointx - w;
		point->points[0].Y = pointy + (h);
		point->points[1].X = pointx;
		point->points[1].Y = pointy - (h);
		point->points[2].X = pointx + w;
		point->points[2].Y = pointy + (h);
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		if (color == "Red") {
			point->brush->Color = System::Drawing::Color::Red;
			e->Graphics->FillPolygon(point->brush,point->points);
		}
		if (color == "Green") {
			point->brush->Color = System::Drawing::Color::Green;
			e->Graphics->FillPolygon(point->brush, point->points);
		}
		if (color == "Blue") {
			point->brush->Color = System::Drawing::Color::Blue;
			e->Graphics->FillPolygon(point->brush, point->points);
		}
		point->pp->Color = System::Drawing::Color::Black;
		if (checked)
			point->pp->Color = System::Drawing::Color::Purple;
		e->Graphics->DrawPolygon(point->pp, point->points);
	}
	void changePos(float x, float y) override {
		point->points[0].X += x;
		point->points[0].Y += y;
		point->points[1].X += x;
		point->points[1].Y += y;
		point->points[2].X += x;
		point->points[2].Y += y;
		pointx += x;
		pointy += y;
	}

	float area(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	}
	bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
	{
		/* Calculate area of triangle ABC */
		float A = area(x1, y1, x2, y2, x3, y3);

		/* Calculate area of triangle PBC */
		float A1 = area(x, y, x2, y2, x3, y3);

		/* Calculate area of triangle PAC */
		float A2 = area(x1, y1, x, y, x3, y3);

		/* Calculate area of triangle PAB */
		float A3 = area(x1, y1, x2, y2, x, y);

		/* Check if sum of A1, A2 and A3 is same as A */
		return (A == A1 + A2 + A3);
	}
	bool checkPos(System::Windows::Forms::MouseEventArgs^ e) override {
		if (isInside(pointx-w,pointy+(h),pointx,pointy-(h),pointx+w,pointy+(h),e->X,e->Y))
			return true;
		return false;
	}
	void drawChecked(System::Windows::Forms::PaintEventArgs^ e) override {
		if (checked) {
			e->Graphics->DrawRectangle(point->checkpen, (pointx - w / 2 - 20), (pointy - h / 2 - 20), (w + 40), (h + 40));
		}
	}
	bool checkBorder(int bordx, int bordy, float x, float y) override {
		if (point->points[0].X+x<1 || point->points[2].X+x>bordx-16|| point->points[0].Y+y>bordy-41 || point->points[1].Y+y<1)
			return false;
		return true;
	}
	void changeSize(float a) override {
		if (checked) {
			h += 2*a;
			w += 2*a;
			point->points[0].X -= a;
			point->points[0].Y += a;
			point->points[1].Y -= a;
			point->points[2].X += a;
			point->points[2].Y += a;
		}
	}
	int isSize() override {
		if (h > 60)
			return 1;
		if (h < 10)
			return 2;
	}
	void changeSizeCorrect(float a, float bordx, float bordy) override {
		if (point->points[2].X + a > bordx - 16)
			changePos(-2, 0);
		if (point->points[0].X + a < 3)
			changePos(2, 0);
		if (point->points[1].Y + a < 3)
			changePos(0, 2);
		if (point->points[0].Y + a > bordy - 41)
			changePos(0, -2);
	}

};
class Circle : public FigureInterface {
public:

	Circle() {

	}
	Circle(float x, float y,float radp) {
		pointx = x;
		pointy = y;
		rad = radp;
		h = 2*radp;
		w = 2*radp;
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		if (color == "Red")
			e->Graphics->FillEllipse(System::Drawing::Brushes::Red, pointx - rad, pointy - rad, rad * 2, rad * 2);
		if (color == "Green")
			e->Graphics->FillEllipse(System::Drawing::Brushes::Green, pointx - rad, pointy - rad, rad * 2, rad * 2);
		if (color == "Blue")
			e->Graphics->FillEllipse(System::Drawing::Brushes::Blue, pointx - rad, pointy - rad, rad * 2, rad * 2);
		e->Graphics->DrawEllipse(System::Drawing::Pens::Black, pointx - rad, pointy - rad, rad * 2, rad * 2);
		if (checked)
			e->Graphics->DrawEllipse(System::Drawing::Pens::Purple, pointx - rad, pointy - rad, rad * 2, rad * 2);
	}
	bool checkPos(System::Windows::Forms::MouseEventArgs^ e) override {
		if (System::Math::Pow(e->X - pointx, 2) + System::Math::Pow(e->Y - pointy, 2) <= System::Math::Pow(rad, 2))
			return true;
		return false;
	}
	void changeSize(float a) override {
		if (checked) {
			rad += a;
			h += 2*a;
			w += 2*a;
		}
	}
};
class MVC {
private:
	int b1, b2, b3;
	Storage <FigureInterface*> figures;
	std::string color;
	bool ctrl = false;
public:
	Rectang* checker = new Rectang(-100, -100, 0, 0);
	void b1Set(int a) { b1 = a; }
	void b2Set(int a) { b2 = a; }
	void b3Set(int a) { b3 = a; }
	void ctrlSet(bool a) { ctrl = a; }
	bool ctrlGet() { return ctrl; }
	void colorSet(std::string color) { this->color = color; }
	int b1Get() { return b1; }
	int b2Get() { return b2; }
	int b3Get() { return b3; }
	void pushObject(int i, System::Windows::Forms::MouseEventArgs^ e) {
		if (b1)
			figures.pushObject(i, new Rectang(e->X, e->Y, 50, 50));
		if (b2)
			figures.pushObject(i, new Circle(e->X, e->Y, 25));
		if (b3)
			figures.pushObject(i, new Triang(e->X, e->Y));
	}
	void drawFigures(System::Windows::Forms::PaintEventArgs^ e) { 
		for (int i = 0; i<figures.getSize(); i++)
			if(!figures.getObject(i)->checked)
				figures.getObject(i)->drawFigure(e);
		checker->drawChecker(e);
		for (int i = 0; i < figures.getSize(); i++)
			if (figures.getObject(i)->checked) {
				figures.getObject(i)->drawFigure(e);
				figures.getObject(i)->drawChecked(e);
			}
		/*for (int i = 0; i < figures.getSize(); i++)
			if (figures.getObject(i)->checked) 
				figures.getObject(i)->drawChecked(e);	*/
		
	}
	int getSize() { return figures.getSize(); }
	void changePosition(float x,float y,float bordx,float bordy) {
		for (int i = figures.getSize() - 1; i >= 0; --i)
			if (figures.getObject(i)->checked && !figures.getObject(i)->checkBorder(bordx, bordy, x, y))
				return;
		for (int i = figures.getSize() - 1; i >= 0; --i) 
			if (figures.getObject(i)->checked) 
				figures.getObject(i)->changePos(x,y);
		checker->changePos(x, y);

	}
	int correctCheck(System::Windows::Forms::MouseEventArgs^ e) {
		for (int i = figures.getSize() - 1; i >= 0; --i)
			if (figures.getObject(i)->checkPos(e) && figures.getObject(i)->checked) {
				return i;
			}
		return -1;
	}
	void makeunCheck() {
		for (int i = figures.getSize() - 1; i >= 0; --i)
			figures.getObject(i)->setCheck(false);		
	}
	void makeCheck(System::Windows::Forms::MouseEventArgs^ e) {
		if (correctCheck(e)!=-1) {
			figures.getObject(correctCheck(e))->setCheck(!figures.getObject(correctCheck(e))->checked);
			return;
		}
		for (int i = figures.getSize() - 1; i >= 0; --i) {
			if (figures.getObject(i)->checkPos(e)) {
				figures.getObject(i)->setCheck(!figures.getObject(i)->checked);
				return;
			}
		}
	}
	void createColor() {
		for (int i = figures.getSize()-1; i>=0; --i) 
			if (figures.getObject(i)->checked) { 
				figures.getObject(i)->color = this->color;
			}
	}
	void inChecker() {
		for (int i = figures.getSize() - 1; i >= 0; --i)
			if (checker->isIn(figures.getObject(i)->pointx, figures.getObject(i)->pointy))
				figures.getObject(i)->setCheck(true);
	}
	void deleteObjects() {
		while (figures.getSize())
			figures.deleteObject(0);
	}
	void changeSizes(float a,float bordx,float bordy) {
		for (int i = figures.getSize() - 1; i >= 0; --i)
			if (figures.getObject(i)->checked) {
				figures.getObject(i)->changeSizeCorrect(a, bordx, bordy);
				if (a < 0 && figures.getObject(i)->isSize() == 2 || a > 0 && figures.getObject(i)->isSize() == 1)
					continue;
				figures.getObject(i)->changeSize(a);
			}
	}
	void outsideBorder(float bordx, float bordy) {
		for (int i = 0; i < figures.getSize(); i++)
			if (!figures.getObject(i)->checkBorder(0, 0, bordx, bordy))
				figures.deleteObject(i);
	}
	
};


