#pragma once
#include"container.h"
#include<math.h>
#include<gcroot.h>
ref class FigureInterface {
public:
	std::string color="Empty";
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
};
ref class Rectang : public FigureInterface {
public:
	float h, w;
	Rectang(float x,float y,float h,float w) {
		this->h = h;
		this->w = w;
		pointx = x-w/2;
		pointy = y-h/2;
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		if (color =="Red")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Red, pointx, pointy, w, h);
		if (color == "Blue")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Blue, pointx, pointy, w, h);
		if (color == "Green")
			e->Graphics->FillRectangle(System::Drawing::Brushes::Green, pointx, pointy, w, h);
		e->Graphics->DrawRectangle(System::Drawing::Pens::Black, pointx, pointy, w, h);
		if (checked)
			e->Graphics->DrawRectangle(System::Drawing::Pens::Purple, pointx, pointy, w, h);
	}
	bool checkPos(System::Windows::Forms::MouseEventArgs^ e) override {
		if (e->X >= pointx && e->X <= pointx + w && e->Y >= pointy && e->Y <= pointy + h)
			return true;
		return false;
	}
};
ref class Triang : public FigureInterface {
public:
	array <System::Drawing::Point>^ points;
	Triang(float x, float y) {
		pointx = x;
		pointy = y;
		h = 675;
		w = 30;
	}
	void drawColor(System::Windows::Forms::PaintEventArgs^ e) {
		float temph = h,tempw=w;
		while (tempw) {
			tempw--;
			temph--;
			if (color == "Red") {
				e->Graphics->DrawLine(System::Drawing::Pens::Red, pointx, pointy - sqrt(temph), pointx - tempw, pointy + sqrt(temph));
				e->Graphics->DrawLine(System::Drawing::Pens::Red, pointx - tempw, pointy + sqrt(temph), pointx + tempw, pointy + sqrt(temph));
				e->Graphics->DrawLine(System::Drawing::Pens::Red, pointx, pointy - sqrt(temph), pointx + tempw, pointy + sqrt(temph));
			}
		}
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		drawColor(e);
		e->Graphics->FillPolygon(System::Drawing::Pens::Cyan, );
		e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx - w, pointy + sqrt(h));
		e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx - w, pointy + sqrt(h), pointx + w, pointy + sqrt(h));
		e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx + w, pointy + sqrt(h));
		if (checked) {
			e->Graphics->DrawLine(System::Drawing::Pens::Purple, pointx, pointy - sqrt(h), pointx - w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Purple, pointx - w, pointy + sqrt(h), pointx + w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Purple, pointx, pointy - sqrt(h), pointx + w, pointy + sqrt(h));
		}
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
		if (isInside(pointx-w,pointy+sqrt(h),pointx,pointy-sqrt(h),pointx+w,pointy+sqrt(h),e->X,e->Y))
			return true;
		return false;
	}
};
ref class Circle : public FigureInterface {
public:

	Circle() {

	}
	Circle(float x, float y,float radp) {
		pointx = x;
		pointy = y;
		rad = radp;
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
	Storage <FigureInterface^> figures;
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
			figures.getObject(i)->drawFigure(e);
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


