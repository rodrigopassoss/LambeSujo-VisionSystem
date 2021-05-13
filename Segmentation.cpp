#include "Segmentation.h"

Segmentation::Segmentation(Mat *Mask)
{
	Mascara[0] = Mask[0];
	Mascara[1] = Mask[1];
    Segmentation_option = 0;
}

void Segmentation::Set_Mask(Mat *Mask)
{
    Mascara[0] = Mask[0];
    Mascara[1] = Mask[1];
}

void Segmentation::Get_Limiar_RGB(Scalar min, Scalar max)
{
    rgbmin = min;
    rgbmax = max;
}

void Segmentation::Get_Limiar_NewRGB(Scalar min, Scalar max, Scalar min2, Scalar max2)
{
    new_rgbmax_1 = max;
    new_rgbmin_1 = min;
    new_rgbmax_2 = max2;
    new_rgbmin_2 = min2;
}

void Segmentation::Get_Limiar_HSV(Scalar min, Scalar max)
{
    hsv_max = max;
    hsv_min = min;
}

Mat* Segmentation::Segmentation_Result(Mat *frame)
{
   if(Segmentation_option == 0)
       RGB_Segmentation(frame);
   else if (Segmentation_option == 1)
       HSV_Segmentation(frame);
   else if(Segmentation_option == 2)
       NEWRGB_Segmentation(frame);

   return &segmentacao;
}

void Segmentation::RGB_Segmentation(Mat *frame)
{
    //Mat aux;
    //cvtColor(*frame,aux,CV_BGR2RGB);
    inRange(*frame, rgbmin, rgbmax, segmentacao);
    morphologyEx(segmentacao, segmentacao,MORPH_OPEN, Mascara[0]);
    //morphologyEx(segmentacao, segmentacao,MORPH_CLOSE, Mascara[1]);

    /*clock_t start, end;
    double aux_print;

    start = clock();
    inRange(*frame, rgbmin, rgbmax, segmentacao);
    end = clock();
    aux_print = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Limiarização: " << aux_print << "ms; ";

    start = clock();
    morphologyEx(segmentacao, segmentacao,MORPH_OPEN, Mascara[0]);
    end = clock();
    aux_print = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Abertura: " << aux_print << "ms; ";

    start = clock();
    morphologyEx(segmentacao, segmentacao,MORPH_CLOSE, Mascara[1]);
    end = clock();
    aux_print = pow(10,3)*(end-start)/CLOCKS_PER_SEC;
    cout << "Fechamento: " << aux_print << "ms; ";*/
}

void Segmentation::HSV_Segmentation(Mat *frame)
{
    Mat aux;
    cvtColor(*frame,aux,COLOR_BGR2HSV);
    inRange(aux, hsv_min, hsv_max, segmentacao);
    morphologyEx(segmentacao, segmentacao,MORPH_OPEN, Mascara[0]);
    morphologyEx(segmentacao, segmentacao,MORPH_CLOSE, Mascara[1]);
}

void Segmentation::NEWRGB_Segmentation(Mat *frame)
{
    segmentacao =  Mat(frame->rows,frame->cols,CV_8U);

    for(int j=0;j<frame->rows; j++)
    {
        for (int i=0;i<frame->cols;i++)
        {
            r = (int)frame->at<Vec3b>(j,i)[2];
            g = (int)frame->at<Vec3b>(j,i)[1];
            b = (int)frame->at<Vec3b>(j,i)[0];
            rg = r-g;
            rb = r-b;
            gb = g-b;
            //cout<<r<<"\n";
            //cout<<g<<"\n";

            if( b >= new_rgbmin_1[0] &&  b <= new_rgbmax_1[0] &&
                g >= new_rgbmin_1[1] &&  g <= new_rgbmax_1[1] &&
                r >= new_rgbmin_1[2] &&  r <= new_rgbmax_1[2] &&
               rg >= new_rgbmin_2[0] && rg <= new_rgbmax_2[0] &&
               rb >= new_rgbmin_2[1] && rb <= new_rgbmax_2[1] &&
               gb >= new_rgbmin_2[2] && gb <= new_rgbmax_2[2]
             )
                segmentacao.at<uchar>(j,i) = (uchar)255;
            else
                segmentacao.at<uchar>(j,i) = (uchar)0;
        }
    }
}

