#include "strategy.h"
#include <cmath>

//////////////////////////////////////////////////////////////////////////////
////////////////////////ADICIONAR FUNCOES NA INTERFACE////////////////////////
//////////////////////////////////////////////////////////////////////////////

//COLOCAR ("NOME QUE APARECE NA INTERFACE",NOME_FUNCAO_DO_JOGADOR)
//FUNCOES...Adicionar_atacante("Nome",Nome_da_funcao);
//          Adicionar_zagueiro("Nome",Nome_da_funcao);
//          Adicionar_goleiro("Nome",Nome_da_funcao);
//          Adicionar_estrategia("Nome",Nome_da_funcao);

void Strategy::get_const(double int1, double int2)
{
    v_max_filp = int1;
    w_max_filp = int2;
}

vector<Robot> Strategy::rec_sign(vector<Robot> rb, comandos resultado, int pos)
{
    if(((int)resultado.logica & 0x18) == 16)
        rb[pos].vrd_p = -(int)resultado.vrD;
    else
        rb[pos].vrd_p = (int)resultado.vrD;

    if(((int)resultado.logica & 0x06) == 4)
        rb[pos].vre_p = (int)resultado.vrE;
    else
        rb[pos].vre_p = -(int)resultado.vrE;
    return rb;
}

Strategy::Strategy()
{
    vr1.push_back(0);
    vr1.push_back(0);

    vr1.push_back(0);
    vr1.push_back(0);

    vr1.push_back(0);
    vr1.push_back(0);

   V = 0;
   W = 0;

   f_ata = 0;

   bola_anterior.x = 0;
   bola_anterior.y = 0;

   goalkeeper = 0;
   g[0] = 1;
   g[1] = 2;
   g[2] = 3;

   ataque = 1;
   a[0] = 4;
   a[1] = 5;
   a[2] = 6;

   defensor = 2;
   z[0] = 7;
   z[1] = 8;
   z[2] = 9;

   Alteracao_jogador[0] = -1;
   Alteracao_jogador[1] = -1;
   Alteracao_jogador[2] = -1;

   flaag=1;

   contadorr = 0;
   flag_1 = 0;
   flag_2 = 0;
   flag_3 = 0;

   flag_fire = 0;
   Adicionar_atacante("Penalty_baixo",&Strategy::atacante2);
   Adicionar_zagueiro("zagueiro2",&Strategy::zagueiro2);
   Adicionar_atacante("Garrincha",&Strategy::Garrincha);
   Adicionar_atacante("Garrincha_contrario",&Strategy::Garrincha_contrario);
   Adicionar_goleiro("goleiro2",&Strategy::goleiro2);
   Adicionar_zagueiro("Calibra-",&Strategy::samuel);
   Adicionar_goleiro("Calibra-",&Strategy::samuel);
   Adicionar_atacante("Calibra-",&Strategy::samuel);
   Adicionar_atacante("CR7",&Strategy::vitoria);
   Adicionar_zagueiro("Calibra+",&Strategy::raphael);
   Adicionar_goleiro("Calibra+",&Strategy::raphael);
   Adicionar_atacante("Calibra+",&Strategy::raphael);
   Adicionar_atacante("Parado",&Strategy::parado);
   Adicionar_zagueiro("Parado",&Strategy::parado);
   Adicionar_goleiro("Parado",&Strategy::parado);
   Adicionar_zagueiro("Ricardo Rocha",&Strategy::Ricardo_rocha);
   Adicionar_zagueiro("Ricardo Rocha cont",&Strategy::Ricardo_rocha_cont);

   Adicionar_atacante("Penalty_cima",&Strategy::atacante);
   Adicionar_atacante("Griezmaan",&Strategy::griezzman);
   Adicionar_zagueiro("zagueiro",&Strategy::zagueiro);
   Adicionar_goleiro("goleiro",&Strategy::goleiro);

   Adicionar_estrategia("estrategia",&Strategy::estrategia1);
   Adicionar_estrategia("Statre_semtroca",&Strategy::estrategia);
   Adicionar_estrategia("estrategia_d",&Strategy::estrategia2);
   Adicionar_estrategia("estrategia_semtroca_d",&Strategy::estrategia5);
   Adicionar_estrategia("Posicionar",&Strategy::posicionar);
   Adicionar_estrategia("Calibra",&Strategy::calibra);
   Adicionar_estrategia("Posicionar_d",&Strategy::posicionar_d);

   Adicionar_goleiro("Paulo Victor",&Strategy::Paulo_Victor);
   Adicionar_goleiro("Paulo Victor_cont",&Strategy::Paulo_Victor_cont);

}

comandos Strategy::griezzman(Robot rb)
{
    comandos resultado;
    /*
    USAR ESSAS VARIAVEIS NO CONTROLADOR DO ATACANTE
            fis_zag_atac;
            dist_i_zag_atac;
            dist_pre_zag_atac;
            p_pre_zag_atac;
            v_pre_zag_atac;
            pbolapre_zag_atac;
*/

    ang_err angulo, angulo2, angulo3;
    double px, py;

    angulo3 = olhar(rb, campo->frightx, campo->meio_campo_y);
    px = bola.x;
    py = bola.y;
    if(bola.x < rb.get_center_robot().x)
        px = bola.x - 20;

    angulo = olhar(rb, px, py);

    if(f_ata == 1)
    {
        int var = 0;
           // se o robÃ´ estiver perto da bola e apontado para ela
        if ((distancia(rb, bola.x, bola.y) < campo->diametro_robo*1.1) & (fabs(angulo.fi) < 45))
        {
            var = 1;
            if(bola.x > rb.get_center_robot().x && fabs(angulo3.fi) < 45)
                var = 3;
        }
        if(var == 1)
        { //chutinho
            angulo = olhar(rb, bola.x, bola.y);
            px = bola.x;
            py = bola.y;

            V = V/(2*fabs(V)); //assume metade da velocidade mÃ¡xima na direÃ§ao da bola
            W = -(angulo.fi/fabs(angulo.fi));
        }
        else if(var == 3)
        { // firekick
            angulo2 = olhar(rb, campo->frightx, campo->meio_campo_y);
            px = campo->frightx;
            py = campo->meio_campo_y;
            V = controle_linear_Kamarry( rb, px, py);
            V = V/fabs(V); //assume velocidade mÃ¡xima na direÃ§ao da bola
            W = controle_angular_Kamarry(rb, px,py,1);
        }
        else
        {
            W = controle_angular_Kamarry(rb, px,py);
            V = controle_linear_Kamarry( rb, px, py);
        }
        if(bola.x < rb.get_center_robot().x - campo->diametro_robo*2)
        {
            //cout << "volta" << endl;
            f_ata = 0;
        }
    }
    else if(f_ata == 0)
    {
        if(bola.y > campo->meio_campo_y)
        {
            px = (campo->meio_campo_x + campo->lzagueiro)/2;
            py = campo->gtopy + campo->diametro_robo;
        }
        else
        {
            px = (campo->meio_campo_x + campo->lzagueiro)/2;
            py = campo->gboty - campo->diametro_robo;
        }
        if(rb.get_center_robot().x > (campo->meio_campo_x + campo->lzagueiro)/2 && rb.get_center_robot().x < campo->meio_campo_x)
        {
            if(bola.y < campo->meio_campo_y && rb.get_center_robot().y < campo->gboty)
            {
                f_ata = 2;
                //cout << "baixo" << endl;
            }
            else if(rb.get_center_robot().y > campo->gtopy)
            {
                f_ata = 3;
                //cout << "cima" << endl;
            }
        }
        W = controle_angular_Kamarry(rb, px,py);
        V = controle_linear_Kamarry(rb, px, py);
    }
    else if(f_ata == 2)
    {
        px = bola.x;
        py = bola.y;
        W = controle_angular_Kamarry(rb, px,py);
        V = 0;
        if(bola.y > campo->meio_campo_y || rb.get_center_robot().x > campo->meio_campo_x)
        {
            //cout << "volta" << endl;
            f_ata = 0;
        }
        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo*4 && rb.get_center_robot().x < bola.x)
        {
            f_ata = 1;
            //cout << "go" << endl;
        }
    }
    else
    {
        px = bola.x;
        py = bola.y;
        W = controle_angular_Kamarry(rb, px,py);
        V = 0;
        if(bola.y < campo->meio_campo_y || rb.get_center_robot().x > campo->meio_campo_x)
        {
            f_ata = 0;
            //cout << "volta" << endl;
        }
        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo*4 && rb.get_center_robot().x < bola.x)
        {
            //cout << "go" << endl;
            f_ata = 1;
        }
    }


    int flag = sairparede(rb);

    if (flag == 1)
    {
        V = -0.2;
        W = 0.2;
    }
    if (flag == 2)
    {
        V = -0.2;
        W = -0.2;
    }
    if (flag == 3)
    {
        V = 0.2;
        W = -0.2;
    }
    if (flag == 4)
    {
        V = 0.2;
        W = 0.2;
    }

    resultado = gera_comandos_vr(rb, V, W);

    return(resultado);
}

comandos Strategy::Paulo_Victor(Robot rb)
{
    ang_err angulog;

    if(bola.y > rb.get_center_robot().y)
             W = controle_angular_Kamarry(rb, campo->lgoleiro, rb.get_center_robot().y + campo->diametro_robo*3);
        else
             W = controle_angular_Kamarry(rb, campo->lgoleiro, rb.get_center_robot().y - campo->diametro_robo*3);

        V = controle_linear_Kamarry(rb,campo->lgoleiro,bola.y);
        if(bola.x < campo->lgoleiro)
            V = 10*V;

        if(rb.get_center_robot().x < campo->lgoleiro + (campo->tam_robo / 2) && rb.get_center_robot().x > campo->lgoleiro - (campo->tam_robo / 2))
        {
            V = controle_linear_Kamarry(rb,rb.get_center_robot().x,bola.y);
            if(bola.y > rb.get_center_robot().y)
                W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);
            else
                 W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y - campo->diametro_robo*3);
        }
            if(bola.y > campo->gtopy)
            {
                V = controle_linear_Kamarry(rb,campo->fleftx,campo->gtopy);
                W = controle_angular_Kamarry(rb, campo->fleftx, campo->gtopy);
            }
            if(bola.y < campo->gboty)
            {
                V =controle_linear_Kamarry(rb,campo->fleftx,campo->gboty);
                 W = controle_angular_Kamarry(rb, campo->fleftx, campo->gboty);

            }

        double ang = rb.get_orientation();
        double p1 = distancia(rb,campo->fleftx,campo->gboty);
        double p2 = distancia(rb,campo->fleftx,campo->gtopy);
        //if (((ang>-10 && ang<10) ||(ang>170)||(ang<-170)) && (p1 < 2*campo->diametro_robo || p2 < 2*campo->diametro_robo))
          //  W = 1;

        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y < rb.get_center_robot().y && bola.x > rb.get_center_robot().x - campo->tam_robo)
            W = -1;
        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y > rb.get_center_robot().y && bola.x > rb.get_center_robot().x - campo->tam_robo)
            W = 1;        

        V = 2*V;
        W = 1.05*W;
        cout << "" << rb.get_orientation() << endl;;
        comandos resultado;
        resultado = gera_comandos(rb, V, W);
        return resultado;
}

comandos Strategy::Paulo_Victor_cont(Robot rb)
{
    ang_err angulog;
        if(bola.y > rb.get_center_robot().y)
             W = controle_angular_Kamarry(rb, campo->lgoleiro, rb.get_center_robot().y + campo->diametro_robo*3);
        else
             W = controle_angular_Kamarry(rb, campo->lgoleiro, rb.get_center_robot().y - campo->diametro_robo*3);

        V = controle_linear_Kamarry(rb,campo->lgoleiro,bola.y);
        if(bola.x > campo->lgoleiro)
            V = 10*V;

        if(rb.get_center_robot().x < campo->lgoleiro + (campo->tam_robo / 2) && rb.get_center_robot().x > campo->lgoleiro - (campo->tam_robo / 2))
        {
            V = controle_linear_Kamarry(rb,rb.get_center_robot().x,bola.y);
            if(bola.y > rb.get_center_robot().y)
                W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);
            else
                 W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y - campo->diametro_robo*3);
        }
            if(bola.y > campo->gtopy)
            {
                V = controle_linear_Kamarry(rb,campo->frightx,campo->gtopy);
                W = controle_angular_Kamarry(rb, campo->frightx, campo->gtopy);

            }
            if(bola.y < campo->gboty)
            {
                V =controle_linear_Kamarry(rb,campo->frightx,campo->gboty);
                W = controle_angular_Kamarry(rb, campo->frightx, campo->gboty);

            }



        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y < rb.get_center_robot().y && bola.x > rb.get_center_robot().x - campo->tam_robo)
            W = 1;
        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y > rb.get_center_robot().y && bola.x > rb.get_center_robot().x - campo->tam_robo)
            W = -1;

        V = 2*V;
        W = 1.05*W;
        comandos resultado;
        resultado = gera_comandos_vr(rb, V, W);
        return resultado;
}

comandos Strategy::Ricardo_rocha(Robot rb)
{
    ang_err angulog;
    if(bola.y > rb.get_center_robot().y)
         W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y + campo->diametro_robo*3);
    else
         W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y - campo->diametro_robo*3);

    double l1 = bola.x - campo->fleftx;
    double l2 = bola.y - campo->meio_campo_y;
    double tg_theta = l2/l1;

    V = controle_linear_Kamarry(rb,campo->lzagueiro,bola.y);
    W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y - campo->diametro_robo*3);

    if(rb.get_center_robot().x < campo->lzagueiro + (campo->tam_robo / 2) && rb.get_center_robot().x > campo->lzagueiro - (campo->tam_robo / 2))
    {
        V = controle_linear_Kamarry(rb,rb.get_center_robot().x,bola.y);
        if(bola.y > rb.get_center_robot().y)
            W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);
        else
            W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y - campo->diametro_robo*3);
    }

    if(bola.x > campo->lzagueiro + campo->diametro_robo)
    {
        if(bola.y > campo->area_topy)
            V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->area_topy);
        if(bola.y < campo->area_boty)
            V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->area_boty);
    }
    else
    {
        if(bola.y > campo->area_topy)
        {
            V = controle_linear_Kamarry(rb,campo->fleftx,campo->area_topy);
            W = controle_angular_Kamarry(rb, campo->fleftx, campo->area_topy);

        }
        if(bola.y < campo->area_boty)
        {
            V =controle_linear_Kamarry(rb,campo->fleftx,campo->area_boty);
            W = controle_angular_Kamarry(rb, campo->fleftx, campo->area_boty);
        }
    }

    if(bola.x > campo->lzagueiro)
    {
        double y_futuro = tg_theta * (rb.get_center_robot().x - bola.x) + bola.y;
        if(bola.y > rb.get_center_robot().y)
            W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y + campo->diametro_robo*3);
        else
            W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y - campo->diametro_robo*3);
        V = controle_linear_Kamarry(rb,campo->lzagueiro,y_futuro);

        if(rb.get_center_robot().x < campo->lzagueiro + (campo->tam_robo / 2) && rb.get_center_robot().x > campo->lzagueiro - (campo->tam_robo / 2))
        {
            V = controle_linear_Kamarry(rb,rb.get_center_robot().x,y_futuro);
            if(bola.y > rb.get_center_robot().y)
               W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);
            else
               W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y - campo->diametro_robo*3);
        }
    }

    if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y < rb.get_center_robot().y && bola.x > rb.get_center_robot().x)
        W = -1;
    if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y > rb.get_center_robot().y && bola.x > rb.get_center_robot().x)
        W = 1;

    ang_err angulo = olhar(rb, bola.x, bola.y);
    if ((distancia(rb, bola.x, bola.y) < 30) & (fabs(angulo.fi) < 45))
    {
        //cout << "fire";
        if(bola.x > rb.get_center_robot().x)
        {
            //cout << "kick";
            V =  controle_linear_Kamarry(rb, bola.x, bola.y);
            V = V/fabs(V); //assume velocidade máxima na direçao da bola
            W = controle_angular_Kamarry(rb, campo->frightx, campo->meio_campo_y,1);
        }
        //cout << endl;
    }
    else
    {
        //cout << "normal" << endl;
        V = 1.5*V;
        W = 1.1*W;
    }
    comandos resultado;
    resultado = gera_comandos_vr(rb, V, W);
    return resultado;
}

comandos Strategy::Ricardo_rocha_cont(Robot rb)
{
    ang_err angulog;
    if(bola.y > rb.get_center_robot().y)
         W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y + campo->diametro_robo*3);
    else
         W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y - campo->diametro_robo*3);

    double l1 = bola.x - campo->frightx;
    double l2 = bola.y - campo->meio_campo_y;
    double tg_theta = l2/l1;

    V = controle_linear_Kamarry(rb,campo->lzagueiro,bola.y);
    W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y - campo->diametro_robo*3);

    if(rb.get_center_robot().x < campo->lzagueiro + (campo->tam_robo / 2) && rb.get_center_robot().x > campo->lzagueiro - (campo->tam_robo / 2))
    {
        V = controle_linear_Kamarry(rb,rb.get_center_robot().x,bola.y);
        if(bola.y > rb.get_center_robot().y)
            W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);
        else
            W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y - campo->diametro_robo*3);
    }

    if(bola.x < campo->lzagueiro + campo->diametro_robo)
    {
        if(bola.y > campo->area_topy)
            V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->area_topy);
        if(bola.y < campo->area_boty)
            V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->area_boty);
    }
    else
    {
        if(bola.y > campo->area_topy - campo->diametro_robo)
        {
            V = controle_linear_Kamarry(rb,campo->frightx,campo->area_topy);
            W = controle_angular_Kamarry(rb, campo->frightx, campo->area_topy);

        }
        if(bola.y < campo->area_boty + campo->diametro_robo)
        {
            V = controle_linear_Kamarry(rb,campo->frightx,campo->area_boty);
            W = controle_angular_Kamarry(rb, campo->frightx, campo->area_boty);
        }
    }

    if(bola.x < campo->lzagueiro)
    {
        double y_futuro = tg_theta * (rb.get_center_robot().x - bola.x) + bola.y;
        if(bola.y > rb.get_center_robot().y)
            W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y + campo->diametro_robo*3);
        else
            W = controle_angular_Kamarry(rb, campo->lzagueiro, rb.get_center_robot().y - campo->diametro_robo*3);
        V = controle_linear_Kamarry(rb,campo->lzagueiro,y_futuro);

        if(rb.get_center_robot().x < campo->lzagueiro + (campo->tam_robo / 2) && rb.get_center_robot().x > campo->lzagueiro - (campo->tam_robo / 2))
        {
            V = controle_linear_Kamarry(rb,rb.get_center_robot().x,y_futuro);
            if(bola.y > rb.get_center_robot().y)
               W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);
            else
               W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y - campo->diametro_robo*3);
        }
    }

    if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y < rb.get_center_robot().y && bola.x < rb.get_center_robot().x)
        W = 1;
    if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y > rb.get_center_robot().y && bola.x < rb.get_center_robot().x)
        W = -1;

    ang_err angulo = olhar(rb, bola.x, bola.y);
    if ((distancia(rb, bola.x, bola.y) < 30) & (fabs(angulo.fi) < 45))
    {
        //cout << "fire";
        if(bola.x < rb.get_center_robot().x)
        {
            //cout << "kick";
            V =  controle_linear_Kamarry(rb, bola.x, bola.y);
            V = V/fabs(V); //assume velocidade máxima na direçao da bola
            W = controle_angular_Kamarry(rb, campo->frightx, campo->meio_campo_y,1);
        }
        //cout << endl;
    }
    else
    {
        //cout << "normal" << endl;
        V = 1.5*V;
        W = 1.1*W;
    }
    comandos resultado;
    resultado = gera_comandos_vr(rb, V, W);
    return resultado;
}

comandos Strategy::Garrincha(Robot rb)
{
    comandos resultado;
        ang_err angulo, angulo2;

        angulo = olhar(rb, bola.pred[1].x, bola.pred[1].y);

        W = controle_angular_Kamarry(rb, bola.pred[1].x, bola.pred[1].y);
        V =  controle_linear_Kamarry(rb, bola.pred[1].x, bola.pred[1].y);

        // se o robô estiver perto da bola e apontado para ela
        if(bola.x > rb.get_center_robot().x - 20 && (distancia(rb, bola.x, bola.y) < 35) && flag_fire == 0)
        {
            if(bola.y > rb.get_center_robot().y)
                W = 1;
            else
                W = -1;
            if(bola.x > campo->area_right)
            {
                if(bola.y > campo->gtopy)
                    W = -1;
                if(bola.y < campo->gboty)
                    W = 1;
            }
        }

        if ((distancia(rb, bola.x, bola.y) < 35) & (fabs(angulo.fi) < 45))
        {
            V = V/(2*fabs(V)); //assume metade da velocidade máxima na direçao da bola
            W = -(angulo.fi/fabs(angulo.fi));
            if(bola.x > rb.get_center_robot().x)
            {
                if(flag_fire == 0)
                {
                    flag_fire = 1;
                    contadorr = 0;
                }
                V = V/fabs(V); //assume velocidade máxima na direçao da bola
                angulo2 = olhar(rb, campo->frightx, campo->meio_campo_y);
                if(flag_fire == 1)
                    W = controle_angular_Kamarry(rb, campo->frightx, campo->meio_campo_y);
                else
                    W = controle_angular_Kamarry(rb, campo->frightx, campo->meio_campo_y,1);
            }
        }

         if(bola.x < campo->lzagueiro)
                {
                    if(bola.y < campo->meio_campo_y)
                    {
                        W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->fbot);
                        V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->fbot);
                    }
                    else
                    {
                          W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->ftop);
                         V = controle_linear_Kamarry(rb, campo->lzagueiro, campo->ftop);
                    }
                }

             if(bola.x < campo->lzagueiro && (rb.get_center_robot().x > campo->lzagueiro - 3 && rb.get_center_robot().x < campo->lzagueiro + 20))
                {
                   W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);

                }

                if(bola.x < campo->lzagueiro && (bola.y < (campo->area_boty - campo->diametro_robo) || bola.y > (campo->area_topy + campo->diametro_robo)))
                {
                    W = controle_angular_Kamarry(rb, bola.x, bola.y);

                    V = controle_linear_Kamarry(rb,bola.x,bola.y);
                }

         int flag = sairparede(rb);

                if (flag == 1)
                {
                    V = -0.2;
                    W = 0.2;
                }
                if (flag == 2)
                {
                    V = -0.2;
                    W = -0.2;
                }
                if (flag == 3)
                {
                    V = 0.2;
                    W = -0.2;
                }
                if (flag == 4)
                {
                    V = 0.2;
                    W = 0.2;
                }

                if(flag>0){
                }
        if(flag_fire == 1)
            contadorr++;
        if(contadorr > 10)
        {
           contadorr = 0;
           flag_fire = 2;
        }

        if(flag_fire == 2 && distancia(rb,bola.x,bola.y) > 50)
            flag_fire = 0;

        //cout << "Count: " << contadorr << " Flag: " << flag_fire << endl;

        resultado = gera_comandos_vr(rb, V, W);
        return(resultado);
}

comandos Strategy::Garrincha_contrario(Robot rb)
{
    comandos resultado;
        ang_err angulo, angulo2;

        angulo = olhar(rb, bola.x, bola.y);

        W = controle_angular_Kamarry(rb, bola.x, bola.y);
        V =  controle_linear_Kamarry(rb, bola.x, bola.y);

        if(bola.x < rb.get_center_robot().x + 20 && (distancia(rb, bola.x, bola.y) < 35) && flag_fire == 0)
        {
            if(bola.y > rb.get_center_robot().y)
                W = -1;
            else
                W = 1;
            if(bola.x > campo->area_right)
            {
                if(bola.y > campo->gtopy)
                    W = 1;
                if(bola.y < campo->gboty)
                    W = -1;
            }
        }

        // se o robô estiver perto da bola e apontado para ela
         if ((distancia(rb, bola.x, bola.y) < 35) & (fabs(angulo.fi) < 45))
        {
            V = V/(2*fabs(V)); //assume metade da velocidade máxima na direçao da bola
            W = -(angulo.fi/fabs(angulo.fi));
            if(bola.x < rb.get_center_robot().x)
            {
                  V = V/fabs(V); //assume velocidade máxima na direçao da bola
                  angulo2 = olhar(rb, campo->fleftx, campo->meio_campo_y);
                  W = controle_angular_Kamarry(rb, campo->fleftx, campo->meio_campo_y,1);
            }
        }

         if(bola.x > campo->lzagueiro)
                {
                    if(bola.y < campo->meio_campo_y)
                    {
                        W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->fbot);
                        V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->fbot);
                    }
                    else
                    {
                          W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->ftop);
                         V = controle_linear_Kamarry(rb, campo->lzagueiro, campo->ftop);
                    }
                }

             if(bola.x > campo->lzagueiro && (rb.get_center_robot().x > campo->lzagueiro - 3 && rb.get_center_robot().x < campo->lzagueiro + 20))
                {
                   W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);

                }

                if(bola.x > campo->lzagueiro && (bola.y < (campo->area_boty - campo->diametro_robo) || bola.y > (campo->area_topy + campo->diametro_robo)))
                {
                    W = controle_angular_Kamarry(rb, bola.x, bola.y);

                    V = controle_linear_Kamarry(rb,bola.x,bola.y);
                }

         int flag = sairparede(rb);

                if (flag == 1)
                {
                    V = -0.2;
                    W = 0.2;
                }
                if (flag == 2)
                {
                    V = -0.2;
                    W = -0.2;
                }
                if (flag == 3)
                {
                    V = 0.2;
                    W = -0.2;
                }
                if (flag == 4)
                {
                    V = 0.2;
                    W = 0.2;
                }

                if(flag>0){
                }


        resultado = gera_comandos_vr(rb, V, W);
        return(resultado);
}

comandos Strategy::raphael(Robot rb)
{
    comandos resultado;
    V = 1;
    W = 0;
    resultado = gera_comandos(rb, V, W);
    cout << "Const: " << rb.ic_dp << " " << rb.ic_ep << endl;
    return(resultado);
}

comandos Strategy::parado(Robot rb)
{
    comandos resultado;
    //V = 0;
    //W = 0;
    //resultado = gera_comandos_vr(rb, V, W);
    resultado.vrD= 0;
    resultado.vrE= 0;
    return(resultado);
}

vector<Robot> parar(vector<Robot> robos)
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;
    envia_comandos_robo(str);

    robos[0].vrd_p = 0;
    robos[1].vrd_p = 0;
    robos[2].vrd_p = 0;
    robos[0].vre_p = 0;
    robos[1].vre_p = 0;
    robos[2].vre_p = 0;
    return robos;
}

comandos Strategy::atacante(Robot rb)
{
        comandos resultado;
            ang_err angulo, angulo2;

            angulo = olhar(rb, bola.x, bola.y);

            W = controle_angular_Kamarry(rb, bola.x, bola.y);
            V =  controle_linear_Kamarry(rb, bola.x, bola.y);

            // se o robô estiver perto da bola e apontado para ela
            if ((distancia(rb, bola.x, bola.y) < 35) & (fabs(angulo.fi) < 45))
            {
                V = V/(2*fabs(V)); //assume metade da velocidade máxima na direçao da bola
                W = -(angulo.fi/fabs(angulo.fi));
                if(bola.x > rb.get_center_robot().x - 20)
                {
                    if(bola.y > rb.get_center_robot().y)
                        W = 1;
                    else
                        W = -1;
                    if(bola.x > campo->area_right)
                    {
                        if(bola.y > campo->gtopy)
                            W = -1;
                        if(bola.y < campo->gboty)
                            W = 1;
                    }
                }
                if(bola.x > rb.get_center_robot().x)
                {
                    if(flag_fire == 0)
                    {
                        flag_fire = 1;
                        contadorr = 0;
                    }
                    V = V/fabs(V); //assume velocidade máxima na direçao da bola
                    angulo2 = olhar(rb, campo->frightx, campo->meio_campo_y);
                    if(flag_fire == 1)
                        W = controle_angular_Kamarry(rb, campo->gright, campo->gtopy);
                    else
                        W = controle_angular_Kamarry(rb, campo->gright, campo->gtopy,1);
                }
            }

             if(bola.x < campo->lzagueiro)
                    {
                        if(bola.y < campo->meio_campo_y)
                        {
                            W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->fbot);
                            V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->fbot);
                        }
                        else
                        {
                              W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->ftop);
                             V = controle_linear_Kamarry(rb, campo->lzagueiro, campo->ftop);
                        }
                    }

                 if(bola.x < campo->lzagueiro && (rb.get_center_robot().x > campo->lzagueiro - 3 && rb.get_center_robot().x < campo->lzagueiro + 20))
                    {
                       W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);

                    }

                    if(bola.x < campo->lzagueiro && (bola.y < (campo->area_boty - campo->diametro_robo) || bola.y > (campo->area_topy + campo->diametro_robo)))
                    {
                        W = controle_angular_Kamarry(rb, bola.x, bola.y);

                        V = controle_linear_Kamarry(rb,bola.x,bola.y);
                    }

             int flag = sairparede(rb);

                    if (flag == 1)
                    {
                        V = -0.2;
                        W = 0.2;
                    }
                    if (flag == 2)
                    {
                        V = -0.2;
                        W = -0.2;
                    }
                    if (flag == 3)
                    {
                        V = 0.2;
                        W = -0.2;
                    }
                    if (flag == 4)
                    {
                        V = 0.2;
                        W = 0.2;
                    }

                    if(flag>0){
                    }
            if(flag_fire == 1)
                contadorr++;
            if(contadorr > 5)
            {
               contadorr = 0;
               flag_fire = 2;
            }

            if(flag_fire == 2 && distancia(rb,bola.x,bola.y) > 50)
                flag_fire = 0;

            cout << "Count: " << contadorr << " Flag: " << flag_fire << endl;

            resultado = gera_comandos_vr(rb, V, W);
            return(resultado);

}

comandos Strategy::atacante2(Robot rb)
{
    comandos resultado;
        ang_err angulo, angulo2;

        angulo = olhar(rb, bola.x, bola.y);

        W = controle_angular_Kamarry(rb, bola.x, bola.y);
        V =  controle_linear_Kamarry(rb, bola.x, bola.y);

        // se o robô estiver perto da bola e apontado para ela
         if ((distancia(rb, bola.x, bola.y) < 35) & (fabs(angulo.fi) < 45))
        {
            V = V/(2*fabs(V)); //assume metade da velocidade máxima na direçao da bola
            W = -(angulo.fi/fabs(angulo.fi));
            if(bola.x > rb.get_center_robot().x - 20)
            {
                if(bola.y > rb.get_center_robot().y)
                    W = 1;
                else
                    W = -1;
                if(bola.x > campo->area_right)
                {
                    if(bola.y > campo->gtopy)
                        W = -1;
                    if(bola.y < campo->gboty)
                        W = 1;
                }
            }
            if(bola.x > rb.get_center_robot().x)
            {
                if(flag_fire == 0)
                {
                    flag_fire = 1;
                    contadorr = 0;
                }
                V = V/fabs(V); //assume velocidade máxima na direçao da bola
                angulo2 = olhar(rb, campo->frightx, campo->meio_campo_y);
                if(flag_fire == 1)
                    W = controle_angular_Kamarry(rb, campo->gright, campo->gboty);
                else
                    W = controle_angular_Kamarry(rb, campo->gright, campo->gboty,1);
            }
        }

         if(bola.x < campo->lzagueiro)
                {
                    if(bola.y < campo->meio_campo_y)
                    {
                        W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->fbot);
                        V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->fbot);
                    }
                    else
                    {
                          W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->ftop);
                         V = controle_linear_Kamarry(rb, campo->lzagueiro, campo->ftop);
                    }
                }

             if(bola.x < campo->lzagueiro && (rb.get_center_robot().x > campo->lzagueiro - 3 && rb.get_center_robot().x < campo->lzagueiro + 20))
                {
                   W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);

                }

                if(bola.x < campo->lzagueiro && (bola.y < (campo->area_boty - campo->diametro_robo) || bola.y > (campo->area_topy + campo->diametro_robo)))
                {
                    W = controle_angular_Kamarry(rb, bola.x, bola.y);

                    V = controle_linear_Kamarry(rb,bola.x,bola.y);
                }

         int flag = sairparede(rb);

                if (flag == 1)
                {
                    V = -0.2;
                    W = 0.2;
                }
                if (flag == 2)
                {
                    V = -0.2;
                    W = -0.2;
                }
                if (flag == 3)
                {
                    V = 0.2;
                    W = -0.2;
                }
                if (flag == 4)
                {
                    V = 0.2;
                    W = 0.2;
                }

                if(flag>0){
                }
        if(flag_fire == 1)
            contadorr++;
        if(contadorr > 5)
        {
           contadorr = 0;
           flag_fire = 2;
        }

        if(flag_fire == 2 && distancia(rb,bola.x,bola.y) > 50)
            flag_fire = 0;

        cout << "Count: " << contadorr << " Flag: " << flag_fire << endl;

        resultado = gera_comandos_vr(rb, V, W);
        return(resultado);

}

comandos Strategy::goleiro2(Robot rb)
{
    comandos resultado;
    ang_err angulo;

    angulo = olhar(rb, bola.x, bola.y);


    W = controle_angular_Kamarry(rb,550,400);

    V = controle_linear_Kamarry(rb, 550,400);



    resultado = gera_comandos_vr(rb, V, W);

    return(resultado);
}

comandos Strategy::vitoria(Robot rb)
{
    float angulo_bola;
    comandos resultado;
        ang_err angulo, angulo2;

        if (bola.x>rb.get_center_robot().x) // bola depois do robo, devo pegar o preditor curto ou so bola, dependendo do angulo da trajetoria dela
        {
            angulo_bola = atan((bola.pred[0].y-bola.y)/(bola.pred[0].x-bola.x+0.001))*180/3.14159265;
            if ((angulo_bola<45 && angulo_bola>0) || (angulo_bola > -45 && angulo_bola<0)) // se a bola estiver numa trajetoria suficientemente horizontal
            {
                angulo = olhar(rb, bola.x, bola.y);
                W = controle_angular_Kamarry(rb, bola.x, bola.y);
                V = controle_linear_Kamarry(rb, bola.x, bola.y);
            }
            else
            {
                angulo = olhar(rb, bola.pred[0].x, bola.pred[0].y);

                W = controle_angular_Kamarry(rb, bola.pred[0].x, bola.pred[0].y);
                V = controle_linear_Kamarry(rb, bola.pred[0].x, bola.pred[0].y);
            }
        }
        else // bola antes do robo, jogada defensiva, usar preditor longo
        {
            angulo = olhar(rb, bola.pred[2].x, bola.pred[2].y);

            W = controle_angular_Kamarry(rb, bola.pred[2].x, bola.pred[2].y);
            V = controle_linear_Kamarry(rb, bola.pred[2].x, bola.pred[2].y);
        }


        // se o robô estiver perto da bola e apontado para ela
        if(bola.x > (rb.get_center_robot().x - campo->diametro_robo*0.4) && (distancia(rb, bola.x, bola.y) < campo->diametro_robo*0.7) && flag_fire == 0)
        {
            if(bola.y < campo->area_boty)
            {
                W = 1;
            }
            else if(bola.y > campo->area_topy)
            {
                W = -1;
            }
            else
            {
                angulo2 = olhar(rb, campo->frightx, rb.get_center_robot().y);
                if(bola.y < campo->meio_campo_y)
                {
                    cout << "Baixo" << endl;
                    if(angulo2.fi > 20)
                        W = 1;
                    else
                        W = -1;
                }
                else
                {
                    cout << "Cima" << endl;
                    if(angulo2.fi > 20)
                        W = -1;
                    else
                        W = 1;
                }
            }
            if(bola.x > campo->area_right)
            {
                if(bola.y > campo->gtopy)
                    W = -1;
                if(bola.y < campo->gboty)
                    W = 1;
            }
        }

        angulo2 = olhar(rb, campo->frightx, campo->meio_campo_y);
        if ((bola.x > rb.get_center_robot().x) & (distancia(rb, bola.x, bola.y) < campo->diametro_robo) & (fabs(angulo.fi) < 45) & (fabs(angulo2.fi) < 45) )
        {
            V = V/(2*fabs(V)); //assume metade da velocidade máxima na direçao da bola
            W = -(angulo.fi/fabs(angulo.fi));
            if(bola.x > rb.get_center_robot().x)
            {
                if(flag_fire == 0)
                {
                    flag_fire = 1;
                    contadorr = 0;
                }
                V = V/fabs(V); //assume velocidade máxima na direçao da bola
                if(flag_fire == 1)
                    W = controle_angular_Kamarry(rb, campo->frightx, campo->meio_campo_y);
                else
                    W = controle_angular_Kamarry(rb, campo->frightx, campo->meio_campo_y,1);
            }
        }

        if(bola.x < campo->lzagueiro)
        {
            if(bola.y < campo->meio_campo_y)
            {
                W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->fbot);
                V = controle_linear_Kamarry(rb,campo->lzagueiro,campo->fbot);
            }
            else
            {
                 W = controle_angular_Kamarry(rb, campo->lzagueiro, campo->ftop);
                 V = controle_linear_Kamarry(rb, campo->lzagueiro, campo->ftop);
            }
        }

        if(bola.x < campo->lzagueiro && (rb.get_center_robot().x > campo->lzagueiro - 3 && rb.get_center_robot().x < campo->lzagueiro + 20))
        {
            W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3);
        }

        if(bola.x < campo->lzagueiro && (bola.y < (campo->area_boty - campo->diametro_robo) || bola.y > (campo->area_topy + campo->diametro_robo)))
        {
            W = controle_angular_Kamarry(rb, bola.pred[1].x, bola.pred[1].y);
            V = controle_linear_Kamarry(rb,bola.pred[1].x,bola.pred[1].y);
        }

        int flag = sairparede(rb);

        if (flag == 1)
        {
            V = -0.2;
            W = 0.2;
        }
        if (flag == 2)
        {
            V = -0.2;
            W = -0.2;
        }
        if (flag == 3)
        {
            V = 0.2;
            W = -0.2;
        }
        if (flag == 4)
        {
            V = 0.2;
            W = 0.2;
        }

        if(flag>0) // perto da parede de alguma forma
        {
            //Vou usar isso pra, se a bola estiver entre o robo e a parede, o robo gira no sentido mais conveniente!!
            if (distancia(rb, bola.x, bola.y)<campo->diametro_robo)
            {
                if (bola.y > campo->meio_campo_y) // bola acima do meio de campo
                {
                    W = 1;
                }
                else
                {
                    W = -1;
                }
            }
            else
            {

            }
        }


        if(flag_fire == 1)
            contadorr++;

        if(contadorr > 10)
        {
           contadorr = 0;
           flag_fire = 2;
        }

        if(flag_fire == 2 && distancia(rb,bola.x,bola.y) > 50)
            flag_fire = 0;

        //cout << "Count: " << contadorr << " Flag: " << flag_fire << endl;

        resultado = gera_comandos(rb, V, W);
        return(resultado);
}

comandos Strategy::samuel(Robot rb)
{
    comandos resultado;
    V = -1;
    W = 0;
    resultado = gera_comandos(rb, V, W);
    cout << "Const: " << rb.ic_dp << " " << rb.ic_ep << endl;
    return(resultado);
}

comandos Strategy::goleiro(Robot rb)
{
    ang_err angulog;

    double l1 = bola.x - bola_anterior.x;
    double l2 = bola.y - bola_anterior.y;

    cout << v_max_filp << " " << w_max_filp << endl;

        if(bola.y > rb.get_center_robot().y)
             W = controle_angular_Kamarry(rb, campo->lgoleiro, rb.get_center_robot().y + campo->diametro_robo*3,w_max_filp);
        else
             W = controle_angular_Kamarry(rb, campo->lgoleiro, rb.get_center_robot().y - campo->diametro_robo*3,w_max_filp);

        V = controle_linear_Kamarry(rb,campo->lgoleiro,bola.y,v_max_filp);

        if(rb.get_center_robot().x < campo->lgoleiro + (campo->tam_robo / 2) && rb.get_center_robot().x > campo->lgoleiro - (campo->tam_robo / 2))
        {
            V = controle_linear_Kamarry(rb,rb.get_center_robot().x,bola.y,v_max_filp);
            if(bola.y > rb.get_center_robot().y)
                W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y + campo->diametro_robo*3,w_max_filp);
            else
                W = controle_angular_Kamarry(rb, rb.get_center_robot().x, rb.get_center_robot().y - campo->diametro_robo*3,w_max_filp);
        }
        if(bola.x > campo->lgoleiro + campo->diametro_robo)
        {
            if(bola.y > campo->gtopy)
                V = controle_linear_Kamarry(rb,campo->lgoleiro,campo->gtopy,v_max_filp);
            if(bola.y < campo->gboty)
                V = controle_linear_Kamarry(rb,campo->lgoleiro,campo->gboty,v_max_filp);
        }
        else
        {
            if(bola.y > campo->gtopy)
            {
                V = controle_linear_Kamarry(rb,campo->lgoleiro,campo->gtopy,v_max_filp);
                W = controle_angular_Kamarry(rb, campo->lgoleiro, campo->gtopy,w_max_filp);

            }
            if(bola.y < campo->gboty)
            {
                V =controle_linear_Kamarry(rb,campo->lgoleiro,campo->gboty,v_max_filp);
                W = controle_angular_Kamarry(rb, campo->lgoleiro, campo->gboty,w_max_filp);
            }
        }



        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y < rb.get_center_robot().y && bola.x > rb.get_center_robot().x - campo->tam_robo)
            W = -1;
        if(distancia(rb,bola.x,bola.y) < campo->diametro_robo && bola.y > rb.get_center_robot().y && bola.x > rb.get_center_robot().x - campo->tam_robo)
            W = 1;

        V = 2*V;
        W = 1.05*W;
        comandos resultado;
        resultado = gera_comandos_vr(rb, V, W);
        return resultado;
}

comandos Strategy::zagueiro2(Robot rb)
{
    comandos resultado;
    ang_err angulo;

    angulo = olhar(rb, bola.x, bola.y);

    W = controle_angular_Kamarry(rb,campo->lzagueiro,bola.y);

    V = controle_linear_Kamarry(rb,campo->lzagueiro,bola.y);

    //V=0;
    //W=0.5;

    resultado = gera_comandos_vr(rb, V, W);

    return(resultado);
}

comandos Strategy::zagueiro(Robot rb)
{
    comandos resultado;
    ang_err angulo;

    angulo = olhar(rb, bola.x, bola.y);

    W = controle_angular_Kamarry(rb,370,381);

    V = controle_linear_Kamarry(rb, 370,381);

    resultado = gera_comandos_vr(rb, V, W);

    return(resultado);
}

void Strategy::estrategia1()
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;

    //DEFINIR JOGADORES DEFAULT
   Atacante = base_Atacantes[0];
   Goleiro  = base_Goleiros [0];
   Zagueiro = base_Zagueiros[0];

   Permitir_alteracao_usuario();

   //CHAMAR A FUNCAO DE ATACANTE DESSA FORMA
  // (this->*Atacante)();

   int aux;

   if( robos[defensor].get_center_robot().y < campo->gtopy && robos[defensor].get_center_robot().y > campo->gboty &&
       robos[defensor].get_center_robot().x < robos[goalkeeper].get_center_robot().x)
   {
      /* double fis_aux;
       double dist_i_aux;
       double dist_pre_aux;
       double p_pre_atac;
       double v_pre_atac;
       double pbolapre_atac;*/

       aux = defensor;

       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y > campo->gtopy && robos[defensor].get_center_robot().x < campo->area_left && robos[goalkeeper].get_center_robot().y > robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y < campo->gboty && robos[defensor].get_center_robot().x < campo->area_left && robos[goalkeeper].get_center_robot().y < robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }

   if(bola.x > campo->lzagueiro && robos[ataque].get_center_robot().x > bola.x  && robos[defensor].get_center_robot().x < bola.x && distancia(robos[defensor],bola.x,bola.y) < campo->diametro_robo*2)
   {
       swap(robos[defensor].V_max,robos[ataque].V_max);
       swap(robos[defensor].W_max,robos[ataque].W_max);
       double d[3];
       for(int i = 0; i < 3; i++)
           d[i] = sqrt(pow((adversarios[i].x - bola.x),2) + pow((adversarios[i].y - bola.y),2));
       double d1 = distancia(robos[defensor], bola.x, bola.y);
       if(d1 < d[0] && d1 < d[1] && d1 < d[2])
       {
            aux = defensor;
            defensor = ataque;
            ataque = aux;
       }
   }

  int ga,at,df;
  if(goalkeeper == 0)
  {
      ga = 1;
      if(ataque == 1)
      {
           at = 4;
           df = 7;
      }
      else
      {
           at = 7;
           df = 4;
      }
  }
  else if(goalkeeper == 1)
  {
      ga = 4;
      if(ataque == 0)
      {
           at = 1;
           df = 7;
      }
      else
      {
           at = 7;
           df = 1;
      }
  }
  else
  {
      ga = 7;
      if(ataque == 1)
      {
           at = 4;
           df = 1;
      }
      else
      {
           at = 1;
           df = 4;
      }
  }

  for(int i = 0; i < 3;i++)
  {
        g[i] = ga++;
        a[i] = at++;
        z[i] = df++;
  }

  robos[defensor].V_max = this->vm3;
  robos[ataque].V_max = this->vm2;
  robos[goalkeeper].V_max = this->vm1;

  cout << robos[1].V_max <<endl;
  resultado = (this->*Zagueiro)(robos[defensor]); // robô 2
  robos = rec_sign(robos,resultado,defensor);
  //cout << "Defensor: " << robos[defensor].vrd_p << " " << robos[defensor].vre_p << endl;

   str[z[0]] = resultado.logica; //lógica
   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   resultado = (this->*Goleiro)(robos[goalkeeper]); //robo 0
   robos = rec_sign(robos,resultado,goalkeeper);
   //cout << "Goleiro: " << robos[goalkeeper].vrd_p << " " << robos[goalkeeper].vre_p << endl;

   str[g[0]] = resultado.logica; //lógica
   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   resultado = (this->*Atacante)(robos[ataque]); // robo 1
   robos = rec_sign(robos,resultado,ataque);
   //cout << "Ataque: " << robos[ataque].vrd_p << " " << robos[ataque].vre_p << endl;

   str[a[0]] = resultado.logica; //lógica
   str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   if(distancia(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //defensor e goleiro
   {
           int flag = larga_robos(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[goalkeeper], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       for(int i = 0; i < 3; i++)
       {
           if(distancia(robos[defensor], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[defensor], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[defensor],adversarios[i].x,adversarios[i].y);
                   str[z[0]] = resultado.logica; //lógica
                   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           ang_err ang = olhar(robos[ataque],bola.x,bola.y);
           if(distancia(robos[ataque], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo) //defensor e goleiro
           {
                   if(distancia(robos[ataque], bola.x, bola.y) > campo->diametro_robo*2)
                   {
                        resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                        str[a[0]] = resultado.logica; //lógica
                        str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                        str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
                   else if (distancia(robos[ataque], bola.x, bola.y) <= campo->diametro_robo*2 && fabs(ang.fi) < 45 && distancia(robos[ataque],bola.x,bola.y) < campo->diametro_robo)
                   {
                       resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                       str[a[0]] = resultado.logica; //lógica
                       str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                       str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
           }

           if(distancia(robos[goalkeeper], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[goalkeeper], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[goalkeeper],adversarios[i].x,adversarios[i].y);
                   str[g[0]] = resultado.logica; //lógica
                   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

      envia_comandos_robo(str);

   bola_anterior.x = bola.x;
   bola_anterior.y = bola.y;
}

void Strategy::posicionar()
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;

    W = controle_angular_Kamarry(robos[defensor], campo->lzagueiro, campo->meio_campo_y);
    V = controle_linear_Kamarry(robos[defensor], campo->lzagueiro, campo->meio_campo_y);

    if(distancia(robos[defensor],robos[goalkeeper].get_center_robot().x,robos[goalkeeper].get_center_robot().y) < 2*campo->diametro_robo)
    {
        if(robos[defensor].get_center_robot().x > robos[goalkeeper].get_center_robot().x)
        {
            if(robos[defensor].get_center_robot().y > robos[goalkeeper].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+50);
                V = controle_linear_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+50);
            }
            else
            {
                W = controle_angular_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-50);
                V = controle_linear_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-50);
            }
        }
        else
        {
            if(robos[defensor].get_center_robot().y > robos[goalkeeper].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+50);
                V = controle_linear_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+50);
            }
            else
            {
                W = controle_angular_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-50);
                V = controle_linear_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-50);
            }
        }
    }

    if(distancia(robos[defensor],robos[ataque].get_center_robot().x,robos[ataque].get_center_robot().y) < 2*campo->diametro_robo)
    {
        if(robos[defensor].get_center_robot().x > robos[ataque].get_center_robot().x)
        {
            if(robos[defensor].get_center_robot().y > robos[ataque].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + 2*campo->diametro_robo, robos[ataque].get_center_robot().y+50);
                V = controle_linear_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + 2*campo->diametro_robo, robos[ataque].get_center_robot().y+50);
            }
            else
            {
                W = controle_angular_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + 2*campo->diametro_robo, robos[ataque].get_center_robot().y-50);
                V = controle_linear_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + 2*campo->diametro_robo, robos[ataque].get_center_robot().y-50);
            }
        }
        else
        {
            if(robos[defensor].get_center_robot().y > robos[ataque].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[defensor], robos[ataque].get_center_robot().x - 2*campo->diametro_robo, robos[ataque].get_center_robot().y+50);
                V = controle_linear_Kamarry(robos[defensor], robos[ataque].get_center_robot().x - 2*campo->diametro_robo, robos[ataque].get_center_robot().y+50);
            }
            else
            {
                W = controle_angular_Kamarry(robos[defensor], robos[ataque].get_center_robot().x - 2*campo->diametro_robo, robos[ataque].get_center_robot().y-50);
                V = controle_linear_Kamarry(robos[defensor], robos[ataque].get_center_robot().x - 2*campo->diametro_robo, robos[ataque].get_center_robot().y-50);
            }
        }
    }

    if(distancia(robos[defensor],campo->lzagueiro,campo->meio_campo_y) < campo->diametro_robo)
    {
        W = controle_angular_Kamarry(robos[defensor],robos[defensor].get_center_robot().x, campo->ftop);
        V = 0;
        flag_2 = 1;
    }
    else if(distancia(robos[defensor],campo->lzagueiro,campo->meio_campo_y) > 2*campo->diametro_robo && flag_2 == 1)
        flag_2 = 0;

    int flag = sairparede(robos[defensor]);

    if (flag == 1)
    {
        V = -0.2;
        W = 0.2;
    }
    if (flag == 2)
    {
        V = -0.2;
        W = -0.2;
    }
    if (flag == 3)
    {
        V = 0.2;
        W = -0.2;
    }
    if (flag == 4)
    {
        V = 0.2;
        W = 0.2;
    }

    resultado = gera_comandos_vr(robos[defensor], V, W);

    str[z[0]] = resultado.logica; //lógica
    str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
    str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

    W = controle_angular_Kamarry(robos[goalkeeper], campo->lgoleiro, campo->meio_campo_y);
    V = controle_linear_Kamarry(robos[goalkeeper], campo->lgoleiro, campo->meio_campo_y);

    if(distancia(robos[goalkeeper],campo->lgoleiro,campo->meio_campo_y) < campo->diametro_robo)
    {
        W = controle_angular_Kamarry(robos[goalkeeper],robos[goalkeeper].get_center_robot().x, campo->ftop);
        V = 0;
        flag_1 = 1;
    }
    else if(distancia(robos[goalkeeper],campo->lgoleiro,campo->meio_campo_y) > 2*campo->diametro_robo && flag_1 == 1)
        flag_1 = 0;

    flag = sairparede(robos[goalkeeper]);

    if (flag == 1)
    {
        V = -0.2;
        W = 0.2;
    }
    if (flag == 2)
    {
        V = -0.2;
        W = -0.2;
    }
    if (flag == 3)
    {
        V = 0.2;
        W = -0.2;
    }
    if (flag == 4)
    {
        V = 0.2;
        W = 0.2;
    }

    resultado = gera_comandos_vr(robos[goalkeeper], V, W);

    str[g[0]] = resultado.logica; //lógica
    str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
    str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

    W = controle_angular_Kamarry(robos[ataque], campo->meio_campo_x - campo->fleftx, campo->meio_campo_y);
    V = controle_linear_Kamarry(robos[ataque], campo->meio_campo_x - campo->fleftx, campo->meio_campo_y);

    if(distancia(robos[ataque],robos[goalkeeper].get_center_robot().x,robos[goalkeeper].get_center_robot().y) < 2*campo->diametro_robo)
    {
        if(robos[ataque].get_center_robot().x > robos[goalkeeper].get_center_robot().x)
        {
            if(robos[ataque].get_center_robot().y > robos[goalkeeper].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
                V = controle_linear_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
            }
            else
            {
                W = controle_angular_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
                V = controle_linear_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x + 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
            }
        }
        else
        {
            if(robos[ataque].get_center_robot().y > robos[goalkeeper].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
                V = controle_linear_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
            }
            else
            {
                W = controle_angular_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
                V = controle_linear_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - 2*campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
            }
        }
    }

    if(distancia(robos[ataque],campo->meio_campo_x - campo->fleftx,campo->meio_campo_y) < campo->diametro_robo)
    {
        W = controle_angular_Kamarry(robos[goalkeeper],robos[goalkeeper].get_center_robot().x, campo->ftop);
        V = 0;
        flag_3 = 1;
    }
    else if(distancia(robos[ataque],campo->meio_campo_x - campo->fleftx,campo->meio_campo_y) > 2*campo->diametro_robo && flag_3 == 1)
        flag_3 = 0;

    flag = sairparede(robos[ataque]);

    if (flag == 1)
    {
        V = -0.2;
        W = 0.2;
    }
    if (flag == 2)
    {
        V = -0.2;
        W = -0.2;
    }
    if (flag == 3)
    {
        V = 0.2;
        W = -0.2;
    }
    if (flag == 4)
    {
        V = 0.2;
        W = 0.2;
    }

    resultado = gera_comandos(robos[ataque], V, W);

    str[a[0]] = resultado.logica; //lógica
    str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
    str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

    for(int i = 0; i < 3; i++)
    {
        if(distancia(robos[defensor], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[defensor], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
        {
            resultado = deslargar(robos[defensor],adversarios[i].x,adversarios[i].y);
            str[z[0]] = resultado.logica; //lógica
            str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
            str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
        }
        ang_err ang = olhar(robos[ataque],bola.x,bola.y);
        if(distancia(robos[ataque], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo) //defensor e goleiro
        {
            if(distancia(robos[ataque], bola.x, bola.y) > campo->diametro_robo*2)
            {
                resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                str[a[0]] = resultado.logica; //lógica
                str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
            }
            else if (distancia(robos[ataque], bola.x, bola.y) <= campo->diametro_robo*2 && fabs(ang.fi) < 45 && distancia(robos[ataque],bola.x,bola.y) < campo->diametro_robo)
            {
                resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                str[a[0]] = resultado.logica; //lógica
                str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
            }
        }
        if(distancia(robos[goalkeeper], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[goalkeeper], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
        {
            resultado = deslargar(robos[goalkeeper],adversarios[i].x,adversarios[i].y);
            str[g[0]] = resultado.logica; //lógica
            str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
            str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
        }
    }
    envia_comandos_robo(str);
}

void Strategy::calibra()
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;

    //DEFINIR JOGADORES DEFAULT
   Atacante = base_Atacantes[0];
   Goleiro  = base_Goleiros [0];
   Zagueiro = base_Zagueiros[0];

   Permitir_alteracao_usuario();


    resultado = (this->*Zagueiro)(robos[defensor]); // robô 2

     str[z[0]] = resultado.logica; //lógica
     str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
     str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

     resultado = (this->*Goleiro)(robos[goalkeeper]); //robo 0

     str[g[0]] = resultado.logica; //lógica
     str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
     str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

     resultado = (this->*Atacante)(robos[ataque]); // robo 1

     str[a[0]] = resultado.logica; //lógica
     str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
     str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

    envia_comandos_robo(str);
}

void Strategy::posicionar_d()
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;

    W = controle_angular_Kamarry(robos[defensor], campo->area_right - campo->fleftx, campo->meio_campo_y);
    V = controle_linear_Kamarry(robos[defensor], campo->area_right - campo->fleftx, campo->meio_campo_y);

    if(distancia(robos[defensor],robos[goalkeeper].get_center_robot().x,robos[goalkeeper].get_center_robot().y) < 2*campo->diametro_robo)
    {
            if(robos[defensor].get_center_robot().y > robos[goalkeeper].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
                V = controle_linear_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
            }
            else
            {
                W = controle_angular_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
                V = controle_linear_Kamarry(robos[defensor], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
            }
    }

    if(distancia(robos[defensor],robos[ataque].get_center_robot().x,robos[ataque].get_center_robot().y) < 2*campo->diametro_robo)
    {
            if(robos[defensor].get_center_robot().y > robos[ataque].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + campo->diametro_robo, robos[ataque].get_center_robot().y+campo->area_boty);
                V = controle_linear_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + campo->diametro_robo, robos[ataque].get_center_robot().y+campo->area_boty);
            }
            else
            {
                W = controle_angular_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + campo->diametro_robo, robos[ataque].get_center_robot().y-campo->area_boty);
                V = controle_linear_Kamarry(robos[defensor], robos[ataque].get_center_robot().x + campo->diametro_robo, robos[ataque].get_center_robot().y-campo->area_boty);
            }
    }

    if(distancia(robos[defensor],campo->area_right - campo->fleftx,campo->meio_campo_y) < campo->diametro_robo)
    {
        W = controle_angular_Kamarry(robos[defensor],robos[defensor].get_center_robot().x, campo->ftop);
        V = 0;
        flag_2 = 1;
    }
    else if(distancia(robos[defensor],campo->area_right - campo->fleftx,campo->meio_campo_y) > 2*campo->diametro_robo && flag_2 == 1)
        flag_2 = 0;

    int flag = sairparede(robos[defensor]);

    if (flag == 1)
    {
        V = -0.2;
        W = 0.2;
    }
    if (flag == 2)
    {
        V = -0.2;
        W = -0.2;
    }
    if (flag == 3)
    {
        V = 0.2;
        W = -0.2;
    }
    if (flag == 4)
    {
        V = 0.2;
        W = 0.2;
    }

    resultado = gera_comandos_vr(robos[defensor], V, W);

    str[z[0]] = resultado.logica; //lógica
    str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
    str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

    W = controle_angular_Kamarry(robos[goalkeeper], campo->frightx - campo->diametro_robo, campo->meio_campo_y);
    V = controle_linear_Kamarry(robos[goalkeeper], campo->frightx - campo->diametro_robo, campo->meio_campo_y);

    if(distancia(robos[goalkeeper],campo->frightx - campo->diametro_robo,campo->meio_campo_y) < campo->diametro_robo)
    {
        W = controle_angular_Kamarry(robos[goalkeeper],robos[goalkeeper].get_center_robot().x, campo->ftop);
        V = 0;
        flag_1 = 1;
    }
    else if(distancia(robos[goalkeeper],campo->frightx - campo->diametro_robo,campo->meio_campo_y) > 2*campo->diametro_robo && flag_1 == 1)
        flag_1 = 0;

    flag = sairparede(robos[goalkeeper]);

    if (flag == 1)
    {
        V = -0.2;
        W = 0.2;
    }
    if (flag == 2)
    {
        V = -0.2;
        W = -0.2;
    }
    if (flag == 3)
    {
        V = 0.2;
        W = -0.2;
    }
    if (flag == 4)
    {
        V = 0.2;
        W = 0.2;
    }

    resultado = gera_comandos_vr(robos[goalkeeper], V, W);

    str[g[0]] = resultado.logica; //lógica
    str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
    str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

    W = controle_angular_Kamarry(robos[ataque], campo->meio_campo_x + campo->fleftx, campo->meio_campo_y);
    V = controle_linear_Kamarry(robos[ataque], campo->meio_campo_x + campo->fleftx, campo->meio_campo_y);

    if(distancia(robos[ataque],robos[goalkeeper].get_center_robot().x,robos[goalkeeper].get_center_robot().y) < 2*campo->diametro_robo)
    {
            if(robos[ataque].get_center_robot().y > robos[goalkeeper].get_center_robot().y)
            {
                W = controle_angular_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
                V = controle_linear_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y+campo->area_boty);
            }
            else
            {
                W = controle_angular_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
                V = controle_linear_Kamarry(robos[ataque], robos[goalkeeper].get_center_robot().x - campo->diametro_robo, robos[goalkeeper].get_center_robot().y-campo->area_boty);
            }
    }

    if(distancia(robos[ataque],campo->meio_campo_x + campo->fleftx,campo->meio_campo_y) < campo->diametro_robo)
    {
        W = controle_angular_Kamarry(robos[goalkeeper],robos[goalkeeper].get_center_robot().x, campo->ftop);
        V = 0;
        flag_3 = 1;
    }
    else if(distancia(robos[ataque],campo->meio_campo_x + campo->fleftx,campo->meio_campo_y) > 2*campo->diametro_robo && flag_3 == 1)
        flag_3 = 0;

    flag = sairparede(robos[ataque]);

    if (flag == 1)
    {
        V = -0.2;
        W = 0.2;
    }
    if (flag == 2)
    {
        V = -0.2;
        W = -0.2;
    }
    if (flag == 3)
    {
        V = 0.2;
        W = -0.2;
    }
    if (flag == 4)
    {
        V = 0.2;
        W = 0.2;
    }

    resultado = gera_comandos_vr(robos[ataque], V, W);

    str[a[0]] = resultado.logica; //lógica
    str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
    str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

    for(int i = 0; i < 3; i++)
    {
        if(distancia(robos[defensor], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[defensor], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
        {
            resultado = deslargar(robos[defensor],adversarios[i].x,adversarios[i].y);
            str[z[0]] = resultado.logica; //lógica
            str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
            str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
        }
        ang_err ang = olhar(robos[ataque],bola.x,bola.y);
        if(distancia(robos[ataque], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo) //defensor e goleiro
        {
            if(distancia(robos[ataque], bola.x, bola.y) > campo->diametro_robo*2)
            {
                resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                str[a[0]] = resultado.logica; //lógica
                str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
            }
            else if (distancia(robos[ataque], bola.x, bola.y) <= campo->diametro_robo*2 && fabs(ang.fi) < 45 && distancia(robos[ataque],bola.x,bola.y) < campo->diametro_robo)
            {
                resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                str[a[0]] = resultado.logica; //lógica
                str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
            }
        }
        if(distancia(robos[goalkeeper], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[goalkeeper], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
        {
            resultado = deslargar(robos[goalkeeper],adversarios[i].x,adversarios[i].y);
            str[g[0]] = resultado.logica; //lógica
            str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
            str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
        }
    }
    envia_comandos_robo(str);
}

void Strategy::estrategia()
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;

    //DEFINIR JOGADORES DEFAULT
   Atacante = base_Atacantes[0];
   Goleiro  = base_Goleiros [0];
   Zagueiro = base_Zagueiros[0];

   Permitir_alteracao_usuario();

   //CHAMAR A FUNCAO DE ATACANTE DESSA FORMA
  // (this->*Atacante)();

   int aux;

   if( robos[defensor].get_center_robot().y < campo->gtopy && robos[defensor].get_center_robot().y > campo->gboty &&
       robos[defensor].get_center_robot().x < robos[goalkeeper].get_center_robot().x)
   {
      /* double fis_aux;
       double dist_i_aux;
       double dist_pre_aux;
       double p_pre_atac;
       double v_pre_atac;
       double pbolapre_atac;*/

       aux = defensor;

       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y > campo->gtopy && robos[defensor].get_center_robot().x < campo->area_left && robos[goalkeeper].get_center_robot().y > robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y < campo->gboty && robos[defensor].get_center_robot().x < campo->area_left && robos[goalkeeper].get_center_robot().y < robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }
/*
   if(bola.x > campo->lzagueiro && robos[ataque].get_center_robot().x > bola.x  && robos[defensor].get_center_robot().x < bola.x && distancia(robos[defensor],bola.x,bola.y) < campo->diametro_robo*2)
   {
       swap(robos[defensor].V_max,robos[ataque].V_max);
       swap(robos[defensor].W_max,robos[ataque].W_max);
       double d[3];
       for(int i = 0; i < 3; i++)
           d[i] = sqrt(pow((adversarios[i].x - bola.x),2) + pow((adversarios[i].y - bola.y),2));
       double d1 = distancia(robos[defensor], bola.x, bola.y);
       if(d1 < d[0] && d1 < d[1] && d1 < d[2])
       {
            aux = defensor;
            defensor = ataque;
            ataque = aux;
       }
   }*/

  int ga,at,df;
  if(goalkeeper == 0)
  {
      ga = 1;
      if(ataque == 1)
      {
           at = 4;
           df = 7;
      }
      else
      {
           at = 7;
           df = 4;
      }
  }
  else if(goalkeeper == 1)
  {
      ga = 4;
      if(ataque == 0)
      {
           at = 1;
           df = 7;
      }
      else
      {
           at = 7;
           df = 1;
      }
  }
  else
  {
      ga = 7;
      if(ataque == 1)
      {
           at = 4;
           df = 1;
      }
      else
      {
           at = 1;
           df = 4;
      }
  }

  for(int i = 0; i < 3;i++)
  {
        g[i] = ga++;
        a[i] = at++;
        z[i] = df++;
  }

  resultado = (this->*Zagueiro)(robos[defensor]); // robô 2
  robos = rec_sign(robos,resultado,defensor);

   str[z[0]] = resultado.logica; //lógica
   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   resultado = (this->*Goleiro)(robos[goalkeeper]); //robo 0
   robos = rec_sign(robos,resultado,goalkeeper);

   str[g[0]] = resultado.logica; //lógica
   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

  resultado = (this->*Atacante)(robos[ataque]); // robo 1
  robos = rec_sign(robos,resultado,ataque);

   str[a[0]] = resultado.logica; //lógica
   str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   if(distancia(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //defensor e goleiro
   {
           int flag = larga_robos(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[goalkeeper], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       for(int i = 0; i < 3; i++)
       {
           if(distancia(robos[defensor], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[defensor], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[defensor],adversarios[i].x,adversarios[i].y);
                   str[z[0]] = resultado.logica; //lógica
                   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           ang_err ang = olhar(robos[ataque],bola.x,bola.y);
           if(distancia(robos[ataque], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo) //defensor e goleiro
           {
                   if(distancia(robos[ataque], bola.x, bola.y) > campo->diametro_robo*2)
                   {
                        resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                        str[a[0]] = resultado.logica; //lógica
                        str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                        str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
                   else if (distancia(robos[ataque], bola.x, bola.y) <= campo->diametro_robo*2 && fabs(ang.fi) < 45 && distancia(robos[ataque],bola.x,bola.y) < campo->diametro_robo)
                   {
                       resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                       str[a[0]] = resultado.logica; //lógica
                       str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                       str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
           }

           if(distancia(robos[goalkeeper], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[goalkeeper], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[goalkeeper],adversarios[i].x,adversarios[i].y);
                   str[g[0]] = resultado.logica; //lógica
                   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

      envia_comandos_robo(str);

   bola_anterior.x = bola.x;
   bola_anterior.y = bola.y;
}

void Strategy::estrategia2()
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;

    //DEFINIR JOGADORES DEFAULT
   Atacante = base_Atacantes[0];
   Goleiro  = base_Goleiros [0];
   Zagueiro = base_Zagueiros[0];

   Permitir_alteracao_usuario();

   //CHAMAR A FUNCAO DE ATACANTE DESSA FORMA
  // (this->*Atacante)();

   int aux;

   if( robos[defensor].get_center_robot().y < campo->gtopy && robos[defensor].get_center_robot().y > campo->gboty &&
       robos[defensor].get_center_robot().x > robos[goalkeeper].get_center_robot().x)
   {
      /* double fis_aux;
       double dist_i_aux;
       double dist_pre_aux;
       double p_pre_atac;
       double v_pre_atac;
       double pbolapre_atac;*/

       aux = defensor;

       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y > campo->gtopy && robos[defensor].get_center_robot().x > campo->area_right && robos[goalkeeper].get_center_robot().y > robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y < campo->gboty && robos[defensor].get_center_robot().x > campo->area_right && robos[goalkeeper].get_center_robot().y < robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }

   if(bola.x < campo->lzagueiro && robos[ataque].get_center_robot().x < bola.x  && robos[defensor].get_center_robot().x > bola.x && distancia(robos[defensor],bola.x,bola.y) < campo->diametro_robo*2)
   {
       swap(robos[defensor].V_max,robos[ataque].V_max);
       swap(robos[defensor].W_max,robos[ataque].W_max);
       double d[3];
       for(int i = 0; i < 3; i++)
           d[i] = sqrt(pow((adversarios[i].x - bola.x),2) + pow((adversarios[i].y - bola.y),2));
       double d1 = distancia(robos[defensor], bola.x, bola.y);
       if(d1 < d[0] && d1 < d[1] && d1 < d[2])
       {
            aux = defensor;
            defensor = ataque;
            ataque = aux;
       }
   }

  int ga,at,df;
  if(goalkeeper == 0)
  {
      ga = 1;
      if(ataque == 1)
      {
           at = 4;
           df = 7;
      }
      else
      {
           at = 7;
           df = 4;
      }
  }
  else if(goalkeeper == 1)
  {
      ga = 4;
      if(ataque == 0)
      {
           at = 1;
           df = 7;
      }
      else
      {
           at = 7;
           df = 1;
      }
  }
  else
  {
      ga = 7;
      if(ataque == 1)
      {
           at = 4;
           df = 1;
      }
      else
      {
           at = 1;
           df = 4;
      }
  }

  for(int i = 0; i < 3;i++)
  {
        g[i] = ga++;
        a[i] = at++;
        z[i] = df++;
  }

  resultado = (this->*Zagueiro)(robos[defensor]); // robô 2

   str[z[0]] = resultado.logica; //lógica
   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   resultado = (this->*Goleiro)(robos[goalkeeper]); //robo 0

   str[g[0]] = resultado.logica; //lógica
   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

  resultado = (this->*Atacante)(robos[ataque]); // robo 1

   str[a[0]] = resultado.logica; //lógica
   str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   if(distancia(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //defensor e goleiro
   {
           int flag = larga_robos(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[goalkeeper], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       for(int i = 0; i < 3; i++)
       {
           if(distancia(robos[defensor], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[defensor], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[defensor],adversarios[i].x,adversarios[i].y);
                   str[z[0]] = resultado.logica; //lógica
                   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           ang_err ang = olhar(robos[ataque],bola.x,bola.y);
           if(distancia(robos[ataque], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo) //defensor e goleiro
           {
                   if(distancia(robos[ataque], bola.x, bola.y) > campo->diametro_robo*2)
                   {
                        resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                        str[a[0]] = resultado.logica; //lógica
                        str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                        str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
                   else if (distancia(robos[ataque], bola.x, bola.y) <= campo->diametro_robo*2 && fabs(ang.fi) < 45 && distancia(robos[ataque],bola.x,bola.y) < campo->diametro_robo)
                   {
                       resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                       str[a[0]] = resultado.logica; //lógica
                       str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                       str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
           }

           if(distancia(robos[goalkeeper], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[goalkeeper], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[goalkeeper],adversarios[i].x,adversarios[i].y);
                   str[g[0]] = resultado.logica; //lógica
                   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

      envia_comandos_robo(str);

   bola_anterior.x = bola.x;
   bola_anterior.y = bola.y;
}

void Strategy::estrategia5()
{
    comandos resultado;
    unsigned char str[10];
    str[0] = 255;
    for(int i=1;i<10;i++) str[i] = 0;

    //DEFINIR JOGADORES DEFAULT
   Atacante = base_Atacantes[0];
   Goleiro  = base_Goleiros [0];
   Zagueiro = base_Zagueiros[0];

   Permitir_alteracao_usuario();

   //CHAMAR A FUNCAO DE ATACANTE DESSA FORMA
  // (this->*Atacante)();

   int aux;

   if( robos[defensor].get_center_robot().y < campo->gtopy && robos[defensor].get_center_robot().y > campo->gboty &&
       robos[defensor].get_center_robot().x > robos[goalkeeper].get_center_robot().x)
   {
      /* double fis_aux;
       double dist_i_aux;
       double dist_pre_aux;
       double p_pre_atac;
       double v_pre_atac;
       double pbolapre_atac;*/

       aux = defensor;

       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y > campo->gtopy && robos[defensor].get_center_robot().x > campo->area_right && robos[goalkeeper].get_center_robot().y > robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }
   if( robos[goalkeeper].get_center_robot().y < campo->gboty && robos[defensor].get_center_robot().x > campo->area_right && robos[goalkeeper].get_center_robot().y < robos[defensor].get_center_robot().y)
   {
       aux = defensor;
       defensor = goalkeeper;
       goalkeeper = aux;
   }
/*
   if(bola.x < campo->lzagueiro && robos[ataque].get_center_robot().x < bola.x  && robos[defensor].get_center_robot().x > bola.x && distancia(robos[defensor],bola.x,bola.y) < campo->diametro_robo*2)
   {
       double d[3];
       for(int i = 0; i < 3; i++)
           d[i] = sqrt(pow((adversarios[i].x - bola.x),2) + pow((adversarios[i].y - bola.y),2));
       double d1 = distancia(robos[defensor], bola.x, bola.y);
       if(d1 < d[0] && d1 < d[1] && d1 < d[2])
       {
            aux = defensor;
            defensor = ataque;
            ataque = aux;
       }
   }*/

  int ga,at,df;
  if(goalkeeper == 0)
  {
      ga = 1;
      if(ataque == 1)
      {
           at = 4;
           df = 7;
      }
      else
      {
           at = 7;
           df = 4;
      }
  }
  else if(goalkeeper == 1)
  {
      ga = 4;
      if(ataque == 0)
      {
           at = 1;
           df = 7;
      }
      else
      {
           at = 7;
           df = 1;
      }
  }
  else
  {
      ga = 7;
      if(ataque == 1)
      {
           at = 4;
           df = 1;
      }
      else
      {
           at = 1;
           df = 4;
      }
  }

  for(int i = 0; i < 3;i++)
  {
        g[i] = ga++;
        a[i] = at++;
        z[i] = df++;
  }

  resultado = (this->*Zagueiro)(robos[defensor]); // robô 2

   str[z[0]] = resultado.logica; //lógica
   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   resultado = (this->*Goleiro)(robos[goalkeeper]); //robo 0

   str[g[0]] = resultado.logica; //lógica
   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

  resultado = (this->*Atacante)(robos[ataque]); // robo 1

   str[a[0]] = resultado.logica; //lógica
   str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
   str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)

   if(distancia(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //defensor e goleiro
   {
           int flag = larga_robos(robos[defensor], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[goalkeeper], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[defensor].get_center_robot().x, robos[defensor].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[z[0]] = resultado.logica; //lógica
               str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       if(distancia(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y) <= campo->diametro_robo*1.3) //atacante e defensoro
       {
           int flag = larga_robos(robos[ataque], robos[goalkeeper].get_center_robot().x, robos[goalkeeper].get_center_robot().y);

           if (flag == 1)
           {
               V = -0.6;
               W = 0.2;
           }
           if (flag == 2)
           {
               V = -0.6;
               W = -0.2;
           }
           if (flag == 3)
           {
               V = 0.6;
               W = -0.2;
           }
           if (flag == 4)
           {
               V = 0.6;
               W = 0.2;
           }
           if(flag == 0)
           {
               V = 0;
               W = 0.4;
               resultado = gera_comandos_vr(robos[defensor], V, W);
               str[g[0]] = resultado.logica; //lógica
               str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           else
           {
               resultado = gera_comandos_vr(robos[ataque], V, W);
               str[a[0]] = resultado.logica; //lógica
               str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
               str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

       for(int i = 0; i < 3; i++)
       {
           if(distancia(robos[defensor], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[defensor], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[defensor],adversarios[i].x,adversarios[i].y);
                   str[z[0]] = resultado.logica; //lógica
                   str[z[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[z[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
           ang_err ang = olhar(robos[ataque],bola.x,bola.y);
           if(distancia(robos[ataque], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo) //defensor e goleiro
           {
                   if(distancia(robos[ataque], bola.x, bola.y) > campo->diametro_robo*2)
                   {
                        resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                        str[a[0]] = resultado.logica; //lógica
                        str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                        str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
                   else if (distancia(robos[ataque], bola.x, bola.y) <= campo->diametro_robo*2 && fabs(ang.fi) < 45 && distancia(robos[ataque],bola.x,bola.y) < campo->diametro_robo)
                   {
                       resultado = deslargar(robos[ataque],adversarios[i].x,adversarios[i].y);
                       str[a[0]] = resultado.logica; //lógica
                       str[a[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                       str[a[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
                   }
           }

           if(distancia(robos[goalkeeper], adversarios[i].x, adversarios[i].y) <= campo->diametro_robo && distancia(robos[goalkeeper], bola.x, bola.y) > campo->diametro_robo*2) //defensor e goleiro
           {
                   resultado = deslargar(robos[goalkeeper],adversarios[i].x,adversarios[i].y);
                   str[g[0]] = resultado.logica; //lógica
                   str[g[1]] = resultado.vrD; // velocidade da roda direita (magnitude)
                   str[g[2]] = resultado.vrE; // velocidade da roda esquerda (magnitude)
           }
       }

      envia_comandos_robo(str);

   bola_anterior.x = bola.x;
   bola_anterior.y = bola.y;
}

comandos Strategy::deslargar(Robot rb, int x, int y)
{
    comandos resultado;

    int flag = larga_robos(rb, x, y);

            if (flag == 1)
            {
                V = -0.4;
                W = 0.2;
            }
            if (flag == 2)
            {
                V = -0.4;
                W = -0.2;
            }
            if (flag == 3)
            {
                V = 0.4;
                W = -0.2;
            }
            if (flag == 4)
            {
                V = 0.4;
                W = 0.2;
            }
            if(flag == 0)
            {
                V = 0;
                W = 1;
            }

            resultado = gera_comandos_vr(robos[defensor], V, W);

   return resultado;
}

int Strategy::sairparede(Robot rb)
{
    // flag = 0 : ok
    // flag = 1 : sai de ré c rotação sentido anti-horário
    // flag = 2 : sai de ré c rotação sentido horário
    // flag = 3 : sai de frente c rotação sentido horário
    // flag = 4 : sai de frente c rotação sentido anti-horário
    int flag = 0,
        tam_rb = (campo->area_topy - campo->gtopy)/4,
        raio_rb = campo->diametro_robo/2,
        delta = raio_rb*1.7,
        x_min = campo->fleftx + delta,
        x_max = campo->frightx - delta,
        y_min = campo->fbot + delta,
        y_max = campo->ftop - delta,
        ang = 70;

    if(rb.get_center_robot().x < campo->fleftx)
    {
        x_min = campo->gleft + delta;
        y_min = campo->gboty + delta;
        y_max = campo->gtopy - delta;
    }

    if(rb.get_center_robot().x > campo->frightx)
    {
        x_max = campo->gright - delta;
        y_min = campo->gboty  + delta;
        y_max = campo->gtopy  - delta;
    }

    if (rb.get_center_robot().y < y_min)
    {
        if ((fabs(rb.get_orientation() + 90) < ang) & (V > 0)) //apontando para baixo (y) e V positivo
                {
                    if ((rb.get_orientation() + 90) >= 0) flag = 2;
                    if ((rb.get_orientation() + 90) < 0) flag = 1;
                }
        if ((fabs(rb.get_orientation() - 90) < ang) & (V < 0)) //apontando para cima (y) e V negativo
                {
                    if ((rb.get_orientation() - 90) >= 0) flag = 3;
                    if ((rb.get_orientation() - 90) < 0) flag = 4;
                }
    }
    if (rb.get_center_robot().y > y_max)
    {
        if ((fabs(rb.get_orientation() + 90) < ang) & (V < 0)) //apontando para baixo (y) e V negativo
                {
                    if ((rb.get_orientation() + 90) >= 0) flag = 3;
                    if ((rb.get_orientation() + 90) < 0) flag = 4;
                }
        if ((fabs(rb.get_orientation() - 90) < ang) & (V > 0)) //apontando para cima (y) e V positivo
                {
                    if ((rb.get_orientation() - 90) >= 0) flag = 2;
                    if ((rb.get_orientation() - 90) < 0) flag = 1;
                }
    }
    if (rb.get_center_robot().x < x_min)
    {
        if ((fabs(fabs(rb.get_orientation())-180) < ang) & (V > 0)) //apontando para a esquerda (x = 0) e V positivo
                {
                    if (rb.get_orientation() >= 0) flag = 1;
                    if (rb.get_orientation() <  0) flag = 2;
                }
        if ((fabs(rb.get_orientation()) < ang) & (V < 0)) //apontando para a direito (x = inf) e V negativo
                {
                    if (rb.get_orientation() >= 0) flag = 4;
                    if (rb.get_orientation() <  0) flag = 3;
                }
    }
    if (rb.get_center_robot().x > x_max)
    {
        if ((fabs(fabs(rb.get_orientation())-180) < ang) & (V < 0)) //apontando para a esquerda (x = 0) e V negativo
                {
                    if (rb.get_orientation() >= 0) flag = 4;
                    if (rb.get_orientation() <  0) flag = 3;
                }
        if ((fabs(rb.get_orientation()) < ang) & (V > 0)) //apontando a direito (x = inf) e V positivo
                {
                    if (rb.get_orientation() >= 0) flag = 2;
                    if (rb.get_orientation() <  0) flag = 1;
                }
    }
    return(flag);
}

int Strategy::larga_robos(Robot rb, int X, int Y)
{
    // flag = 0 : outro robo tem que sair
    // flag = 1 : sai de ré c rotação sentido anti-horário
    // flag = 2 : sai de ré c rotação sentido horário
    // flag = 3 : sai de frente c rotação sentido horário
    // flag = 4 : sai de frente c rotação sentido anti-horário

    int ang = 70,
        flag = 0;

    if(rb.get_center_robot().x >= X )
    {
        if (rb.get_center_robot().y <= Y) //primeiro quadrante
        {
                if ((fabs(fabs(rb.get_orientation())-180) < ang) & (V >= 0)) //apontando para a esquerda (x = 0) e V positivo
                        {
                            if (rb.get_orientation() >= 0) flag = 2;
                            if (rb.get_orientation() <  0) flag = 1;
                        }
                if ((fabs(rb.get_orientation()) < ang) & (V <= 0)) //apontando para a direito (x = inf) e V negativo
                {
                            if (rb.get_orientation() >= 0) flag = 3;
                            if (rb.get_orientation() <  0) flag = 4;
                }
                if ((fabs(rb.get_orientation() + 90) < ang) & (V <= 0)) //apontando para baixo (y) e V negativo
                {
                            if ((rb.get_orientation() + 90) >= 0) flag = 4;
                            if ((rb.get_orientation() + 90) < 0) flag = 3;
                }
                if ((fabs(rb.get_orientation() - 90) < ang) & (V >= 0)) //apontando para cima (y) e V positivo
                {
                            if ((rb.get_orientation() - 90) >= 0) flag = 2;
                            if ((rb.get_orientation() - 90) < 0) flag = 1;
                }
        }
        if (rb.get_center_robot().y > Y) //quarto quadrante
        {
                if ((fabs(fabs(rb.get_orientation())-180) < ang) & (V >= 0)) //apontando para a esquerda (x = 0) e V positivo
                        {
                            if (rb.get_orientation() >= 0) flag = 1;
                            if (rb.get_orientation() <  0) flag = 2;
                        }
                if ((fabs(rb.get_orientation()) < ang) & (V <= 0)) //apontando para a direito (x = inf) e V negativo
                        {
                            if (rb.get_orientation() >= 0) flag = 3;
                            if (rb.get_orientation() <  0) flag = 4;
                        }
                if ((fabs(rb.get_orientation() + 90) < ang) & (V >= 0)) //apontando para baixo (y) e V positivo
                        {
                            if ((rb.get_orientation() + 90) >= 0) flag = 2;
                            if ((rb.get_orientation() + 90) < 0) flag = 1;
                        }
                if ((fabs(rb.get_orientation() - 90) < ang) & (V <= 0)) //apontando para cima (y) e V negativo
                        {
                            if ((rb.get_orientation() - 90) >= 0) flag = 3;
                            if ((rb.get_orientation() - 90) < 0) flag = 4;
                        }
        }
    }
    else
    {
        if (rb.get_center_robot().y <= Y) //segundo quadrante
        {
                if ((fabs(fabs(rb.get_orientation())-180) < ang) & (V <= 0)) //apontando para a esquerda (x = 0) e V negativo
                        {
                            if (rb.get_orientation() >= 0) flag = 4;
                            if (rb.get_orientation() <  0) flag = 3;
                        }
                if ((fabs(rb.get_orientation()) < ang) & (V >= 0)) //apontando para a direito (x = inf) e V positivo
                {
                            if (rb.get_orientation() >= 0) flag = 1;
                            if (rb.get_orientation() <  0) flag = 2;
                }
                if ((fabs(rb.get_orientation() + 90) < ang) & (V <= 0)) //apontando para baixo (y) e V negativo
                {
                            if ((rb.get_orientation() + 90) >= 0) flag = 3;
                            if ((rb.get_orientation() + 90) < 0) flag = 4;
                }
                if ((fabs(rb.get_orientation() - 90) < ang) & (V >= 0)) //apontando para cima (y) e V positivo
                {
                            if ((rb.get_orientation() - 90) >= 0) flag = 2;
                            if ((rb.get_orientation() - 90) < 0) flag = 1;
                }
        }
        if (rb.get_center_robot().y > Y) //terceiro quadrante
        {
                if ((fabs(fabs(rb.get_orientation())-180) < ang) & (V <= 0)) //apontando para a esquerda (x = 0) e V negativo
                        {
                            if (rb.get_orientation() >= 0) flag = 4;
                            if (rb.get_orientation() <  0) flag = 3;
                        }
                if ((fabs(rb.get_orientation()) < ang) & (V >= 0)) //apontando para a direito (x = inf) e V positivo
                        {
                            if (rb.get_orientation() >= 0) flag = 2;
                            if (rb.get_orientation() <  0) flag = 1;
                        }
                if ((fabs(rb.get_orientation() + 90) < ang) & (V >= 0)) //apontando para baixo (y) e V positivo
                        {
                            if ((rb.get_orientation() + 90) >= 0) flag = 1;
                            if ((rb.get_orientation() + 90) < 0) flag = 2;
                        }
                if ((fabs(rb.get_orientation() - 90) < ang) & (V <= 0)) //apontando para cima (y) e V negativo
                        {
                            if ((rb.get_orientation() - 90) >= 0) flag = 3;
                            if ((rb.get_orientation() - 90) < 0) flag = 4;
                        }
        }
    }

    return(flag);
}

void Strategy::Setar_Campo(Configurations *c)
{
    campo = c;
}

void Strategy::Setar_Variaveis_jogo(vector<Robot> r, Ball b, vector<Point> a)
{
    robos = r;
    bola = b;
    adversarios = a;
}

vector<string> Strategy::Get_atacantes()
{
    return Nome_atacante;
}

vector<string>Strategy::Get_goleiros()
{
    return Nome_goleiro;
}

vector<string>Strategy::Get_zagueiros()
{
    return Nome_zagueiro;
}

vector<string>Strategy::Get_Estrategias()
{
    return Nome_Estrategias;
}

void Strategy::Adicionar_atacante(String nome, Func atacante)
{
    Nome_atacante.push_back(nome);
    base_Atacantes.push_back(atacante);
}

void Strategy::Adicionar_goleiro(String nome, Func goleiro)
{
    Nome_goleiro.push_back(nome);
    base_Goleiros.push_back(goleiro);
}

void Strategy::Adicionar_estrategia(String nome, cerebro Est)
{
    Nome_Estrategias.push_back(nome);
    Estrategias.push_back(Est);
}

void Strategy::Adicionar_zagueiro(String nome, Func zagueiro)
{
    Nome_zagueiro.push_back(nome);
    base_Zagueiros.push_back(zagueiro);
}

void Strategy::Executar_estrategia(int i)
{
    if(i != -1 && i != -2)
     (this->*Estrategias[i])();

}

void Strategy::Setar_Atacante(int i)
{

      Alteracao_jogador[0] = i;
}

void Strategy::Setar_Goleiro(int i)
{
    Alteracao_jogador[1] = i;
}

void Strategy::Setar_Zagueiro(int i)
{
    Alteracao_jogador[2] = i;
}

void Strategy::Permitir_alteracao_usuario()
{
    if(Alteracao_jogador[0] != -1)
      Atacante = base_Atacantes[Alteracao_jogador[0]];

    if(Alteracao_jogador[1] != -1)
      Goleiro = base_Goleiros[Alteracao_jogador[1]];

    if(Alteracao_jogador[2] != -1)
        Zagueiro = base_Zagueiros[Alteracao_jogador[2]];
}

Strategy::~Strategy()
{
    delete campo;
}
