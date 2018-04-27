#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;

//�洢���������������ݽṹ
struct flight_x {
	char flightID[20];//����ID
	char from[20];//��ɻ���
	char to[20];//�������
	char start_d[20];//�������
	char start_t[20];//���ʱ��
	char end_d[20];//��������
	char end_t[20];//����ʱ��
	char planeID[20];
	char cancel[20];//ȡ��
	char straight[20];//��ֱ
	char voidfly[20];//�շ�
	char signchange[20];//ǩת
	char signchange_detail[100];//ǩת���
};


//�洢ԭʼ���ݵ����ݽṹ
struct flight_y {
	char y_flightID[20];//ԭʼ���ݺ���ID
	char y_from[20];//ԭʼ������ɻ���
	char y_to[20];  //ԭʼ���ݽ������
	char y_start_d[20];//ԭʼ�����������
	char y_start_t[20];//ԭʼ�������ʱ��
	char y_end_d[20]; //ԭʼ���ݽ�������
	char y_end_t[20]; //ԭʼ���ݽ���ʱ��
	char y_planeID[20];//ԭʼ���ݷɻ�ID
	char y_plNum[20];//ԭʼ������ͨ�ÿ�����
	char y_llNum[20];//ԭʼ���������ÿ�����
	char y_seatNum[20];//ԭʼ������λ��
}y_table[5000];


int main()
{
	FILE *fp = NULL;//�����ȡ�����������ļ���ָ��
	FILE *yuandata = NULL;//�����ȡԭ�����ļ����ļ�ָ��
	char line[2048];//�����ȡԭ�����ļ�ÿ��2048���ַ�
	char yuan[2048];//�����ȡ�����������ļ�ÿ��2048���ַ�
	struct flight_x x_table[5000];


	//��ԭʼ���ݴ����ڴ浱��
	//yuandata2 = fopen("hangxia20170823.csv", "r");
	//if (yuandata2 == NULL) cout << "cuowu" << endl;
	if ((yuandata = fopen("hangxia20170823.csv", "r+")) != NULL)
	{
		char douhao[] = ",";//����
		char space[] = " ";//�ո�
		char *result2 = NULL;

		//��¼ԭʼ���ݵĸ���ָ��
		char *y_flightID;//ԭʼ���ݺ���ID
						 /*		char *y_from;//ԭʼ������ɻ���
						 char *y_to;  //ԭʼ���ݽ������
						 char *y_start_d;//ԭʼ�����������
						 char *y_start_t;//ԭʼ�������ʱ��
						 char *y_end_d; //ԭʼ���ݽ�������
						 char *y_end_t; //ԭʼ���ݽ���ʱ��
						 char *y_planeID;//ԭʼ���ݷɻ�ID
						 char *y_plNum;//ԭʼ������ͨ�ÿ�����
						 char *y_llNum;//ԭʼ���������ÿ�����
						 char *y_seatNum;//ԭʼ������λ��
						 */
						 //fgets(yuan, sizeof(yuan), yuandata);//����ԭʼ���ݵĵ�һ��
		int ii = 1;
		while (fgets(yuan, 2048, yuandata))
		{
			//cout << yuan << endl;
			result2 = strtok(yuan, douhao);
			y_flightID = result2;  //�洢ԭʼ���ݵ�y_flightID
			int temp = atoi(y_flightID);
			memcpy(y_table[ii].y_flightID, result2, (strlen(result2) + 1));
			//y_table[ii].y_flightID = result2;
			//sscanf(result2, "%s", y_table[ii].y_flightID);

			//���ŷָ�֮����������Ϊԭʼ���ݺ�����ɻ���
			//	result2 = strtok(NULL, douhao);
			//	result2 = strtok(NULL, douhao);
			//	result2 = strtok(NULL, douhao);
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_from = result2;
			memcpy(y_table[ii].y_from, result2, (strlen(result2) + 1));

			//���ŷָ�֮�����������Ϊԭʼ���ݺ��ཱུ�����
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_to = result2;
			memcpy(y_table[ii].y_to, result2, (strlen(result2) + 1));

			//�ո�ָ�֮����߸�����Ϊԭʼ���ݺ����������
			result2 = strtok(NULL, space);
			//y_table[ii].y_start_d = result2;
			memcpy(y_table[ii].y_start_d, result2, (strlen(result2) + 1));

			//ԭʼ���ݵ����ʱ��
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_start_t = result2;
			memcpy(y_table[ii].y_start_t, result2, (strlen(result2) + 1));

			//ԭʼ���ݵĽ�������
			result2 = strtok(NULL, space);
			//y_table[ii].y_end_d = result2;
			memcpy(y_table[ii].y_end_d, result2, (strlen(result2) + 1));

			//ԭʼ���ݵĽ���ʱ��
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_end_t = result2;
			memcpy(y_table[ii].y_end_t, result2, (strlen(result2) + 1));

			//ԭʼ����planeID
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_planeID = result2;
			memcpy(y_table[ii].y_planeID, result2, (strlen(result2) + 1));

			//��������������֮����ԭʼ������ͨ�ÿ�����
			//	result2 = strtok(NULL, douhao);
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_plNum = result2;
			memcpy(y_table[ii].y_plNum, result2, (strlen(result2) + 1));

			//����һ�����ź��������ÿ�����
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_llNum = result2;
			memcpy(y_table[ii].y_llNum, result2, (strlen(result2) + 1));

			//����һ�����ź��Ƿɻ���λ��
			result2 = strtok(NULL, "\n");
			//y_table[ii].y_seatNum = result2;
			memcpy(y_table[ii].y_seatNum, result2, (strlen(result2) + 1));

			//if(ii>3)cout <<"now i ="<<ii<<"\n in i="<<ii-1<<" "<< y_table[ii-1].y_flightID << "," << y_table[ii-1].y_from << "," << y_table[ii-1].y_to << "," << y_table[ii-1].y_start_d << " " << y_table[ii-1].y_start_t << "," << y_table[ii-1].y_end_d << " " << y_table[ii-1].y_end_t << "," << y_table[ii-1].y_planeID << endl;
			//cout << "i=1  "<< y_table[1].y_flightID << "," << y_table[1].y_from << "," << y_table[1].y_to << "," << y_table[1].y_start_d << " " << y_table[1].y_start_t << "," << y_table[1].y_end_d << " " << y_table[1].y_end_t << "," << y_table[1].y_planeID << endl;
			ii++;
		}
		fclose(yuandata);
		yuandata = NULL;
	}

	//���������������ݴ����ڴ浱��
	if ((fp = fopen("quickWithZero.csv", "at+")) != NULL)
	{
		char comma[] = ",";//����
		char space[] = " ";//�ո�
		char *result = NULL;
		char gogo[20];//һ���м�����������м��ַ���ת��

		while (fgets(line, 2048, fp))//���ж�ȡ�ļ��е�����
		{
			result = strtok(line, comma);//���������ݰ��ո�ָ���
			memcpy(gogo, result, (strlen(result) + 1));
			//�洢�����������еĺ���ID
			memcpy(x_table[atoi(gogo)].flightID, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].flightID = flightID;

			//�洢�����������е���ɻ���
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].from, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].from = result;

			//�洢�����������еĽ������
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].to, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].to = result;

			////�洢�����������е��������
			result = strtok(NULL, space);
			memcpy(x_table[atoi(gogo)].start_d, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].start_d = result;

			//�洢�����������е����ʱ��
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].start_t, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].start_t = result;

			//�洢�����������еĽ�������
			result = strtok(NULL, space);
			memcpy(x_table[atoi(gogo)].end_d, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].end_d = result;

			//�洢�����������еĽ���ʱ��
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].end_t, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].end_t = result;

			//�洢�����������е�planeID
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].planeID, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].planeID = result;

			//�洢�����������е�ȡ��
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].cancel, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].cancel = result;

			//�洢�����������е���ֱ
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].straight, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].straight = result;

			//�洢�����������еĵ���
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].voidfly, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].voidfly = result;
		}
		fclose(fp);
		fp = NULL;
	}


	//˼·;1���ȼ�����Ƿ�Ϊ������ֱ����ɵ�ȡ��������ǣ��򲻹�
	//     2������⵽������������ֱ����ɵ�ȡ���������ǩת����
	//     3���ҳ��ʹ�ȡ�����������ͬ��ɺͽ�������ĺ��࣬����ǩת
	//     4���ҳ�������Ӧ�������ͨ�ÿ�������λ���������һ��ǩת��ϣ������
	//     5���������ҳ��ڶ����������ǩת
	//     6���ظ�����3��4��5��ֱ���������������ÿ�ǩת���Ϊֹ
	//     7���������������ô˺������ǩת�ĺ��࣬��Ȼ����ʹ���������ÿ�ǩת��ϣ������������ȡ��

	int sseatNum = 0;//ĳ�ܺ���ʣ�����λ����
	int anpai_sNum = 0;//ĳ�ܺ�����ÿͱ����ź�ʣ����
	string aa = "1";
	string bb = "0";
	string dd = " ";
	char *end;
	char *aa1 = "1";
	char *aa0 = "0";
	char *aak = " ";
	//std::string x_cancel_s;
	for (int i = 1; i <= sizeof(y_table) / sizeof(y_table[1]); i++)//ѭ��ԭʼ�����е�2048������
	{
		memcpy(x_table[i].signchange, aa0, (strlen(aa0) + 1));//�������������е��ÿ�ǩת��ȫ�á�0��
		memcpy(x_table[i].signchange_detail, aak, (strlen(aak) + 1));//�������������е��ÿ�ǩת��ȫ�ÿո�

		if (x_table[i].cancel == aa)//�������������е����������Ӧ����ȡ�����������һ��
		{
			if (x_table[i].straight == bb)//�������������е����������Ӧ��ȡ���в�������������ɣ��������һ��
			{
				std::string yplNum_s = std::string(y_table[i].y_plNum);
				anpai_sNum = static_cast<int>(strtol(yplNum_s.c_str(), &end, 10));//�������������е������������Ӧ��ԭʼ�����ҳ�������������ͨ�ÿ͵��Ǹ��ַ�����ת��Ϊ����

																				  //�������ǵ����������ҳ�������ȡ���������Ķ�Ӧ����ɻ����ͽ������һ�µĺ���j
				for (int j = 1; j <= sizeof(x_table) / sizeof(x_table[1]); j++)//
				{
					if (anpai_sNum > 0)//�������i�����ŵ��ÿ���������0���������һ��
					{
						if (std::string(x_table[i].from) == std::string(x_table[j].from) && std::string(x_table[i].to) == std::string(x_table[j].to))//�Ŷ�����i�뺽��j��ʼ�����Ƿ�һ��,��һ־���������һ��
						{
							std::string yseatNum_s = std::string(y_table[j].y_seatNum);
							std::string yplNum_s = std::string(y_table[j].y_plNum);
							std::string yllNum_s = std::string(y_table[j].y_llNum);
							int ystNum = static_cast<int>(strtol(yseatNum_s.c_str(), &end, 10));
							int yplNum = static_cast<int>(strtol(yplNum_s.c_str(), &end, 10));
							int yllNum = static_cast<int>(strtol(yllNum_s.c_str(), &end, 10));
							sseatNum = ystNum - yplNum - yllNum;//�������j�л��ж��ٿ�λ���Խ����ÿ�
							if (sseatNum > 0)//�����п�λ���������һ��
							{
								if (x_table[j].cancel == bb)//�жϴ˼ܺ����Ƿ�ȡ������û��ȡ�����������һ��
								{
									cout << j << endl;
									//	std::string yseatNum_s = std::string(y_table[j].y_seatNum);
									//	std::string yplNum_s = std::string(y_table[j].y_plNum);
									//	std::string yllNum_s = std::string(y_table[j].y_llNum);
									//	int ystNum = static_cast<int>(strtol(yseatNum_s.c_str(), &end, 10));
									//	int yplNum = static_cast<int>(strtol(yplNum_s.c_str(), &end, 10));
									//	int yllNum = static_cast<int>(strtol(yllNum_s.c_str(), &end, 10));
									//	sseatNum = ystNum - yplNum - yllNum;

									std::string yplNum_si = std::string(y_table[i].y_plNum);
									int yplNumi = static_cast<int>(strtol(yplNum_si.c_str(), &end, 10));//������i�е���ͨ�ÿ�����ת��Ϊ����


									if (sseatNum >= yplNumi)//������j��ʣ����λ�����ڵ��ں���i�д����ŵ���ͨ�ÿ�����������һ��
									{
										//����˼·��1���������������еĺ���i��ǩת�����Ϊ��1��
										//           2��������i�д����ŵ���ͨ�ÿ�ȫ�������뺽��j
										//           3��������j�е�ԭʼ��ͨ�ÿͼ��ϱ����Ž������ÿͣ�������������������j�е���ͨ�ÿͣ��Է�����һ��ѭ�����㻹ʣ���ٿ�λ
										//           4��������i�л�δ���ŵ��ÿ�������0
										char temp11[20];
										//x_table[i].signchange = (char*)"1";
										memcpy(x_table[i].signchange, aa1, (strlen(aa1) + 1));
										_itoa(j, temp11, 10);
										//snprintf(temp11, sizeof(temp11), "%d", j);
										string temp21(temp11);
										string temp22(y_table[i].y_plNum);
										string temp3 = temp21 + ":" + temp22;
										char *temp121 = NULL;
										int len = temp3.length();
										temp121 = (char*)malloc((len + 1) * sizeof(char));
										temp3.copy(temp121, len, 0);
										//x_table[i].signchange_detail = temp12;
										memcpy(x_table[i].signchange_detail, temp121, (strlen(temp121) + 1));
										free(temp121);
										//temp12 = NULL;
										int zhuan = 0;
										zhuan = yplNumi + yplNum;
										char yp[20];
										//snprintf(yp, sizeof(yp), "%d", zhuan);
										_itoa(zhuan, yp, 10);
										memcpy(y_table[j].y_plNum, yp, (strlen(yp) + 1));
										//itoa(zhuan, y_table[j].y_plNum, 10);
										//snprintf(y_table[j].y_plNum, sizeof(y_table[j].y_plNum), "%d", zhuan);
										anpai_sNum = 0;
									}
									else if (sseatNum < yplNumi)//������j��ʣ����λ��С�ں���i�д����ŵ���ͨ�ÿ�����������һ��
									{
										//����˼·��1���������������еĺ���i��ǩת�����Ϊ��1��
										//           2��������i�д����ŵ�һ������ͨ�ÿ�ȫ�������뺽��j
										//           3��������j�е�ԭʼ��ͨ�ÿͼ��ϱ����Ž������ÿͣ�������������������j�е���ͨ�ÿͣ��Է�����һ��ѭ�����㻹ʣ���ٿ�λ
										//           4��������i�л�δ���ŵ��ÿ���������anpai_sNum���Խ�����һ��ѭ��
										//char *temp11 = NULL;
										//char *temp66 = NULL;
										char temp11[20];
										char temp66[20];
										char res2[5];
										memcpy(x_table[i].signchange, aa1, (strlen(aa1) + 1));
										//x_table[i].signchange = "1";
										_itoa(j, temp11, 10);
										_itoa(sseatNum, temp66, 10);
										//snprintf(temp11, sizeof(temp11), "%d", j);
										//snprintf(temp66, sizeof(temp66), "%d", sseatNum);
										string temp21(temp11);
										string temp22(temp66);
										string temp4(x_table[i].signchange_detail);
										//string temp4;
										//int hh = 0;
										//while (48 <= x_table[i].signchange_detail[hh] <= 57 && x_table[i].signchange_detail[hh] == 58 && x_table[i].signchange_detail[hh] == 38&&x_table[i].signchange_detail[hh]==32)
										//{
										//	sprintf(res2, "%c", x_table[i].signchange_detail[hh]);
										//	temp4 = temp4 + res2;
										//}
										if (x_table[i].signchange_detail == dd)//�жϺ���i�еİ�������Ƿ�Ϊ�գ���Ϊ�գ��򺽰�ϸ�ڵ��ַ���ǰ�治��"&"���
										{
											string temp32;
											char *temp123 = NULL;
											int len32;
											temp32 = temp21 + ":" + temp22;
											len32 = temp32.length();
											temp123 = (char*)malloc((len32 + 1) * sizeof(char));
											temp32.copy(temp123, len32, 0);
											memcpy(x_table[i].signchange_detail, temp123, (strlen(temp123) + 1));
											free(temp123);
											temp123 = NULL;
										}
										else//�жϺ���i�еİ�������Ƿ�Ϊ�գ�����Ϊ�գ��򺽰�ϸ�ڵ��ַ���ǰ���"&"��ǣ��Դ������Ӷ���������
										{
											string temp33 = temp4 + "&" + temp21 + ":" + temp22;
											char *temp12 = NULL;
											int len33 = temp33.length();
											temp12 = (char*)malloc((len33 + 1) * sizeof(char));
											temp33.copy(temp12, len33, 0);
											memcpy(x_table[i].signchange_detail, temp12, (strlen(temp12) + 1));
											//x_table[i].signchange_detail = temp12;
											free(temp12);
											temp12 = NULL;
										}
										int zhuan = 0;
										zhuan = sseatNum + yplNum;
										//zhuan = sseatNum + atoi(y_table[j].y_plNum);
										char yp2[20];
										//snprintf(yp2, sizeof(yp2), "%d", zhuan);
										_itoa(zhuan, yp2, 10);
										memcpy(y_table[j].y_plNum, yp2, (strlen(yp2) + 1));
										//itoa(zhuan, y_table[j].y_plNum, 10);
										//snprintf(y_table[j].y_plNum, sizeof(y_table[j].y_plNum), "%d", zhuan);
										//anpai_sNum = atoi(y_table[i].y_plNum) - sseatNum;
										anpai_sNum = yplNumi - sseatNum;
									}
									//	else
									//	{
									//		memcpy(x_table[i].signchange, aa0, (strlen(aa0) + 1));
									//		memcpy(x_table[i].signchange_detail, aak, (strlen(aak) + 1));
									//	}
								}
							}
						}

					}
				}
			}
		}
	}

	//����½�csv�ĵ��Դ洢ԭ������ݾ����ÿ͵��Ⱥ��ֵ
	ofstream outfile;
	outfile.open("qianzhuanlvke.csv", ios::out);
	int tt666 = sizeof(x_table) / sizeof(x_table[1]);
	for (int tt = 1; tt <= tt666; tt++)
	{
		outfile << x_table[tt].flightID << "," << x_table[tt].from << "," << x_table[tt].to << "," << x_table[tt].start_d << " " << x_table[tt].start_t << "," << x_table[tt].end_d << " " << x_table[tt].end_t << "," << x_table[tt].planeID << "," << x_table[tt].cancel << "," << x_table[tt].straight << "," << x_table[tt].voidfly << "," << x_table[tt].signchange << "," << x_table[tt].signchange_detail << "\n";
	}
	outfile.close();
	system("pause");
	return 0;
}




