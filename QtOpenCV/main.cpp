#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <Python.h>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*
    QString num1 = "10";
    QString num2 = "10";
    Py_Initialize();
    PyObject* pModule = PyImport_ImportModule("mypython");
    if(pModule == NULL)
    {
        qDebug() << "find file Error";
    }
    PyObject* pFunadd = PyObject_GetAttrString(pModule, "add");
    if(!PyCallable_Check(pFunadd))
    {
        qDebug() <<"find attr error";
    }
    PyObject* args = PyTuple_New(2);
    PyObject* arg1 = Py_BuildValue("d", num1.toDouble());
    PyObject* arg2 = Py_BuildValue("d", num2.toDouble());
    PyTuple_SetItem(args, 0, arg1);
    PyTuple_SetItem(args, 1, arg2);
    PyObject* pyValue = PyEval_CallObject(pFunadd, args);
    double d;
    PyArg_Parse(pyValue, "d", &d);
    qDebug() << d;
    Py_Finalize();
8/
    /*
    Py_Initialize();
    //如果初始化失败，返回
    if(!Py_IsInitialized())
    {
        qDebug()<<"初始化失败！";
        return a.exec();
    }
    //加载模块，模块名称为myModule，就是myModule.py文件
    PyObject *pModule = PyImport_ImportModule("mypython");
    //如果加载失败，则返回
    if(!pModule)
    {
        qDebug()<<"加载Python文件失败";
        return a.exec();
    }
   //加载函数greatFunc

    PyObject * pFuncHello = PyObject_GetAttrString(pModule, "hello");
    //如果失败则返回
        if(!pFuncHello)
        {
            qDebug()<<"加载函数失败";
            return a.exec();
        }
    //调用函数
    PyObject * pResult = PyObject_CallFunction(pFuncHello, NULL);
//    qDebug()<< *pResult;
    //退出
    Py_Finalize();
*/

    return a.exec();
}
