#pragma once
#include "Engine/GameObject.h"

const double DEF_TIMER_TIME{ 1.0 };

class CTimer :
    public GameObject
{
    double CountDownTimer_; //���݂̎c�莞��
    double TIMER_INIT_TIME_; //��������
    bool isTimerRun_; //�^�C�}�[�������Ă��邩�ǂ���
public:
    CTimer()
        :TIMER_INIT_TIME_(DEF_TIMER_TIME),
        CountDownTimer_(DEF_TIMER_TIME),
        isTimerRun_(true) {};

    CTimer(double _initTime)
        :TIMER_INIT_TIME_(DEF_TIMER_TIME),
        CountDownTimer_(DEF_TIMER_TIME),
        isTimerRun_(true) {};

    bool IsTimeOber(); //�^�C�}�[��0�ɂȂ�����
    void ResetTimer(); //�^�C�}�[���������Ԃɖ߂�
    void StartTimer(); //�^�C�}�[���X�^�[�g����
    void StopTimaer(); //�^�C�}�[���X�g�b�v����
    double GetTimer() { return(CountDownTimer_); }
};

