#include <iostream>
#include <iomanip>

using namespace std;

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;

typedef struct time {
	int hours, minutes, seconds;
} Time;

void canonify(Time& time) {
	time.seconds %= SECONDS_PER_MINUTE;
	time.minutes += time.seconds / SECONDS_PER_MINUTE;
	time.hours += time.minutes / MINUTES_PER_HOUR;
	time.minutes %= MINUTES_PER_HOUR;
}

Time* inputTimeArray(int& n) {
	Time* result;
	cout << "Enter the number of values:" << endl;
	cin >> n;
	//result = (Time*)malloc(sizeof(Time) * n);
	result = new Time[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter hour, minutes, seconds: " << endl;
		cin >> result[i].hours >> result[i].minutes >> result[i].seconds;
		canonify(result[i]);
	}
	return result;
}

void printTimeArray(Time times[], int n) {
	for (int i = 0; i < n; i++) {
		cout<< setw(2)<<setfill('0') <<times[i].hours << ":"
			<<setw(2) << setfill('0') << times[i].minutes << ":"
			<< setw(2) << setfill('0') << times[i].seconds << endl;
	}
}

int main()
{
	int n = 0;
	Time* times = inputTimeArray(n);
	printTimeArray(times, n);
}