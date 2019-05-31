#ifndef TIMER_H__
#define TIMER_H__

#include <chrono>
#include <stdexcept>

/**
 * @class Timer
 * @brief 時刻計測クラス. 時刻計測を行いたいブロックの前後に start() と stop() を組み合わせて使う。stop() は、start() が呼び出された時刻からの経過時間を返す.
 * このクラスは、start() と stop() の複数回の呼び出しに対応する複数個の経過時間を積算している。積算経過時間は total() 関数により得られる。
 */
class Timer{
public:
	Timer() : sum_microsec_(0), status_(false) {}

	/**
	 * @brief 時刻計測を開始する
	 */
	void start()
	{
		start_ = std::chrono::system_clock::now();
		status_ = true; // 時刻計測の開始（タイマースタートのイメージ）
	}

	/**
	 * @brief 時刻計測を一時停止する
	 * @return 今回の計測区間の経過時間
	 */
	double stop()
	{
		if(!status_){
			throw std::runtime_error("time is not started.");
		}
		auto end = std::chrono::system_clock::now();
		double msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_).count();
		double microsec = std::chrono::duration_cast<std::chrono::microseconds>(end - start_).count();
		sum_microsec_ += microsec;
		status_ = false;
		return msec;
	}

	/**
	 * @brief 全 start()-stop() 間の合計経過時間を返す
	 * @return 合計経過時間
	 */
	int total()
	{
		return static_cast<int>(sum_microsec_ / 1000.);
	}


private:

	std::chrono::system_clock::time_point start_;
	double sum_microsec_;
	bool status_;

};

#endif
