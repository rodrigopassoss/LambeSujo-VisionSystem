#ifndef KMEANS_H
#define KMEANS_H

// Implementation of the KMeans Algorithm
// reference: http://mnemstudio.org/clustering-k-means-example-1.htm
#include "mainwindow.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

//OpenCV
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/calib3d/calib3d.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

#include "omp.h"

using namespace std;
using namespace cv;

class _Point
{
private:
    int id_point, id_cluster;
    Point values;
    string name;

public:
    _Point(int id_point, Point& values, string name = "")
    {
        this->id_point = id_point;
        this->values = values;

        this->name = name;
        id_cluster = -1;
    }

    int getID()
    {
        return id_point;
    }

    void setCluster(int id_cluster)
    {
        this->id_cluster = id_cluster;
    }

    int getCluster()
    {
        return id_cluster;
    }

    Point getValue()
    {
        return values;
    }

    string getName()
    {
        return name;
    }
};

class Cluster
{
private:
    int id_cluster;
    Point central_values;
    vector<_Point> points;

public:
    Cluster(int id_cluster, _Point point)
    {
        this->id_cluster = id_cluster;
        this->central_values = point.getValue();
        points.push_back(point);
    }

    void addPoint(_Point point)
    {
        points.push_back(point);
    }

    bool removePoint(int id_point)
    {
        int total_points = points.size();

        for(int i = 0; i < total_points; i++)
        {
            if(points[i].getID() == id_point)
            {
                points.erase(points.begin() + i);
                return true;
            }
        }
        return false;
    }

    Point getCentralValue()
    {
        return central_values;
    }

    void setCentralValue(Point value)
    {
        central_values = value;
    }

    _Point getPoint(int index)
    {
        return points[index];
    }

    int getTotalPoints()
    {
        return points.size();
    }

    int getID()
    {
        return id_cluster;
    }
};

class KMeans
{
private:
    int K; // number of clusters
    int total_points, max_iterations;
    vector<Cluster> clusters;

    // return ID of nearest center (uses euclidean distance)
    int getIDNearestCenter(_Point point)
    {
        double sum = 0.0, min_dist;
        int id_cluster_center = 0;


        sum = pow(clusters[0].getCentralValue().x - point.getValue().x, 2.0)
                    + pow(clusters[0].getCentralValue().y - point.getValue().y, 2.0);


        min_dist = sqrt(sum);

        for(int i = 1; i < K; i++)
        {
            double dist;
            sum = 0.0;

            sum = pow(clusters[i].getCentralValue().x - point.getValue().x, 2.0)
                    + pow(clusters[i].getCentralValue().y - point.getValue().y, 2.0);

            dist = sqrt(sum);

            if(dist < min_dist)
            {
                min_dist = dist;
                id_cluster_center = i;
            }
        }

        return id_cluster_center;
    }

    friend class MainWindow;

public:
    KMeans(int K, int total_points, int max_iterations)
    {
        this->K = K;
        this->total_points = total_points;
        this->max_iterations = max_iterations;
    }

    void run(vector<_Point> & points)
    {
        if(K > total_points)
            return;

        vector<int> prohibited_indexes;

        // choose K distinct values for the centers of the clusters
        for(int i = 0; i < K; i++)
        {
            while(true)
            {
                int index_point = rand() % total_points;

                if(find(prohibited_indexes.begin(), prohibited_indexes.end(),
                        index_point) == prohibited_indexes.end())
                {
                    prohibited_indexes.push_back(index_point);
                    points[index_point].setCluster(i);
                    Cluster cluster(i, points[index_point]);
                    clusters.push_back(cluster);
                    break;
                }
             }
         }


        int iter = 1;


            while(true)
            {
                bool done = true;

                // associates each point to the nearest center
                #pragma omp parallel for schedule(static)
                for(int i = 0; i < total_points; i++)
                {
                    int id_old_cluster = points[i].getCluster();
                    int id_nearest_center = getIDNearestCenter(points[i]);

                    if(id_old_cluster != id_nearest_center)
                    {
                        {
                            if(id_old_cluster != -1)
                                clusters[id_old_cluster].removePoint(points[i].getID());

                            points[i].setCluster(id_nearest_center);

                            #pragma omp critical
                            clusters[id_nearest_center].addPoint(points[i]);
                            done = false;
                        }
                    }
                }


                // recalculating the center of each cluster
                for(int i = 0; i < K; i++)
                {

                        int total_points_cluster = clusters[i].getTotalPoints();
                        double sum = 0.0;
                        double _sum = 0.0;

                        if(total_points_cluster > 0)
                        {
                            #pragma omp parallel for simd reduction(+:sum,_sum)
                            for(int p = 0; p < total_points_cluster; p++)
                            {
                                sum += clusters[i].getPoint(p).getValue().x;
                                _sum += clusters[i].getPoint(p).getValue().y;
                            }
                            clusters[i].setCentralValue(Point(sum/total_points_cluster,_sum/total_points_cluster));
                        }

                }



                if(done == true || iter >= max_iterations)
                {
                    //cout << "Break in iteration " << iter << "\n\n";
                    break;
                }

                iter++;


            }
        // shows elements of clusters
        /*for(int i = 0; i < K; i++)
        {
            int total_points_cluster =  clusters[i].getTotalPoints();

            cout << "Cluster " << clusters[i].getID() + 1 << endl;
            for(int j = 0; j < total_points_cluster; j++)
            {
                cout << "Point " << clusters[i].getPoint(j).getID() + 1 << ": ";
                    cout << clusters[i].getPoint(j).getValue() << " ";

                string point_name = clusters[i].getPoint(j).getName();

                if(point_name != "")
                    cout << "- " << point_name;

                cout << endl;
            }

            cout << "Cluster values: ";
                cout << clusters[i].getCentralValue() << " ";

            cout << "\n\n";
        }*/
    }
};




#endif // KMEANS_H
