#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

#define MAX_VALUE 0
#define MIN_VALUE 1
#define min 0
#define max 1
#define CORTAR 1

enum RGB{R,G,B};
enum HSV{H=3,S,V};
enum Cores{Azul, Amarelo, Verde, Laranja, Vermelho, Magenta};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->janela->setScaledContents(true);
    ui->janela_2->setScaledContents(true);


    cronometro = new QTimer(this);
    cronometro2 = new QTimer(this);

    arquivo = fopen("../release/saida.txt", "w");
    if(arquivo == NULL)
        fprintf(stderr, "Erro ao abrir o arquivo.txt.\n");

    out.open("../constants/teste2.txt");
    /////////////////////////////////// comunicação serial ///////////////////////////////
    int val = inicia_comunicacao_serial();
    if (val == 0) // se a porta não estiver disponível encerre o programa
        QMessageBox::warning(this, tr("Erro"), "Erro na porta serial!", QMessageBox::Close);

    /////////////////////////////////// comunicação serial ///////////////////////////////

    //Eventos do mouse
    connect(ui->janela_2, SIGNAL(Mouse_pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->janela_2, SIGNAL(Mouse_pressed()), this, SLOT(Mouse_pressed()));

    connect(cronometro,SIGNAL(timeout()),this,SLOT(Refresh_position_robots()));
    cronometro->start(25);

    connect(cronometro2,SIGNAL(timeout()),this,SLOT(calibration()));
    cronometro2->start(25);
    cronometro2->blockSignals(true);

    con = new Constantes_robot();

    con->hide();

    comando = -2;
    comando_atacante = -1;
    comando_goleiro = -1;
    comando_zagueiro = -1;

    razer = false;
    if (ctx.query_devices().size() > 0)
    {
        razer = true;

        auto advanced_sensors = ctx.query_all_sensors();

        for (auto&& sensor : advanced_sensors)
        {
            std::string module_name = sensor.get_info(RS2_CAMERA_INFO_NAME);
            std::cout << module_name << std::endl;
            if (module_name == "RGB Camera")
            {
                cout << "Definido: " << module_name << endl;
                color_sensor = sensor;
            }
        }
        set = new Configurations(cfg,"../constants/Settings.xml");
        p.start(cfg);
        frames = p.wait_for_frames();
        color = frames.get_color_frame();
    }
    else
    {
        cout << "Abrindo WebCAM..."<<endl;
        //cap.open(0,CAP_V4L2);
        cap.open("../release/razer_%02d.jpg",CAP_IMAGES);   //Testes plot virtual e calibração
        if(!cap.isOpened())
        {
            cout << "FALHA AO ABRIR!"<<endl;
        }else{
            cout << "SUCESSO AO ABRIR!"<<endl;

        }
        set = new Configurations(cap,"../constants/Settings.xml");
    }

    roi = set->GetCutFramePoints();
    set->ReadConfigurationsRobots("../constants/Constantes.xml");
    set->GetConfigurationsElement(Mascaras);
    set->GetThresholdColor(Blue, "Blue");
    set->GetThresholdColor(Red, "Red");
    set->GetThresholdColor(Yellow, "Yellow");
    set->GetThresholdColor(Orange, "Orange");
    set->GetThresholdColor(Mg,"Magenta");
    set->GetThresholdColor(Green,"Green");

    set->GetThresholdColor_HSV(HSV_Blue, "Blue");
    set->GetThresholdColor_HSV(HSV_Red, "Red");
    set->GetThresholdColor_HSV(HSV_Yellow, "Yellow");
    set->GetThresholdColor_HSV(HSV_Orange, "Orange");
    set->GetThresholdColor_HSV(HSV_Mg,"Magenta");
    set->GetThresholdColor_HSV(HSV_Green,"Green");

    set->GetThresholdColor_NEWRGB(New_Blue_1,New_Blue_2, "Blue");
    set->GetThresholdColor_NEWRGB(New_Red_1, New_Red_2, "Red");
    set->GetThresholdColor_NEWRGB(New_Yellow_1,New_Yellow_2, "Yellow");
    set->GetThresholdColor_NEWRGB(New_Orange_1,New_Orange_2,"Orange");
    set->GetThresholdColor_NEWRGB(New_Mg_1,New_Mg_2,"Magenta");
    set->GetThresholdColor_NEWRGB(New_Green_1,New_Green_2,"Green");

    //cout<<New_Blue_1[0]<<" "<<New_Blue_1[1];

    azul = new Segmentation(Mascaras);
    vermelho = new Segmentation(Mascaras);
    amarelo = new Segmentation(Mascaras);
    laranja = new Segmentation(Mascaras);
    magenta = new Segmentation(Mascaras);
    verde = new Segmentation(Mascaras);

    azul->Get_Limiar_RGB(Blue[0], Blue[1]);
    vermelho->Get_Limiar_RGB(Red[0], Red[1]);
    amarelo->Get_Limiar_RGB(Yellow[0], Yellow[1]);
    laranja->Get_Limiar_RGB(Orange[0], Orange[1]);
    magenta->Get_Limiar_RGB(Mg[0],Mg[1]);
    verde->Get_Limiar_RGB(Green[0],Green[1]);

    azul->Get_Limiar_NewRGB(New_Blue_1[0], New_Blue_1[1],New_Blue_2[0], New_Blue_2[1]);
    vermelho->Get_Limiar_NewRGB(New_Red_1[0], New_Red_1[1], New_Red_2[0], New_Red_2[1]);
    amarelo->Get_Limiar_NewRGB(New_Yellow_1[0], New_Yellow_1[1],New_Yellow_2[0], New_Yellow_2[1]);
    laranja->Get_Limiar_NewRGB(New_Orange_1[0], New_Orange_1[1],New_Orange_2[0], New_Orange_2[1]);
    magenta->Get_Limiar_NewRGB(New_Mg_1[0],New_Mg_1[1],New_Mg_2[0],New_Mg_2[1]);
    verde->Get_Limiar_NewRGB(New_Green_1[0],New_Green_1[1],New_Green_2[0],New_Green_2[1]);

    azul->Get_Limiar_HSV(HSV_Blue[0], HSV_Blue[1]);
    vermelho->Get_Limiar_HSV(HSV_Red[0], HSV_Red[1]);
    amarelo->Get_Limiar_HSV(HSV_Yellow[0], HSV_Yellow[1]);
    laranja->Get_Limiar_HSV(HSV_Orange[0], HSV_Orange[1]);
    magenta->Get_Limiar_HSV(HSV_Mg[0],HSV_Mg[1]);
    verde->Get_Limiar_HSV(HSV_Green[0],HSV_Green[1]);

    azul_group = new Grouping(3,0);
    amarelo_group = new Grouping(3,0);
    verde_group =  new Grouping(4,0);
    vermelho_group = new Grouping (2,0);
    magenta_group = new Grouping(2,0);
    laranja_group = new Grouping (1,0);

    Machine_of_Robots = new Build_Robot(3);
    Machine_of_Robots->Record_Position(false);

    Machine_of_Robots->Change_dist_cores(25);//mudar aqui distancia entra a parte azul e a outra cor

    Cerebro = new Strategy();
    Cerebro->Setar_Campo(set);
    Bola.Set_Campo(set);

    vector<string> nome;

    nome = Cerebro->Get_atacantes();

    for(int i = 0; i < nome.size();i++)
        ui->combo_atacante->addItem(QString::fromStdString(nome[i]));

    nome = Cerebro->Get_goleiros();

    for(int i = 0; i < nome.size();i++)
        ui->combo_goleiro->addItem(QString::fromStdString(nome[i]));

    nome = Cerebro->Get_zagueiros();

    for(int i = 0; i < nome.size();i++)
        ui->combo_zagueiro->addItem(QString::fromStdString(nome[i]));

    nome = Cerebro->Get_Estrategias();

    for(int i = 0; i < nome.size();i++)
        ui->comboBox->addItem(QString::fromStdString(nome[i]));
    
    ui->comboBox->setCurrentIndex(-1);
    ui->combo_goleiro->setCurrentIndex(-1);
    ui->combo_zagueiro->setCurrentIndex(-1);
    ui->combo_atacante->setCurrentIndex(-1);

    if(razer)
        for(int i = 0; i < 3; i++)
        {
            frames = p.wait_for_frames();
            color = frames.get_color_frame();
        }
    else
        for(int i = 0; i < 3; i++)
            cap >> input;

    time = 0;
    pos_bola[0] = Point(-1,-1);
    pos_bola[1] = Point(-1,-1);
    contador = 1;
    Color_Space = RGB;
    
    cont_help = 0;

    set_ui_values();

    //Constroe o Objeto para instaciar a comunicação
    SerialComm = new communication();
    info_ports();

    DefplotComm();



}

void MainWindow::Refresh_position_robots()
{
    if(ui->tabWidget->currentIndex() == 1)
    {
        cronometro->blockSignals(true);
        cronometro2->blockSignals(false);
    }

    if(!this->isVisible())
        con->close();

    contador++;
    if(razer)
    {
        frames = p.wait_for_frames();
        color = frames.get_color_frame();

        // Query frame size (width and height)
        const int w = color.as<rs2::video_frame>().get_width();
        const int h = color.as<rs2::video_frame>().get_height();

        // Create OpenCV matrix of size (w,h) from the colorized depth data
        Mat image(Size(w, h), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
        input = image;
    }
    else
    {
        cap.open("../release/razer_%02d.jpg",CAP_IMAGES);   //Testes plot virtual e calibração
        //cap.open(0,CAP_V4L2);

        if(!cap.isOpened())
        {
            QMessageBox::warning(this, tr("Error"), "Câmera não conectada", QMessageBox::Close);

        }
        if(!cap.read(input))
        {
            QMessageBox::warning(this, tr("Error"), "Frame não pode ser aberto", QMessageBox::Close);
            this->close();
        }
    }

    start = clock();
    if(ui->checkBox_flip->isChecked())
        flip(input,input,1);

    end = clock();
    double aux = pow(10,6)*(end-start)/CLOCKS_PER_SEC;
    cout << "Flip: " << aux << "us; ";
    fprintf(arquivo, "Flip: %f ", aux);

    start = clock();
    if(roi.area() > 0 && roi.width+roi.x < input.cols && roi.height+roi.y < input.rows)
        input = input(roi);
    end = clock();
    aux = pow(10,6)*(end-start)/CLOCKS_PER_SEC;
    cout << "Cut: " << aux << "us; ";
    fprintf(arquivo, "Cut: %f ", aux);

    // IMAGEM BINARIA DAS SEGMENTACOES DAS CORES

    Mat *binary_img_azul;
    Mat *binary_img_amarelo;
    Mat *binary_img_verde;
    Mat *binary_img_vermelho;
    Mat *binary_img_magenta;
    Mat *binary_img_laranja;

    vector<pair<Point,int> > center_camisa_azul;
    vector<pair<Point,int> > center_camisa_amarelo;
    vector<pair<Point,int> > centers_id_camisa[3];

    azul->Segmentation_option = Color_Space;
    amarelo->Segmentation_option = Color_Space;
    vermelho->Segmentation_option = Color_Space;
    verde->Segmentation_option = Color_Space;
    magenta->Segmentation_option = Color_Space;
    laranja->Segmentation_option = Color_Space;

    start = clock();

    binary_img_verde = verde->Segmentation_Result(&input);
    //binary_img_verde = verde->Segmentation_Result(&input_aux);
    // imshow("verde",*binary_img_verde);

    end = clock();
    aux = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Limiarização 2: " << aux << "ms; ";
    fprintf(arquivo, "Lim2: %f ", aux);

/*    #pragma omp parallel sections
    {
        #pragma omp section
        {
            binary_img_azul = azul->Segmentation_Result(&input);
            //imshow("azul",*binary_img_azul);
            center_camisa_azul = azul_group->Grouping_Result(binary_img_azul);
        }

        #pragma omp section
        {
            binary_img_amarelo = amarelo->Segmentation_Result(&input);
            //imshow("amarelo",*binary_img_amarelo);
            center_camisa_amarelo = amarelo_group->Grouping_Result(binary_img_amarelo);
        }

        #pragma omp section
        {
            binary_img_laranja = laranja->Segmentation_Result(&input);
            if(laranja_group->Grouping_Result(binary_img_laranja).size() > 0)
                Bola.Refresh_Position(laranja_group->Grouping_Result(binary_img_laranja)[0].first);
        }
    }*/

    start = clock();

    binary_img_azul = azul->Segmentation_Result(&input);
    binary_img_amarelo = amarelo->Segmentation_Result(&input);
    binary_img_laranja = laranja->Segmentation_Result(&input);
    binary_img_vermelho = vermelho->Segmentation_Result(&input);
    binary_img_verde = verde->Segmentation_Result(&input);
    binary_img_magenta = magenta->Segmentation_Result(&input);

    end = clock();
    aux = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Limiarização: " << aux << "ms; ";

    fprintf(arquivo, "Lim: %f ", aux);

    start = clock();

    center_camisa_azul = azul_group->Grouping_Result(binary_img_azul);
    center_camisa_amarelo = amarelo_group->Grouping_Result(binary_img_amarelo);
    if(laranja_group->Grouping_Result(binary_img_laranja).size() > 0)
        Bola.Refresh_Position(laranja_group->Grouping_Result(binary_img_laranja)[0].first);

    end = clock();
    aux = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Grouping: " << aux << "ms; ";
    fprintf(arquivo, "Group: %f ", aux);

    //imshow("azul",*binary_img_azul);
    //imshow("amarelo",*binary_img_amarelo);


    Mat input_aux = Mat(input.rows,input.cols,CV_8UC3);
    if(time == 0)
    {
        int xsup = 0;
        int xmin = 0;
        int ysup = 0;
        int ymin = 0;
        int robotSize = set->fleftx - set->gleft;
        for(int i = 0;i < center_camisa_azul.size();i++)
        {
            if((center_camisa_azul[i].first.x - robotSize) >= 0)
                xmin = center_camisa_azul[i].first.x - robotSize;
            else
                xmin = 0;

            if((center_camisa_azul[i].first.x + robotSize) < input_aux.cols)
                xsup = center_camisa_azul[i].first.x + robotSize;
            else
                xsup = input_aux.cols - 1;

            if((center_camisa_azul[i].first.y - robotSize) >= 0)
                ymin = center_camisa_azul[i].first.y - robotSize;
            else
                ymin = 0;

            if((center_camisa_azul[i].first.y + robotSize) < input_aux.rows)
                ysup = center_camisa_azul[i].first.y + robotSize;
            else
                ysup = input_aux.rows - 1;


            for(int j = ymin; j < ysup;j++)
                for(int k = xmin; k < xsup;k++)
                     input_aux.at<Vec3b>(j,k) = input.at<Vec3b>(j,k);           
        }
    }
    else if(time == 1)
    {
        int xsup = 0;
        int xmin = 0;
        int ysup = 0;
        int ymin = 0;
        int robotSize = set->fleftx - set->gleft;
        for(int i = 0; i < center_camisa_amarelo.size();i++)
        {
            if((center_camisa_amarelo[i].first.x - robotSize) >= 0)
                xmin = center_camisa_amarelo[i].first.x - robotSize;
            else
                xmin = 0;

            if((center_camisa_amarelo[i].first.x + robotSize) < input_aux.cols)
                xsup = center_camisa_amarelo[i].first.x + robotSize;
            else
                xsup = input_aux.cols - 1;

            if((center_camisa_amarelo[i].first.y - robotSize) >= 0)
                ymin = center_camisa_amarelo[i].first.y - robotSize;
            else
                ymin = 0;

            if((center_camisa_amarelo[i].first.y + robotSize) < input_aux.rows)
                ysup = center_camisa_amarelo[i].first.y + robotSize;
            else
                ysup = input_aux.rows - 1;

            for(int j = ymin;j < ysup;j++)
                for(int k = xmin;k < xsup;k++)
                     input_aux.at<Vec3b>(j,k) = input.at<Vec3b>(j,k);
        }
    }

    start = clock();
    centers_id_camisa[0] = vermelho_group->Grouping_Result(binary_img_vermelho);
    centers_id_camisa[1] = verde_group->Grouping_Result(binary_img_verde);
    centers_id_camisa[2]=  magenta_group->Grouping_Result(binary_img_magenta);
    end = clock();
    aux = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Grouping 2: " << aux << "ms; ";
    fprintf(arquivo, "Group 2: %f ", aux);

    // RETORNO DOS CENTROS E QUANTIDADE DE PIXEL VINCULADO A CADA CENTRO ... FEITO PELO AGRUPAMENTO
    // O RETORNO É UM VETOR DE PARES ONDE ... "vetor[i].first é o ponto do centro e vetor[i].second é a quantidade de contorno ou pixel vinculado a aquele centro"

    // POS PROCESSAMENTO PARA FORMACAO DE ROBOS...USO DO CASAMENTO...
    start = clock();
    vector<Point>  adversario;
    if(time == 0)
    {
        Machine_of_Robots->Get_Centers(center_camisa_azul,centers_id_camisa,center_camisa_amarelo);
        for(int i = 0; i < center_camisa_amarelo.size();i++)
            adversario.push_back(center_camisa_amarelo[i].first);
    }
    else
    {
        Machine_of_Robots->Get_Centers(center_camisa_amarelo,centers_id_camisa,center_camisa_azul);
        for(int i = 0; i < center_camisa_azul.size();i++)
            adversario.push_back(center_camisa_azul[i].first);
    }

    end = clock();
    aux = pow(10,6)*(end-start)/CLOCKS_PER_SEC;
    cout << "Casamento: " << aux << "us; ";
    fprintf(arquivo, "Casamento: %f ", aux);

    // RETORNO DOS ROBOS JA FORMADOS
    robos = Machine_of_Robots->Get_robos();

    robos[0].zonamorta_direita_positiva  = con->robo[con->atual1].rb_zonamorta_d_pos;
    robos[0].zonamorta_esquerda_positiva = con->robo[con->atual1].rb_zonamorta_e_pos;

    robos[0].zonamorta_direita_negativa  = con->robo[con->atual1].rb_zonamorta_d_neg;
    robos[0].zonamorta_esquerda_negativa = con->robo[con->atual1].rb_zonamorta_e_neg;

    robos[1].zonamorta_direita_positiva  = con->robo[con->atual2].rb_zonamorta_d_pos;
    robos[1].zonamorta_esquerda_positiva = con->robo[con->atual2].rb_zonamorta_e_pos;

    robos[1].zonamorta_direita_negativa  = con->robo[con->atual2].rb_zonamorta_d_neg;
    robos[1].zonamorta_esquerda_negativa = con->robo[con->atual2].rb_zonamorta_e_neg;

    robos[2].zonamorta_direita_positiva  = con->robo[con->atual3].rb_zonamorta_d_pos;
    robos[2].zonamorta_esquerda_positiva = con->robo[con->atual3].rb_zonamorta_e_pos;

    robos[2].zonamorta_direita_negativa  = con->robo[con->atual3].rb_zonamorta_d_neg;
    robos[2].zonamorta_esquerda_negativa = con->robo[con->atual3].rb_zonamorta_e_neg;

    Cerebro->vm1 = robos[0].V_max;
    robos[0].V_max = con->robo[con->atual1].V_max;
    robos[0].k_lin = con->robo[con->atual1].k_lin;
    robos[0].W_max = con->robo[con->atual1].W_max;
    robos[0].k_ang = con->robo[con->atual1].k_ang;
    robos[0].ic_dn = con->robo[con->atual1].ic_dn;
    robos[0].ic_dp = con->robo[con->atual1].ic_dp;
    robos[0].ic_en = con->robo[con->atual1].ic_en;
    robos[0].ic_ep = con->robo[con->atual1].ic_ep;
    robos[0].rb_VRd_max_neg = con->robo[con->atual1].rb_VRd_max_neg;
    robos[0].rb_VRd_max_pos = con->robo[con->atual1].rb_VRd_max_pos;
    robos[0].rb_VRe_max_neg = con->robo[con->atual1].rb_VRe_max_neg;
    robos[0].rb_VRe_max_pos = con->robo[con->atual1].rb_VRe_max_pos;

    Cerebro->vm2 = robos[1].V_max;
    robos[1].V_max = con->robo[con->atual2].V_max;
    robos[1].k_lin = con->robo[con->atual2].k_lin;
    robos[1].W_max = con->robo[con->atual2].W_max;
    robos[1].k_ang = con->robo[con->atual2].k_ang;
    robos[1].ic_dn = con->robo[con->atual2].ic_dn;
    robos[1].ic_dp = con->robo[con->atual2].ic_dp;
    robos[1].ic_en = con->robo[con->atual2].ic_en;
    robos[1].ic_ep = con->robo[con->atual2].ic_ep;
    robos[1].rb_VRd_max_neg = con->robo[con->atual2].rb_VRd_max_neg;
    robos[1].rb_VRd_max_pos = con->robo[con->atual2].rb_VRd_max_pos;
    robos[1].rb_VRe_max_neg = con->robo[con->atual2].rb_VRe_max_neg;
    robos[1].rb_VRe_max_pos = con->robo[con->atual2].rb_VRe_max_pos;

    Cerebro->vm3 = robos[2].V_max;
    robos[2].V_max = con->robo[con->atual3].V_max;
    robos[2].k_lin = con->robo[con->atual3].k_lin;
    robos[2].W_max = con->robo[con->atual3].W_max;
    robos[2].k_ang = con->robo[con->atual3].k_ang;
    robos[2].ic_dn = con->robo[con->atual3].ic_dn;
    robos[2].ic_dp = con->robo[con->atual3].ic_dp;
    robos[2].ic_en = con->robo[con->atual3].ic_en;
    robos[2].ic_ep = con->robo[con->atual3].ic_ep;
    robos[2].rb_VRd_max_neg = con->robo[con->atual3].rb_VRd_max_neg;
    robos[2].rb_VRd_max_pos = con->robo[con->atual3].rb_VRd_max_pos;
    robos[2].rb_VRe_max_neg = con->robo[con->atual3].rb_VRe_max_neg;
    robos[2].rb_VRe_max_pos = con->robo[con->atual3].rb_VRe_max_pos;

    if(contador > 2)
    {
        robos[0].vrd_p = Cerebro->robos[0].vrd_p;
        robos[0].vre_p = Cerebro->robos[0].vre_p;
        robos[1].vrd_p = Cerebro->robos[1].vrd_p;
        robos[1].vre_p = Cerebro->robos[1].vre_p;
        robos[2].vrd_p = Cerebro->robos[2].vrd_p;
        robos[2].vre_p = Cerebro->robos[2].vre_p;
    }

    start = clock();
    circle(input,robos[0].get_center_robot(),15, Scalar(0,255,255),1,5,0);
    circle(input,robos[1].get_center_robot(),15, Scalar(0,255,255),1,5,0);
    circle(input,robos[2].get_center_robot(),15, Scalar(0,255,255),1,5,0);
    circle(input,Point(Bola.x,Bola.y),6, Scalar(0,255,255),1,5,0);
    arrowedLine(input,Point(Bola.x,Bola.y),Bola.pred[0],Scalar(255,255,255),1,8,0,0.5);
    arrowedLine(input,Point(Bola.x,Bola.y),Bola.pred[1],Scalar(255,0,255),1,8,0,0.5);
    arrowedLine(input,Point(Bola.x,Bola.y),Bola.pred[2],Scalar(0,255,255),1,8,0,0.5);

    line(input,Machine_of_Robots->rb1_linha[0],Machine_of_Robots->rb1_linha[1],Scalar(0,255,255),1);
    line(input,Machine_of_Robots->rb2_linha[0],Machine_of_Robots->rb2_linha[1],Scalar(0,255,255),1);
    line(input,Machine_of_Robots->rb3_linha[0],Machine_of_Robots->rb3_linha[1],Scalar(0,255,255),1);

    cvtColor(input, input, COLOR_BGR2RGB,3);

    image = QImage((uchar*) input.data, input.cols, input.rows,input.step, QImage::Format_RGB888);
    if(image.width() > 0 && image.height() > 0)
    {
        ui->janela->setFixedWidth(image.width());
        ui->janela->setFixedHeight(image.height());
    }

    ui->janela->setPixmap(QPixmap::fromImage(image));

    end = clock();
    aux = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Plot: " << aux << "ms; ";
    fprintf(arquivo, "Plot: %f ", aux);

    Cerebro->vet1 = Machine_of_Robots->rb2_linha[1];

    start = clock();
    // ESTRATÉGIA
    pos_bola[0] = pos_bola[1];
    pos_bola[1] = Point(Bola.x,Bola.y);

    Cerebro->Setar_Variaveis_jogo(robos,Bola,adversario);

    Cerebro->Setar_Atacante(comando_atacante);
    Cerebro->Setar_Goleiro(comando_goleiro);
    Cerebro->Setar_Zagueiro(comando_zagueiro);

    Cerebro->Executar_estrategia(comando);

    if(comando == -2)
        Cerebro->robos = parar(robos);

    end = clock();
    aux = pow(10,6)*(end-start)/CLOCKS_PER_SEC;
    cout << "Estratégia: " << aux << "us; ";
    cout << endl;
    fprintf(arquivo, "Estratégia: %f\n", aux);

    contador++;

    binary_img_azul = 0;
    binary_img_amarelo = 0;
    binary_img_verde = 0;
    binary_img_vermelho = 0;
    binary_img_magenta = 0;
    binary_img_laranja = 0;

    /*end = clock();
    double aux = 1000*(end-start)/CLOCKS_PER_SEC;
    QString tempo = QString::number(aux);
    ui->milesegundos->setText(tempo);*/

     upatatetaxa++;
    //Atualização das Velocidades
    if(upatatetaxa>10)
    {
        VL_data->pop_front();
        VL_data->push_back(30 + 30*sin(contador));
        VR_data->pop_front();
        VR_data->push_back(60 + 40*cos(contador));
        plotComm();
        upatatetaxa=0;
    }
}

void MainWindow::calibration()
{
    // Verifica aba atual, caso esteja na aba de jogo ele para esse função e parte para a função refresh_robot_position()
    if(ui->tabWidget->currentIndex() == 0)
    {
        cronometro->blockSignals(false);
        cronometro2->blockSignals(true);
    }

    // Ler frame da razer ou webcam qualquer
    if(razer)
    {
        frames = p.wait_for_frames();
        color = frames.get_color_frame();

        // Query frame size (width and height)
        const int w = color.as<rs2::video_frame>().get_width();
        const int h = color.as<rs2::video_frame>().get_height();

        // Create OpenCV matrix of size (w,h) from the colorized depth data
        Mat image(Size(w, h), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
        input = image;
    }
    else
    {
        cap.open("../release/razer_%02d.jpg",CAP_IMAGES);   //Testes plot virtual e calibração
        if(!cap.isOpened())
            QMessageBox::warning(this, tr("Error"), "Câmera não conectada", QMessageBox::Close);

        if(!cap.read(input))
        {
            QMessageBox::warning(this, tr("Error"), "Frame não pode ser aberto", QMessageBox::Close);
            this->close();
        }
    }

    if(ui->checkBox_flip->isChecked())
        flip(input,input,1);

    if(roi.area()!=0 && pontos_corte.size() == 2)
    {
        input = input(roi);
    }

    // Decide se a imagem exibida é a imagem original ou com a limiarização
    if(ui->checkBox_limiar->isChecked())
    {
        Mat *binary_image;
        binary_image = select_Limiar2Segment(input);
        image = QImage((uchar*) binary_image->data, binary_image->cols, binary_image->rows,binary_image->step, QImage::Format_Grayscale8);
        //binary_image->release();
    }
    else
    {
        cvtColor(input, input, COLOR_BGR2RGB,3);
        image = QImage((uchar*) input.data, input.cols, input.rows,input.step, QImage::Format_RGB888);
    }

    if(ui->checkBox_linha_principais->isChecked())
        plotar_principais();

    if(ui->checkBox_linha_secundaria->isChecked())
        plotar_secundarias();

    /*if(image.width() > 0 && image.height() > 0)
    {
        ui->janela_2->setMinimumHeight(image.height());
        ui->janela_2->setMinimumWidth(image.width());
        //cout << image.height() << " " << image.width() << endl;
        //ui->janela_2->setFixedWidth(image.width());
        //ui->janela_2->setFixedHeight(image.height());
    }
    else
        cout << "out" << endl;*/

    if(ui->checkBox_help_lines->isChecked())
    {
        switch(cont_help/40)
        {
            case 0:
                input = imread("../imagens/FG1.PNG");
                break;
            case 1:
                input = imread("../imagens/FG2.PNG");
                break;
            case 2:
                input = imread("../imagens/AL1.PNG");
                break;
            case 3:
                input = imread("../imagens/AL2.PNG");
                break;
            case 4:
                input = imread("../imagens/AL3.PNG");
                break;
            default:
                input = imread("../imagens/FG1.PNG");
                cont_help = 0;
                break;
        }

        image = QImage((uchar*) input.data, input.cols, input.rows,input.step, QImage::Format_RGB888);
        cont_help++;
        cout << "Contador: " << cont_help << endl;
    }

    ui->janela_2->setPixmap(QPixmap::fromImage(image));

    end = clock();
    double aux = 1000*(end-start)/CLOCKS_PER_SEC;
    out << aux << endl;
    QString tempo = QString::number(aux);
    ui->milesegundos->setText(tempo);
    start = clock();
}

MainWindow::~MainWindow()
{
    cap.release();
    /////////////////////////////////// comunicação serial ///////////////////////////////
    encerra_comunicacao_serial();
    /////////////////////////////////// comunicação serial ///////////////////////////////

    fclose(arquivo);
    vector<int> mascara;
    mascara.push_back(ui->comboBox_tipomask->currentIndex());
    mascara.push_back(ui->spinBox_abertura->value());
    mascara.push_back(ui->spinBox_fechamento->value());
    String fileSettings = "../constants/Settings.xml";
    set->WriteSettings(mascara,Blue,Yellow,Green,Orange,Red,Mg,roi,fileSettings);
    set->WriteConfigurationsRobots(con->constantes_rb1,con->constantes_rb2,con->constantes_rb3,con->zona_morta_rb1_positiva,con->zona_morta_rb2_positiva,con->zona_morta_rb3_positiva,"../constants/Constantes.xml");
    delete azul;
    delete amarelo;
    delete vermelho;
    delete verde;
    delete magenta;
    delete laranja;

    delete azul_group;
    delete amarelo_group;
    delete verde_group;
    delete vermelho_group;
    delete magenta_group;
    delete laranja_group;

    delete Machine_of_Robots;

    delete set;
    delete con;
    delete cronometro;
    delete cronometro2;

    input.release();

    out.close();

    delete ui;
}

mouseevents::mouseevents(QWidget *parent) :
     QLabel(parent)
{

}

void mouseevents::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->pos().x();
    this->y = ev->pos().y();
    emit Mouse_pos();
}

void mouseevents::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
        {
            x_press = ev->localPos().x();
            y_press = ev->localPos().y();

            emit Mouse_pressed();

        }
}

void MainWindow::plotComm()
{
    ui->qcustomplot->graph(0)->setData((*x_data), (*VL_data));
    ui->qcustomplot->graph(1)->setData((*x_data), (*VR_data));
    ui->qcustomplot->replot();
}

void MainWindow::DefplotComm()
{
    // generate some data:
    x_data = new QVector<double>(101);
    VL_data = new QVector<double>(101);
    VR_data = new QVector<double>(101);

    for (int i=0; i<100; ++i)
    {
      (*x_data)[i] = i;
      (*VL_data)[i] = 30 + 30*sin(i);
      (*VR_data)[i] = 60 + 40*cos(i);
    }
    // create graph and assign data to it:
    ui->qcustomplot->addGraph();
    ui->qcustomplot->addGraph();
    //ui->widget->graph(1)->setData(x, x);
    ui->qcustomplot->graph(0)->setPen(QPen(Qt::red));
    ui->qcustomplot->graph(1)->setPen(QPen(Qt::blue));
    // give the axes some labels:
    ui->qcustomplot->yAxis->setLabel("Vel");
    // set axes ranges, so we see all data:
    ui->qcustomplot->xAxis->setRange(0, 100);
    ui->qcustomplot->yAxis->setRange(-105, 105);
    //tirando o label inferior
    ui->qcustomplot->xAxis->setVisible(false);
    ui->qcustomplot->replot();
}

void MainWindow::Mouse_current_pos()
{
    ui->label_23->setText(QString("X = %1, Y = %2").arg(ui->janela_2->x).arg(ui->janela_2->y));

    cout << "test" << endl;
}

void MainWindow::Mouse_pressed()
{
    ui->label_23->setText(QString("X = %1, Y = %2").arg(ui->janela_2->x_press).arg(ui->janela_2->y_press));
    cout << "Button Pressed!" <<endl;

    if(action_calib == CORTAR)
    {

        if(pontos_corte.size() < 2)
        {

            pontos_corte.push_back(Point(ui->janela_2->x_press, ui->janela_2->y_press));
            cout << pontos_corte.back() << endl;
            cout << "começa corte" <<endl;

        }
        else
        {
            roi = Rect2d(pontos_corte[0].x,pontos_corte[0].y,abs(pontos_corte[1].x - pontos_corte[0].x),abs(pontos_corte[1].y - pontos_corte[0].y));
            action_calib=0;
            cout << "fim corte" <<endl;
            cout << roi <<endl;

        }


    }


}


void MainWindow::on_actionKmeans_triggered()
{
    con->show();
}

void MainWindow::on_select_azul_triggered()
{
    ui->select_azul->setChecked(true);
    ui->select_amarelo->setChecked(false);
    time = 0;
}

void MainWindow::on_select_amarelo_triggered()
{
    ui->select_azul->setChecked(false);
    ui->select_amarelo->setChecked(true);
    time = 1;
}

void MainWindow::on_actionComandos_triggered()
{

}

void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex() != -1)
      comando = ui->comboBox->currentIndex();

    if(ui->combo_atacante->currentIndex() != -1)
        comando_atacante = ui->combo_atacante->currentIndex();

    if(ui->combo_goleiro->currentIndex() != -1)
        comando_goleiro = ui->combo_goleiro->currentIndex();

    if(ui->combo_zagueiro->currentIndex()!= -1)
        comando_zagueiro = ui->combo_zagueiro->currentIndex();
}

void MainWindow::on_pushButton_2_clicked()
{
    comando = -2;

    cout << "Parou"<< endl;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->combo_goleiro->setCurrentIndex(-1);
    ui->combo_zagueiro->setCurrentIndex(-1);
    ui->combo_atacante->setCurrentIndex(-1);
}

void MainWindow::on_comboBox_activated(int index)
{
    ui->combo_goleiro->setCurrentIndex(-1);
    ui->combo_zagueiro->setCurrentIndex(-1);
    ui->combo_atacante->setCurrentIndex(-1);
}

void MainWindow::on_actionAbrir_Settings_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir arquivo"),".", tr("All files (*.*);;XML (*.xml)"));
    if(!fileName.isNull())
    {
        filename = fileName.toStdString();
        set = new Configurations(cap,filename);

        set->GetThresholdColor(Blue, "Blue");
        set->GetThresholdColor(Red, "Red");
        set->GetThresholdColor(Yellow, "Yellow");
        set->GetThresholdColor(Orange, "Orange");
        set->GetThresholdColor(Mg,"Magenta");
        set->GetThresholdColor(Green,"Green");

        azul= new Segmentation(Mascaras);
        vermelho = new Segmentation(Mascaras);
        amarelo = new Segmentation(Mascaras);
        laranja = new Segmentation(Mascaras);
        magenta = new Segmentation(Mascaras);
        verde = new Segmentation(Mascaras);

        azul_group = new Grouping(3,0);
        amarelo_group = new Grouping(3,0);
        verde_group =  new Grouping(2,0);
        vermelho_group = new Grouping (2,0);
        magenta_group = new Grouping(2,0);
        laranja_group = new Grouping (1,0);

        Machine_of_Robots = new Build_Robot(3);
        Machine_of_Robots->Record_Position(false);
        Machine_of_Robots->Change_dist_cores(25);

        Cerebro = new Strategy();
        Cerebro->Setar_Campo(set);
    }
}

void MainWindow::on_select_RGB_triggered()
{
    ui->select_RGB->setChecked(true);
    ui->select_New_RGB->setChecked(false);
    ui->select_HSV->setChecked(false);
    Color_Space = RGB;
}

void MainWindow::on_select_New_RGB_triggered()
{
    ui->select_RGB->setChecked(false);
    ui->select_New_RGB->setChecked(true);
    ui->select_HSV->setChecked(false);
    Color_Space = NEW_RGB;
}

void MainWindow::on_select_HSV_triggered()
{
    ui->select_RGB->setChecked(false);
    ui->select_New_RGB->setChecked(false);
    ui->select_HSV->setChecked(true);
    Color_Space = HSV;
}
void MainWindow::on_select_HSV_triggered(bool)
{

}

void MainWindow::on_contraste_valueChanged(int value)
{
    if(razer)
        set->set_contraste(color_sensor,value);
    else
        set->set_contraste(cap,value);
}

void MainWindow::on_saturacao_valueChanged(int value)
{
    if(razer)
        set->set_saturacao(color_sensor,value);
    else
        set->set_saturacao(cap,value);
}

void MainWindow::on_brilho_valueChanged(int value)
{
    if(razer)
        set->set_brilho(color_sensor,value);
    else
        set->set_brilho(cap,value);
}

void MainWindow::on_exposicao_valueChanged(int value)
{
    if(razer)
        set->set_exposure(color_sensor,value);
    else
        set->set_exposure(cap,value);
    ui->checkBox_expo_auto->setChecked(false);
}

void MainWindow::on_Resolucao_currentIndexChanged(int index)
{
    if(razer)
         p.stop();
    switch(index)
    {
        case 0:
            if(razer)
                set->set_resolution(cfg,640,360,0);
            else
                set->set_resolution(cap,640,480,0);
            break;
        case 1:
            if(razer)
                set->set_resolution(cfg,848,480,1);
            else
                set->set_resolution(cap,800,600,1);
            break;
        case 2:
            if(razer)
                set->set_resolution(cfg,960,540,2);
            else
                set->set_resolution(cap,1024,768,2);
            break;
        case 3:
            if(razer)
                set->set_resolution(cfg,1280,720,3);
            else
                set->set_resolution(cap,1280,720,3);
            break;
        case 4:
            if(razer)
                set->set_resolution(cfg,1920,1080,4);
            else
                set->set_resolution(cap,1920,1080,4);
            break;
    }
    ui->janela_2->resize(set->width,set->heigth);
    if(razer)
        p.start(cfg);
}

void MainWindow::on_hue_valueChanged(int value)
{
    if(razer)
        set->set_hue(color_sensor,value);
}

void MainWindow::on_white_balance_valueChanged(int value)
{
    if(razer)
        set->set_whiteBalance(color_sensor,value);
    ui->checkBox_wb_auto->setChecked(false);
}

void MainWindow::on_Gamma_valueChanged(int value)
{
    if(razer)
        set->set_gamma(color_sensor,value);
}

void MainWindow::on_Gain_valueChanged(int value)
{
    if(razer)
        set->set_gain(color_sensor,value);
}

void MainWindow::on_Back_Compensation_valueChanged(int value)
{
    if(razer)
        set->set_backlight_compensation(color_sensor,value);
}

void MainWindow::on_nitidez_valueChanged(int value)
{
    if(razer)
        set->set_nitidez(color_sensor,value);
}

Mat *MainWindow::select_Limiar2Segment(Mat input)
{
    if(ui->comboBox_colors->currentIndex() == 0)
        return azul->Segmentation_Result(&input);
    else if(ui->comboBox_colors->currentIndex() == 1)
        return amarelo->Segmentation_Result(&input);
    else if(ui->comboBox_colors->currentIndex() == 2)
        return verde->Segmentation_Result(&input);
    else if(ui->comboBox_colors->currentIndex() == 3)
        return laranja->Segmentation_Result(&input);
    else if(ui->comboBox_colors->currentIndex() == 4)
        return vermelho->Segmentation_Result(&input);
    else
        return magenta->Segmentation_Result(&input);
}

void MainWindow::change_limiares(int value, int row, int col)
{
    if(ui->comboBox_colors->currentIndex() == 0)
    {
        Blue[row][col] = value;
        azul->Get_Limiar_RGB(Blue[0],Blue[1]);
    }
    else if(ui->comboBox_colors->currentIndex() == 1)
    {
        Yellow[row][col] = value;
        amarelo->Get_Limiar_RGB(Yellow[0],Yellow[1]);
    }
    else if(ui->comboBox_colors->currentIndex() == 2)
    {
        Green[row][col] = value;
        verde->Get_Limiar_RGB(Green[0],Green[1]);
    }
    else if(ui->comboBox_colors->currentIndex() == 3)
    {
        Orange[row][col] = value;
        laranja->Get_Limiar_RGB(Orange[0],Orange[1]);
    }
    else if(ui->comboBox_colors->currentIndex() == 4)
    {
        Red[row][col] = value;
        vermelho->Get_Limiar_RGB(Red[0],Red[1]);
    }
    else if(ui->comboBox_colors->currentIndex() == 5)
    {
        Mg[row][col] = value;
        magenta->Get_Limiar_RGB(Mg[0],Mg[1]);
    }
}

void MainWindow::on_bmin_valueChanged(int value)
{
    change_limiares(value,0,0);
}

void MainWindow::on_gmin_valueChanged(int value)
{
    change_limiares(value,0,1);
}

void MainWindow::on_rmin_valueChanged(int value)
{
    change_limiares(value,0,2);
}

void MainWindow::on_bmax_valueChanged(int value)
{
    change_limiares(value,1,0);
}

void MainWindow::on_gmax_valueChanged(int value)
{
    change_limiares(value,1,1);
}

void MainWindow::on_rmax_valueChanged(int value)
{
    change_limiares(value,1,2);
}

void MainWindow::on_comboBox_colors_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->bmin->setValue(Blue[min][B]);
        ui->gmin->setValue(Blue[min][G]);
        ui->rmin->setValue(Blue[min][R]);
        ui->bmax->setValue(Blue[max][B]);
        ui->gmax->setValue(Blue[max][G]);
        ui->rmax->setValue(Blue[max][R]);
    }
    else if(index == 1)
    {
        ui->bmin->setValue(Yellow[min][B]);
        ui->gmin->setValue(Yellow[min][G]);
        ui->rmin->setValue(Yellow[min][R]);
        ui->bmax->setValue(Yellow[max][B]);
        ui->gmax->setValue(Yellow[max][G]);
        ui->rmax->setValue(Yellow[max][R]);
    }
    else if(index == 2)
    {
        ui->bmin->setValue(Green[min][B]);
        ui->gmin->setValue(Green[min][G]);
        ui->rmin->setValue(Green[min][R]);
        ui->bmax->setValue(Green[max][B]);
        ui->gmax->setValue(Green[max][G]);
        ui->rmax->setValue(Green[max][R]);
    }
    else if(index == 3)
    {
        ui->bmin->setValue(Orange[min][B]);
        ui->gmin->setValue(Orange[min][G]);
        ui->rmin->setValue(Orange[min][R]);
        ui->bmax->setValue(Orange[max][B]);
        ui->gmax->setValue(Orange[max][G]);
        ui->rmax->setValue(Orange[max][R]);
    }
    else if(index == 4)
    {
        ui->bmin->setValue(Red[min][B]);
        ui->gmin->setValue(Red[min][G]);
        ui->rmin->setValue(Red[min][R]);
        ui->bmax->setValue(Red[max][B]);
        ui->gmax->setValue(Red[max][G]);
        ui->rmax->setValue(Red[max][R]);
    }
    else if(index == 5)
    {
        ui->bmin->setValue(Mg[min][B]);
        ui->gmin->setValue(Mg[min][G]);
        ui->rmin->setValue(Mg[min][R]);
        ui->bmax->setValue(Mg[max][B]);
        ui->gmax->setValue(Mg[max][G]);
        ui->rmax->setValue(Mg[max][R]);
    }
}

void MainWindow::set_ui_values()
{
    // Set Combo Boxes
    on_comboBox_colors_currentIndexChanged(0);
    ui->comboBox_tipomask->setCurrentIndex(set->tipo_mask);
    ui->Resolucao->setCurrentIndex(set->index);

    // Set SpinBoxes
    ui->spinBox_abertura->setValue(set->abertura);
    ui->spinBox_fechamento->setValue(set->fechamento);
    ui->spinBox_cut_x->setValue(roi.x);
    ui->spinBox_cut_y->setValue(roi.y);
    ui->spinBox_cut_width->setValue(roi.width);
    ui->spinBox_cut_height->setValue(roi.height);

    // Set Sliders config
    ui->brilho->setValue(set->brilho);
    ui->contraste->setValue(set->contraste);
    ui->Back_Compensation->setValue(set->backlight_compensantion);
    ui->saturacao->setValue(set->saturacao);
    ui->hue->setValue(set->hue);
    ui->nitidez->setValue(set->nitidez);
    ui->white_balance->setValue(set->whiteBalance);
    ui->Gain->setValue(set->gain);
    ui->Gamma->setValue(set->gamma);
    ui->exposicao->setValue(set->exposure);

    // Set CheckBoxes
    ui->checkBox_expo_auto->setChecked(set->auto_exposure);
    on_checkBox_expo_auto_clicked(set->auto_exposure);
    ui->checkBox_wb_auto->setChecked(set->auto_whiteBalance);
    on_checkBox_wb_auto_clicked(set->auto_whiteBalance);

    // Set SpinBoxes Campo
    ui->spinBox_area_boty->setValue(set->area_boty);
    ui->spinBox_area_left->setValue(set->area_left);
    ui->spinBox_area_right->setValue(set->area_right);
    ui->spinBox_area_topy->setValue(set->area_topy);
    ui->spinBox_fbot->setValue(set->fbot);
    ui->spinBox_ftop->setValue(set->ftop);
    ui->spinBox_fleftx->setValue(set->fleftx);
    ui->spinBox_frightx->setValue(set->frightx);
    ui->spinBox_gleft->setValue(set->gleft);
    ui->spinBox_gright->setValue(set->gright);
    ui->spinBox_lgoleiro->setValue(set->lgoleiro);
    ui->spinBox_lzagueiro->setValue(set->lzagueiro);
    ui->spinBox_p_area_b->setValue(set->p_area_b);
    ui->spinBox_p_area_t->setValue(set->p_area_t);
}

void MainWindow::on_spinBox_abertura_valueChanged(int arg1)
{
    Mat elementOpening = getStructuringElement(ui->comboBox_tipomask->currentIndex(), Size(arg1,arg1), Point(-1, -1));
    Mat elementClosing = getStructuringElement(ui->comboBox_tipomask->currentIndex(), Size(ui->spinBox_fechamento->value(), ui->spinBox_fechamento->value()), Point(-1, -1));
    Mascaras[0] = elementOpening;
    Mascaras[1] = elementClosing;
    set_mascaras();
}

void MainWindow::on_spinBox_fechamento_valueChanged(int arg1)
{
    Mat elementClosing = getStructuringElement(ui->comboBox_tipomask->currentIndex(), Size(arg1,arg1), Point(-1, -1));
    Mat elementOpening = getStructuringElement(ui->comboBox_tipomask->currentIndex(), Size(ui->spinBox_abertura->value(), ui->spinBox_abertura->value()), Point(-1, -1));
    Mascaras[0] = elementOpening;
    Mascaras[1] = elementClosing;
    set_mascaras();
}

void MainWindow::on_comboBox_tipomask_currentIndexChanged(int index)
{
    Mat elementOpening = getStructuringElement(index, Size(ui->spinBox_abertura->value(),   ui->spinBox_abertura->value()  ), Point(-1, -1));
    Mat elementClosing = getStructuringElement(index, Size(ui->spinBox_fechamento->value(), ui->spinBox_fechamento->value()), Point(-1, -1));
    Mascaras[0] = elementOpening;
    Mascaras[1] = elementClosing;
    set_mascaras();
}

void MainWindow::set_mascaras()
{
    azul     = new Segmentation(Mascaras);
    amarelo  = new Segmentation(Mascaras);
    laranja  = new Segmentation(Mascaras);
    verde    = new Segmentation(Mascaras);
    vermelho  = new Segmentation(Mascaras);
    magenta   = new Segmentation(Mascaras);

    azul->Get_Limiar_RGB(Blue[0],Blue[1]);
    amarelo->Get_Limiar_RGB(Yellow[0],Yellow[1]);
    verde->Get_Limiar_RGB(Green[0],Green[1]);
    laranja->Get_Limiar_RGB(Orange[0],Orange[1]);
    vermelho->Get_Limiar_RGB(Red[0],Red[1]);
    magenta->Get_Limiar_RGB(Mg[0],Mg[1]);

}

void MainWindow::on_spinBox_cut_y_valueChanged(int arg1)
{
    roi.y = arg1;
}

void MainWindow::on_spinBox_cut_x_valueChanged(int arg1)
{
    roi.x = arg1;
}

void MainWindow::on_spinBox_cut_width_valueChanged(int arg1)
{
    roi.width = arg1;
}

void MainWindow::on_spinBox_cut_height_valueChanged(int arg1)
{
    roi.height = arg1;
}

void MainWindow::on_checkBox_expo_auto_clicked(bool checked)
{
    if(razer)
        set->set_auto_exposure(color_sensor,checked);
}

void MainWindow::on_checkBox_wb_auto_clicked(bool checked)
{
    if(razer)
        set->set_auto_whiteBalance(color_sensor,checked);
}

//Variáveis do campo
void MainWindow::on_pushButton_linhas_campo_clicked()
{
    set->fbot = input.rows * 0.0185;
    ui->spinBox_fbot->setValue(set->fbot);
    set->ftop = input.rows * 0.9815;
    ui->spinBox_ftop->setValue(set->ftop);
    set->gboty = input.rows * 0.352;
    ui->spinBox_gboty->setValue(set->gboty);
    set->gtopy = input.rows * 0.648;
    ui->spinBox_gtopy->setValue(set->gtopy);

    set->gleft = input.cols * 0.014;
    ui->spinBox_gleft->setValue(set->gleft);
    set->gright = input.cols * 0.986;
    ui->spinBox_gright->setValue(set->gright);
    set->fleftx = input.cols * 0.072;
    ui->spinBox_fleftx->setValue(set->fleftx);
    set->frightx = input.cols * 0.928;
    ui->spinBox_frightx->setValue(set->frightx);

    set->area_left = input.cols * 0.157;
    ui->spinBox_area_left->setValue(set->area_left);
    set->area_right = input.cols * 0.843;
    ui->spinBox_area_right->setValue(set->area_right);
    set->area_boty = input.rows * 0.186;
    ui->spinBox_area_boty->setValue(set->area_boty);
    set->area_topy = input.rows * 0.814;
    ui->spinBox_area_topy->setValue(set->area_topy);

    set->lgoleiro = input.cols * 0.088;
    ui->spinBox_lgoleiro->setValue(set->lgoleiro);
    set->lzagueiro = input.cols * 0.286;
    ui->spinBox_lzagueiro->setValue(set->lzagueiro);

    set->p_area_b = input.rows * 0.426;
    ui->spinBox_p_area_b->setValue(set->p_area_b);
    set->p_area_t = input.rows * 0.574;
    ui->spinBox_p_area_t->setValue(set->p_area_t);
}

void MainWindow::plotar_principais()
{
    line(input,Point(0,set->ftop)   ,Point(input.cols,set->ftop)   ,Scalar(0,255,0));
    line(input,Point(0,set->fbot)   ,Point(input.cols,set->fbot)   ,Scalar(0,255,0));
    line(input,Point(0,set->gtopy)  ,Point(input.cols,set->gtopy)  ,Scalar(0,255,0));
    line(input,Point(0,set->gboty)  ,Point(input.cols,set->gboty)  ,Scalar(0,255,0));
    line(input,Point(set->fleftx,0) ,Point(set->fleftx,input.rows) ,Scalar(0,255,0));
    line(input,Point(set->frightx,0),Point(set->frightx,input.rows),Scalar(0,255,0));
    line(input,Point(set->gleft,0)  ,Point(set->gleft,input.rows)  ,Scalar(0,255,0));
    line(input,Point(set->gright,0) ,Point(set->gright,input.rows) ,Scalar(0,255,0));
}

void MainWindow::plotar_secundarias()
{
    line(input,Point(0,set->area_boty)  ,Point(input.cols,set->area_boty)  ,Scalar(0,0,255));
    line(input,Point(0,set->area_topy)  ,Point(input.cols,set->area_topy)  ,Scalar(0,0,255));
    line(input,Point(0,set->p_area_b),Point(input.cols,set->p_area_b),Scalar(0,0,255));
    line(input,Point(0,set->p_area_t),Point(input.cols,set->p_area_t),Scalar(0,0,255));
    line(input,Point(set->lgoleiro,0)   ,Point(set->lgoleiro,input.rows)   ,Scalar(255,0,0));
    line(input,Point(set->lzagueiro,0)  ,Point(set->lzagueiro,input.rows)  ,Scalar(255,0,0));
    line(input,Point(set->area_left,0)  ,Point(set->area_left,input.rows)  ,Scalar(0,0,255));
    line(input,Point(set->area_right,0) ,Point(set->area_right,input.rows) ,Scalar(0,0,255));
}

void MainWindow::on_spinBox_ftop_valueChanged(int arg1)
{
    set->ftop = arg1;
}

void MainWindow::on_spinBox_fbot_valueChanged(int arg1)
{
    set->fbot = arg1;
}

void MainWindow::on_spinBox_gtopy_valueChanged(int arg1)
{
    set->gtopy = arg1;
}

void MainWindow::on_spinBox_gboty_valueChanged(int arg1)
{
    set->gboty = arg1;
}

void MainWindow::on_spinBox_fleftx_valueChanged(int arg1)
{
    set->fleftx = arg1;
}

void MainWindow::on_spinBox_frightx_valueChanged(int arg1)
{
    set->frightx = arg1;
}

void MainWindow::on_spinBox_gleft_valueChanged(int arg1)
{
    set->gleft = arg1;
}

void MainWindow::on_spinBox_gright_valueChanged(int arg1)
{
    set->gright = arg1;
}

void MainWindow::on_spinBox_area_left_valueChanged(int arg1)
{
    set->area_left = arg1;
}

void MainWindow::on_spinBox_area_right_valueChanged(int arg1)
{
    set->area_right = arg1;
}

void MainWindow::on_spinBox_lzagueiro_valueChanged(int arg1)
{
    set->lzagueiro = arg1;
}

void MainWindow::on_spinBox_lgoleiro_valueChanged(int arg1)
{
    set->lgoleiro = arg1;
}

void MainWindow::on_spinBox_area_topy_valueChanged(int arg1)
{
    set->area_topy = arg1;
}

void MainWindow::on_spinBox_area_boty_valueChanged(int arg1)
{
    set->area_boty = arg1;
}

void MainWindow::on_spinBox_p_area_b_valueChanged(int arg1)
{
    set->p_area_b = arg1;
}

void MainWindow::on_spinBox_p_area_t_valueChanged(int arg1)
{
    set->p_area_t = arg1;
}

void MainWindow::on_pushButton_cortar_clicked()
{
   // set->cropper = selectROI(input);  // Em Configurações configurar envio para arquivo xml
    action_calib = 1;
    pontos_corte.clear();


}

void MainWindow::on_checkBox_help_lines_pressed()
{

}

void MainWindow::on_checkBox_help_lines_clicked(bool checked)
{
    if(checked)
        cont_help = 0;
}

void MainWindow::on_refresh_ports_clicked()
{
    SerialComm->checkSerial();
    ui->select_ports->clear();
    info_ports();

}

void MainWindow::info_ports()
{
    ui->select_ports->insertItems(0,SerialComm->list_port);
    ui->status->setText(SerialComm->status);
    ui->monitor->setText(SerialComm->baund_rate);
    ui->connect_disconnect->setText(SerialComm->button_status);
}

void MainWindow::on_read_data_clicked()
{
    SerialComm->readData();
    ui->receive_data->setText(SerialComm->receive_data);
    info_ports();
    ui->lcdNumber->display(SerialComm->byte_lido[0]);
    ui->lcdNumber_2->display(SerialComm->byte_lido[1]);



}

void MainWindow::on_write_data_clicked()
{
    SerialComm->writeData();
    info_ports();

}

void MainWindow::on_connect_disconnect_clicked()
{
    SerialComm->def_port(ui->select_ports->currentText());
    SerialComm->connectToSerial();
    info_ports();
}

void MainWindow::on_sendvl_valueChanged(int value)
{
    int index = ui->select_robo->currentIndex();
    if(index == 0)
    {
        for(int i = 1; i<10 ;i+=2)
        {
            SerialComm->write_buf[i]=SerialComm->converter_write(value);
        }
    }
    else
    {
        for(int i = 1; i<10 ;i+=2)
        {
            SerialComm->write_buf[i]=0;
        }
        SerialComm->write_buf[2*index-1]=SerialComm->converter_write(value);

    }

}

void MainWindow::on_sendvr_valueChanged(int value)
{
    int index = ui->select_robo->currentIndex();
    if(index == 0)
    {
        for(int i = 2; i<=10 ;i+=2)
        {
            SerialComm->write_buf[i]=SerialComm->converter_write(value);
        }
    }
    else
    {
        for(int i = 2; i<=10 ;i+=2)
        {
            SerialComm->write_buf[i]=0;
        }
        SerialComm->write_buf[2*index]=SerialComm->converter_write(value);

    }
}


