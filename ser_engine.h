﻿#ifndef SER_ENGINE_H
#define SER_ENGINE_H
#include"tensorflowcomp.h"
#include <QObject>
#include"opensmilecomp.h"
#include<QString>
#include<QThread>
#include<QStringList>
#include"string"
using std::string;

class cSpyThread;

class cSER_Engine:public QObject
{
    Q_OBJECT
public:
    cSER_Engine(QString work_dir=".");
    virtual ~cSER_Engine();
    Q_INVOKABLE int start_engine(); //开启spyThread，tensorflow ,opensmile recorder
    Q_INVOKABLE int restart_engien();
    Q_INVOKABLE int stop_engine();
    Q_INVOKABLE int set_workdir(QString work_dir=".");//设置工作目录
    Q_INVOKABLE int preboot_engine();//开启spyThread,tensorflow模块
    Q_INVOKABLE int start_recorder();//开启opensmile录音
    Q_INVOKABLE int stop_recorder();//停止opensmile录音
    Q_INVOKABLE QString get_wav_seg_path();//停止opensmile录音
    Q_INVOKABLE int get_startIndex();//获取录音开始编号
    bool engine_running;
    bool engine_exstart;

private:
    QString engine_path;
    QString model_path;
    QString tempdata_path;
    QString wav_seg_path;
    QString feature_path;
    QString openSmile_path;
    QString work_dir;
    cSpyThread* spyThread;
    bool spyThread_running;
    cOpenSmileComp *openSmile;
	cTensorFlowComp * tensorFlow;
    bool openSmile_runnig;
    bool tensorFlow_runnig;

signals:
    void stop_all();
    void recognition_complete(QString predict_path);
    void out_predict_result(QString voice_seg,QString predict,QStringList probability);
public slots:
    int state_recv(QString compName,bool state);

};


class cSpyThread:public QThread
{
    Q_OBJECT

public:
    QString wav_seg_path;
    cSpyThread(QString work_dir);
    void set_workdir(QString work_dir=".");
    int filecur_num;
    ~cSpyThread();
    void run();

signals:
    void turnComplete(QString wavfile_path);
    void threadstopped(QString name,bool state);
    void threadstarted(QString name,bool state);



public slots:
    int stop();
private:
    bool is_loop;

};

#endif // SER_ENGINE_H
