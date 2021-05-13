#include "../include/Configurations.h"
#include "../include/constantes_robot.h"

void Configurations::set_contraste(VideoCapture cap ,int contrast)
{
    this->contraste = contrast;
    cap.set(CAP_PROP_CONTRAST, this->contraste);
    usleep(30 * 100);
}

void Configurations::set_contraste(sensor color_sensor ,int contrast)
{
    this->contraste = contrast;
    color_sensor.set_option(RS2_OPTION_CONTRAST,contrast);
}

void Configurations::set_exposure(sensor color_sensor, int exposicao)
{
    this->exposure = exposicao;
    color_sensor.set_option(RS2_OPTION_EXPOSURE,exposicao);
}

void Configurations::set_saturacao(VideoCapture cap, int sat)
{
    this->saturacao = sat;
    cap.set(CAP_PROP_SATURATION, this->saturacao);
    usleep(30 * 100);
}

void Configurations::set_saturacao(sensor color_sensor, int sat)
{
    this->saturacao = sat;
    color_sensor.set_option(RS2_OPTION_SATURATION,sat);
}

void Configurations::set_brilho(VideoCapture cap, int bri)
{
    this->brilho = bri;
    cap.set(CAP_PROP_BRIGHTNESS, this->brilho + 1);
    usleep(30 * 100);
    cap.set(CAP_PROP_BRIGHTNESS, this->brilho);
    usleep(30 * 100);
}

void Configurations::set_exposure(VideoCapture cap, int exp)
{
    this->exposure = exp;
    usleep(30 * 1000);
    cap.set(CAP_PROP_EXPOSURE, exp);
    usleep(30 * 1000);
    cap.set(CAP_PROP_BRIGHTNESS, brilho + 1);
    usleep(30 * 1000);
    cap.set(CAP_PROP_BRIGHTNESS, brilho);
}

void Configurations::set_brilho(sensor color_sensor, int bri)
{
    this->brilho = bri;
    color_sensor.set_option(RS2_OPTION_BRIGHTNESS,bri);
}

void Configurations::set_hue(sensor color_sensor, int hue)
{
    this->hue = hue;
    color_sensor.set_option(RS2_OPTION_HUE,hue);
}

void Configurations::set_whiteBalance(sensor color_sensor, int wb)
{
    this->whiteBalance = wb;
    color_sensor.set_option(RS2_OPTION_WHITE_BALANCE,wb);
}

void Configurations::set_auto_whiteBalance(sensor color_sensor, bool auto_wb)
{
    this->auto_whiteBalance = auto_wb;
    color_sensor.set_option(RS2_OPTION_ENABLE_AUTO_WHITE_BALANCE,auto_wb);
}

void Configurations::set_auto_exposure(sensor color_sensor, bool auto_expo)
{
    this->auto_exposure = auto_expo;
    color_sensor.set_option(RS2_OPTION_ENABLE_AUTO_EXPOSURE,auto_expo);
}

void Configurations::set_gamma(sensor color_sensor, int gam)
{
    this->gamma = gam;
    color_sensor.set_option(RS2_OPTION_GAMMA,gam);
}

void Configurations::set_gain(sensor color_sensor, int gain)
{
    this->gain = gain;
    color_sensor.set_option(RS2_OPTION_GAIN,gain);
}

void Configurations::set_nitidez(sensor color_sensor, int nitidez)
{
    this->nitidez = nitidez;
    color_sensor.set_option(RS2_OPTION_SHARPNESS,nitidez);
}

void Configurations::set_backlight_compensation(sensor color_sensor, int bc)
{
    this->backlight_compensantion = bc;
    color_sensor.set_option(RS2_OPTION_BACKLIGHT_COMPENSATION,bc);
}

void Configurations::set_resolution(VideoCapture cap, int width, int heigth, int ind)
{
    this->width = width;
    this->heigth = heigth;
    this->index = ind;
    usleep(30 * 1000);
    cap.set(CAP_PROP_FRAME_WIDTH , width);
    usleep(30 * 1000);
    cap.set(CAP_PROP_FRAME_HEIGHT , heigth);
    usleep(30 * 1000);
}

void Configurations::set_resolution(config cfg, int width, int heigth, int ind)
{
    this->width = width;
    this->heigth = heigth;
    this->index =  ind;

    cfg.disable_all_streams();

    int fps = 60;

    if(width > 1900)
        fps = 30;
    cfg.enable_stream(RS2_STREAM_COLOR, width, heigth, RS2_FORMAT_BGR8, fps);
}

Configurations::Configurations(VideoCapture cap, String filename)
{
	fs.open(filename, FileStorage::READ);
    if(!fs.isOpened())
    {
        cerr << filename << " FAIL!" << endl;

    }
	GetAndSetConfigurationsCamera(cap);
    GetVariaveisCampo();
}

Configurations::Configurations(config cfg, String filename)
{
    fs.open(filename, FileStorage::READ);
    if(!fs.isOpened())
    {
        cerr << filename << " FAIL!" << endl;

    }
    GetAndSetConfigurationsCamera(cfg);
    GetVariaveisCampo();
}

void Configurations::GetAndSetConfigurationsCamera(config cfg)
{
    FileNode data2 = fs["Resolution"];
    if (data2.empty())
        cerr << "Node Resolution is empty! FAIL" << endl;
    usleep(30 * 1000);
    //cfg.enable_stream(RS2_STREAM_COLOR, (int)(data2["Width"]), (int)(data2["Height"]), RS2_FORMAT_BGR8, 60);
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 60);
    this->width = (int)(data2["Width"]);
    this->heigth = (int)(data2["Height"]);
    this->index = (int)(data2["index"]);

    FileNode data = fs["Camera_Settings"];
    if (data.empty())
        cerr << "Node Camera_Settings is empty! FAIL" << endl;

    this->contraste = (int)(data["Contrast"]);
    this->saturacao = (int)(data["Saturation"]);
    this->exposure = (int)(data["Exposure"]);
    this->brilho = (int)(data["Brightness"]);
    this->gamma = (int)(data["Gamma"]);
    this->gain = (int)(data["Ganho"]);
    this->nitidez = (int)(data["Nitidez"]);
    this->whiteBalance = (int)(data["WhiteBalance"]);
    this->hue = (int)(data["Matiz"]);
    this->backlight_compensantion = (int)(data["Luz_fundo"]);
    this->auto_exposure = (int)(data["ExpoAuto"]);
    this->auto_whiteBalance = (int)(data["WhiteBalAuto"]);
}

void Configurations::GetAndSetConfigurationsCamera(VideoCapture cap)
{
    FileNode data2 = fs["Resolution"];
    if (data2.empty())
        cerr << "Node Resolution is empty! FAIL" << endl;
    usleep(30 * 1000);
    cap.set(CAP_PROP_FRAME_WIDTH ,(int)(data2["Width"]));
    usleep(30 * 1000);
    cap.set(CAP_PROP_FRAME_HEIGHT , (int)(data2["Height"]));
    usleep(30 * 1000);

    FileNode data = fs["Camera_Settings"];
    if (data.empty())
        cerr << "Node Camera_Settings is empty! FAIL" << endl;
    usleep(30 * 1000);
    cap.set(CAP_PROP_EXPOSURE, (int)(data["Exposure"]));
    usleep(30 * 1000);
    cap.set(CAP_PROP_CONTRAST, (int)(data["Contrast"]));
    usleep(30 * 1000);
    cap.set(CAP_PROP_SATURATION, (int)(data["Saturation"]));
    usleep(30 * 1000);
    cap.set(CAP_PROP_EXPOSURE, (int)(data["Exposure"]));
    usleep(30 * 1000);
    cap.set(CAP_PROP_BRIGHTNESS, (int)(data["Brightness"]) + 1);
    usleep(30 * 1000);
    cap.set(CAP_PROP_BRIGHTNESS, (int)(data["Brightness"]));
    usleep(30 * 1000);
}

vector<int> Configurations::GetSettingsAnyData(String dataName)
{
	FileNode data = fs[dataName];
    if (data.empty())
    {
        cerr << dataName <<" in getsettingsanydata() is empty! FAIL" << endl;
    }

    vector <int> l;
	int i = 0;
	FileNodeIterator it = data.begin(), it_end = data.end();
	for (; it != it_end; ++it)
	{
		l[i] = (int)*it;
		i++;
	}
	return l;
}

Rect Configurations::GetCutFramePoints()
{
	FileNode data = fs["Cut_Frame_Points"];
    if (data.empty())
    {
        cerr << "Cut_Frame_Points is empty! FAIL" << endl;
    }

	Rect cut((int)(data["X"]), (int)(data["Y"]), (int)(data["Width"]), (int)(data["Height"]));
	return cut;
}

void Configurations::GetThresholdColor(Scalar *Threshold, String ColorName)
{
	FileNode data = fs[ColorName];
    if (data.empty())
    {
        cerr << ColorName <<" is empty! FAIL" << endl;
    }
	Scalar aux1((int)(data["Blue_Min"]), (int)(data["Green_Min"]), (int)(data["Red_Min"]));
	Scalar aux2((int)(data["Blue_Max"]), (int)(data["Green_Max"]), (int)(data["Red_Max"]));
	Threshold[0] = aux1;
	Threshold[1] = aux2;
}

void Configurations::GetThresholdColor_NEWRGB(Scalar *Threshold,Scalar *Threshold2 , String ColorName)
{
    FileNode data = fs[ColorName];
    if (data.empty())
    {
        cerr << ColorName <<" is empty! FAIL" << endl;
    }
    Scalar aux1((int)(data["Blue_Min_2"]), (int)(data["Green_Min_2"]), (int)(data["Red_Min_2"]));
    Scalar aux2((int)(data["Blue_Max_2"]), (int)(data["Green_Max_2"]), (int)(data["Red_Max_2"]));

    Scalar aux3((int)(data["Red_Green_Min"]), (int)(data["Red_Blue_Min"]), (int)(data["Green_Blue_Min"]));
    Scalar aux4((int)(data["Red_Green_Max"]), (int)(data["Red_Blue_Max"]), (int)(data["Green_Blue_Max"]));

    Threshold[0] = aux1;
    Threshold[1] = aux2;

    Threshold2[0] = aux3;
    Threshold2[1] = aux4;
}

void Configurations::GetThresholdColor_HSV(Scalar *Threshold, String ColorName)
{
    FileNode data = fs[ColorName];
    if (data.empty())
    {
        cerr << ColorName <<" is empty! FAIL" << endl;
    }
    Scalar aux1((int)(data["H_Min"]), (int)(data["S_Min"]), (int)(data["V_Min"]));
    Scalar aux2((int)(data["H_Max"]), (int)(data["S_Max"]), (int)(data["V_Max"]));
    Threshold[0] = aux1;
    Threshold[1] = aux2;
}

void Configurations::GetConfigurationsElement(Mat *Mascaras)
{
	FileNode data = fs["Mascara"];
    if (data.empty())
    {
        cerr << "Mascara" <<" is empty! FAIL" << endl;
    }
	Mat elementOpening = getStructuringElement((int)(data["Format"]), Size((int)(data["Size"]), (int)(data["Size"])), Point(-1, -1));
	Mat elementClosing = getStructuringElement((int)(data["Format"]), Size((int)(data["Size_close"]), (int)(data["Size_close"])), Point(-1, -1));
	Mascaras[0] = elementOpening;
	Mascaras[1] = elementClosing;
    tipo_mask = data["Format"];
    abertura = data["Size"];
    fechamento = data["Size_close"];
}

void Configurations::GetVariaveisCampo()
{
    FileNode data = fs["Variaveis"];
    if (data.empty())
        cerr << "Variaveis" <<" is empty! FAIL" << endl;
    ftop = (int)(data["ftop"]);
    fbot = (int)(data["fbot"]);
    gtopy = (int)(data["gtopy"]);
    gboty = (int)(data["gboty"]);
    fleftx = (int)(data["fleftx"]);
    frightx = (int)(data["frightx"]);
    gleft = (int)(data["gleft"]);
    gright = (int)(data["gright"]);
    area_left = (int)(data["area_left"]);
    area_right = (int)(data["area_right"]);
    lgoleiro = (int)(data["lgoleiro"]);
    lzagueiro = (int)(data["lzagueiro"]);
    area_topy = (int)(data["area_topy"]);
    area_boty = (int)(data["area_boty"]);
    p_area_b = (int)(data["p_area_b"]);
    p_area_t = (int)(data["p_area_t"]);
    tam_robo = (area_topy - gtopy) / 2;
    diametro_robo = fleftx - gleft;
    meio_campo_x = (frightx - fleftx) / 2 + fleftx;
    meio_campo_y = (ftop - fbot) / 2 + fbot;
}

void Configurations::ReadConfigurationsRobots(String filename)
{
    double k_lin;
    double k_ang;
    double v_max;
    double w_max;

    int zonamorta_d;
    int zonamorta_e;

    double k_lin2;
    double k_ang2;
    double v_max2;
    double w_max2;

    int zonamorta_d2;
    int zonamorta_e2;

    double k_lin3;
    double k_ang3;
    double v_max3;
    double w_max3;

    int zonamorta_d3;
    int zonamorta_e3;

    fs2.open(filename, FileStorage::READ);
    if(!fs.isOpened())
    {
        cerr << filename << " FAIL!" << endl;

    }

    FileNode data = fs2["Variaveis_RB1"];
    if (!data.empty())
    {
        k_lin = (double)(data["K_LIN"]);
        k_ang = (double)(data["K_ANG"]);
        v_max = (double)(data["V_MAX"]);
        w_max = (double)(data["W_MAX"]);

        zonamorta_d = (double)(data["ZONA_MORTA_D"]);
        zonamorta_e = (double)(data["ZONA_MORTA_E"]);
    }
    else
    {
        cout << "erro - config.cpp ln 164" << endl;
        k_lin = 0.008;
        k_ang = 0.288;
        v_max = 0.440;
        w_max = -0.850;

        zonamorta_d = 35;
        zonamorta_e = 35;
    }

    FileNode data2 = fs2["Variaveis_RB2"];
    if (!data2.empty())
    {
        k_lin2 = (double)(data2["K_LIN"]);
        k_ang2 = (double)(data2["K_ANG"]);
        v_max2 = (double)(data2["V_MAX"]);
        w_max2 = (double)(data2["W_MAX"]);

        zonamorta_d2 = (double)(data2["ZONA_MORTA_D"]);
        zonamorta_e2 = (double)(data2["ZONA_MORTA_E"]);
    }
    else
    {
        cout << "erro - config.cpp ln 188" << endl;
        k_lin2 = 0.002;
        k_ang2 = 0.1;
        v_max2 = 1;
        w_max2 = -1;

        zonamorta_d2 = 35;
        zonamorta_e2 = 35;
    }

    FileNode data3 = fs2["Variaveis_RB3"];
    if (!data3.empty())
    {
        k_lin3 = (double)(data2["K_LIN"]);
        k_ang3 = (double)(data2["K_ANG"]);
        v_max3 = (double)(data2["V_MAX"]);
        w_max3 = (double)(data2["W_MAX"]);

        zonamorta_d3 = (double)(data2["ZONA_MORTA_D"]);
        zonamorta_e3 = (double)(data2["ZONA_MORTA_E"]);
    }
    else
    {
        cout << "erro - config.cpp ln 213" << endl;
        k_lin3 = 0.002;
        k_ang3 = 0.1;
        v_max3 = 1;
        w_max3 = -1;

        zonamorta_d3 = 35;
        zonamorta_e3 = 35;
    }

    rb1[0] = v_max;
    rb1[1] = k_lin;
    rb1[2] = w_max;
    rb1[3] = k_ang;

    rb2[0] = v_max2;
    rb2[1] = k_lin2;
    rb2[2] = w_max2;
    rb2[3] = k_ang2;

    rb3[0] = v_max3;
    rb3[1] = k_lin3;
    rb3[2] = w_max3;
    rb3[3] = k_ang3;

    zonamorta_rb1[0] = zonamorta_d;
    zonamorta_rb1[1] = zonamorta_e;

    zonamorta_rb2[0] = zonamorta_d2;
    zonamorta_rb2[1] = zonamorta_e2;

    zonamorta_rb3[0] = zonamorta_d3;
    zonamorta_rb3[1] = zonamorta_e3;
}

void Configurations::WriteConfigurationsRobots(double *rb1, double *rb2, double *rb3, int *zona1, int *zona2, int *zona3, String filename)
{
    fs2.open(filename, FileStorage::WRITE);
    fs2 << "Variaveis_RB1";
    fs2 << "{" << "V_MAX" << rb1[0];
    fs2 <<        "K_LIN" << rb1[1];
    fs2 <<        "W_MAX" << rb1[2];
    fs2 <<        "K_ANG" << rb1[3];
    fs2 <<        "ZONA_MORTA_D" << zona1[0];
    fs2 <<        "ZONA_MORTA_E" << zona1[1] << "}";
    fs2 << "Variaveis_RB2";
    fs2 << "{" << "V_MAX" << rb2[0];
    fs2 <<        "K_LIN" << rb2[1];
    fs2 <<        "W_MAX" << rb2[2];
    fs2 <<        "K_ANG" << rb2[3];
    fs2 <<        "ZONA_MORTA_D" << zona2[0];
    fs2 <<        "ZONA_MORTA_E" << zona2[1] << "}";
    fs2 << "Variaveis_RB3";
    fs2 << "{" << "V_MAX" << rb3[0];
    fs2 <<        "K_LIN" << rb3[1];
    fs2 <<        "W_MAX" << rb3[2];
    fs2 <<        "K_ANG" << rb3[3];
    fs2 <<        "ZONA_MORTA_D" << zona3[0];
    fs2 <<        "ZONA_MORTA_E" << zona3[1] << "}";
}

void Configurations::WriteSettings(vector<int> mascara, Scalar *Blue, Scalar *Yellow, Scalar *Green, Scalar *Orange, Scalar *Red, Scalar *Mg, Rect roi, String filename)
{
    Scalar b_min = Blue[0], b_max = Blue[1];
    Scalar g_min = Green[0], g_max = Green[1];
    Scalar y_min = Yellow[0], y_max = Yellow[1];
    Scalar o_min = Orange[0], o_max = Orange[1];
    Scalar r_min = Red[0], r_max = Red[1];
    Scalar m_min = Mg[0], m_max = Mg[1];

    fs2.open(filename, FileStorage::WRITE);
    fs2 << "Camera_Settings";
    fs2 << "{" << "Brightness"   << brilho;
    fs2 <<        "Saturation"   << saturacao;
    fs2 <<        "Exposure"     << exposure;
    fs2 <<        "ExpoAuto"     << auto_exposure;
    fs2 <<        "Gamma"        << gamma;
    fs2 <<        "Nitidez"      << nitidez;
    fs2 <<        "Ganho"        << gain;
    fs2 <<        "WhiteBalance" << whiteBalance;
    fs2 <<        "WhiteBalAuto" << auto_whiteBalance;
    fs2 <<        "Luz_fundo"    << backlight_compensantion;
    fs2 <<        "Contrast"     << contraste;
    fs2 <<        "Matiz"        << hue << "}";
    fs2 << "Cut_Frame_Points";
    fs2 << "{" << "X"      << roi.x;
    fs2 <<        "Y"      << roi.y;
    fs2 <<        "Width"  << roi.width;
    fs2 <<        "Height" << roi.height << "}";
    fs2 << "Blue";
    fs2 << "{" << "Red_Max"   << b_max[2];
    fs2 <<        "Red_Min"   << b_min[2];
    fs2 <<        "Green_Max" << b_max[1];
    fs2 <<        "Green_Min" << b_min[1];
    fs2 <<        "Blue_Max"  << b_max[0];
    fs2 <<        "Blue_Min"  << b_min[0] << "}";
    fs2 << "Yellow";
    fs2 << "{" << "Red_Max"   << y_max[2];
    fs2 <<        "Red_Min"   << y_min[2];
    fs2 <<        "Green_Max" << y_max[1];
    fs2 <<        "Green_Min" << y_min[1];
    fs2 <<        "Blue_Max"  << y_max[0];
    fs2 <<        "Blue_Min"  << y_min[0] << "}";
    fs2 << "Green";
    fs2 << "{" << "Red_Max"   << g_max[2];
    fs2 <<        "Red_Min"   << g_min[2];
    fs2 <<        "Green_Max" << g_max[1];
    fs2 <<        "Green_Min" << g_min[1];
    fs2 <<        "Blue_Max"  << g_max[0];
    fs2 <<        "Blue_Min"  << g_min[0] << "}";
    fs2 << "Orange";
    fs2 << "{" << "Red_Max"   << o_max[2];
    fs2 <<        "Red_Min"   << o_min[2];
    fs2 <<        "Green_Max" << o_max[1];
    fs2 <<        "Green_Min" << o_min[1];
    fs2 <<        "Blue_Max"  << o_max[0];
    fs2 <<        "Blue_Min"  << o_min[0] << "}";
    fs2 << "Red";
    fs2 << "{" << "Red_Max"   << r_max[2];
    fs2 <<        "Red_Min"   << r_min[2];
    fs2 <<        "Green_Max" << r_max[1];
    fs2 <<        "Green_Min" << r_min[1];
    fs2 <<        "Blue_Max"  << r_max[0];
    fs2 <<        "Blue_Min"  << r_min[0] << "}";
    fs2 << "Magenta";
    fs2 << "{" << "Red_Max"   << m_max[2];
    fs2 <<        "Red_Min"   << m_min[2];
    fs2 <<        "Green_Max" << m_max[1];
    fs2 <<        "Green_Min" << m_min[1];
    fs2 <<        "Blue_Max"  << m_max[0];
    fs2 <<        "Blue_Min"  << m_min[0] << "}";
    fs2 << "Mascara";
    fs2 << "{" << "Format"     << mascara[0];
    fs2 <<        "Size"       << mascara[1];
    fs2 <<        "Size_close" << mascara[2] << "}";
    fs2 << "Resolution";
    fs2 << "{" << "Width"  << width;
    fs2 <<        "Height" << heigth;
    fs2 <<        "index"  << index << "}";
    fs2 << "Variaveis";
    fs2 << "{" << "ftop"       << ftop;
    fs2 <<        "fbot"       << fbot;
    fs2 <<        "gtopy"      << gtopy;
    fs2 <<        "gboty"      << gboty;
    fs2 <<        "fleftx"     << fleftx;
    fs2 <<        "frightx"    << frightx;
    fs2 <<        "gleft"      << gleft;
    fs2 <<        "gright"     << gright;
    fs2 <<        "area_left"  << area_left;
    fs2 <<        "area_right" << area_right;
    fs2 <<        "lgoleiro"   << lgoleiro;
    fs2 <<        "lzagueiro"  << lzagueiro;
    fs2 <<        "area_topy"  << area_topy;
    fs2 <<        "area_boty"  << area_boty;
    fs2 <<        "p_area_b"   << p_area_b;
    fs2 <<        "p_area_t"   << p_area_t << "}";
}

Configurations::~Configurations()
{
	fs.release();
    fs2.release();
}
