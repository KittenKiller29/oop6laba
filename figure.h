#pragma once
#include"container.h"
class FigureInterface {
public:
	std::string color="Black";
	float pointx, pointy,h,w,rad;
	virtual void setColor(std::string color) {
	}
	virtual void changePos(System::EventArgs^ e) {
	}
	virtual void checkPos(System::EventArgs^ e) {
	}
	virtual void drawFigure(System::Windows::Forms::PaintEventArgs^ e) {
	}
};
class Rectang : public FigureInterface {
public:
	float h, w;
	Rectang(float x,float y,float h,float w) {
		this->h = h;
		this->w = w;
		pointx = x-w/2;
		pointy = y-h/2;
	}
	void setColor(std::string color) override {
		this->color = color;
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		if (color == "Black")
			e->Graphics->DrawRectangle(System::Drawing::Pens::Black, pointx, pointy, w, h);
		if (color == "Red")
			e->Graphics->DrawRectangle(System::Drawing::Pens::Red, pointx, pointy, w, h);
		if (color == "Blue")
			e->Graphics->DrawRectangle(System::Drawing::Pens::Blue, pointx, pointy, w, h);
		if (color == "Green")
			e->Graphics->DrawRectangle(System::Drawing::Pens::Green, pointx, pointy, w, h);
	}
};
class Triang : public FigureInterface {
public:
	Triang(float x, float y) {
		pointx = x;
		pointy = y;
		h = 675;
		w = 30;
	}
	void setColor(std::string color) override {
		this->color = color;
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		
		if (color == "Black") {
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy-sqrt(h), pointx-w, pointy+sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx-w, pointy + sqrt(h), pointx+w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx + w, pointy + sqrt(h));
		}
		if (color == "Red") {
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx - w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx - w, pointy + sqrt(h), pointx + w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx + w, pointy + sqrt(h));
		}
		if (color == "Blue") {
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx - w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx - w, pointy + sqrt(h), pointx + w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx + w, pointy + sqrt(h));
		}
		if (color == "Green") {
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx - w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx - w, pointy + sqrt(h), pointx + w, pointy + sqrt(h));
			e->Graphics->DrawLine(System::Drawing::Pens::Black, pointx, pointy - sqrt(h), pointx + w, pointy + sqrt(h));
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
		color = "Black";
	}
	void setColor(std::string color) override {
		this->color = color;
	}
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e) override {
		if (color == "Black")
			e->Graphics->DrawEllipse(System::Drawing::Pens::Black, pointx - rad, pointy - rad, rad * 2, rad * 2);
		if (color == "Red")
			e->Graphics->DrawEllipse(System::Drawing::Pens::Red, pointx - rad, pointy - rad, rad * 2, rad * 2);
		if (color == "Blue")
			e->Graphics->DrawEllipse(System::Drawing::Pens::Blue, pointx - rad, pointy - rad, rad * 2, rad * 2);
		if (color == "Green")
			e->Graphics->DrawEllipse(System::Drawing::Pens::Green, pointx - rad, pointy - rad, rad * 2, rad * 2);
	}
};
class MVC {
private:
	int b1, b2, b3;
	Storage <FigureInterface*> figures;
public:
	void b1Set(int a) { b1 = a; }
	void b2Set(int a) { b2 = a; }
	void b3Set(int a) { b3 = a; }
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
		for (int i = 0; i < figures.getSize(); i++)
			figures.getObject(i)->drawFigure(e);
	}
	int getSize() { return figures.getSize(); }
};


