#include <QApplication>
//#include "mainwindow.h"

#include "matrix33f.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/
    Vector<float, 2> A = Vector<float, 2>(0.0f);
    Vector<float, 2> B = Vector<float, 2>(0.0f);
    A[0] = 1.0f;
    A[1] = 0.5f;
    B[0] = 2.0f;
    B[1] = 4.0f;
    Vector<float, 2> C = Vector<float, 2>(B);
    Vec3f D = Vec3f(0.0f, 5.0f, 2.0f);
    Vec3f E = Vec3f(D);
    E[0] = 1.0f;
    Vec3f F = Vec3f(E);
    Vec2f translation = Vec2f(C);
    Matrix33f T = Matrix33f(D, E, F);
    Matrix33f M = T;
    Matrix33f R = T.applyTranslation(translation);
    R.applyRotation(30.0f);


    std::cout << "C :" << C << std::endl;
    std::cout << "T : {" << T[0] << ", " << T[1] << ", "
              << T[2] << "}" << std::endl;
    std::cout << "M : {" << M[0] << ", " << M[1] << ", "
              << M[2] << "}" << std::endl;
    std::cout << "R : {" << R[0] << ", " << R[1] << ", "
              << R[2] << "}" << std::endl;

    return a.exec();
}
