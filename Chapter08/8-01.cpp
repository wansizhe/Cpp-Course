#include<iostream>
using namespace std;

class Time
{
	public://ԭ��
	void set_time(void);
	void show_time(void);
    private://ԭ��
	int hour;
    int minute;
    int sec;
};

Time t;

int main()
{
	t.set_time();//ԭ��set_time();
	t.show_time();//ԭ��show_time();
	return 0;
}

void Time:: set_time(void)//ԭ��int set_time(void)
{
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}

void Time::show_time()//ԭ��int show_time()
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}