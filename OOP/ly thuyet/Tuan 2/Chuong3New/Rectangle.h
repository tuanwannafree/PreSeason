#pragma once
class Rectangle
{
	private:
		int width;
		int length;
		static int count;
	public:
		void set(int w, int l);
		int area();
};

