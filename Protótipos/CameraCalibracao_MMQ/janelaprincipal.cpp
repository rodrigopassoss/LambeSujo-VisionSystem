#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"

#include "mouseevents.h"

#define CORTAR 1
#define CALIBRAR 2
#define AJUSTE 3



enum pontos{O,P1,P2,P3,P4,P5,P6,P7,P8,P9,
            P10,P11,P12,P13,P14,P15,P16,P17,P18,P19};

using namespace std;
using namespace cv;

JanelaPrincipal::JanelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
    ui->frame->setScaledContents(true);

    cronometro = new QTimer(this);

    connect(cronometro,SIGNAL(timeout()),this,SLOT(WorkMetodo()));
    cronometro->start(0);

    connect(ui->frame, SIGNAL(Mouse_pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->frame, SIGNAL(Mouse_pressed()), this, SLOT(Mouse_pressed()));


    //Setar os Pontos do espaço real em cm
    real.push_back(Point(0,0));     //O(0,0)
    real.push_back(Point(15,30));   //P1
    real.push_back(Point(37,25));   //P2
    real.push_back(Point(75,0));    //P3
    real.push_back(Point(113,25));  //P4
    real.push_back(Point(135,30));  //P5
    real.push_back(Point(150,0));   //P6
    real.push_back(Point(0,45));    //P7
    real.push_back(Point(37,65));   //P8
    real.push_back(Point(113,65));  //P9
    real.push_back(Point(150,45));  //P10
    real.push_back(Point(0,85));    //P11
    real.push_back(Point(15,100));  //P12
    real.push_back(Point(37,105));  //P13
    real.push_back(Point(113,105)); //P14
    real.push_back(Point(135,100)); //P15
    real.push_back(Point(150,85));  //P16
    real.push_back(Point(0,130));   //P17
    real.push_back(Point(150,130));  //P18
    //Fim do Setar


}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_cortar_clicked()
{
    ui->option->setText("Cortar");
    ui->info->setText("");
    cont = 0;
    cont_2 = 0;
    modo_operate = CORTAR;
}

void JanelaPrincipal::on_calibrar_clicked()
{
    ui->option->setText("Calibrar");
    ui->info->setText("Ponto Marcado: ...");
    cont_3 = 0;
    modo_operate = CALIBRAR;
}


void JanelaPrincipal::Mouse_current_pos()
{
    ui->XY_pos->setText(QString("X = %1, Y = %2").arg(ui->frame->x).arg(ui->frame->y));
    x = ui->frame->x;
    y = ui->frame->y;

}

void JanelaPrincipal::Mouse_pressed()
{
    cout << "Button Pressed!" <<endl;

    if(modo_operate == CORTAR)
    {

        if(cont < 2)
        {
            cont_2++;
            pontos_corte[cont] = Point(ui->frame->x_press, ui->frame->y_press);
            cout << pontos_corte[cont] << endl;
            cont++;
        }


    }else if(modo_operate == CALIBRAR)
    {
        if(customOrder_enable)
        {
            index_pixels.push_back(ui->indexPoint->value());
            Point aux = Point(ui->frame->x_press, ui->frame->y_press);
            pixels.push_back(aux);

            if(ui->indexPoint->value() == 0)
            {
                ui->info->setText("Ponto Marcado: O(0,0)");
            }else
            {
                ui->info->setText(QString("Ponto Marcado: P%1(%2,%3)").arg(ui->indexPoint->value()).arg(ui->frame->x_press).arg(ui->frame->y_press));
            }
           cont_3++;
        }else
        {
            Point aux = Point(ui->frame->x_press, ui->frame->y_press);
            pixels.push_back(aux);
            index_pixels.push_back(cont_3);

            if(cont_3 == 0)
                ui->info->setText("Ponto Marcado: O(0,0)");
            else
                ui->info->setText(QString("Ponto Marcado: P%1(%2,%3)").arg(cont_3).arg(ui->frame->x_press).arg(ui->frame->y_press));

            cont_3++;
            ui->indexPoint->setValue(cont_3);

        }

        ui->Ponto->setText("P");
    }

}


void JanelaPrincipal::WorkMetodo()
{
    img = imread("razer.png");
    roi = Rect2d(pontos_corte[0].x,pontos_corte[0].y,abs(pontos_corte[1].x - pontos_corte[0].x),abs(pontos_corte[1].y - pontos_corte[0].y));

    if(roi.area()!=0 && cont == 2)
    {
        img = img(roi);
    }

    //cout << "ROI:" << roi << endl;
    //cout << "(x,y): (" << pontos_corte[0].x << ", "<< pontos_corte[0].y << ")" << endl;
    //cout << "Widith:" << abs(pontos_corte[1].x - pontos_corte[0].x) << endl;
    //cout << "Height:" << abs(pontos_corte[1].y - pontos_corte[0].y) << endl;
    //cout << "Rows: " << img.rows << endl;
    //cout << "Cols: " << img.cols << endl;


    if(guia_enable == 0)
    {
        ui->frame->setScaledContents(true);

        if(modo_operate == CALIBRAR)
        {
            x = ui->frame->x;
            y = ui->frame->y;

            line(img,Point(x,y), Point(0,y), Scalar(0,255,125),2);
            line(img,Point(x,y), Point(img.cols,y), Scalar(0,255,125),2);
            line(img,Point(x,y), Point(x,0), Scalar(0,255,125),2);
            line(img,Point(x,y), Point(x,img.rows), Scalar(0,255,125),2);

            if(customOrder_enable)
             {
                if(point_enable == 2)
                {

                    int len = pixels.size();
                    for(int i = 0; i < len; i++)
                    {
                        if(index_pixels[i])
                        {
                            circle(img, pixels[i], 5, Scalar(0,255,0),3);
                            circle(img, pixels[i], 2, Scalar(255,255,255),2);
                            putText(img,QString("P%1(%2,%3)").arg(index_pixels[i]).arg(pixels[i].x).arg(pixels[i].y).toStdString(),
                                    Point(pixels[i].x+5,pixels[i].y),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255,0,0),1,LINE_AA);
                        }else
                        {
                            circle(img, pixels[i], 5, Scalar(0,255,0),3);
                            circle(img, pixels[i], 2, Scalar(255,255,255),2);
                            putText(img,QString("O(%1,%2)").arg(pixels[i].x).arg(pixels[i].y).toStdString(),
                                    Point(pixels[i].x+5,pixels[i].y),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255,0,0),1,LINE_AA);
                        }

                    }
                }
            }else
            {
                if(point_enable == 2)
                {
                    if(!pixels.empty())
                    {
                    circle(img, pixels[0], 5, Scalar(0,255,0),3);
                    circle(img, pixels[0], 2, Scalar(255,255,255),2);
                    putText(img,QString("O(%2,%3)").arg(pixels[0].x).arg(pixels[0].y).toStdString(),
                            Point(pixels[0].x+5,pixels[0].y),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255,0,0),1,LINE_AA);
                    }

                    int len = pixels.size();
                    for(int i = len - 1; i > 0; i-- )
                    {
                        circle(img, pixels[i], 5, Scalar(0,255,0),3);
                        circle(img, pixels[i], 2, Scalar(255,255,255),2);
                        putText(img,QString("P%1(%2,%3)").arg(len-i).arg(pixels[len-i].x).arg(pixels[len-i].y).toStdString(),
                                Point(pixels[len-i].x+5,pixels[len-i].y),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255,0,0),1,LINE_AA);

                    }
                }
            }
        }else if(modo_operate == CORTAR && cont < 2)
        {
            if(cont_2 == 1) pontos_corte[1] = Point(x,y);
            rectangle(img,pontos_corte[0], pontos_corte[1], Scalar(0,0,255), 2);
        }

         Mat M = getRotationMatrix2D(Point(img.cols/2,img.rows/2),ui->rot->value(),1);
         Mat img_dist;
         warpAffine(img,img_dist,M,Size(img.cols,img.rows));
         image = QImage((uchar*) img_dist.data, img_dist.cols, img_dist.rows,img_dist.step, QImage::Format_BGR888);
         ui->frame->setPixmap(QPixmap::fromImage(image));


     }else if(guia_enable == 2)
    {
        ui->frame->setScaledContents(true);

        Mat guia = imread("campo.png");
        image = QImage((uchar*) guia.data, guia.cols, guia.rows,guia.step, QImage::Format_BGR888);
        ui->frame->setPixmap(QPixmap::fromImage(image));
    }


    vector<Point2f> src(4), dist(4);
    if(pixels.size()>=4 && !(guia_enable == 2))
    {

        for (int i = 0; i < 4;i++)
        {
            src[i]=pixels[i];
            dist[i]=Point(real[index_pixels[i]].x*(img.cols/150),real[index_pixels[i]].y*(img.rows/130));

        }
        Mat M = getPerspectiveTransform(src,dist);
        cout << M << endl;

        Mat img_dist;
        warpPerspective(img,img_dist,M,Size(abs(dist[1].x-dist[2].x)+10,abs(dist[0].y-dist[1].y)+10));
        image = QImage((uchar*) img_dist.data, img_dist.cols, img_dist.rows,img_dist.step, QImage::Format_BGR888);
        ui->frame->setPixmap(QPixmap::fromImage(image));
        cout << "Rows: " << img_dist.rows << endl;
        cout << "Cols: " << img_dist.cols << endl;

    }




}

/*
    Pontos a acrescentar na interface:
        * Tornar mais fácil o acesso ao guia de referência;
        * Acrecentar outra opção ao
*/

void JanelaPrincipal::on_guia_stateChanged(int arg1)
{
    guia_enable = arg1;
}

void JanelaPrincipal::on_showPoint_stateChanged(int arg1)
{
    point_enable = arg1;
}

void JanelaPrincipal::on_customOrder_stateChanged(int arg1)
{
    customOrder_enable = arg1;
}

void JanelaPrincipal::on_zerar_clicked()
{
    pixels.resize(0);
    index_pixels.resize(0);
    cont_3 = 0;
    ui->Ponto->setText("O");
    ui->indexPoint->setValue(0);
    ui->info->setText("Ponto Marcado: ...");
}

void JanelaPrincipal::on_remover_clicked()
{
    if(customOrder_enable)
    {
        if(!pixels.empty())
         {
            pixels.pop_back();
            index_pixels.pop_back();
            cont_3--;
            if(index_pixels.back())
            {
                ui->info->setText(QString("Ponto Marcado: P%1(%2,%3)").arg(index_pixels.back()).arg(pixels.back().x).arg(pixels.back().y));
                ui->Ponto->setText("P");
                ui->indexPoint->setValue(index_pixels.back());
            }
            else
            {
                ui->info->setText(QString("Ponto Marcado: O(%1,%2)").arg(pixels.back().x).arg(pixels.back().y));
                ui->Ponto->setText("O");
                ui->indexPoint->setValue(index_pixels.back());
            }
        }

    }else{

        if(!pixels.empty())
        {
            pixels.pop_back();
            index_pixels.pop_back();
            cont_3--;
            if(pixels.size()>1)
            {
                ui->info->setText(QString("Ponto Marcado: P%1(%2,%3)").arg(cont_3-1).arg(pixels.back().x).arg(pixels.back().y));
                ui->Ponto->setText("P");
                ui->indexPoint->setValue(cont_3);
            }
            else if(pixels.size()==1)
            {
                ui->info->setText(QString("Ponto Marcado: O(%1,%2)").arg(pixels.back().x).arg(pixels.back().y));
                ui->Ponto->setText("P");
                ui->indexPoint->setValue(cont_3);
            }else
            {
                ui->info->setText("Ponto Marcado: ...");
                ui->Ponto->setText("O");
                ui->indexPoint->setValue(0);
            }
        }

    }

}

void JanelaPrincipal::on_applyAjuste_clicked()
{
    cout << "Real = " << real << endl;
    cout << "Pixels = " << pixels << endl;
    int m = 0;
    float medicao_auto = 0;

    for(m = 0; m<100;m++)
    {
        std::chrono::time_point<std::chrono::system_clock> inicio, fim;

        inicio = std::chrono::system_clock::now();
        algoritimo();
        fim = std::chrono::system_clock::now();

        float temp1 = std::chrono::duration_cast<std::chrono::microseconds>(fim-inicio).count();

        medicao_auto = medicao_auto + temp1;
    }
    ui->time->setText(QString("Tempo da Operação: %1 us").arg(medicao_auto/(float)m));

}

void JanelaPrincipal::algoritimo()
{
    int n = pixels.size();

    //int Ax[n][2];       //matriz de parâmetros Ax - Pixels
    //int Ay[n][2];       //matriz de parâmetros Ay - Pixels
    gsl_vector *Bx = gsl_vector_alloc(n);       //matriz de coordenadas Bx - Real
    gsl_vector *By = gsl_vector_alloc(n);       //matriz de coordenadas By - Real

    gsl_matrix *A_x = gsl_matrix_alloc(n, 2);
    gsl_matrix *A_y = gsl_matrix_alloc(n, 2);
    gsl_matrix *A_pinvx,  *A_pinvy;

    for(int i = 0; i < n;i++)
    {
        //Abicissa
        /*Ax[i][0] = 1;
        Ax[i][1] = pixels[i].x;
        Bx[i] = real[i].x;
        //Ordenada
        Ay[i][0] = 1;
        Ay[i][1] = pixels[i].y;
        By[i] = real[i].y;*/

        gsl_matrix_set(A_x,i,0,1);
        gsl_matrix_set(A_x,i,1,pixels[i].x);
        gsl_matrix_set(A_y,i,0,1);
        gsl_matrix_set(A_y,i,1,pixels[i].y);

        gsl_vector_set(Bx,i,real[index_pixels[i]].x);       //matriz de coordenadas Bx - Real
        gsl_vector_set(By,i,real[index_pixels[i]].y);      //matriz de coordenadas By - Real
    }

    cout << "A_x = [";
    print_matrix(A_x);
    cout << "] " << endl;
    cout << "A_y = [";
    print_matrix(A_y);
    cout << "] " << endl;

    //Pseudo_inversa de Ax
    A_pinvx = moore_penrose_pinv(A_x,1E-15);
    //Pseudo inversa de Ay
    A_pinvy = moore_penrose_pinv(A_y,1E-15);

    cout << "A_pinvx = [";
    print_matrix(A_pinvx);
    cout << "] " << endl;
    cout << "A_pinvy = [";
    print_matrix(A_pinvy);
    cout << "] " << endl;

    float abX[2]={0,0};
    float abY[2]={0,0};

    for(int i = 0;i<2;i++)
    {
        for(int k=0;k<n;k++)
        {
            abX[i] += gsl_matrix_get(A_pinvx,i,k)*gsl_vector_get(Bx,k);
            abY[i] += gsl_matrix_get(A_pinvy,i,k)*gsl_vector_get(By,k);
        }
    }

    // Equações da reta X
    cout << "Equações da Reta:" << endl;
    cout << "Y_x = "<<abX[1]<<"x"<<" + "<<abX[0];
    // Equações da reta Y
    cout << "\nY_y = "<<abY[1]<<"y"<<" + "<<abY[0]<<endl;



    // A*A'
  /*  float Mx[n][n];
    float My[n][n];

    cout << "\nMx = [ ";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Mx[i][j] = Ax[i][0]*Ax[j][0] + Ax[i][1]*Ax[j][1];
            My[i][j] = Ay[i][0]*Ay[j][0] + Ay[i][1]*Ay[j][1];
           cout << Mx[i][j] << " ";
        }
        cout << ";\n";
    }
    cout << "]" << endl;
    //CALCULO DAS MATRIZES INVERSAS (inv(A*A'))
    float inv_Mx[n][n];
    float inv_My[n][n];

    int linha, coluna, k = 0;
    float pivo_x = 0, pivo_y = 0, mx = 0, my = 0;

    //Criando Matrizes identidades
    for(linha = 0; linha < n; linha++)
    {
            for(coluna = 0; coluna < n; coluna++)
            {
                if(linha == coluna)
                {
                     inv_Mx[linha][coluna] = 1;
                     inv_My[linha][coluna] = 1;

                }else{
                        inv_Mx[linha][coluna] = 0;
                        inv_My[linha][coluna] = 0;
                }
            }
     }

    //Itera sobre as colunas das matrizes Mx e My
    for(coluna = 0; coluna < n; coluna++)
    {
        pivo_x = Mx[coluna][coluna];
        pivo_y = My[coluna][coluna];

        if(pivo_x==0)
        {

            for(k = n-1; k > coluna; k--)
            {
                if(Mx[k][coluna]!=0)
                {
                    for(int i = 0; i < n; i++)
                        Mx[coluna][i] = Mx[coluna][i] + Mx[k][i];
                    pivo_x = Mx[coluna][coluna];
                    break;
                }

            }
            if(pivo_x==0){
                cerr << "Erro em Mx: Pivo " << coluna << " = 0, "<<"Não Possui inversa!" << endl;
                break;
            }

        }
        if(pivo_y==0)
        {

            for(k = n-1; k > coluna; k--)
            {
                if(My[k][coluna]!=0)
                {
                    for(int i = 0; i < n; i++)
                        My[coluna][i] = My[coluna][i] + My[k][i];
                    pivo_y = My[coluna][coluna];
                    break;
                }

            }
            if(pivo_y==0){
                cerr << "Erro em My: Pivo " << coluna << " = 0, "<<"Não Possui inversa!" << endl;
                break;
            }

        }


        for(k=0;k<n;k++)
        {
            //Faz L(n) -> L(n)/pivo_x
            Mx[coluna][k]     = Mx[coluna][k]/pivo_x;
            inv_Mx[coluna][k] = inv_Mx[coluna][k]/pivo_x;
             //Faz L(n) -> L(n)/pivo_y
            My[coluna][k]     = My[coluna][k]/pivo_y;
            inv_My[coluna][k] = inv_My[coluna][k]/pivo_y;

        }

        //Itera pelas linhas que não contém o pivo atual
        for(linha = 0; linha < n ;linha++)
        {
            if(linha!=coluna)
            {
                mx = Mx[linha][coluna];
                my = My[linha][coluna];
                for(k=0;k<n;k++)
                {
                    Mx[linha][k] = Mx[linha][k] - (mx*(Mx[coluna][k]));
                    inv_Mx[linha][k] = inv_Mx[linha][k] - (mx*(inv_Mx[coluna][k]));

                    My[linha][k] = My[linha][k] - (my*(My[coluna][k]));
                    inv_My[linha][k] = inv_My[linha][k] - (my*(inv_My[coluna][k]));

                }
            }
        }

    }

    cout << "Diagonal da Matriz linha reduzida de Mx: ";

    for(linha = 0; linha < n; linha++){
        cout << Mx[linha][linha] << "";
        cout << endl;
    }*/

}

