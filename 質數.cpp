#include <stdio.h>
#include <math.h>
#include <unistd.h> 
#include <time.h> //�u�O�Q�n���K�p��@�U�ɶ� 
#include <process.h> //�h������禡�w

bool prime(unsigned int Num2);

int main(){
	unsigned int Num1;
	while(1){
		printf("�п�J�@�ӭ�:");
		scanf("%u",&Num1);									//�p�G�n��double�N�n�ϥ� %lf �ӧ���ܼƭ� unsingned int �n�� %u 
		/*printf("��Ʀ�:2");
		for(int LoopNum1 = 3; LoopNum1 <= Num1 ; LoopNum1+=2){    	//�۰ʲ��� 3 ~ �ϥΪ̿�J���ȡA���Ʀ]���@�w�� 2 ���]�ơA���F�[�֧P�w�ڥ��������ͩ_�ơC 
			if(prime(LoopNum1))										//�P�w�O�_����ơA�O�N��X 
				printf(",%d",LoopNum1);
		}*/
		/*if(prime(Num1))									//�P�w�O�_����ơA�O�N��X 
				printf("�O���");
		else(unsigned int)
				printf("���O���");*/
		for(unsigned int LoopNum1 = Num1; LoopNum1 >= 2 ; LoopNum1--){    	//�۰ʲ��� 3 ~ �ϥΪ̿�J���ȡA���Ʀ]���@�w�� 2 ���]�ơA���F�[�֧P�w�ڥ��������ͩ_�ơC 
			if(prime(LoopNum1)){								//�P�w�O�_����ơA�O�N��X 
				printf(",%u",LoopNum1);
				break;
			}
		}
		system("pause");
	}
	return 0;
}

bool prime(unsigned int Num2){
	bool realNum = true;
	for(unsigned int LoopNum2 = 2; LoopNum2 <= sqrt(Num2) ; LoopNum2++)	//�ڷ|�ήڸ��O�]�� ���ۭ��̤j�N�O2����F�ҥH���ڸ��Y�i�ֱ��ܦh�P�w
		if(Num2 % LoopNum2 == 0){								//�}�l�P�w�C�u�n�i�H���ɴN�P�w���O��ơA�N�|���W���X�j��  
			realNum = false;
			break;
		}
	return realNum;
}


void displayProgress(int progress){  
        int k = 0;  
        for (k=0; k<106; k++)  
                putchar('\b');										//�M����Цb�����@��A�Ψӧ@���i�ױ���ܶi��  
        int j = 0;
        fprintf(stderr,"  �i��: ");
        for (j=0; j<progress/2; j++)  
                putchar('>');										//�i�ק�����������">"�Ӫ�� 
        for (j=1; j<=50-progress/2; j++)  
                putchar('-');										//�i�ץ�������������"="�Ӫ��
        fprintf(stdout, "  %3d%%",progress);  
        fflush(stdout);
}
