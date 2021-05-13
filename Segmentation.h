/*
 ________________________________________________________________________________________
| INFORMAÇÕES:																			 |
|	 ARQUIVO:    Segmentation.h														     |
|	 SISTEMA:    VisionSystem															 |
|	 COMPONENTE: Segmentation															 |
|	 LINGUAGEM:  C++																	 |
|	 E-MAIL:     gprufs@gmail.com														 |
|	 CONTATO:    http://gprufs.org/														 |
|	 AUTOR:      GPRUFS 2015															 |
|																						 |
| DESCRIÇÃO:     Esse arquivo Contém a definição da classe Segmentation, que é           |
|                responsável por realizar a segmentação de uma determinada               |
|                cor numa imagem, a partir de um intervalo entre limiares que            |
|				 representam uma determinada cor em RGB.    				             |
|																			   			 |
|																						 |
|                               (c) Copyright GPRUFS 2015                                |
|________________________________________________________________________________________|
*/
#ifndef SEGMENTATION_H_
#define SEGMENTATION_H_

#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
//#include <Windows.h>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace cv;
using namespace std;
enum Space_Color
{
    RGB,
    HSV,
    NEW_RGB,
};
class Segmentation
{
public:
	Scalar rgbmin;
	Scalar rgbmax;

    Scalar new_rgbmin_1;
    Scalar new_rgbmax_1;
    Scalar new_rgbmin_2;
    Scalar new_rgbmax_2;

    Scalar hsv_max;
    Scalar hsv_min;

    Mat segmentacao;
    Mat Mascara[2];
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;

    int r;
    int g;
    int b;
    int rg;
    int rb;
    int gb;

public:
    int Segmentation_option;
    /*
     * Método: Segmentation(Scalar min,Scalar max,Mat *Mask);
     *
     * Descrição: Instancia um objeto da classe Segmentation
     *            atribuindo características como os intervalos
     *            de limiares e as máscaras para operações
     *            morfológicas de abertura e fechamento
     *
     * Parâmetros:
     *            1)  min  ->  Limiar contendo os valores mínimos de Red,Green,Blue
     *
     *            2)  max  ->  Limiar contendo os valores máximos de Red,Green,Blue
     *
     *            3)  *Mask -> Ponteiro para uma matriz do tipo Mat que representa
     *                         a forma da máscara usada para as operações de
     *                         abertura e fechamento.
     *
     * Retorno: Nenhum
     */
    Segmentation(Mat *Mask);

    void Set_Mask(Mat *Mask);

    /*
     * Método:  Segmentation_Result(Mat *frame);
     *
     * Descrição: Responsável pelo retorno da matriz binária resultante
     *            da segmentação, feita a partir dos limiares definidos,
     *            da imagem fornecida.
     *
     * Parâmetros:
     *            1)  min -> Limiar contendo os valores mínimos de Red,Green,Blue
     *
     *            2)  max -> Limiar contendo os valores máximo de Red,Green,Blue
     *
     *            3)  *Mask -> Ponteiro para uma matriz do tipo Mat que representa
     *                         a forma da máscara usada para as operações de
     *                         abertura e fechamento.
     *
     * Retorno:
     *        Nenhum
     */
    void Get_Limiar_NewRGB(Scalar min,Scalar max, Scalar min2, Scalar max2);
    void Get_Limiar_RGB(Scalar min,Scalar max);
    void Get_Limiar_HSV(Scalar min,Scalar max);

	Mat* Segmentation_Result(Mat *frame);
    void RGB_Segmentation(Mat *frame);
    void HSV_Segmentation(Mat *frame);
    void NEWRGB_Segmentation(Mat *frame);





};
#endif
