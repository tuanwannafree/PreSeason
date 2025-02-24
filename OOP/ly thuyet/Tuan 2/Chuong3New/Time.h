#pragma once
class Time
{
	private:
		int hrs;
		int mins;
		int secs;
	public:
		void Set(int hours, int minutes, int seconds);
		void Increment();
		Time(int initHrs, int initMins, int initSecs);
		Time(); // default constructor
};

