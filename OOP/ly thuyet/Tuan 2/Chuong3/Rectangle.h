#pragma once
class Rectangle
{
	private:
		int width, length;
	public:
		void set(int w, int l);
		int area() { return width * length; }
};

