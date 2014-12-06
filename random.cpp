
#include"myrandom.h"
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

/*************************
//生成均匀的[0,1]分布
//RAND_MAX=32767=0x7fff(不定)
//size的大小不宜大于RAND_MAX
*************************/
void Std_uniform_distribution(double data[],const int size)
{
    //改变种子，随机数的初始值
    srand(time(NULL));
    for(int i = 0; i < size ;i++)
    {
        data[i] = double(rand()) / RAND_MAX ;
    }
}



/******************************
//由均匀分布生成均值为mean
//方差为var的正太分布
*******************************/
bool Normal_distribution(double data[], const int size,
                         double mean, double variance,
                         const double source1[],
                         const double source2[],
                         const int source_size)
{
    if(size > source_size) return false;
    for(int i = 0; i < size ;i++)
    {
        data[i] = sqrt(-2 * log(1 - source1[i])) *
         cos(2 * pi * source2[i]) * sqrt(variance) + mean;
    }
    return true;
}


/********************************
//通过快速排序来确定均匀分布的
//正确性，以均匀分布要覆盖X%的
//点为准则，100个数据点，X=90表
//示100个点里至少90个点不一样
*********************************/
int compare(const void* a, const void * b)
{
    return int( 2 * ((*((double*)a) > *((double*)b)) - 0.5));
}
bool check_Std_uniform_distribution(const double data[], const int size)
{
    double *temp_data = new double[size] ;
    for(int i = 0; i < size ; i++)
    {
        temp_data[i] = data[i];
    }
    qsort(temp_data, size, sizeof(double), compare);
    int counter = 0;
    double epsinon = double( 0.5 / RAND_MAX );
    for(int i = 1; i < size ; i++)
    {
        if(temp_data[i] - temp_data[i-1] > epsinon)
            counter++;
        //cout<<temp_data[i]<<'\n';
    }
    delete[] temp_data;
    double threshold = 0.9;
    if(counter > threshold * size)
        return true;
    else
        return false;

}


/******************************
//依据3sigma准则检验正太分布
//的正确性，sgima1=0.6526,
//sigma2=0.9544,sigma3=0.9974
*******************************/

bool Check_Normal_distribution(const double data[], const int size,
                               double mean, double variance)
{
    double * temp_data = new double [size];
    for(int i = 0; i < size; i++)
    {
        temp_data[i] = fabs(data[i]);
    }
    qsort(temp_data, size, sizeof(double), compare);
    double sigma1 = 0.6826 * size;
    double sigma2 = 0.9545 * size;
    double sigma3 = 0.9973 * size;
    double std_deviation1 = sqrt(variance);
    double std_deviation2 = std_deviation1 * 2;
    double std_deviation3 = std_deviation1 * 3;
    int sigma1_count = 0, sigma2_count = 0, sigma3_count = 0;
    for(int i = 0; i < size; i++)
    {
        if(temp_data[i] < std_deviation1)
            sigma1_count++;
        if(temp_data[i] < std_deviation2)
            sigma2_count++;
        if(temp_data[i] < std_deviation3)
            sigma3_count++;
        //cout<<temp_data[i]<<'\n';
    }
    //cout<<sigma1_count<<endl<<sigma2_count<<sigma3_count<<endl;
    int threshold = 0.05 * size;
    if(abs(sigma1_count - sigma1) < threshold
       && abs(sigma2_count - sigma2) < threshold
       && abs(sigma3_count - sigma3) < threshold)
        return true;
    else
        return false;
}

