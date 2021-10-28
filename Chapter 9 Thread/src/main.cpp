#include <iostream>
#include <thread>

using namespace std;

using namespace std::chrono;

template <class T>

void measure(T &&func)
{
	auto beg_t = system_clock::now();
	func();
	auto end_t = system_clock::now();
	duration<double> diff = end_t - beg_t;
	printf("performTest total time: ");
	cout << diff.count() << endl;
}

void NumberAdd(unsigned long long start, unsigned long long end, unsigned long long & ans)
{
	int sum = 0;
	for (unsigned long long i = start; i <= end; i++)
	{
		sum += i;
	}
	ans = sum;
}

int main()
{
	unsigned long long times = 100;
	measure([times]()
			{
				unsigned long long ans = 0;

				NumberAdd(1, times, ref(ans));
				cout << "result of single thread: " << ans << endl;
			});

	measure([times]()
			{
				unsigned long long ans1 = 0, ans2 = 0;

				thread t1 = thread(NumberAdd, 1, times / 2, ref(ans1));
				thread t2 = thread(NumberAdd, times / 2, times, ref(ans2));

				t1.join();
				t2.join();

				cout << "result of two threads: " << ans1 + ans2 << endl;
			});

	measure([times]()
			{
				unsigned long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

				thread t1 = thread(NumberAdd, 1, times / 4, ref(ans1));
				thread t2 = thread(NumberAdd, times / 4, times / 2, ref(ans2));
				thread t3 = thread(NumberAdd, times / 2, 3 * times / 4, ref(ans3));
				thread t4 = thread(NumberAdd, 3 * times / 4, times, ref(ans4));

				t1.join();
				t2.join();
				t3.join();
				t4.join();

				cout << "result of four threads: " << ans1 + ans2 + ans3 + ans4 << endl;
			});

	measure([times]()
			{
				unsigned long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0, ans7 = 0, ans8 = 0;

				unsigned long long h1 = times / 8;
				unsigned long long h2 = times / 4;
				unsigned long long h3 = h1 + h2;
				unsigned long long h4 = times / 2;
				unsigned long long h5 = h4 + h1;
				unsigned long long h6 = h4 + h2;
				unsigned long long h7 = h4 + h3;

				thread t1 = thread(NumberAdd, 1, h1, ref(ans1));
				thread t2 = thread(NumberAdd, h1, h2, ref(ans2));
				thread t3 = thread(NumberAdd, h2, h3, ref(ans3));
				thread t4 = thread(NumberAdd, h3, h4, ref(ans4));
				thread t5 = thread(NumberAdd, h4, h5, ref(ans5));
				thread t6 = thread(NumberAdd, h4, h6, ref(ans6));
				thread t7 = thread(NumberAdd, h6, h7, ref(ans7));
				thread t8 = thread(NumberAdd, h7, times, ref(ans8));

				t1.join();
				t2.join();
				t3.join();
				t4.join();
				t5.join();
				t6.join();
				t7.join();
				t8.join();

				cout << "result of eight threads: " << ans1 + ans2 + ans3 + ans4 + ans5 + ans6 + ans7 + ans8 << endl;
			});
}