#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

//Qt
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>
#include <QMessageBox>

//OpenCV
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/calib3d/calib3d.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

//OUTROS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>
#include <time.h>


typedef double realtype;

#define max(a,b)		((a) > (b) ? (a) : (b))
#define min(a,b)		((a) < (b) ? (a) : (b))


QT_BEGIN_NAMESPACE
namespace Ui { class JanelaPrincipal; }
QT_END_NAMESPACE

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    JanelaPrincipal(QWidget *parent = nullptr);
    ~JanelaPrincipal();

    QTimer *cronometro;
    cv::Mat img;
    cv::VideoCapture cap;
    QImage image;
    cv::Rect2d roi;
    cv::Point pontos_corte[2];
    double x;
    double y;
    int cont = 0, cont_2 = 0, cont_3 = 0, cont_4 = 0;
    int modo_operate = 1;
    int guia_enable = 0;
    int point_enable = 0;
    int customOrder_enable = 0;
    bool applyCorte = false;
    std::vector<int> index_pixels;   // Para caso de seleção de pontos por ordem customizada


    //Vetores que armazena os pontos do plano imagem e do espaço real
    std::vector<cv::Point> pixels;
    std::vector<cv::Point> real;
    std::vector<cv::Point> cache;





private slots:
    void on_cortar_clicked();

    void on_calibrar_clicked();

    void Mouse_current_pos();

    /*
         * Método: Mouse_pressed();
         *
         * Descrição: Chamdo com o evento do click do mouse.
         *
         * Parâmentros:
         *            1) QMouseEvent *ev - essa classe é capaz de obter
         *                                 todos os eventos do mouse.
         *
         * Retorno:
         *       Nenhum.
    */

    void Mouse_pressed();

    void WorkMetodo();

    void on_guia_stateChanged(int arg1);

    void on_showPoint_stateChanged(int arg1);

    void on_customOrder_stateChanged(int arg1);

    void on_zerar_clicked();

    void on_remover_clicked();

    void on_applyAjuste_clicked();


private:
    Ui::JanelaPrincipal *ui;

    void algoritimo();

    void print_matrix(const gsl_matrix *m) {
        size_t i, j;

        for (i = 0; i < m->size1; i++) {
            for (j = 0; j < m->size2; j++) {
                printf("%f\t", gsl_matrix_get(m, i, j));
            }
            printf("\n");
        }
    }
    void print_vector (const gsl_vector * v) {
        size_t i;

        for (i = 0; i < v->size; i++) {
            printf("%f\t", gsl_vector_get (v, i));
        }
    }
    gsl_matrix* moore_penrose_pinv(gsl_matrix *A, const realtype rcond) {

        gsl_matrix *V, *Sigma_pinv, *U, *A_pinv;
        gsl_matrix *_tmp_mat = NULL;
        gsl_vector *_tmp_vec;
        gsl_vector *u;
        realtype x, cutoff;
        size_t i, j;
        unsigned int n = A->size1;
        unsigned int m = A->size2;
        bool was_swapped = false;


        if (m > n) {
            /* libgsl SVD can only handle the case m <= n - transpose matrix */
            was_swapped = true;
            _tmp_mat = gsl_matrix_alloc(m, n);
            gsl_matrix_transpose_memcpy(_tmp_mat, A);
            A = _tmp_mat;
            i = m;
            m = n;
            n = i;
        }

        /* do SVD */
        V = gsl_matrix_alloc(m, m);
        u = gsl_vector_alloc(m);
        _tmp_vec = gsl_vector_alloc(m);
        gsl_linalg_SV_decomp(A, V, u, _tmp_vec);
        gsl_vector_free(_tmp_vec);

        /* compute Σ⁻¹ */
        Sigma_pinv = gsl_matrix_alloc(m, n);
        gsl_matrix_set_zero(Sigma_pinv);
        cutoff = rcond * gsl_vector_max(u);

        for (i = 0; i < m; ++i) {
            if (gsl_vector_get(u, i) > cutoff) {
                x = 1. / gsl_vector_get(u, i);
            }
            else {
                x = 0.;
            }
            gsl_matrix_set(Sigma_pinv, i, i, x);
        }

        /* libgsl SVD yields "thin" SVD - pad to full matrix by adding zeros */
        U = gsl_matrix_alloc(n, n);
        gsl_matrix_set_zero(U);

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                gsl_matrix_set(U, i, j, gsl_matrix_get(A, i, j));
            }
        }

        if (_tmp_mat != NULL) {
            gsl_matrix_free(_tmp_mat);
        }

        /* two dot products to obtain pseudoinverse */
        _tmp_mat = gsl_matrix_alloc(m, n);
        gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1., V, Sigma_pinv, 0., _tmp_mat);

        if (was_swapped) {
            A_pinv = gsl_matrix_alloc(n, m);
            gsl_blas_dgemm(CblasNoTrans, CblasTrans, 1., U, _tmp_mat, 0., A_pinv);
        }
        else {
            A_pinv = gsl_matrix_alloc(m, n);
            gsl_blas_dgemm(CblasNoTrans, CblasTrans, 1., _tmp_mat, U, 0., A_pinv);
        }

        gsl_matrix_free(_tmp_mat);
        gsl_matrix_free(U);
        gsl_matrix_free(Sigma_pinv);
        gsl_vector_free(u);
        gsl_matrix_free(V);

        return A_pinv;
    }




};
#endif // JANELAPRINCIPAL_H
