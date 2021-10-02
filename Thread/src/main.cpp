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

void NumberAdd(long long start, long long end, long long &ans)
{
	int sum = 0;
	for (long long i = start; i < end; i++)
		sum = sum + 1;
	ans = sum;
}

int main()
{
	long long times = 5000000;
	measure([times]()
			{
				long long ans = 0;
				NumberAdd(0, times, ans);
				cout << "result of single thread: " << ans << endl;
			});

	measure([times]()
			{
				long long ans1 = 0, ans2 = 0;
				thread t1 = thread(NumberAdd, 0, times / 2, ref(ans1));
				thread t2 = thread(NumberAdd, times / 2, times, ref(ans2));

				t1.join();
				t2.join();

				cout << "result of two threads: " << ans1 + ans2 << endl;
			});

	measure([times]()
			{
				long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
				thread t1 = thread(NumberAdd, 0, times / 4, ref(ans1));
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
				long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0, ans7 = 0, ans8 = 0;
				thread t1 = thread(NumberAdd, 0, times / 8, ref(ans1));
				thread t2 = thread(NumberAdd, times / 8, times / 4, ref(ans2));
				thread t3 = thread(NumberAdd, times / 4, 3 * times / 8, ref(ans3));
				thread t4 = thread(NumberAdd, 3 * times / 8, times / 2, ref(ans4));
				thread t5 = thread(NumberAdd, times / 2, 5 * times / 8, ref(ans5));
				thread t6 = thread(NumberAdd, 5 * times / 8, 3 * times / 4, ref(ans6));
				thread t7 = thread(NumberAdd, 3 * times / 4, 7 * times / 8, ref(ans7));
				thread t8 = thread(NumberAdd, 7 * times / 8, times, ref(ans8));

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