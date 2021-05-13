/*
 ________________________________________________________________________________________
| INFORMAÇÕES:																			 |
|	 ARQUIVO:    strategy.h															     |
|	 SISTEMA:    VisionSystem															 |
|	 COMPONENTE: strategy															     |
|	 LINGUAGEM:  C++																	 |
|	 E-MAIL:     gprufs@gmail.com														 |
|	 CONTATO:    http://gprufs.org/														 |
|	 AUTOR:      GPRUFS 2015															 |
|																						 |
| DESCRIÇÃO: Esse arquivo contém a definição da classe Strategy                          |
|            que é responsável por definir diferentes comportamentos                     |
|            para cada robô do time, além de permitir que o comportamento                |
|            seja alterado a partir da interface.							             |
|																			   			 |
|																						 |
|                               (c) Copyright GPRUFS 2015                                |
|________________________________________________________________________________________|
*/

#ifndef STRATEGY_H
#define STRATEGY_H
#include <iostream>
#include "Robot.h"
#include "Ball.h"
#include "controlador.h"
#include "serialcomm.h"
#include "Configurations.h"
#include "Configurations.h"
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<Robot> parar(vector<Robot>);

// COMPORTAMENTOS
// FUNÇÃO PARA COORDENAR OS COMPORTAMENTOS DOS ROBÔS


class Strategy
{
public:
    typedef
       comandos (Strategy::*Func)(Robot);
    typedef
       void (Strategy::*cerebro)();

    vector<Robot>robos;
    Configurations *campo;
    Ball bola;
    Ball bola_anterior;
    void get_const(double,double);
    double v_max_filp;
    double w_max_filp;
    vector<Robot> rec_sign(vector<Robot>,comandos,int);

    vector<Point>adversarios;
    vector<double> w_ang, orientation;
    double vm1, vm2, vm3;
    double flaag;
    bool gole;
    int cont_gol;
    Func Atacante;
    Func Goleiro;
    Func Zagueiro;

    vector<cerebro>Estrategias;
    vector<double> vr1; // Par - Esquerda, Ímpar - Direita.

    vector<Func>base_Atacantes;
    vector<Func>base_Goleiros;
    vector<Func>base_Zagueiros;

    vector<string>Nome_atacante;
    vector<string>Nome_goleiro;
    vector<string>Nome_zagueiro;
    vector<string>Nome_Estrategias;

    Strategy();
    ~Strategy();
    /*
     * Método: Setar_Campo(Configurations *c);
     *
     * Descrição: Carrega na classe as delimitações do campo
     *
     * Parâmetros:
     *            1) *c -> Ponteiro para um objeto do tipo Configurations
     *                     que guarda todas as delimitações do campo
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Setar_Campo(Configurations *c);

    /*
     * Método: Setar_Variaveis_jogo
     *
     * Descrição: Carrega na classe na classe todas as informações sobre os robôs, bola e adversários
     *
     * Parâmetros:
     *            1) r -> um vetor do tipo Vector<Robot> com tamanho 3 em
     *                    que cada elemento é um objeto Robot que se refere
     *                    a um robô específico
     *
     *            2) b -> um objeto do tipo Ball que guarda a posição da bola com relação
     *                    à imagem adquirida pela câmera do sistema
     *
     *            3) a -> um vetor do tipo Vector<Point> com tamanho 3 em que cada
     *                    elemento do vetor corresponde ao centro de um robô adversário
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Setar_Variaveis_jogo(vector<Robot>r,Ball b,vector<Point>a);

    /*
     * Método:Get_atacantes();
     *
     * Descrição: Retorna o Nome de toda os comportamentos referentes ao atacante
     *
     * Parâmetros:
     *           Nenhum.
     *
     *
     * Retorno:
     *        Retorna um vetor do tipo vector<string> em que cada elemento do vetor é uma string
     *        que representa o nome do comportamento para o atacante.
     */
    vector<string> Get_atacantes();

    /*
     * Método: Get_goleiros();
     *
     * Descrição: Retorna o Nome de toda os comportamentos referentes ao goleiro
     *
     * Parâmetros:
     *           Nenhum.
     *
     *
     * Retorno:
     *        Retorna um vetor do tipo vector<string> em que cada elemento do vetor é uma string
     *        que representa o nome do comportamento para o goleiro.
     */
    vector<string> Get_goleiros();

    /*
     * Método:Get_zagueiros();
     *
     * Descrição: Retorna o Nome de toda os comportamentos referentes ao zagueiro
     *
     * Parâmetros:
     *           Nenhum.
     *
     *
     * Retorno:
     *        Retorna um vetor do tipo vector<string> em que cada elemento do vetor é uma string
     *        que representa o nome do comportamento para o zagueiro.
     */
    vector<string> Get_zagueiros();

    /*
     * Método:Get_Estrategias();
     *
     * Descrição: A estratégia coordena os comportamentos de todos os jogadores do time
     *            além de permitir a troca de posições de cada jogador. Esse método retorna
     *            o nome de todas as estratégias cadastradas na classe
     *
     * Parâmetros:
     *           Nenhum.
     *
     *
     * Retorno:
     *        Retorna um vetor do tipo vector<string> em que cada elemento do vetor é uma string
     *        que representa o nome das estratégias cadastradas na classe.
     */
    vector<string> Get_Estrategias();

    /*
     * Método: Adicionar_atacante(String nome,Func atacante);
     *
     * Descrição: Esse método permite que um comportamento que foi definido
     *            na classe para o atacante apareça na interface para ser
     *            selecionada durante o jogo.
     *
     *
     * Parâmetros:
     *           1)nome -> Nome referente ao comportamento
     *
     *           2)atacante -> Nome da função declarada na classe que define
     *                         o comportamento para o atacante
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Adicionar_atacante(String nome,Func atacante);

    /*
     * Método: Adicionar_goleiro(String nome,Func goleiro);
     *
     * Descrição: Esse método permite que um comportamento que foi definido
     *            na classe para o goleiro apareça na interface para ser
     *            selecionada durante o jogo.
     *
     *
     * Parâmetros:
     *           1)String nome - Nome referente ao comportamento
     *
     *           2)Func atacante - Nome da função declarada na classe que define
     *                             o comportamento para o goleiro
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Adicionar_goleiro(String nome,Func goleiro);

    /*
     * Método: Adicionar_zagueiro(String nome,Func zagueiro);
     *
     * Descrição: Esse método permite que um comportamento que foi definido
     *            na classe para o zagueiro apareça na interface para ser
     *            selecionada durante o jogo.
     *
     *
     * Parâmetros:
     *           1)String nome - Nome referente ao comportamento
     *
     *           2)Func atacante - Nome da função declarada na classe que define
     *                             o comportamento para o zagueiro
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Adicionar_zagueiro(String nome,Func zagueiro);


    /*
     * Método: Adicionar_estrategia(String nome,cerebro Est);
     *
     * Descrição: A estratégia coordena os comportamentos de todos os jogadores do time
     *            além de permitir a troca de posições de cada jogador. Esse método permite
     *            que a estratégia que foi definida na classe apareça na interface para ser
     *            selecionada durante o jogo.
     *
     * Parâmetros:
     *           1)String nome - Nome referente ao comportamento
     *
     *           2)cerebro Est - Nome da função declarada na classe que define
     *                           a estrategia.
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Adicionar_estrategia(String nome,cerebro Est);

    /*
     * Método: Executar_estrategia(int i);
     *
     * Descrição: Executa uma determinada estratégia entre as que foram
     *            definidas na classe
     *
     * Parâmetros:
     *           1)int i - valor inteiro que se refere ao número da estratégia
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Executar_estrategia(int i);

    /*
     * Método: Setar_Atacante(int i);
     *
     * Descrição: esse metodo impõe que certo robô i irá receber o comportamento
     *            de um atacante
     *
     * Parâmetros:
     *           1)int i - valor inteiro que representa um determinado robô
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Setar_Atacante(int i);

    /*
     * Método: Setar_Goleiro(int i);
     *
     * Descrição: esse metodo impõe que certo robô i irá receber o comportamento
     *            de um goleiro
     *
     * Parâmetros:
     *           1)int i - valor inteiro que representa um determinado robô
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Setar_Goleiro(int i);

    /*
     * Método: Setar_Zagueiro(int i);
     *
     * Descrição: esse metodo impõe que certo robô i irá receber o comportamento
     *            de um zagueiro
     *
     * Parâmetros:
     *           1)int i - valor inteiro que representa um determinado robô
     *
     *
     * Retorno:
     *        Nenhum
     */
    void Setar_Zagueiro(int i);


    int defensor;
    int z[3];
    int ataque;
    int a[3];
    int goalkeeper;
    int g[3];

    double V,W;

    void Permitir_alteracao_usuario();

    int Alteracao_jogador[3]; //0-atacante, 1-goleiro, 2- zagueiro



    //COMPORTAMENTOS CADASTRADOS NA CLASSE
    //----------------------------------------------------------------------------

    void estrategia1();
    void posicionar();
    void posicionar_d();
    void estrategia2();
    void estrategia();
    void estrategia5();
    void calibra();

    comandos goleiro(Robot);

    comandos zagueiro(Robot);
    comandos atacante(Robot);

    int flag_fire, f_ata;
    Point vet1, vet2;
    int flag_1,flag_2,flag_3;
    int contadorr;

    comandos goleiro2(Robot);
    comandos vitoria(Robot);
    comandos cr7_contrario(Robot);
    comandos samuel(Robot);
    comandos Ricardo_rocha(Robot);
    comandos Ricardo_rocha_cont(Robot);
    comandos Paulo_Victor(Robot);
    comandos Paulo_Victor_cont(Robot);
    comandos zagueiro2(Robot);
    comandos atacante2(Robot);
    comandos Garrincha(Robot);
    comandos griezzman(Robot);
    comandos Garrincha_contrario(Robot);
    comandos raphael(Robot);
    comandos parado(Robot);
    comandos penalty_des(Robot);
    comandos p_cima(Robot);
    comandos pegandofogo(Robot);
    int sairparede(Robot);
    int larga_robos(Robot, int, int);
    comandos deslargar(Robot, int, int);



};

#endif // STRATEGY_H
