#ifndef MYRANDOM_H_INCLUDED
#define MYRANDOM_H_INCLUDED

/***************************
//生成均匀的0,1分布
//RAND_MAX=32767=0x3fff(不定)
//size的大小不宜大于RAND_MAX
****************************/
void Std_uniform_distribution(double data[], const int size);



/****************************
//由均匀分布生成均值为mean
//方差为var的正太分布
*****************************/
bool Normal_distribution(double data[], const int size,
                         double mean, double variance,
                         const double source1[],
                         const double source2[],
                         const int source_size);


/******************************
//通过快速排序来确定均匀分布的
//正确性，以均匀分布要覆盖X%的
//点为准则，100个数据点，X=90表
//示100个点里至少90个点不一样
********************************/
bool check_Std_uniform_distribution(const double data[], const int size);


/******************************
//依据3sigma准则检验正太分布
//的正确性，1sgima=0.6526,
//2sigma=0.9544,3sigma=0.9974
*******************************/
bool Check_Normal_distribution(const double data[], const int size,
                               double mean, double variance);



/******************************
//IEEE754规定double小数位54位
//对应十进制数小数位16-17位
//float小数位为23位
//对应十进制小数位为6-7位
********************************/
const double pi = 3.1415926535898;



#endif // MYRANDOM_H_INCLUDED
