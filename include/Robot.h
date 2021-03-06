/*
 ________________________________________________________________________________________
| INFORMAÇÕES:																			 |
|	 ARQUIVO:    Robot.h														         |
|	 SISTEMA:    VisionSystem															 |
|	 COMPONENTE: Robot															         |
|	 LINGUAGEM:  C++																	 |
|	 E-MAIL:     gprufs@gmail.com														 |
|	 CONTATO:    http://gprufs.org/														 |
|	 AUTOR:      GPRUFS 2015															 |
|																						 |
| DESCRIÇÃO:     Esse arquivo contém a definição da classe Robot,                        |
|                responsável por armazenar características referentes                    | 
|				 a um determinado robô, as quais estão listadas abaixo:                  |
|                                                                                        |
|                   - Centros das cores de identificação e da camisa do time             |
|                   - Coordenada (x,y) da posição do centro do robô com relação à imagem |
|                   - Orientação do robô em radianos                                     |   
|                   - Zona morta das rodas direita e esquerda do robô                    |
|                   - Velocidade linear máxima                                           |
|                   - Velocidade angular máxima                                          |
|                   - Constante de proporcionalidade da velocidade linear                |
|                   - Constante de proporcionalidade da velocidade angular    		     |
|																			   			 |
|																						 |
|                               (c) Copyright GPRUFS 2015                                |
|________________________________________________________________________________________|
*/

#ifndef ROBOT_H_
#define ROBOT_H_
#include <iostream>
#include "opencv2/opencv.hpp"
#include "../include/Grouping.h"

using namespace cv;

class Robot
{
	private:
        Point camisa_identificador;// centro da cor da parte da camisa q identifica um robô
		Point camisa_time; // centro da cor da parte da camisa que identifica o time... azul ou amarelo
		Point centro_robo;
		double orientacao; // dada em radianos
	public:
		Robot();
		Robot(Point cor_time, Point cor_id);
		~Robot();
        /*
         * Método: Refresh_Position(Point cor_time, Point cor_id);
         *
         * Descrição: Atualiza a posição e orientação do robô com relação
         *            à imagem adquirida pela câmera do sistema.
         *
         * Parâmetros:
         *            1)  cor_time -> Objeto do tipo Point correspondente ao centro de massa
         *                           da cor do time robô.
         *
         *            2)  cor_id  -> Objeto do tipo Point correspondente ao centro de massa
         *                          da cor de identificação do robô.
         *
         * Retorno:
         *        Nenhum
         */
		void Refresh_Position(Point cor_time, Point cor_id);

        int zonamorta_direita_positiva;
        int zonamorta_direita_negativa;// zona morta do motor referente à roda direita

        int zonamorta_esquerda_positiva;
        int zonamorta_esquerda_negativa;// zona morta do motor referente à roda esquerda
        double vrd_p, vre_p;
        double V,W;

        double k_lin; // constante de proporcionalidade linear
        double k_ang; // constante de proporcionalidade angular
        double V_max; // velocidade linear máxima
        double W_max; // velocidade angular máxima
        double prop_roda_d;
        double prop_roda_e;

        int       rb_VRe_max_pos,
                  rb_VRd_max_pos,
                  rb_VRe_max_neg,
                  rb_VRd_max_neg,
                  rb_zonamorta_d_pos,
                  rb_zonamorta_d_neg,
                  rb_zonamorta_e_pos,
                  rb_zonamorta_e_neg;

        double ic_dp,
            ic_dn,
            ic_ep,
            ic_en;


        /*
         * Método: get_center_robot();
         *
         * Descrição: Retorna as coordenadas (x,y) correspondentes ao centro do robô.
         *
         *
         * Parâmetros:
         *           Nenhum
         *
         * Retorno: 
		          Point -> Objeto que armazena as coordenadas (x,y)
         *                 correspondentes à posição central do robô.
         */
		Point get_center_robot();

        /*
         * Método: get_orientation();
         *
         * Descrição: Retorna a orientação do robô em radianos
         *
         * Parâmetros:
         *           Nenhum
         *
         * Retorno:
         *        double -> Valor referente à orientação do robô em radianos
         */
		double get_orientation();

	private:
        /*
         * Método: calc_orientation();
         *
         * Descrição: Calcula a orientação do robô (em radianos) e a
		             armazena na variável "orientacao".
         *
         *
         * Parâmetros:
         *           Nenhum
         *
         * Retorno:
         *        Nenhum
         */
		void calc_orientation();

        /*
         * Método: calc_center_robot();
         *
         * Descrição: Calcula as coordenadas (x,y) correspondentes à posição do centro do robô.
         *            O valor calculado é armazenado na variável "centro_robo".
         *
         * Parâmetros:
         *           Nenhum
         *
         * Retorno:
         *        Nenhum
         */
		void calc_center_robot();
};
#endif
