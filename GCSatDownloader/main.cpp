#include "GCSatDownloader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GCSatDownloader w;
    w.show();

    a.exec();
}

//#include <atomic>
//#include <thread>
//#include <chrono>
//#include <iostream>
//
//struct MainWindow
//{
//	std::atomic<bool> stop_{ false };
//	std::thread task_;
//
//	void run()
//	{
//		while (!stop_) {
//			std::cout << "Processing ...\n";
//			std::this_thread::sleep_for(std::chrono::seconds(1));
//		}
//
//		std::cout << "Stopping ...\n";
//	}
//
//	void launch_thread()
//	{
//		task_ = std::thread(&MainWindow::run, this);
//	}
//
//	~MainWindow()
//	{
//		stop_ = true;
//		task_.join();
//	}
//};
//
//int main()
//{
//	{
//		MainWindow w;
//		w.launch_thread();
//		std::this_thread::sleep_for(std::chrono::seconds(5));
//	}
//
//	cout << "goin out" << endl;
//}