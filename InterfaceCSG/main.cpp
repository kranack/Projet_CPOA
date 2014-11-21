//#include <QApplication>
//#include "mainwindow.h"

#include "vector.h"

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
	MainWindow w;
    w.show();*/
    Vector<float, 2> A = Vector<float, 2>(0.0f);
    Vector<float, 2> B = Vector<float, 2>(0.0f);
    A[0] = 1.0f;
    A[1] = 0.5f;
    B[0] = 2.0f;
    B[1] = 4.0f;
    Vector<float, 2> C = Vector<float, 2>(B);

    std::cout << "A :" << A << std::endl;
    std::cout << "B :" << B << std::endl;
    std::cout << "C :" << C << std::endl;
    std::cout << "A + B : " << (A + B) << std::endl;
    std::cout << "A == B : " << (A == B) << std::endl;
    std::cout << "A != B : " << (A != B) << std::endl;
    std::cout << "B == C : " << (B == C) << std::endl;


    //return a.exec();
}
