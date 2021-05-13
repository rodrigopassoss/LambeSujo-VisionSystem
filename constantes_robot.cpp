#include "constantes_robot.h"
#include "ui_constantes_robot.h"

Constantes_robot::Constantes_robot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constantes_robot)
{
    ui->setupUi(this);
   
   filename = "constantes.xml";
   GetandSetconstant();
}

Constantes_robot::~Constantes_robot()
{
    delete ui;
}

void Constantes_robot::GetandSetconstant()
{
    fs.open(filename, FileStorage::READ);
    FileNode data = fs["Index"];
    atual1 = data["r1"];
    atual2 = data["r2"];
    atual3 = data["r3"];

    ui->robo1->setCurrentIndex(atual1);
    ui->robo2->setCurrentIndex(atual2);
    ui->robo3->setCurrentIndex(atual3);

    for(int i = 0; i<7; i++)
    {
        if(i == 0)
            data = fs["A"];
        else if(i == 1)
            data = fs["B"];
        else if(i == 2)
            data = fs["C"];
        else if(i == 3)
            data = fs["D"];
        else if(i == 4)
            data = fs["E"];
        else if(i == 5)
            data = fs["F"];
        else
            data = fs["G"];

        robo[i].V_max = data["vmax"]; // vmax
        robo[i].k_lin = data["klin"]; // klin
        robo[i].W_max = data["wmax"]; // wmax
        robo[i].k_ang = data["kang"]; // kang
        robo[i].rb_VRd_max_neg = data["v_dir_n"]; //
        robo[i].rb_VRd_max_pos = data["v_dir_p"]; //
        robo[i].rb_VRe_max_neg = data["v_esq_n"]; //
        robo[i].rb_VRe_max_pos = data["v_esq_p"]; //
        robo[i].rb_zonamorta_d_neg = data["zona_morta_d_n"];
        robo[i].rb_zonamorta_e_neg = data["zona_morta_e_n"];
        robo[i].rb_zonamorta_d_pos = data["zona_morta_d_p"];
        robo[i].rb_zonamorta_e_pos = data["zona_morta_e_p"];
        robo[i].ic_dn = data["ic_dn"];
        robo[i].ic_dp = data["ic_dp"];
        robo[i].ic_en = data["ic_en"];
        robo[i].ic_ep = data["ic_ep"];
    }

    ui->rb1_vmax->setValue(robo[atual1].V_max);
    ui->rb1_klin->setValue(robo[atual1].k_lin);
    ui->rb1_wmax->setValue(robo[atual1].W_max);
    ui->rb1_kang->setValue(robo[atual1].k_ang);
    ui->rb1_dir_n->setValue(robo[atual1].rb_VRd_max_neg);
    ui->rb1_dir_p->setValue(robo[atual1].rb_VRd_max_pos);
    ui->rb1_esq_n->setValue(robo[atual1].rb_VRe_max_neg);
    ui->rb1_esq_p->setValue(robo[atual1].rb_VRe_max_pos);
    ui->rb1_zn_d->setValue(robo[atual1].rb_zonamorta_d_neg);
    ui->rb1_zn_e->setValue(robo[atual1].rb_zonamorta_e_neg);
    ui->rb1_zp_d->setValue(robo[atual1].rb_zonamorta_d_pos);
    ui->rb1_zp_e->setValue(robo[atual1].rb_zonamorta_e_pos);
    ui->rb1_ic_dn->setValue(robo[atual1].ic_dn);
    ui->rb1_ic_dp->setValue(robo[atual1].ic_dp);
    ui->rb1_ic_en->setValue(robo[atual1].ic_en);
    ui->rb1_ic_ep->setValue(robo[atual1].ic_ep);

    ui->rb2_vmax->setValue(robo[atual2].V_max);
    ui->rb2_klin->setValue(robo[atual2].k_lin);
    ui->rb2_wmax->setValue(robo[atual2].W_max);
    ui->rb2_kang->setValue(robo[atual2].k_ang);
    ui->rb2_dir_n->setValue(robo[atual2].rb_VRd_max_neg);
    ui->rb2_dir_p->setValue(robo[atual2].rb_VRd_max_pos);
    ui->rb1_esq_n_2->setValue(robo[atual2].rb_VRe_max_neg);
    ui->rb2_esq_p->setValue(robo[atual2].rb_VRe_max_pos);
    ui->rb2_zn_d->setValue(robo[atual2].rb_zonamorta_d_neg);
    ui->rb2_zn_e->setValue(robo[atual2].rb_zonamorta_e_neg);
    ui->rb2_zp_d->setValue(robo[atual2].rb_zonamorta_d_pos);
    ui->rb2_zp_e->setValue(robo[atual2].rb_zonamorta_e_pos);
    ui->rb2_ic_dn->setValue(robo[atual2].ic_dn);
    ui->rb2_ic_dp->setValue(robo[atual2].ic_dp);
    ui->rb2_ic_en->setValue(robo[atual2].ic_en);
    ui->rb2_ic_ep->setValue(robo[atual2].ic_ep);

    ui->rb3_vmax->setValue(robo[atual3].V_max);
    ui->rb3_klin->setValue(robo[atual3].k_lin);
    ui->rb3_wmax->setValue(robo[atual3].W_max);
    ui->rb3_kang->setValue(robo[atual3].k_ang);
    ui->rb3_dir_n->setValue(robo[atual3].rb_VRd_max_neg);
    ui->rb3_dir_p->setValue(robo[atual3].rb_VRd_max_pos);
    ui->rb3_esq_n->setValue(robo[atual3].rb_VRe_max_neg);
    ui->rb3_esq_p->setValue(robo[atual3].rb_VRe_max_pos);
    ui->rb3_zn_d->setValue(robo[atual3].rb_zonamorta_d_neg);
    ui->rb3_zn_e->setValue(robo[atual3].rb_zonamorta_e_neg);
    ui->rb3_zp_d->setValue(robo[atual3].rb_zonamorta_d_pos);
    ui->rb3_zp_e->setValue(robo[atual3].rb_zonamorta_e_pos);
    ui->rb3_ic_dn->setValue(robo[atual3].ic_dn);
    ui->rb3_ic_dp->setValue(robo[atual3].ic_dp);
    ui->rb3_ic_en->setValue(robo[atual3].ic_en);
    ui->rb3_ic_ep->setValue(robo[atual3].ic_ep);
    fs.release();
}
void Constantes_robot::setar_constantes(double rb1[],int zona1[], double rb2[],int zona2[],double rb3[],int zona3[])
{
    for(int i =0;i<4;i++)
    {
        constantes_rb1[i] = rb1[i];
        constantes_rb2[i] = rb2[i];
        constantes_rb3[i] = rb3[i];
    }

    ui->rb1_vmax->setValue(rb1[0]);
    ui->rb1_klin->setValue(rb1[1]);
    ui->rb1_wmax->setValue(rb1[2]);
    ui->rb1_kang->setValue(rb1[3]);

    ui->rb2_vmax->setValue(rb2[0]);
    ui->rb2_klin->setValue(rb2[1]);
    ui->rb2_wmax->setValue(rb2[2]);
    ui->rb2_kang->setValue(rb2[3]);

    ui->rb3_vmax->setValue(rb3[0]);
    ui->rb3_klin->setValue(rb3[1]);
    ui->rb3_wmax->setValue(rb3[2]);
    ui->rb3_kang->setValue(rb3[3]);

}
void Constantes_robot::on_pushButton_clicked()
{
     int i1 = ui->robo1->currentIndex();

     robo[i1].V_max = ui->rb1_vmax->value(); // vmax
     robo[i1].k_lin = ui->rb1_klin->value(); // klin
     robo[i1].W_max = ui->rb1_wmax->value(); // wmax
     robo[i1].k_ang = ui->rb1_kang->value(); // kang
     robo[i1].rb_VRd_max_neg = ui->rb1_dir_n->value(); //
     robo[i1].rb_VRd_max_pos = ui->rb1_dir_p->value(); //
     robo[i1].rb_VRe_max_neg = ui->rb1_esq_n->value(); //
     robo[i1].rb_VRe_max_pos = ui->rb1_esq_p->value(); //
     robo[i1].rb_zonamorta_d_neg = ui->rb1_zn_d->value();
     robo[i1].rb_zonamorta_e_neg = ui->rb1_zn_e->value();
     robo[i1].rb_zonamorta_d_pos = ui->rb1_zp_d->value();
     robo[i1].rb_zonamorta_e_pos = ui->rb1_zp_e->value();
     robo[i1].ic_dp = ui->rb1_ic_dp->value();
     robo[i1].ic_dn = ui->rb1_ic_dn->value();
     robo[i1].ic_ep = ui->rb1_ic_ep->value();
     robo[i1].ic_en = ui->rb1_ic_en->value();

     i1 = ui->robo2->currentIndex();

     robo[i1].V_max = ui->rb2_vmax->value(); // vmax
     robo[i1].k_lin = ui->rb2_klin->value(); // klin
     robo[i1].W_max = ui->rb2_wmax->value(); // wmax
     robo[i1].k_ang = ui->rb2_kang->value(); // kang
     robo[i1].rb_VRd_max_neg = ui->rb2_dir_n->value(); //
     robo[i1].rb_VRd_max_pos = ui->rb2_dir_p->value(); //
     robo[i1].rb_VRe_max_neg = ui->rb1_esq_n_2->value(); //
     robo[i1].rb_VRe_max_pos = ui->rb2_esq_p->value(); //
     robo[i1].rb_zonamorta_d_neg = ui->rb2_zn_d->value();
     robo[i1].rb_zonamorta_e_neg = ui->rb2_zn_e->value();
     robo[i1].rb_zonamorta_d_pos = ui->rb2_zp_d->value();
     robo[i1].rb_zonamorta_e_pos = ui->rb2_zp_e->value();
     robo[i1].ic_dp = ui->rb2_ic_dp->value();
     robo[i1].ic_dn = ui->rb2_ic_dn->value();
     robo[i1].ic_ep = ui->rb2_ic_ep->value();
     robo[i1].ic_en = ui->rb2_ic_en->value();

     i1 = ui->robo3->currentIndex();

     robo[i1].V_max = ui->rb3_vmax->value(); // vmax
     robo[i1].k_lin = ui->rb3_klin->value(); // klin
     robo[i1].W_max = ui->rb3_wmax->value(); // wmax
     robo[i1].k_ang = ui->rb3_kang->value(); // kang
     robo[i1].rb_VRd_max_neg = ui->rb3_dir_n->value(); //
     robo[i1].rb_VRd_max_pos = ui->rb3_dir_p->value(); //
     robo[i1].rb_VRe_max_neg = ui->rb3_esq_n->value(); //
     robo[i1].rb_VRe_max_pos = ui->rb3_esq_p->value(); //
     robo[i1].rb_zonamorta_d_neg = ui->rb3_zn_d->value();
     robo[i1].rb_zonamorta_e_neg = ui->rb3_zn_e->value();
     robo[i1].rb_zonamorta_d_pos = ui->rb3_zp_d->value();
     robo[i1].rb_zonamorta_e_pos = ui->rb3_zp_e->value();
     robo[i1].ic_dp = ui->rb3_ic_dp->value();
     robo[i1].ic_dn = ui->rb3_ic_dn->value();
     robo[i1].ic_ep = ui->rb3_ic_ep->value();
     robo[i1].ic_en = ui->rb3_ic_en->value();

     fs.open(filename, FileStorage::WRITE);

       for(int i = 0;i<=6;i++)
       {
           if(i == 0)
               fs << "A";
           else if(i == 1)
               fs << "B";
           else if(i == 2)
               fs << "C";
           else if(i == 3)
               fs << "D";
           else if(i == 4)
               fs << "E";
           else if(i == 5)
               fs << "F";
           else
               fs << "G";

              fs << "{" << "zona_morta_d_n" << robo[i].rb_zonamorta_d_neg;
              fs        << "zona_morta_e_n" << robo[i].rb_zonamorta_e_neg;
              fs        << "zona_morta_d_p" << robo[i].rb_zonamorta_d_pos;
              fs        << "zona_morta_e_p" << robo[i].rb_zonamorta_e_pos;
              fs        << "vmax"           << robo[i].V_max;
              fs        << "klin"           << robo[i].k_lin;
              fs        << "wmax"           << robo[i].W_max;
              fs        << "kang"           << robo[i].k_ang;
              fs        << "ic_dp"          << robo[i].ic_dp;
              fs        << "ic_dn"          << robo[i].ic_dn;
              fs        << "ic_ep"          << robo[i].ic_ep;
              fs        << "ic_en"          << robo[i].ic_en;
              fs        << "v_dir_n"        << robo[i].rb_VRd_max_neg;
              fs        << "v_dir_p"        << robo[i].rb_VRd_max_pos;
              fs        << "v_esq_n"        << robo[i].rb_VRe_max_neg;
              fs        << "v_esq_p"        << robo[i].rb_VRe_max_pos  << "}" ;
       }

    i1 = ui->robo1->currentIndex();
    int i2 = ui->robo2->currentIndex();
    int i3 = ui->robo3->currentIndex();
    fs << "Index";
        fs << "{" << "r1" << i1;
        fs        << "r2" << i2;
        fs        << "r3" << i3 << "}";

    fs.release();
}

void Constantes_robot::on_robo1_currentIndexChanged(int index)
{
    int i1 = index;
    atual1 = i1;
    ui->rb1_vmax->setValue(robo[i1].V_max); // vmax
    ui->rb1_klin->setValue(robo[i1].k_lin); // klin
    ui->rb1_wmax->setValue(robo[i1].W_max); // wmax
    ui->rb1_kang->setValue(robo[i1].k_ang); // kang
    ui->rb1_dir_n->setValue(robo[i1].rb_VRd_max_neg); //
    ui->rb1_dir_p->setValue(robo[i1].rb_VRd_max_pos); //
    ui->rb1_esq_n->setValue(robo[i1].rb_VRe_max_neg); //
    ui->rb1_esq_p->setValue(robo[i1].rb_VRe_max_pos); //
    ui->rb1_zn_d->setValue(robo[i1].rb_zonamorta_d_neg);
    ui->rb1_zn_e->setValue(robo[i1].rb_zonamorta_e_neg);
    ui->rb1_zp_d->setValue(robo[i1].rb_zonamorta_d_pos);
    ui->rb1_zp_e->setValue(robo[i1].rb_zonamorta_e_pos);
    ui->rb1_ic_dn->setValue(robo[i1].ic_dn);
    ui->rb1_ic_dp->setValue(robo[i1].ic_dp);
    ui->rb1_ic_en->setValue(robo[i1].ic_en);
    ui->rb1_ic_ep->setValue(robo[i1].ic_ep);
}

void Constantes_robot::on_robo2_currentIndexChanged(int index)
{
    int i1 = index;
    atual2 = i1;
    ui->rb2_vmax->setValue(robo[i1].V_max); // vmax
    ui->rb2_klin->setValue(robo[i1].k_lin); // klin
    ui->rb2_wmax->setValue(robo[i1].W_max); // wmax
    ui->rb2_kang->setValue(robo[i1].k_ang); // kang
    ui->rb2_dir_n->setValue(robo[i1].rb_VRd_max_neg); //
    ui->rb2_dir_p->setValue(robo[i1].rb_VRd_max_pos); //
    ui->rb1_esq_n_2->setValue(robo[i1].rb_VRe_max_neg); //
    ui->rb2_esq_p->setValue(robo[i1].rb_VRe_max_pos); //
    ui->rb2_zn_d->setValue(robo[i1].rb_zonamorta_d_neg);
    ui->rb2_zn_e->setValue(robo[i1].rb_zonamorta_e_neg);
    ui->rb2_zp_d->setValue(robo[i1].rb_zonamorta_d_pos);
    ui->rb2_zp_e->setValue(robo[i1].rb_zonamorta_e_pos);
    ui->rb2_ic_dn->setValue(robo[i1].ic_dn);
    ui->rb2_ic_dp->setValue(robo[i1].ic_dp);
    ui->rb2_ic_en->setValue(robo[i1].ic_en);
    ui->rb2_ic_ep->setValue(robo[i1].ic_ep);
}

void Constantes_robot::on_robo3_currentIndexChanged(int index)
{
    int i1 = index;
    atual3 = i1;
    ui->rb3_vmax->setValue(robo[i1].V_max); // vmax
    ui->rb3_klin->setValue(robo[i1].k_lin); // klin
    ui->rb3_wmax->setValue(robo[i1].W_max); // wmax
    ui->rb3_kang->setValue(robo[i1].k_ang); // kang
    ui->rb3_dir_n->setValue(robo[i1].rb_VRd_max_neg); //
    ui->rb3_dir_p->setValue(robo[i1].rb_VRd_max_pos); //
    ui->rb3_esq_n->setValue(robo[i1].rb_VRe_max_neg); //
    ui->rb3_esq_p->setValue(robo[i1].rb_VRe_max_pos); //
    ui->rb3_zn_d->setValue(robo[i1].rb_zonamorta_d_neg);
    ui->rb3_zn_e->setValue(robo[i1].rb_zonamorta_e_neg);
    ui->rb3_zp_d->setValue(robo[i1].rb_zonamorta_d_pos);
    ui->rb3_zp_e->setValue(robo[i1].rb_zonamorta_e_pos);
    ui->rb3_ic_dn->setValue(robo[i1].ic_dn);
    ui->rb3_ic_dp->setValue(robo[i1].ic_dp);
    ui->rb3_ic_en->setValue(robo[i1].ic_en);
    ui->rb3_ic_ep->setValue(robo[i1].ic_ep);
}
