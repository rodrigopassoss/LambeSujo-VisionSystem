/*
 ________________________________________________________________________________________
| INFORMAÇÕES:																			 |
|	 ARQUIVO:    mainwindow.h														     |
|	 SISTEMA:    VisionSystem															 |
|	 COMPONENTE: mainwindow															     |
|	 LINGUAGEM:  C++																	 |
|	 E-MAIL:     gprufs@gmail.com														 |
|	 CONTATO:    http://gprufs.org/														 |
|	 AUTOR:      GPRUFS 2015															 |
|																						 |
| DESCRIÇÃO:     Esse arquivo contém a definição da classe MainWindows que corresponde   |
|                à janela principal do programa e tem a função de instanciar e juntar    |
|                todos os módulos necessários para o funcionamento desse sistema.        |
|																			   			 |
|																						 |
|                               (c) Copyright GPRUFS 2015                                |
|________________________________________________________________________________________|
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <librealsense2/rs.hpp>

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QImage>
#include <QFileDialog>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include "../include/Configurations.h"
#include "../include/Robot.h"
#include "../include/Build_Robot.h"
#include "../include/Segmentation.h"
#include "../include/Grouping.h"
#include "../include/Ball.h"
#include "../include/controlador.h"
#include "../include/serialcomm.h"
#include "../include/constantes_robot.h"
#include "../include/strategy.h"
#include "../include/Communication.h"
#include "../utils/qcustomplot.h"

// incluido por lucas - INICIO
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
//#include <Windows.h>
#include <assert.h>
//#include <commctrl.h>
//#include "serialcomm.h"
#include "comandos.h"
#include "iostream"
#include "fstream"
//#include <omp.h>


using namespace rs2;

namespace Ui {
 class mouseevents;

}

class mouseevents : public QLabel
{
    Q_OBJECT
public:
    explicit mouseevents(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;

    double x,y, x_press, y_press;



Q_SIGNALS:

    void Mouse_pos();
    void Mouse_pressed();

};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    int classificador; //0-Find Contours...//1- Kameans
    QTimer *cronometro;
    QTimer *cronometro2;
    Configurations *set;
    VideoCapture cap;
    Mat input;
    double dist;
    string filename = "Settings.xml";

    context ctx;
    config cfg;
    bool razer;
    pipeline p;
    frameset frames;
    frame color;
    sensor color_sensor;

    ofstream out;

    FILE* arquivo;
    filebuf fb;
    ostream *os;


    vector<Point>azul_pt;       // Vetor de coordenadas(x,y) da posição do centro de cada um dos corpos azuis.
    vector<Point>vermelho_pt;   // Vetor de coordenadas(x,y) da posição do centro de cada um dos corpos vermelhos.
    vector<Point>amarelo_pt;    // Vetor de coordenadas(x,y) da posição do centro de cada um dos corpos amarelos.
    vector<Point>laranja_pt;    // Vetor de coordenadas(x,y) da posição do centro de cada um dos corpos laranjas.
    vector<Point>Magenta_pt;    // Vetor de coordenadas(x,y) da posição do centro de cada um dos corpos Magentas.
    vector<Point>Green_pt;      // Vetor de coordenadas(x,y) da posição do centro de cada um dos corpos verdes.

    Scalar Blue[2];             // vetor com o intervalo de limiares para a cor azul. Blue[0]->limiar mínimo Blue[1]->limiar máximo
    Scalar Red[2];              // vetor com o intervalo de limiares para a cor vermelho. Red[0]->limiar mínimo Red[1]-limiar máximo
    Scalar Yellow[2];           // vetor com o intervalo de limiares para a cor amarelo. yellow[0]->limiar mínimo yellow[1]->limiar máximo
    Scalar Orange[2];           // vetor com o intervalo de limiares para a cor laranja. orange[0]->limiar mínimo orange[1]->limiar máximo
    Scalar Mg[2];               // vetor com o intervalo de limiares para a cor magenta. Mg[0]->limiar mínimo Mg[1]->limiar máximo
    Scalar Green[2];            // vetor com o intervalo de limiares para a cor verde. Green[0]->limiar mínimo Green[1]->limiar máximo

    Scalar New_Blue_1[2];             // vetor com o intervalo de limiares para a cor azul. Blue[0]->limiar mínimo Blue[1]->limiar máximo
    Scalar New_Red_1[2];              // vetor com o intervalo de limiares para a cor vermelho. Red[0]->limiar mínimo Red[1]-limiar máximo
    Scalar New_Yellow_1[2];           // vetor com o intervalo de limiares para a cor amarelo. yellow[0]->limiar mínimo yellow[1]->limiar máximo
    Scalar New_Orange_1[2];           // vetor com o intervalo de limiares para a cor laranja. orange[0]->limiar mínimo orange[1]->limiar máximo
    Scalar New_Mg_1[2];               // vetor com o intervalo de limiares para a cor magenta. Mg[0]->limiar mínimo Mg[1]->limiar máximo
    Scalar New_Green_1[2];            // vetor com o intervalo de limiares para a cor verde. Green[0]->limiar mínimo Green[1]->limiar máximo

    Scalar New_Blue_2[2];             // vetor com o intervalo de limiares para a cor azul. Blue[0]->limiar mínimo Blue[1]->limiar máximo
    Scalar New_Red_2[2];              // vetor com o intervalo de limiares para a cor vermelho. Red[0]->limiar mínimo Red[1]-limiar máximo
    Scalar New_Yellow_2[2];           // vetor com o intervalo de limiares para a cor amarelo. yellow[0]->limiar mínimo yellow[1]->limiar máximo
    Scalar New_Orange_2[2];           // vetor com o intervalo de limiares para a cor laranja. orange[0]->limiar mínimo orange[1]->limiar máximo
    Scalar New_Mg_2[2];               // vetor com o intervalo de limiares para a cor magenta. Mg[0]->limiar mínimo Mg[1]->limiar máximo
    Scalar New_Green_2[2];            // vetor com o intervalo de limiares para a cor verde. Green[0]->limiar mínimo Green[1]->limiar máximo

    Scalar HSV_Blue[2];             // vetor com o intervalo de limiares para a cor azul. Blue[0]->limiar mínimo Blue[1]->limiar máximo
    Scalar HSV_Red[2];              // vetor com o intervalo de limiares para a cor vermelho. Red[0]->limiar mínimo Red[1]-limiar máximo
    Scalar HSV_Yellow[2];           // vetor com o intervalo de limiares para a cor amarelo. yellow[0]->limiar mínimo yellow[1]->limiar máximo
    Scalar HSV_Orange[2];           // vetor com o intervalo de limiares para a cor laranja. orange[0]->limiar mínimo orange[1]->limiar máximo
    Scalar HSV_Mg[2];               // vetor com o intervalo de limiares para a cor magenta. Mg[0]->limiar mínimo Mg[1]->limiar máximo
    Scalar HSV_Green[2];

    Mat Mascaras[2];            //vetor com as mascaras usadas para operações de abertura e fechamento.
    Rect2d roi;                   // retângulo usado para fazer a retirada da imagem do campo

    Segmentation *azul;         // Objeto responsável pela segmentação dos corpos de cor azul
    Segmentation *amarelo;      // Objeto responsável pela segmentação dos corpos de cor amarelo
    Segmentation *vermelho;     // Objeto responsável pela segmentação dos corpos de cor vermelo
    Segmentation *verde;        // Objeto responsável pela segmentação dos corpos de cor verde
    Segmentation *magenta;      // Objeto responsável pela segmentação dos corpos de cor magenta
    Segmentation *laranja;      // Objeto responsável pela segmentação dos corpos de cor laranja

    Grouping *azul_group;       // Objeto responsável por identificar o centro de massa dos corpos de cor azul
    Grouping *amarelo_group;    // Objeto responsável por identificar o centro de massa dos corpos de cor amarelo
    Grouping *verde_group;      // Objeto responsável por identificar o centro de massa dos corpos de cor verde
    Grouping *vermelho_group;   // Objeto responsável por identificar o centro de massa dos corpos de cor vermelho
    Grouping *magenta_group;    // Objeto responsável por identificar o centro de massa dos corpos de cor magenta
    Grouping *laranja_group;    // Objeto responsável por identificar o centro de massa dos corpos de cor laranja

    Constantes_robot *con;      // Objeto responsável pelas constantes características de cada robô
    Strategy *Cerebro;          // Objeto responsável pelos comportamentos e coordenação dos robôs
    int comando;
    int comando_atacante;
    int comando_zagueiro;
    int comando_goleiro;

    Build_Robot *Machine_of_Robots; // Objeto responsável por evitar ambiguidades durante colisões ou junção de robôs
    Ball Bola;                      // Objeto responsável por armazenar as coordenadas(x,y) da posição da bola

    clock_t end,start;
    vector<Robot> robos;        // Objeto responsável por armazenar todos dos robôs instanciados no sistema
    QImage image;

    Robot rb1;
    Robot rb2;
    Robot rb3;

    int time; //Valor que representa a camisa do time.  (0) - TIME AZUL, (1)- TIME AMARELO
    int contador;
    Point pos_bola[2];
    int aux;

    int Color_Space, cont_help;

    // Objeto para instaciar a Comunicação
    communication *SerialComm;

    //Plot das Velocidades
    void plotComm();
    void DefplotComm();
    QVector<double> *x_data;

    // Atributos para armazenar as velocidades lidas
    QVector<double> *VL_data;
    QVector<double> *VR_data;
    //Taxa de atualização do Plot
    int upatatetaxa = 0;

    //Pontos de Corte
    vector<cv::Point> pontos_corte;
    int action_calib;



private Q_SLOTS:

    void Mouse_current_pos();

    /*
         * Método: Mouse_pressed();
         *
         * Descrição: Chamdo com o evento do click do mouse.
         *
         * Parâmentros:
         *            1) QMouseEvent *ev - essa classe é capaz de obter
         *                                 todos os eventos do mouse.
         *
         * Retorno:
         *       Nenhum.
    */

    void Mouse_pressed();

    /*
     * Método:Refresh_position_robots();
     *
     * Descrição: Método responsável capturar e processar toda a imagem do campo, a fim de encontrar as posições centrais dos robôs
	 *
     * Parâmetro:
     *           Nenhum.
     * Retorno:
     *       Nenhum.
    */
     void Refresh_position_robots();

     void calibration();

     void on_actionKmeans_triggered();

     /*
      * Método:on_select_azul_triggered();
      *
      * Descrição: Método responsável por disparar um evento de seleção da cor azul do time
      *
      * Parâmetro:
      *           Nenhum.
      * Retorno:
      *          Nenhum.
     */
     void on_select_azul_triggered();

     /*
      * Método:on_select_amarelo_triggered();
      *
      * Descrição: Método responsável por disparar um evento de seleção da cor amarela do time
      *
      * Parâmetro:
      *           Nenhum.
      * Retorno:
      *       Nenhum.
     */
     void on_select_amarelo_triggered();

     void on_actionComandos_triggered();

     /*
      * Método: on_pushButton_clicked();
      *
      * Descrição: Método responsável por atribuir estratégias e comportamentos para os robôs
      *            que foram selecionados pelo usuário.
      *
      * Parâmetro:
      *           Nenhum.
      * Retorno:
      *       Nenhum.
     */
     void on_pushButton_clicked();


     /*
      * Método:on_pushButton_2_clicked();

      *
      * Descrição: Método responsável por parar todos os robôs
      *
      * Parâmetro:
      *           Nenhum.
      * Retorno:
      *       Nenhum.
     */
     void on_pushButton_2_clicked();

     void on_comboBox_currentIndexChanged(int index);

     void on_comboBox_activated(int index);

     /*
      * Método:on_actionAbrir_Settings_triggered();
      *
      * Descrição: Método resposável por carregar dados de um determinado arquivo de texto.
      *            Lista dos dados  carregados:
      *                - Limiares
      *                - Configurações do campo
	  *                - Configurações da câmera
	  *                - Constantes dos robôs
      *
      * Parâmetro:
      *           Nenhum.
      * Retorno:
      *          Nenhum.
     */
     void on_actionAbrir_Settings_triggered();

     void on_select_RGB_triggered();

     void on_select_New_RGB_triggered();

     void on_select_HSV_triggered(bool checked);

     void on_select_HSV_triggered();

     void on_contraste_valueChanged(int value);

     void on_saturacao_valueChanged(int value);

     void on_brilho_valueChanged(int value);

     void on_exposicao_valueChanged(int value);

     void on_Resolucao_currentIndexChanged(int index);

     void on_hue_valueChanged(int value);

     void on_white_balance_valueChanged(int value);

     void on_Gamma_valueChanged(int value);

     void on_Gain_valueChanged(int value);

     void on_Back_Compensation_valueChanged(int value);

     void on_nitidez_valueChanged(int value);

     Mat* select_Limiar2Segment(Mat);

     void change_limiares(int value, int row, int col);

     void on_bmin_valueChanged(int value);

     void on_gmin_valueChanged(int value);

     void on_rmin_valueChanged(int value);

     void on_bmax_valueChanged(int value);

     void on_gmax_valueChanged(int value);
     
     void on_rmax_valueChanged(int value);
     
     void on_comboBox_colors_currentIndexChanged(int index);

     void set_ui_values();

     void on_spinBox_abertura_valueChanged(int arg1);

     void on_spinBox_fechamento_valueChanged(int arg1);

     void on_comboBox_tipomask_currentIndexChanged(int index);

     void set_mascaras();

     void on_spinBox_cut_y_valueChanged(int arg1);

     void on_spinBox_cut_x_valueChanged(int arg1);

     void on_spinBox_cut_width_valueChanged(int arg1);

     void on_spinBox_cut_height_valueChanged(int arg1);

     void on_checkBox_expo_auto_clicked(bool checked);

     void on_checkBox_wb_auto_clicked(bool checked);

     void on_pushButton_linhas_campo_clicked();

     void plotar_principais();

     void plotar_secundarias();

     void on_spinBox_ftop_valueChanged(int arg1);

     void on_spinBox_fbot_valueChanged(int arg1);

     void on_spinBox_gtopy_valueChanged(int arg1);

     void on_spinBox_gboty_valueChanged(int arg1);

     void on_spinBox_fleftx_valueChanged(int arg1);

     void on_spinBox_frightx_valueChanged(int arg1);

     void on_spinBox_gleft_valueChanged(int arg1);

     void on_spinBox_gright_valueChanged(int arg1);

     void on_spinBox_area_left_valueChanged(int arg1);

     void on_spinBox_area_right_valueChanged(int arg1);

     void on_spinBox_lzagueiro_valueChanged(int arg1);

     void on_spinBox_lgoleiro_valueChanged(int arg1);

     void on_spinBox_area_topy_valueChanged(int arg1);

     void on_spinBox_area_boty_valueChanged(int arg1);

     void on_spinBox_p_area_b_valueChanged(int arg1);

     void on_spinBox_p_area_t_valueChanged(int arg1);

     void on_pushButton_cortar_clicked();

     void on_checkBox_help_lines_pressed();

     void on_checkBox_help_lines_clicked(bool checked);

     void on_refresh_ports_clicked();
     void info_ports();

     void on_read_data_clicked();

     void on_write_data_clicked();

     void on_connect_disconnect_clicked();

     void on_sendvl_valueChanged(int value);

     void on_sendvr_valueChanged(int value);


Q_SIGNALS:
     void Robos(Robot rb1,Robot rb2,Robot rb3);



};

#endif // MAINWINDOW_H
