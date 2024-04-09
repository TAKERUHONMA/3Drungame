#pragma once
#include "Engine/GameObject.h"

const double DEF_TIMER_TIME{ 1.0 };

class CTimer :
    public GameObject
{
    double CountDownTimer_; //現在の残り時間
    double TIMER_INIT_TIME_; //初期時間
    bool isTimerRun_; //タイマーが動いているかどうか
public:
    CTimer()
        :TIMER_INIT_TIME_(DEF_TIMER_TIME),
        CountDownTimer_(DEF_TIMER_TIME),
        isTimerRun_(true) {};

    CTimer(double _initTime)
        :TIMER_INIT_TIME_(DEF_TIMER_TIME),
        CountDownTimer_(DEF_TIMER_TIME),
        isTimerRun_(true) {};

    bool IsTimeOber(); //タイマーは0になったか
    void ResetTimer(); //タイマーを初期時間に戻す
    void StartTimer(); //タイマーをスタートする
    void StopTimaer(); //タイマーをストップする
    double GetTimer() { return(CountDownTimer_); }
};

