#include "controlador.h"
#include <cmath>


double limita_velocidade(double valor, double sat)
{
      if (valor > sat) {valor = sat;}
      if (valor < -sat) {valor = -sat;}
      return(valor);
}

ang_err olhar(Robot rb, double px, double py)   // função testada - ok!
{
      double r = rb.get_orientation(); // orientação do robô de -180 a 180
      ang_err angulo;

      angulo.flag = 1;
      angulo.fi = atan2((py - rb.get_center_robot().y) , (px - rb.get_center_robot().x))*180/M_PI;  //ângulo entre -180 e 180

      if (r < 0)  {r = r + 360;}          //muda para 0 a 360
      if (angulo.fi < 0)   {angulo.fi = angulo.fi + 360;}      //muda para 0 a 360

      angulo.fi = angulo.fi - r;  //erro de orientação a ser corrigido

      if (angulo.fi > 180) {angulo.fi = angulo.fi - 360;}  // limita entre -180 e 180
      if (angulo.fi < -180) {angulo.fi = angulo.fi + 360;} // limita entre -180 e 180

      if (angulo.fi > 90) // se for mais fácil, olhar com o fundo...
      {
          angulo.fi = angulo.fi - 180;
          angulo.flag = -1;
      }
      if (angulo.fi < -90) // se for mais fácil, olhar com o fundo...
      {
          angulo.fi = 180 + angulo.fi;
          angulo.flag = -1;
      }

      // angulo.fi é o ângulo a ser corrigido na convenção do sistema de visão. valores entre -90 e 90.
      // angulo.flag é o sinal a ser aplicado na velocidade linear
      return(angulo);
}

double distancia(Robot rb, double px, double py)
{
      double dist = sqrt( pow((rb.get_center_robot().x-px),2) + pow((rb.get_center_robot().y-py),2) );
      return(dist);
}

double controle_linear_Kamarry(Robot rb, double px, double py)
{
    double  V = 0,
            k_lin = rb.k_lin,   //constante de contração da tangente hiperbólica
           // k_lin =0.0075,   //constante de contração da tangente hiperbólica
            V_max = rb.V_max,       //constante limitante da tangente hiperbólica

            dist = distancia(rb, px, py);

   ang_err angulo = olhar(rb, px, py);

    V = V_max*tanh(k_lin*dist*angulo.flag)*cos(angulo.fi*M_PI/180);  //controle não linear de V
    //cout << "V: " << V_max << endl;
    return(V);
}

double controle_angular_Kamarry(Robot rb, double px, double py)
{
    double  W = 0,
            k_ang = rb.k_ang,   //constante de contração da tangente hiperbólica
            //k_lin = 1,   //constante de contração da tangente hiperbólica
            ww_max = rb.W_max,       //constante limitante da tangente hiperbólica

            dist = distancia(rb, px, py);


    ang_err angulo = olhar(rb, px, py);
//W = 0.2*tanh(0.05*dist)*cos(0.005*angulo.fi/90);
   /* if(dist<1.1){
           W = 1.5*tanh(0.08*(angulo.fi/90))*tanh(dist); // não linear
    }else{
           W = 1.5*tanh(0.08*(angulo.fi/90))*tanh(dist)/dist; // não linear
    }*/

  //  cout <<px<< ' x'<<" \n";
   // cout <<py<< ' y'<<" \n";

    //ang_err angulo_desejado = olhar(rb, 20, 40);
    //W = -1.3*tanh(0.08*(angulo.fi/90))*tanh(dist); // não linear
    //W = -0.07*angulo.fi*M_PI/180 + 1.5*tanh(0.1*(angulo.fi/90))*tanh(dist)/dist;
    W = -0.07*angulo.fi*M_PI / 180 + ww_max*tanh(k_ang*(angulo.fi / 90))*tanh(dist) / dist;


//    W = -0.09*(angulo.fi*M_PI/180 +2*(((angulo_desejado.fi*M_PI/180)*(angulo_desejado.fi*M_PI/180))/angulo.fi*M_PI/180)) +0.53*0.05*(tanh(dist)/dist)*(angulo_desejado.fi*M_PI/180)*(sin(angulo.fi*M_PI/180)/angulo.fi*M_PI/180)*cos(angulo.fi*M_PI/180) +0.5*(tanh(dist)/dist)*sin(angulo.fi*M_PI/180)*cos(angulo.fi*M_PI/180);

//cout << "W: " << ww_max << endl;

    W = limita_velocidade(W,ww_max); //satura em -1 a 1

    return(W);
}

double controle_angular(Robot rb, double fi) // função testada. lembrete : (sinal de w) = -(sinal de fi)
{
    double W_max = rb.W_max,    // constante limitante da tangente hiperbólica : deve ser negativa
           k_ang = rb.k_ang,
           W = 0;
           fi = fi/90; // coloca o erro entre -1 e 1

           W = W_max*tanh(k_ang*fi); // nгo linear
                                     //  W =  kw*fi;                     // proporcional

           W = limita_velocidade(W, 1); //satura em -1 a 1

    return(W); //deve tetornar um valor entre -1 e 1
}

double controle_linear(Robot rb, double px, double py)
{
    double  V = 0,
            k_lin = rb.k_lin,   //constante de contração da tangente hiperbólica
            V_max = rb.V_max,       //constante limitante da tangente hiperbólica
            v_min = 0.03,  	 //módulo da velocidade linear mínima permitida
            ang_grande = 30, //para ângulos maiores que esse valor o sistema da prioridade ao W, reduzindo o V
            dist = distancia(rb, px, py);

    ang_err angulo = olhar(rb, px, py);

    V = V_max*tanh(k_lin*dist*angulo.flag);  //controle não linear de V

    if (V*angulo.flag < v_min) V = v_min*angulo.flag;  //aplica o valor definido em v_min

                                                       //if (angulo.fi*angulo.flag > ang_grande) V = v_min*angulo.flag;  // controle de prioridade reduzindo V quando "ang_err" for grande
    V = V*cos(angulo.fi*M_PI / 180);// controle de prioridade reduzindo V quando "ang_err" for grande

    V = limita_velocidade(V, 1); //satura em -1 a 1

    return(V);
}
// --------------------------------------------------------------------------------------------------------------

comandos gera_comandos_vr(Robot rb, double V, double W)
{
    double vrd_ = (V + W);
    double vre_ = (V - W);
    comandos final;

    rb.W = W;
    rb.V = V;

    // PARA ERIK OU PHILPINHO:
    // mudar zona morta para: "rb.zonamorta_e_pos e rb.zonamorta_e_neg"   e   "rb.zonamorta_d_pos e rb.zonamorta_d_neg" (os dois são valores positivos)
    // criar variaveis :      "rb.VRe_max_pos e rb.VRe_max_neg"   e   "rb.VRd_max_pos e rb.VRd_max_neg"

    int
    rb_VRe_max_pos       = rb.rb_VRe_max_pos,
    rb_VRd_max_pos       = rb.rb_VRd_max_pos,
    rb_VRe_max_neg       = -rb.rb_VRe_max_neg,
    rb_VRd_max_neg       = -rb.rb_VRd_max_neg,
    rb_zonamorta_d_pos   = rb.zonamorta_direita_positiva,
    rb_zonamorta_d_neg   = rb.zonamorta_direita_negativa,
    rb_zonamorta_e_pos   = rb.zonamorta_esquerda_positiva,
    rb_zonamorta_e_neg   = rb.zonamorta_esquerda_negativa;

    // RODA ESQUERDA
    if (vre_ >= 0) // diferencia rotação positiva e negativa da roda esquerda
    {
        vre_ = (V - W)*(rb_VRe_max_pos - rb_zonamorta_e_pos);
    }
    else
    {
        vre_ = (V - W)*(rb_VRe_max_neg - rb_zonamorta_e_neg);
    }
    //cout << "Ve: " << vre_ << " ";

    // RODA DIREITA
    if (vrd_ >= 0) // diferencia rotação positiva e negativa da roda direita
    {
        vrd_ = (V + W)*(rb_VRd_max_pos - rb_zonamorta_d_pos);
    }
    else
    {
        vrd_ = (V + W)*(rb_VRd_max_neg - rb_zonamorta_d_neg);
    }
    //cout << "Vd: " << vre_ << endl;

    // RODA ESQUERDA
    if (vre_ >= 0) // Ajusta o valor de acordo com a zona morta das rodas
    {
        vre_ = vre_ + rb_zonamorta_e_pos;
        vre_ = limita_velocidade(vre_, rb_VRe_max_pos);
    }
    else
    {
        vre_ = vre_ - rb_zonamorta_e_neg;
        vre_ = limita_velocidade(vre_, rb_VRe_max_neg);
    }


    // RODA DIREITA
    if (vrd_ >= 0) // Ajusta o valor de acordo com a zona morta das rodas
    {
        vrd_ = vrd_ + rb_zonamorta_d_pos;
        vrd_ = limita_velocidade(vrd_, rb_VRd_max_pos);
    }
    else
    {
        vrd_ = vrd_ - rb_zonamorta_d_neg;
        vrd_ = limita_velocidade(vrd_, rb_VRd_max_neg);
    }


    final.vrD = rint(abs(vrd_));
    final.vrE = rint(abs(vre_));

    // atribuindo as direções à palavra logica
    final.logica = 0;
    if(vrd_ > 0) final.logica = final.logica | 8;
    if(vrd_ < 0) final.logica = final.logica | 16;
    if(vre_ > 0) final.logica = final.logica | 4;
    if(vre_ < 0) final.logica = final.logica | 2;

    return(final);
}

comandos gera_comandos(Robot rb, double V, double W)
{
    double vrd_ = (V + W);
    double vre_ = (V - W);
    comandos final;

    rb.W = W;
    rb.V = V;

    // PARA ERIK OU PHILPINHO:
    // mudar zona morta para: "rb.zonamorta_e_pos e rb.zonamorta_e_neg"   e   "rb.zonamorta_d_pos e rb.zonamorta_d_neg" (os dois são valores positivos)
    // criar variaveis :      "rb.VRe_max_pos e rb.VRe_max_neg"   e   "rb.VRd_max_pos e rb.VRd_max_neg"

    int
    rb_VRe_max_pos       = rb.rb_VRe_max_pos,
    rb_VRd_max_pos       = rb.rb_VRd_max_pos,
    rb_VRe_max_neg       = -rb.rb_VRe_max_neg,
    rb_VRd_max_neg       = -rb.rb_VRd_max_neg,
    rb_zonamorta_d_pos   = rb.zonamorta_direita_positiva,
    rb_zonamorta_d_neg   = rb.zonamorta_direita_negativa,
    rb_zonamorta_e_pos   = rb.zonamorta_esquerda_positiva,
    rb_zonamorta_e_neg   = rb.zonamorta_esquerda_negativa;

    // RODA ESQUERDA
    if (vre_ >= 0) // diferencia rotação positiva e negativa da roda esquerda
    {
        vre_ = (V - W)*(rb_VRe_max_pos - rb_zonamorta_e_pos);
    }
    else
    {
        vre_ = (V - W)*(rb_VRe_max_neg - rb_zonamorta_e_neg);
    }
    //cout << "Ve: " << vre_ << " ";

    // RODA DIREITA
    if (vrd_ >= 0) // diferencia rotação positiva e negativa da roda direita
    {
        vrd_ = (V + W)*(rb_VRd_max_pos - rb_zonamorta_d_pos);
    }
    else
    {
        vrd_ = (V + W)*(rb_VRd_max_neg - rb_zonamorta_d_neg);
    }
    //cout << "Vd: " << vrd_ << endl;

    // RODA ESQUERDA
    if (vre_ >= 0) // Ajusta o valor de acordo com a zona morta das rodas
    {
        vre_ = vre_ + rb_zonamorta_e_pos;
        vre_ = limita_velocidade(vre_, rb_VRe_max_pos);

        //cout << "iC_ep: " << rb.ic_ep << " vre_p: " << rb.vre_p << " Ve Desejado: " << vre_ << " ";
        if (abs(vre_-rb.vre_p)>50) //apenas usa o slow start se a diferença de velocidade for muito grande
            vre_ = rb.ic_ep * vre_ + (1-rb.ic_ep)*rb.vre_p;
    }
    else
    {
        vre_ = vre_ - rb_zonamorta_e_neg;
        vre_ = limita_velocidade(vre_, rb_VRe_max_neg);

        //cout << "iC_en: " << rb.ic_en << " vre_p: " << rb.vre_p << " Ve Desejado: " << vre_ << " ";
        if (abs(vre_-rb.vre_p)>50)
            vre_ = rb.ic_en * vre_ + (1-rb.ic_en)*rb.vre_p;
    }


    // RODA DIREITA
    if (vrd_ >= 0) // Ajusta o valor de acordo com a zona morta das rodas
    {
        vrd_ = vrd_ + rb_zonamorta_d_pos;
        vrd_ = limita_velocidade(vrd_, rb_VRd_max_pos);

        //cout << "iC_dp: " << rb.ic_dp << " vrd_p: " << rb.vrd_p << " Vd Desejado: " << vrd_ << " ";
        if (abs(vrd_-rb.vrd_p)>50)
            vrd_ = rb.ic_dp * vrd_ + (1-rb.ic_dp)*rb.vrd_p;
    }
    else
    {
        vrd_ = vrd_ - rb_zonamorta_d_neg;
        vrd_ = limita_velocidade(vrd_, rb_VRd_max_neg);

        //cout << "iC_dn: " << rb.ic_dn << " vrd_p: " << rb.vrd_p << " Vd Desejado: " << vrd_ << " ";
        if (abs(vrd_-rb.vrd_p)>50)
            vrd_ = rb.ic_dn * vrd_ + (1-rb.ic_dn)*rb.vrd_p;
    }


    final.vrD = rint(abs(vrd_));
    final.vrE = rint(abs(vre_));

    // atribuindo as direções à palavra logica
    final.logica = 0;
    if(vrd_ > 0) final.logica = final.logica | 8;
    if(vrd_ < 0) final.logica = final.logica | 16;
    if(vre_ > 0) final.logica = final.logica | 4;
    if(vre_ < 0) final.logica = final.logica | 2;

    return(final);
}


double controle_linear_Kamarry(Robot rb, double px, double py, double v_max_filp)
{
    double  V = 0,
            //k_lin = rb.k_lin,   //constante de contração da tangente hiperbólica
            k_lin =0.0075,   //constante de contração da tangente hiperbólica
            V_max = rb.V_max,       //constante limitante da tangente hiperbólica

            dist = distancia(rb, px, py);

   ang_err angulo = olhar(rb, px, py);

    V = v_max_filp*tanh(k_lin*dist*angulo.flag)*cos(angulo.fi*M_PI/180);  //controle não linear de V

    return(V);
}


double controle_angular_Kamarry(Robot rb, double px, double py, double w_max_filp)
{
    double  W = 0,
            //k_lin = rb.k_lin,   //constante de contração da tangente hiperbólica
            k_lin = 1,   //constante de contração da tangente hiperbólica
            V_max = rb.V_max,       //constante limitante da tangente hiperbólica

            dist = distancia(rb, px, py);


    ang_err angulo = olhar(rb, px, py);
//W = 0.2*tanh(0.05*dist)*cos(0.005*angulo.fi/90);
   /* if(dist<1.1){
           W = 1.5*tanh(0.08*(angulo.fi/90))*tanh(dist); // não linear
    }else{
           W = 1.5*tanh(0.08*(angulo.fi/90))*tanh(dist)/dist; // não linear
    }*/

  //  cout <<px<< ' x'<<" \n";
   // cout <<py<< ' y'<<" \n";

    ang_err angulo_desejado = olhar(rb, 20, 40);
    //W = -1.3*tanh(0.08*(angulo.fi/90))*tanh(dist); // não linear
    W = -0.07*angulo.fi*M_PI/180 + 1.5*tanh(0.1*(angulo.fi/90))*tanh(dist)/dist;


//    W = -0.09*(angulo.fi*M_PI/180 +2*(((angulo_desejado.fi*M_PI/180)*(angulo_desejado.fi*M_PI/180))/angulo.fi*M_PI/180)) +0.53*0.05*(tanh(dist)/dist)*(angulo_desejado.fi*M_PI/180)*(sin(angulo.fi*M_PI/180)/angulo.fi*M_PI/180)*cos(angulo.fi*M_PI/180) +0.5*(tanh(dist)/dist)*sin(angulo.fi*M_PI/180)*cos(angulo.fi*M_PI/180);


    W = W*15;
    W = limita_velocidade(W,w_max_filp); //satura em -1 a 1
    //cout << "W: " << W << " W_Max: " << w_max_filp << endl;
    return(W);
}
