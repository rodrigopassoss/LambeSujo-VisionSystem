#include "Ball.h"

Ball::Ball()
{
    // Se O Preditor_2 nao tiver legal, coloca N=3 e usa Preditor1
    int N = 10;
    for(int i = 0; i < N; i++)
    {
        pos.push_back(Point(0,0));
        pred.push_back(Point(0,0));
    }
    x = -1;
    y = -1;
    contador = 0;
}

void Ball::Refresh_Position(Point bola)
{
	x = bola.x;
	y = bola.y;

    pos.push_back(Point(x,y));
    pos.erase(pos.begin()+0);

    if (contador%3 == 0)
        pred = Predict_Ball_2();
    if (sqrt(pow(x-pred[2].x,2) + pow(y-pred[2].y,2)) > (area_left))
    {
        //cout << "Dist: " << sqrt(pow(x-pred.x,2) + pow(y-pred.y,2)) << endl;
        pred[0] = Point(x,y);
        pred[1] = Point(x,y);
        pred[2] = Point(x,y);
    }
    contador++;
}

void Ball::Refresh_Position(int xa, int ya)
{
    x = xa;
    y = ya;
}

vector <Point> Ball::Predict_Ball(void)
{

    // Quantas amostras serão usadas para treinar: 3;
    // Depende de quantas foram inicializadas no construtor
    // Retornarei um vetor de 3 pontos, tais que os primeiros elementos são futuros mais próximos

    float a = 0;     // Começo da pseudoinversão (A'A)^(-1)
    float A1,A2;     // Multiplica a por A'
    float theta = 0; //Guarda o termo do preditor
    float temp = 0;
    vector <Point> result;
    result.push_back(Point(0,0));
    result.push_back(Point(0,0));
    result.push_back(Point(0,0));

    //Primeiro para a posição x.
    a = 1/(pow(this->pos[0].x,2) + pow(this->pos[1].x,2)+0.001);

    A1 = this->pos[0].x * a;
    A2 = this->pos[1].x * a;//Fim da pseudoinversão

    theta = A1 * this->pos[1].x + A2 * this->pos[2].x;

    //cout << this->pos[2].x << " " << theta << endl;
    temp = theta * this->pos[2].x;
    result[0].x = theta * temp;
    temp = theta * result[0].x;
    result[1].x = theta * result[0].x;
    result[2].x = theta * result[1].x;

    //Agora para a posição y.

    a = 1/(pow(this->pos[0].y,2) + pow(this->pos[1].y,2)+0.001);

    A1 = this->pos[0].y * a;
    A2 = this->pos[1].y * a;//Fim da pseudoinversão

    theta = A1 * this->pos[1].y + A2 * this->pos[2].y;

    temp = theta * this->pos[2].y;
    result[0].y = theta * temp;
    temp = theta * result[0].y;
    result[1].y = theta * result[0].y;
    result[2].y = theta * result[1].y;

    return result;
}

vector<Point> Ball::Predict_Ball_2()
{

    // Depende de quantas foram inicializadas no construtor
    // Retornarei um vetor de 3 pontos, tais que os primeiros elementos são futuros mais próximos
    int N = 0;
    float a = 0;     // Começo da pseudoinversão (A'A)^(-1)
    float A1,A2;     // Multiplica a por A'
    float theta = 0; //Guarda o termo do preditor
    float temp = 0;
    N = this->pos.size()-1; // indice do ultimo elemento

    vector <Point> result;
    result.push_back(Point(0,0));
    result.push_back(Point(0,0));
    result.push_back(Point(0,0));

    //Primeiro para a posição x.
    for (int m = 0; m < (N-1);m++)
       a = a + pow(this->pos[m].x,2);
    a = 1/(a + 0.001);

    for(int m = 0; m < (N-1);m++)
       theta = theta + a * this->pos[m].x * this->pos[m+1].x;

    temp = theta * this->pos[N].x;
    result[0].x = theta * temp;
    temp = theta * result[0].x;
    result[1].x = theta * result[0].x;
    result[2].x = theta * result[1].x;

    //Agora pra posicao y.
    a = 0;
    theta = 0;

    for (int m = 0; m < (N-1);m++)
       a = a + pow(this->pos[m].y,2);
    a = 1/(a + 0.001);

    for(int m = 0; m < (N-1);m++)
       theta = theta + a * this->pos[m].y * this->pos[m+1].y;

    temp = theta * this->pos[N].y;
    result[0].y = theta * temp;
    temp = theta * result[0].y;
    result[1].y = theta * result[0].y;
    result[2].y = theta * result[1].y;

    return result;
}

void Ball::Set_Campo(Configurations *c)
{
    area_left = c->area_left;
}

Ball::~Ball()
{

}
