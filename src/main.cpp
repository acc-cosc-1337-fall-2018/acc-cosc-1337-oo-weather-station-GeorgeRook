#include "clock.h"
#include<thread>
#include<iostream>

class Timer
{
	std::thread th;
	bool running = false;
public:
	typedef std::chrono::milliseconds Interval;
	typedef std::function<void(void)> Timeout;

	void start(const Interval &interval,
		const Timeout &timeout)
	{
		running = true;
		th = std::thread([=]()
		{
			while (running == true) {
				std::this_thread::sleep_for(interval);
				timeout();
			}
		});
	}

	void stop()
	{
		running = false;
		th.join();
	}
};

int main() 
{
	Clock clock;
	/*Timer tHello;
	
	tHello.start(std::chrono::milliseconds(1000), [&] {

		//auto t = std::time(nullptr);
		clock.display_time();
		std::cout <<std::endl;
		//cout << std::ctime(&t) << std::endl;

	
	});*/
	
	int i{ 0 };
	while (i != 100) 
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		clock.display_time();
		std::cout << std::endl;
		i++;
	}
	
//	tHello.stop();
	
	return 0;
}
