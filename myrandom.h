#ifndef MYRANDOM_H_INCLUDED
#define MYRANDOM_H_INCLUDED

/***************************
//���ɾ��ȵ�0,1�ֲ�
//RAND_MAX=32767=0x3fff(����)
//size�Ĵ�С���˴���RAND_MAX
****************************/
void Std_uniform_distribution(double data[], const int size);



/****************************
//�ɾ��ȷֲ����ɾ�ֵΪmean
//����Ϊvar����̫�ֲ�
*****************************/
bool Normal_distribution(double data[], const int size,
                         double mean, double variance,
                         const double source1[],
                         const double source2[],
                         const int source_size);


/******************************
//ͨ������������ȷ�����ȷֲ���
//��ȷ�ԣ��Ծ��ȷֲ�Ҫ����X%��
//��Ϊ׼��100�����ݵ㣬X=90��
//ʾ100����������90���㲻һ��
********************************/
bool check_Std_uniform_distribution(const double data[], const int size);


/******************************
//����3sigma׼�������̫�ֲ�
//����ȷ�ԣ�1sgima=0.6526,
//2sigma=0.9544,3sigma=0.9974
*******************************/
bool Check_Normal_distribution(const double data[], const int size,
                               double mean, double variance);



/******************************
//IEEE754�涨doubleС��λ54λ
//��Ӧʮ������С��λ16-17λ
//floatС��λΪ23λ
//��Ӧʮ����С��λΪ6-7λ
********************************/
const double pi = 3.1415926535898;



#endif // MYRANDOM_H_INCLUDED
