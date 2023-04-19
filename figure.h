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
	virtual void changePos(System::Windows::Forms::MouseEventArgs^ e) {
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
};
class Rectang : public FigureInterface {
public:
	Rectang(float x,float y,float h,float w) {
		this->h = h;
		this->w = w;
		pointx = x;
		pointy = y;;
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		if (color =="Red")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Red, pointx-w/2, pointy-h/2, w, h);
		if (color == "Blue")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Blue, pointx-w/2, pointy-h/2, w, h);
		if (color == "Green")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Green, pointx-w/2, pointy-h/2, w, h);
		e->Graphics->DrawRectangle(System::Drawing::Pens::Black, pointx-w/2, pointy-h/2, w, h);
		if (checked)
			e->Graphics->DrawRectangle(System::Drawing::Pens::Purple, pointx-w/2, pointy-h/2, w, h);
	}
	bool checkPos(System::Windows::Forms::MouseEventArgs^ e) override {
		if (e->X >= pointx-w/2 && e->X <= pointx-w/2 + w && e->Y >= pointy-h/2 && e->Y <= pointy-h/2 + h)
			return true;
		return false;
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
};
class MVC {
private:
	int b1, b2, b3;
	Storage <FigureInterface*> figures;
	std::string color;
public:
	void b1Set(int a) { b1 = a; }
	void b2Set(int a) { b2 = a; }
	void b3Set(int a) { b3 = a; }
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
		for (int i = 0; i < figures.getSize(); i++)
			if (figures.getObject(i)->checked) {
				figures.getObject(i)->drawFigure(e);
				figures.getObject(i)->drawChecked(e);
			}
		
	}
	int getSize() { return figures.getSize(); }
	void changePosition(System::Windows::Forms::MouseEventArgs^ e) {

	}
	void makeunCheck() {
		for (int i = figures.getSize() - 1; i >= 0; --i)
			figures.getObject(i)->setCheck(false);
			
	}
	void makeCheck(System::Windows::Forms::MouseEventArgs^ e) {
		for (int i = figures.getSize() - 1; i >= 0; --i)
			if (figures.getObject(i)->checkPos(e)) {
				figures.getObject(i)->setCheck(!figures.getObject(i)->checked);
				return;
			}
	}
	void createColor() {
		for (int i = figures.getSize()-1; i>=0; --i) 
			if (figures.getObject(i)->checked) { 
				figures.getObject(i)->color = this->color;
			}
	}
	
};


