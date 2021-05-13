#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string>

//OpenCV
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/calib3d/calib3d.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

#include "omp.h"
#include "Kmeans.h"

#define Max 1
#define Min 0

using namespace cv;
using namespace std;

enum RGB_limiares{Rmin,Rmax,Gmin,Gmax,Bmin,Bmax};
enum _RgB{R,G,B};
enum __RgB{_B,_G,_R};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int enable = 0;

    Mat image;
    Mat Limiar;

    Scalar Blue[2];             // vetor com o intervalo de limiares para a cor azul. Blue[0]->limiar mínimo Blue[1]->limiar máximo
    Scalar Red[2];              // vetor com o intervalo de limiares para a cor vermelho. Red[0]->limiar mínimo Red[1]-limiar máximo
    Scalar Yellow[2];           // vetor com o intervalo de limiares para a cor amarelo. yellow[0]->limiar mínimo yellow[1]->limiar máximo
    Scalar Orange[2];           // vetor com o intervalo de limiares para a cor laranja. orange[0]->limiar mínimo orange[1]->limiar máximo
    Scalar Green[2];            // vetor com o intervalo de limiares para a cor verde. Green[0]->limiar mínimo Green[1]->limiar máximo
    Scalar _rgb[2];

    int rgb[6] = {0,0,0,0,0,0};

    Mat blue_Mat_binary;
    Mat yellow_Mat_binary;
    Mat orange_Mat_binary;
    Mat red_Mat_binary;

    int r;
    int b;
    int g;


    QTimer *time = NULL;

    QImage img_original;
    QImage img_limiarizada;

    float temp_paralelo = 0;
    float temp_serial = 0;
    float temp_kmeans = 0;

    vector<Point>pontos_kmeans;
    vector<float> _tempos;
    int cont = 0;
    int cont_2 = 0;




private:
    Ui::MainWindow *ui;

    void update_frame(Mat imagem);
    void update_frame_Binary(Mat imagem_Binary);
    void extrair_limiares();
    void segmentacao(Mat Input, Scalar* limiares, Mat* Output);
    void _kmeans(Mat *Mat_Binary, int K);
    void _kmeans_Worker();


private slots:
    void workSapace();

    void on_R_min_valueChanged(int value);
    void on_R_min_2_valueChanged(int arg1);
    void on_R_max_valueChanged(int value);
    void on_R_max_2_valueChanged(int arg1);
    void on_G_min_valueChanged(int value);
    void on_G_min_2_valueChanged(int arg1);
    void on_G_max_valueChanged(int value);
    void on_G_max_2_valueChanged(int arg1);
    void on_B_min_valueChanged(int value);
    void on_B_min_2_valueChanged(int arg1);
    void on_B_max_valueChanged(int value);
    void on_B_max_2_valueChanged(int arg1);
    void on_SelectColor_currentIndexChanged(int index);
    void on_salve_clicked();
    void on_enable_limiares_stateChanged(int arg1);
    void on_opencv_clicked();
};
#endif // MAINWINDOW_H
